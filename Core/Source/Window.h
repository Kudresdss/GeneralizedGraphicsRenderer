#pragma once

#include <GLFW/glfw3.h>

#include <string>

namespace GGR {

struct WindowSpecification
{
	std::string title = "New Window";
	uint32_t width = 1280;
	uint32_t height = 720;

	bool isResizeable = true;
	bool hasVSync = true;

	// event call back fn
};

class Window
{
public:
	Window(const WindowSpecification& WindowSpec = WindowSpecification());
	
	~Window();
	void destroy();
	bool shouldClose() const;

	void create();
	void update();

	//void raiseEvent();
	
	//glm::vec2 GetFramebufferSize() const;
	//glm::vec2 GetMousePos() const;

	GLFWwindow* getWindowHandle() const { return WindowHandle; };

private:
	WindowSpecification WindowSpec;
	GLFWwindow* WindowHandle = nullptr;

};

} // namespace GGR
