#include <core/Application.hpp>

namespace Open3D::Windowing
{
	void Application::Run(int width, int height, LPCWSTR title, WindowData wData)
	{
		ZeroMemory(&this->_windowClass, sizeof(WNDCLASS));
		this->className = title;
		this->_windowClass.lpfnWndProc = this->WindowProcedure;
		this->_windowClass.lpszClassName = this->className;
		this->_windowClass.hInstance = wData.hInstance;

		RegisterClass(&this->_windowClass);
		this->windowHandle = CreateWindowEx(0, this->className, title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height, NULL, NULL, wData.hInstance, NULL);
		if (this->windowHandle == NULL)
		{
			MessageBox(NULL, L"Failed to create window!", L"Open3D Renderer API Error", 0);
		}
		ShowWindow(this->windowHandle, wData.nCmdShow);
		this->onInit(this->windowHandle);
		while (GetMessage(&this->message, NULL, 0, 0) > 0)
		{
			TranslateMessage(&this->message);
			DispatchMessage(&this->message);
		}
	}
	LRESULT Application::WindowProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_QUIT:
			PostQuitMessage(0);

		default:
			break;
		}
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}