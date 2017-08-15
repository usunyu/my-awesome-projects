#pragma once

#include <dxgi.h>
#include <d3dcommon.h>
#include <d3d11.h>

class DXManager
{
public:
    DXManager();
    ~DXManager();

    bool Initialize(int screenWidth, int screenHeight, bool vsync, HWND hwnd, bool fullscreen);
    void BeginScene(float r, float g, float b, float a);
    void EndScene();

    void EnableAlphaBlending(bool enable);
    void EnableZBuffer(bool enable);

    ID3D11Device* GetDevice();
    ID3D11DeviceContext* GetDeviceContext();

private:
    bool InitializeSwapChain(
        HWND hwnd,
        bool fullscreen,
        int screenWidth,
        int screenHeight,
        unsigned int numerator,
        unsigned int denominator);
    bool InitializeDepthBuffer(int screenWidth, int screenHeight);
    bool InitializeDepthStencilBuffer();
    bool InitializeStencilView();
    bool InitializeRasterizerState();
    void InitializeViewport(int screenWidth, int screenHeight);
    bool InitializeAlphaBlending();
    bool InitializeZBuffer();

    bool m_vsync_enabled;
    int m_videoCardMemory;
    char m_videoCardDescription[128];
    IDXGISwapChain* m_swapChain;
    ID3D11Device* m_device;
    ID3D11DeviceContext* m_deviceContext;
    ID3D11RenderTargetView* m_renderTargetView;
    ID3D11Texture2D* m_depthStencilBuffer;
    ID3D11DepthStencilState* m_depthStencilState;
    ID3D11DepthStencilView* m_depthStencilView;
    ID3D11RasterizerState* m_rasterState;
    ID3D11BlendState* m_alphaEnableBlendingState;
    ID3D11BlendState* m_alphaDisableBlendingState;
    ID3D11DepthStencilState* m_depthDisabledStencilState;
};

