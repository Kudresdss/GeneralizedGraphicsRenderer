#pragma once

#include "Window.h"

#include <string>
#include <memory>

namespace GGR {

struct ApplicationSpecification {
	std::string appName{ "Generalized Graphics Renderer" };
	WindowSpecification WindowSpecs;
};

class Application {
public:
	Application(const ApplicationSpecification& AppSpecs = ApplicationSpecification());
	~Application();

	void run();
	void stop();

	//void raiseEvent();

	//void pushLayer();
	//TLayer* getLayer();

	//glm::vec2 getFramebuffersize();

	std::shared_ptr<Window> getWindow();

private:
	ApplicationSpecification AppSpecs;
	std::shared_ptr<Window> Window;

	bool isRunning = false;

	//layerStack;

	friend class Layer;

};


}  // namespace GGR
