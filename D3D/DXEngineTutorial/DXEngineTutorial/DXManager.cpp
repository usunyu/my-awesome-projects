#include "DXManager.h"

DXManager::DXManager()
{
    m_swapChain = 0;
    m_device = 0;
    m_deviceContext = 0;
    m_renderTargetView = 0;
    m_depthStencilBuffer = 0;
    m_depthStencilState = 0;
    m_depthStencilView = 0;
    m_rasterState = 0;
    m_alphaEnableBlendingState = 0;
    m_alphaDisableBlendingState = 0;
    m_depthDisabledStencilState = 0;
}

DXManager::~DXManager()
{
    // Before shutting down set to windowed mode or when you release the swap chain
    // it will throw an exception
    if (m_swapChain)
    {
        m_swapChain->SetFullscreenState(false, NULL);
    }
    if (m_depthDisabledStencilState)
    {
        m_depthDisabledStencilState->Release();
        m_depthDisabledStencilState = 0;
    }
    if (m_alphaDisableBlendingState)
    {
        m_alphaDisableBlendingState->Release();
        m_alphaDisableBlendingState = 0;
    }
    if (m_alphaEnableBlendingState)
    {
        m_alphaEnableBlendingState->Release();
        m_alphaEnableBlendingState = 0;
    }
    if (m_rasterState)
    {
        m_rasterState->Release();
        m_rasterState = 0;
    }
    if (m_depthStencilView)
    {
        m_depthStencilView->Release();
        m_depthStencilView = 0;
    }
    if (m_depthStencilState)
    {
        m_depthStencilState->Release();
        m_depthStencilState = 0;
    }
    if (m_depthStencilBuffer)
    {
        m_depthStencilBuffer->Release();
        m_depthStencilBuffer = 0;
    }
    if (m_renderTargetView)
    {
        m_renderTargetView->Release();
        m_renderTargetView = 0;
    }
    if (m_deviceContext)
    {
        m_deviceContext->Release();
        m_deviceContext = 0;
    }
    if (m_device)
    {
        m_device->Release();
        m_device = 0;
    }
    if (m_swapChain)
    {
        m_swapChain->Release();
        m_swapChain = 0;
    }
}

bool DXManager::Initialize(int screenWidth, int screenHeight, bool vsync, HWND hwnd, bool fullscreen)
{
    HRESULT result;
    IDXGIFactory* factory;
    IDXGIAdapter* adapter;
    IDXGIOutput* adapterOutput;
    unsigned int numModes, numerator = 0, denominator = 0, stringLength;
    DXGI_MODE_DESC* displayModeList;
    DXGI_ADAPTER_DESC adapterDesc;
    int error;
    ID3D11Texture2D* backBufferPth;

    // Store vscync setting
    m_vsync_enabled = vsync;

    // Create a DirectX graphic interface factory
    result = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&factory);
    if (FAILED(result))
    {
        return false;
    }
    
    // Use the factory to create an adapter for the primary graphics interface
    result = factory->EnumAdapters(0, &adapter);
    if (FAILED(result))
    {
        return false;
    }

    // Enumarate the primary adapter output
    result = adapter->EnumOutputs(0, &adapterOutput);
    if (FAILED(result))
    {
        return false;
    }

    // Get the number of modes that fit the DXGI_FORMAT_R8G8B8A8_UNORM display format
    // for the adapter output
    result = adapterOutput->GetDisplayModeList(
        DXGI_FORMAT_R8G8B8A8_UNORM,
        DXGI_ENUM_MODES_INTERLACED,
        &numModes,
        NULL);
    if (FAILED(result))
    {
        return false;
    }

    // Create a list to hold all the possibile modes for the monitor/video card combination
    displayModeList = new DXGI_MODE_DESC[numModes];

    // Fill the display mode list
    result = adapterOutput->GetDisplayModeList(
        DXGI_FORMAT_R8G8B8A8_UNORM,
        DXGI_ENUM_MODES_INTERLACED,
        &numModes,
        displayModeList);
    if (FAILED(result))
    {
        return false;
    }

    for (int i = 0; i < numModes; ++i)
    {
        if (displayModeList[i].Width == (unsigned int)screenWidth)
        {
            if (displayModeList[i].Height == (unsigned int)screenHeight)
            {
                numerator = displayModeList[i].RefreshRate.Numerator;
                denominator = displayModeList[i].RefreshRate.Denominator;
            }
        }
    }
    if (numerator == 0 && denominator == 0)
    {
        return false;
    }

    // Get the adapter description
    result = adapter->GetDesc(&adapterDesc);
    if (FAILED(result))
    {
        return false;
    }

    // Store the video card memory in mbs
    m_videoCardMemory = (int)(adapterDesc.DedicatedVideoMemory / 1024 / 1024);

    // Convert the name of the video card to a character array
    error = wcstombs_s(&stringLength, m_videoCardDescription, 128, adapterDesc.Description, 128);
    if (error)
    {
        return false;
    }

    // Relase memory
    delete[] displayModeList;
    displayModeList = 0;

    adapterOutput->Release();
    adapterOutput = 0;

    adapter->Release();
    adapter = 0;

    factory->Release();
    factory = 0;

    return true;
}

void DXManager::BeginScene(float r, float g, float b, float a)
{

}

void DXManager::EndScene()
{

}

void DXManager::EnableAlphaBlending(bool enable)
{

}

void DXManager::EnableZBuffer(bool enable)
{

}

ID3D11Device* DXManager::GetDevice()
{
    return NULL;
}

ID3D11DeviceContext* DXManager::GetDeviceContext()
{
    return NULL;
}

bool DXManager::InitializeSwapChain(
    HWND hwnd,
    bool fullscreen,
    int screenWidth,
    int screenHeight,
    unsigned int numerator,
    unsigned int denominator)
{
    return false;
}

bool DXManager::InitializeDepthBuffer(int screenWidth, int screenHeight)
{
    return false;
}

bool DXManager::InitializeDepthStencilBuffer()
{
    return false;
}

bool DXManager::InitializeStencilView()
{
    return false;
}

bool DXManager::InitializeRasterizerState()
{
    return false;
}

void DXManager::InitializeViewport(int screenWidth, int screenHeight)
{

}

bool DXManager::InitializeAlphaBlending()
{
    return false;
}

bool DXManager::InitializeZBuffer()
{
    return false;
}