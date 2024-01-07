#include <Windows.h>

#include <Application.hpp>
#include <RenderingContext.hpp>

using namespace Open3D::Windowing;
using namespace Open3D::Render;

class App :public Application
{
    RenderingContext ctx{};

    void onInit(HWND hWnd)
    {
        ctx.createContext(hWnd);
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
    App app{};
    app.Run(800, 800, "Hello");

}