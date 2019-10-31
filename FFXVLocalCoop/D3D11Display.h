#pragma once
#include <Windows.h>
#include <d3d11.h>

struct SurfaceImp
{
	char description[0x20];
	ID3D11Resource* texture_;
	ID3D11RenderTargetView* renderTargetView_;
	ID3D11DepthStencilView *depthStencilView_;
	ID3D11DepthStencilView *depthStencilViewReadOnly_;
	ID3D11ShaderResourceView *shaderResourceView_;
	unsigned __int64 subResourceIndex_;
	unsigned __int64 mipmapIndex_;
	unsigned __int64 arrayIndex_;
	__int16 viewX_;
	__int16 viewY_;
	__int16 viewWidth_;
	__int16 viewHeight_;
};

struct RenderTexture
{
	void* color[8];
	void* depthStencil;
	unsigned int mrtCount;
	bool owner;
};

struct D3D11Display
{
	int displayMode;
	HWND__* hwnd;
	bool autoDestroyWindow;
	SurfaceImp surface;
	RenderTexture backBuffer;
	char overlaySurface[0x68];
	IDXGISwapChain* swapChain;  //TODO see if AutoComPtr<IDXGISwapChain> can be treated as IDXGISwapChain* OR AutoComPtr.ptr.IDXGISwapChain
	DXGI_SWAP_CHAIN_DESC lastSwapChainDesc;
	bool lastFullScreenMode_;
	ID3D11Query* flipSyncs_[8];
	unsigned int flipSyncCounter_;
	unsigned int outputDisplayIndex_;
	bool changedSwapChain_;
	float pqLuminanceScale_;
	float displayScale_;
	char displayScalingMode_;
	unsigned __int64 width_;
	unsigned __int64 height_;
	unsigned __int64 windowWidth_;
	unsigned __int64 windowHeight_;
	float aspect_;
	int syncInterval_;
	bool active_;
	bool bindedDisplay_;
	float gamma_;
	int outputCount_;
	bool useOverlay_;
	char hdrMode_;
	int reservedHDRMode_;
	char stereo3D[0xE0];
};

/*
struct __cppobj SQEX::Luminous::RenderInterface::D3D11::D3D11Display : SQEX::Luminous::RenderInterface::Allocatable
{
  SQEX::Luminous::RenderInterface::DisplayMode displayMode;
  HWND__ *windowHandle_;
  bool autoDestroyWindow_;
  SQEX::Luminous::RenderInterface::Surface displayBuffer;
  SQEX::Luminous::RenderInterface::RenderTexture backBuffer;
  SQEX::Luminous::RenderInterface::TextureEx overlaySurface;
  SQEX::Luminous::RenderInterface::D3D11::AutoComPtr<IDXGISwapChain> swapChain;
  DXGI_SWAP_CHAIN_DESC lastSwapChainDesc_;
  bool lastFullScreenMode_;
  SQEX::Luminous::RenderInterface::D3D11::AutoComPtr<ID3D11Query> flipSyncs_[8];
  unsigned int flipSyncCounter_;
  unsigned int outputDisplayIndex_;
  bool changedSwapChain_;
  float pqLuminanceScale_;
  float displayScale_;
  SQEX::Luminous::RenderInterface::DisplayScalingMode displayScalingMode_;
  unsigned __int64 width_;
  unsigned __int64 height_;
  unsigned __int64 windowWidth_;
  unsigned __int64 windowHeight_;
  float aspect_;
  int syncInterval_;
  bool active_;
  bool bindedDisplay_;
  float gamma_;
  int outputCount_;
  bool useOverlay_;
  SQEX::Luminous::RenderInterface::HDRMode hdrMode_;
  int reservedHDRMode_;
  SQEX::Luminous::RenderInterface::Stereo3D stereo3D;
};
*/