#include <Windows.h>
#include <Util.h>

#include <cstring>
#include <cstdlib>
#include <iostream>

#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>
#include <d3d11.h>
#include <d3d11_1.h>

using namespace std;

namespace Open3D::Windowing
{
	// Define a interface for create a base
	// to build high-graphics applications
	// with DirectX trough Win32 APIs
	class API_EXPORT Application
	{
	public:
		inline Application() { this->window = 0; }

		// Utils

		// Core
		virtual void onInit(HWND hWnd) = 0;
		virtual void onUpdate() = 0;
		virtual void onExit() = 0;

		void Run(int width, int height, std::string title);
	private:
		GLFWwindow* window;
	};
}