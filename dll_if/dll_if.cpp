#include "pch.h"

#define VC_DLL_EXPORTS
#include "dll_if.h"

using namespace System;
using namespace dllif;


#using "dll_gui.dll"



void __stdcall dllif::dll_if_get(dll_if_t *if_c) {
	if_c->ad = dll_gui::GUI_IF::get_value();
}

void __stdcall dllif::dll_if_gui_start() {
	try {
		Console::WriteLine("GUI!");
		dll_gui::GUI_IF::start_gui();
	}
	catch (Exception ^e) {
		Console::WriteLine("exception!");
	}
}

void __stdcall dllif::dll_if_gui_end() {
	try {
		dll_gui::GUI_IF::end_gui();
	}
	catch (Exception ^e) {
		Console::WriteLine("exception!");
	}
}

bool __stdcall dllif::dll_if_gui_is_active() {
	try {
		return dll_gui::GUI_IF::gui_is_active();
	}
	catch (Exception ^e) {
		Console::WriteLine("exception!");
	}
}
