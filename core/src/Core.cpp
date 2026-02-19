#include "glad/glad.h"
#include "Core.h"
//#include "KHR/khrplatform.h"

#include <GLFW/glfw3.h>

#include <fstream>
#include <sstream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

unsigned int createShaderProgram(const std::string& vertexShaderCode, const std::string& fragmentShaderCode);
unsigned int compileShader(unsigned int type, const std::string& source);

std::string readFile(const std::string fileName);

int render()
{
    GLFWwindow* window;

    // Initialize GLFW library
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Mac OS X

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
    if (window == NULL) {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Initialize GLAD library
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);

    // triangle
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };


    // VAO
    unsigned int VAO{};
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // VBO
    unsigned int VBO{};
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
    glEnableVertexAttribArray(0);



    glBindBuffer(GL_ARRAY_BUFFER, 0);



    unsigned int shaderProgram =
                createShaderProgram(
                readFile("../../../resources/shaders/SimpleVertexShader.shader"),
                readFile("../../../resources/shaders/SimpleFragmentShader.shader"));

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        /* input */
        processInput(window);

        /* Render here */
        
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);

        glClearColor(0.2f, 0.8f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Poll for and process events */
        glfwPollEvents();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

unsigned int createShaderProgram(const std::string& vertexShaderCode, const std::string& fragmentShaderCode)
{
    unsigned int shaderProgram = glCreateProgram();
    unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderCode);
    unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderCode);


    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glValidateProgram(shaderProgram);

    return shaderProgram;
}

unsigned int compileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* shaderSource = source.c_str();
    glShaderSource(id, 1, &shaderSource, nullptr);
    glCompileShader(id);

    int ivResult;
    glGetShaderiv(id, GL_COMPILE_STATUS, &ivResult);
    if (ivResult == GL_FALSE) {
        int logLength;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &logLength);
        char* log = (char*)alloca(logLength * sizeof(char));
        glGetShaderInfoLog(id, logLength, &logLength, log);
        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
        std::cout << log << std::endl;

        glDeleteShader(id);

        return 0;
    }

    return id;
}

std::string readFile(const std::string filePath)
{
    std::cout << filePath << std::endl;

    std::ifstream file(filePath);
    if (file.fail())
        std::cout << "no file" << std::endl;

    std::stringstream content;



    content << file.rdbuf();

    std::cout << content.str() << std::endl;

    return content.str();
}
