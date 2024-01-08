#include <Windows.h>

#include <Open3D.hpp>

using namespace Open3D::Windowing;
using namespace Open3D::Render;

class App :public Application
{
    RenderingContext ctx{};

    void onInit(HWND hWnd)
    {
        ctx.createContext(hWnd, 800, 800);

        float color[4] = { 0.0f, 0.5f, 0.0f, 1.0f};
        clearColor(ctx, color);

        ctx._swapChain->Present(0, 0);
    }
    void onUpdate()
    {

    }
    void onExit()
    {
        ctx.cleanup();
    }
};

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    WindowData data;
    data.hInstance = hInst;
    data.nCmdShow = cmdshow;

    App app{};
    app.Run(800, 800, L"Hello", data);

}