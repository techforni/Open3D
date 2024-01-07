#include <Application.hpp>

namespace Open3D::Windowing
{
	void Application::Run(int width, int height, std::string title)
	{
		if (!glfwInit())
		{
			throw std::runtime_error("Failed to start GLFW API!");
			glfwTerminate();
		}

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		this->window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		if (window == nullptr)
		{
			throw std::runtime_error("Failed to create a window!");
		}
		glfwMakeContextCurrent(this->window);

		this->onInit(glfwGetWin32Window(this->window));

		while (!glfwWindowShouldClose(this->window))
		{
			this->onUpdate();
			glfwSwapBuffers(this->window);
			glfwPollEvents();
		}
		this->onExit();
		glfwDestroyWindow(this->window);
		glfwTerminate();
	}
}