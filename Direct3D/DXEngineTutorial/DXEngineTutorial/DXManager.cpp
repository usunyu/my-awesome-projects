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
    ID3D11Texture2D* backBufferPtr;

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

    for (int i = 0; i < (int)numModes; ++i)
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

    if (!InitializeSwapChain(hwnd, fullscreen, screenWidth, screenHeight, numerator, denominator))
    {
        return false;
    }

    // Get the pointer to the back buffer
    result = m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBufferPtr);
    if (FAILED(result))
    {
        return false;
    }

    // Create the render target view
    result = m_device->CreateRenderTargetView(backBufferPtr, NULL, &m_renderTargetView);
    if (FAILED(result))
    {
        return false;
    }

    // Relase back buffer
    backBufferPtr->Release();
    backBufferPtr = 0;

    if (!InitializeDepthBuffer(screenWidth, screenHeight))
    {
        return false;
    }

    if (!InitializeDepthStencilBuffer())
    {
        return false;
    }

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
    DXGI_SWAP_CHAIN_DESC swapChainDesc;
    D3D_FEATURE_LEVEL featureLevel;
    HRESULT result;

    // Initialize swap chain
    ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));

    // Set to a single back buffer
    swapChainDesc.BufferCount = 1;

    // Set the width and height of the back buffer
    swapChainDesc.BufferDesc.Width = screenWidth;
    swapChainDesc.BufferDesc.Height = screenHeight;

    // Set the regular 32-bit back buffer
    swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

    // Set the refresh rate of the back buffer
    if (m_vsync_enabled)
    {
        swapChainDesc.BufferDesc.RefreshRate.Numerator = numerator;
        swapChainDesc.BufferDesc.RefreshRate.Denominator = denominator;
    }
    else
    {
        swapChainDesc.BufferDesc.RefreshRate.Numerator = 0;
        swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
    }

    // Set the usage of the back buffer
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

    // Set the handle for the window
    swapChainDesc.OutputWindow = hwnd;

    // Turn multisampling off
    swapChainDesc.SampleDesc.Count = 1;
    swapChainDesc.SampleDesc.Quality = 0;

    // Set to full screen or windowed mode
    swapChainDesc.Windowed = fullscreen;

    // Set the scan line ordering and scaling to unspecified
    swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
    swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

    // Discard the back buffer contents after presenting
    swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    swapChainDesc.Flags = 0;

    // Set feature level to DirectX 11
    featureLevel = D3D_FEATURE_LEVEL_11_0;

    // Create swap chain, device, and device context
    result = D3D11CreateDeviceAndSwapChain(
        NULL,
        D3D_DRIVER_TYPE_HARDWARE,
        NULL,
        0,
        &featureLevel,
        1,
        D3D11_SDK_VERSION,
        &swapChainDesc,
        &m_swapChain,
        &m_device,
        NULL,
        &m_deviceContext);
    if (FAILED(result))
    {
        return false;
    }

    return true;
}

bool DXManager::InitializeDepthBuffer(int screenWidth, int screenHeight)
{
    D3D11_TEXTURE2D_DESC depthBufferDesc;
    HRESULT result;

    // Initialize depth buffer desc
    ZeroMemory(&depthBufferDesc, sizeof(depthBufferDesc));

    // Setup depth buffer desc
    depthBufferDesc.Width = screenWidth;
    depthBufferDesc.Height = screenHeight;
    depthBufferDesc.MipLevels = 1;
    depthBufferDesc.ArraySize = 1;
    depthBufferDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    depthBufferDesc.SampleDesc.Count = 1;
    depthBufferDesc.SampleDesc.Quality = 0;
    depthBufferDesc.Usage = D3D11_USAGE_DEFAULT;
    depthBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
    depthBufferDesc.CPUAccessFlags = 0;
    depthBufferDesc.MiscFlags = 0;

    // Create the texture for the depth buffer
    result = m_device->CreateTexture2D(&depthBufferDesc, NULL, &m_depthStencilBuffer);
    if (FAILED(result))
    {
        return false;
    }

    return true;
}

bool DXManager::InitializeDepthStencilBuffer()
{
    D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
    HRESULT result;

    // Initialize depth stencil desc
    ZeroMemory(&depthStencilDesc, sizeof(depthStencilDesc));

    // Setup description
    depthStencilDesc.DepthEnable = true;
    depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
    depthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;

    depthStencilDesc.StencilEnable = true;
    depthStencilDesc.StencilReadMask = 0xFF;
    depthStencilDesc.StencilWriteMask = 0xFF;

    // Stencil operations if pixel is front-facing
    depthStencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
    depthStencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
    depthStencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_INCR;
    depthStencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

    // Stencil operations if pixel is back-facing
    depthStencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
    depthStencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
    depthStencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_INCR;
    depthStencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

    // Create depth stencil state
    result = m_device->CreateDepthStencilState(&depthStencilDesc, &m_depthStencilState);
    if (FAILED(result))
    {
        return false;
    }

    // Set depth stencil state
    m_deviceContext->OMSetDepthStencilState(m_depthStencilState, 1);

    return true;
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