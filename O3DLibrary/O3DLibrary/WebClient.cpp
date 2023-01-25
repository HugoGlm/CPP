#include "WebClient.h"
#include "Exception.h"
#include "Process.h"
#include "WebCallBack.h"
#pragma comment(lib, "Urlmon.lib")
#include <Urlmon.h>

#pragma region constructor
Core::Net::WebClient::WebClient(const Uri& _uri)
{
	uri = _uri;
}
Core::Net::WebClient::WebClient(const WebClient& _copy)
{
	uri = _copy.uri;
}
#pragma endregion

#pragma region methods
void Core::Net::WebClient::DownloadFile(const PrimitiveType::FString& _pathFile)
{
	const std::wstring _uriWstr = uri.Path().ToWString();
	const LPCWSTR _uri = _uriWstr.c_str();
	const std::wstring _pathWstr = _pathFile.ToWString();
	const LPCWSTR _path = _pathWstr.c_str();
	WebCallBack* _callback = new WebCallBack();
	_callback->OnDownLoadProgress.AddDynamic(&OnDownLoadProgress, &Action<float>::Invoke);
	const HRESULT _result = URLDownloadToFile(NULL, _uri, _path, 0, _callback);
	if (_result != S_OK)
		throw Exception("[WEBCLIENT] => uri doesn't valid !");
	else
		Diagnostics::Process::Start(_pathFile, "");
}
#pragma endregion