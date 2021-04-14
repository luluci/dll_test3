#pragma once

//using namespace System;


// エクスポートとインポートの切り替え
//#ifdef VC_DLL_EXPORTS
//#undef VC_DLL_EXPORTS
//#define VC_DLL_EXPORTS extern "C" __declspec(dllexport)
//#else
//#define VC_DLL_EXPORTS extern "C" __declspec(dllimport)
//#endif
#define VC_DLL_EXPORTS


namespace dllif {
	/*
	public ref class Class1
	{
		// TODO: このクラスのメソッドをここに追加します。
		int hoge;
	};
	*/

	typedef struct dll_if_type {
		int ad;
	} dll_if_t;

	VC_DLL_EXPORTS void __stdcall dll_if_get(dll_if_t*);
	VC_DLL_EXPORTS void __stdcall dll_if_gui(void);
}
