#include "RenderingContext.hpp"

namespace Open3D::Render
{
	void RenderingContext::createContext(HWND hWnd)
	{
		DXGI_SWAP_CHAIN_DESC swapDescriptor;
		ZeroMemory(&swapDescriptor, sizeof(DXGI_SWAP_CHAIN_DESC));
        swapDescriptor.BufferCount = 1;                                    // one back buffer
        swapDescriptor.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;     // use 32-bit color
        swapDescriptor.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;      // how swap chain is to be used
        swapDescriptor.OutputWindow = hWnd;                                // the window to be used
        swapDescriptor.SampleDesc.Count = 4;                               // how many multisamples
        swapDescriptor.Windowed = TRUE;                                    // windowed/full-screen mode

        // create a device, device context and swap chain using the information in the swapDescriptor struct
        D3D11CreateDeviceAndSwapChain(NULL,
            D3D_DRIVER_TYPE_HARDWARE,
            NULL,
            NULL,
            NULL,
            NULL,
            D3D11_SDK_VERSION,
            &swapDescriptor,
            &this->_swapChain,
            &this->_gpuInstance,
            NULL,
            &this->_gpuContext);
	}
	void RenderingContext::cleanup()
	{
        this->_swapChain->Release();
        this->_gpuInstance->Release();
        this->_gpuContext->Release();
	}
}