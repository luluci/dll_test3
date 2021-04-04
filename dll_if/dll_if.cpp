#include "pch.h"

#define VC_DLL_EXPORTS
#include "dll_if.h"

using namespace System;
using namespace dllif;


#using "dll_gui.dll"



ref class WND_WRAPPER {
public:
	static dll_gui::UserControl1 ^wnd = gcnew dll_gui::UserControl1();
};



void __stdcall dllif::dll_if_get(dll_if_t *if_c) {
	if_c->ad = WND_WRAPPER::wnd->data_c->X;
}

void __stdcall dllif::dll_if_gui() {
	WND_WRAPPER::wnd->ShowDialog();
}
