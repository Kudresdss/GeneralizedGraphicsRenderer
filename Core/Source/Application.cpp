#include "Application.h"

#include <iostream>


namespace GGR {


static Application* GlobalApplication = nullptr; // ????? ??????? ??? ?????????? ????????? ??? ??-?? lifetime?

static void glfwErrorCallback(int error, const char* description)
{
	std::cerr << "[GLFW Error]: " << description << std::endl;
}

Application::Application(const ApplicationSpecification& AppSpecs) : AppSpecs(AppSpecs)
{

}


}  // namespace GGR

