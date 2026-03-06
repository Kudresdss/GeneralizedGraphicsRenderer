#include "Window.h"

#include "glad/glad.h"

#include <iostream>
#include <assert.h>

namespace GGR {

Window::Window(const WindowSpecification& WindowSpec) : WindowSpec(WindowSpec) {}

Window::~Window()
{
	destroy();
}

void Window::destroy()
{
	if (WindowHandle != nullptr) {
		glfwDestroyWindow(WindowHandle);
		WindowHandle = nullptr;
	}
}

bool Window::shouldClose() const
{
	return glfwWindowShouldClose(WindowHandle);
}

void Window::create()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

	WindowHandle = glfwCreateWindow(
		WindowSpec.width, WindowSpec.height, WindowSpec.title.c_str(),
		nullptr, nullptr
	);

	if (WindowHandle == nullptr) {
		std::cerr << "Failed to create GLFW window!\n";
		assert(false);
	}

	glfwMakeContextCurrent(WindowHandle);
	gladLoadGL();

	glfwSwapInterval(WindowSpec.hasVSync ? 1 : 0);

	glfwSetWindowUserPointer(WindowHandle, this);

	// GLFW CALLBACKS
}

void Window::update()
{
	glfwSwapBuffers(WindowHandle);
}


}  // namespace GGR
