#include <cstring>
#include <cstdlib>
#include <iostream>

#include <Windows.h>

#include <d3d11.h>
#include <d3d11_1.h>

#include <core/Util.h>

using namespace std;

namespace Open3D::Windowing
{

	struct API_EXPORT WindowData
	{
	public:
		HINSTANCE hInstance;
		int nCmdShow;
	};

	// Define a interface for create a base
	// to build high-graphics applications
	// with DirectX trough Win32 APIs
	class API_EXPORT Application
	{
	public:
		inline Application() { }

		// Utils

		// Core
		virtual void onInit(HWND hWnd) = 0;
		virtual void onUpdate() = 0;
		virtual void onExit() = 0;

		void Run(int width, int height, LPCWSTR title, WindowData wData);
	private:
		WNDCLASS _windowClass;
		LPCWSTR className;
		HWND windowHandle;
		MSG message;

		static LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	};
}