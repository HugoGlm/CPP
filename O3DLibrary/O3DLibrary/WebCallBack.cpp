#include "WebCallBack.h"

#pragma region IBindStatusCallback
HRESULT __stdcall Core::Net::WebCallBack::QueryInterface(REFIID riid, void** ppvObject)
{
    if (IsEqualIID(IID_IBindStatusCallback, riid) || IsEqualIID(IID_IUnknown, riid))
    {
        *ppvObject = reinterpret_cast<void*>(this);
        return S_OK;
    }
    return E_NOINTERFACE;
}
ULONG __stdcall Core::Net::WebCallBack::AddRef(void)
{
    return 2UL;
}
ULONG __stdcall Core::Net::WebCallBack::Release(void)
{
    return 1UL;
}
HRESULT __stdcall Core::Net::WebCallBack::OnStartBinding(DWORD dwReserved, IBinding* pib)
{
    return E_NOTIMPL;
}
HRESULT __stdcall Core::Net::WebCallBack::GetPriority(LONG* pnPriority)
{
    return E_NOTIMPL;
}
HRESULT __stdcall Core::Net::WebCallBack::OnLowResource(DWORD reserved)
{
    return E_NOTIMPL;
}
HRESULT __stdcall Core::Net::WebCallBack::OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText)
{
    switch (ulStatusCode)
    {
    case BINDSTATUS_FINDINGRESOURCE:
        std::cout << "Find ressource..." << std::endl;
        break;
    case BINDSTATUS_CONNECTING:
        std::cout << "Connecting..." << std::endl;
        break;
    case BINDSTATUS_SENDINGREQUEST:
        std::cout << "Sendig request..." << std::endl;
        break;
    case BINDSTATUS_MIMETYPEAVAILABLE:
        std::cout << "Mime type available..." << std::endl;
        break;
    case BINDSTATUS_CACHEFILENAMEAVAILABLE:
        std::cout << "Cache filename available..." << std::endl;
        break;
    case BINDSTATUS_BEGINDOWNLOADDATA:
        std::cout << "Begin download..." << std::endl;
        break;
    case BINDSTATUS_DOWNLOADINGDATA:
    {
        const float _percent = (100.0 * (float)ulProgress / (float)ulProgressMax);
        if (lastPercent < _percent)
        {
            OnDownLoadProgress.Invoke(lastPercent = _percent);
        }
        break;
    }
    case BINDSTATUS_ENDDOWNLOADDATA:
        std::cout << "End download..." << std::endl;
        break;
    default:
        std::cout << "Status code: " << ulStatusCode << std::endl;
    }
    return S_OK;
}
HRESULT __stdcall Core::Net::WebCallBack::OnStopBinding(HRESULT hresult, LPCWSTR szError)
{
    return E_NOTIMPL;
}
HRESULT __stdcall Core::Net::WebCallBack::GetBindInfo(DWORD* grfBINDF, BINDINFO* pbindinfo)
{
    return E_NOTIMPL;
}
HRESULT __stdcall Core::Net::WebCallBack::OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC* pformatetc, STGMEDIUM* pstgmed)
{
    return E_NOTIMPL;
}
HRESULT __stdcall Core::Net::WebCallBack::OnObjectAvailable(REFIID riid, IUnknown* punk)
{
    return E_NOTIMPL;
}
#pragma endregion
