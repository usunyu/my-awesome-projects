#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

class Framework
{
public:
    Framework();
    ~Framework();

    bool Initialize();
    void Run();

private:
    bool CreateDXWindow(char* windowTitle, int x, int y, int width, int height);
    char* m_applicationName;
    HINSTANCE m_hInstance;
};

