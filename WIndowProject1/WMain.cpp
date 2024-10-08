#include "MyWindow.h"
#include <d3d11.h>
#include <random>
// #pragma comment(lib, "d3d11.lib")
// interface acquire

class MyDevice2 : public MyWindow
{
public:
	using MyWindow::MyWindow;
	ID3D11Device* g_pd3dDevice = nullptr;
	ID3D11DeviceContext* g_pContext = nullptr;
	IDXGISwapChain* g_pSwapChain = nullptr;
	ID3D11RenderTargetView* g_pRTV = nullptr;

	bool CreateDevice();
	void DeleteDevice();
	void GameRun();
};


bool MyDevice2::CreateDevice()
{
	//IDXGIAdapter* pAdapter = nullptr;
	//D3D_DRIVER_TYPE DriverType = D3D_DRIVER_TYPE_HARDWARE;
	//HMODULE Software = nullptr;
	//UINT Flags = 0;
	CONST D3D_FEATURE_LEVEL pFeatureLevels = D3D_FEATURE_LEVEL_11_0;
	//UINT FeatureLevels = 1;
	//UINT SDKVersion = D3D11_SDK_VERSION;
	// relate to swapchain
	DXGI_SWAP_CHAIN_DESC pSwapChainDesc;
	ZeroMemory(&pSwapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
	pSwapChainDesc.BufferDesc.Width = 1024;
	pSwapChainDesc.BufferDesc.Height = 1024;
	pSwapChainDesc.BufferDesc.RefreshRate.Numerator = 100;
	pSwapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	pSwapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	//pSwapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	pSwapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	pSwapChainDesc.SampleDesc.Count = 1;
	//pSwapChainDesc.SampleDesc.Quality = 0;
	pSwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	pSwapChainDesc.BufferCount = 1;
	pSwapChainDesc.OutputWindow = this->hWnd;
	pSwapChainDesc.Windowed = true;
	pSwapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	//pSwapChainDesc.Flags = 0;

	HRESULT hr = D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		0,
		&pFeatureLevels,
		1,
		D3D11_SDK_VERSION,
		&pSwapChainDesc,
		&g_pSwapChain,
		&g_pd3dDevice,
		nullptr,
		&g_pContext
		);

	if (FAILED(hr))
	{
		return false;
	}
	
	if (g_pd3dDevice != nullptr && g_pSwapChain != nullptr)
	{
		ID3D11Texture2D* pBackBuffer = nullptr;
		g_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBackBuffer);

		ID3D11Resource* pResource = pBackBuffer;
		D3D11_RENDER_TARGET_VIEW_DESC* pDesc = nullptr;
		hr = g_pd3dDevice->CreateRenderTargetView(
			pResource,
			pDesc,
			&g_pRTV);
		if (FAILED(hr))
		{
			return false;
		}

		pBackBuffer->Release();
	}

	if (g_pContext != nullptr)
	{
		g_pContext->OMSetRenderTargets(1, &g_pRTV, nullptr);
	}
	return true;
}

void MyDevice2::DeleteDevice()
{
	if(g_pSwapChain) g_pSwapChain->Release();
	if(g_pd3dDevice) g_pd3dDevice->Release();
	if(g_pContext) g_pContext->Release();
	if(g_pRTV) g_pRTV->Release();
}

void MyDevice2::GameRun()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<float> a(0.f, 1.f);
	
	Sleep(100);
	float clearColor[] = { a(mt), 0.f, 0.f, 1.0f };
	g_pContext->ClearRenderTargetView(g_pRTV, clearColor);

	g_pSwapChain->Present(0, 0);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR
	pCmdLine, int nCmdShow)
{
	MyDevice2 device(hInstance, L"MyWindow Project");
	//MyWindow window(hInstance, L"Test");
	if (device.CreateWin(100, 100, 1024, 768))
	{
		if (device.CreateDevice())
		{
			device.WindowRun();
		}
		device.DeleteDevice();
	}
	// Run the message loop.
	return 0;
}

