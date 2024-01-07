#pragma once

#include <Windows.h>
#include <d3d11.h>
#include <d3d11_1.h>

#include <Util.h>

namespace Open3D::Render
{
	class API_EXPORT RenderingContext
	{
	public:
		// Fields
		IDXGISwapChain* _swapChain;
		ID3D11Device* _gpuInstance;
		ID3D11DeviceContext* _gpuContext;

		// Methods
		void createContext(HWND hWnd);
		void cleanup();
	};
}