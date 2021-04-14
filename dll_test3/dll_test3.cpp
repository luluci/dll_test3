// dll_test3.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <thread>

#include <windows.h>

#include "dll_if.h"

typedef void(__stdcall* DLL_IF_GET)(dllif::dll_if_t*);
typedef void(__stdcall* DLL_IF_GUI)(void);

bool thread_finish = false;
void gui_hdle(DLL_IF_GET);

int main()
{

    std::cout << "Hello World!\n";

	auto dll = ::LoadLibrary(L"dll_if.dll");
	auto if_get = reinterpret_cast<DLL_IF_GET>(::GetProcAddress(dll, "dll_if_get"));
	auto if_gui = reinterpret_cast<DLL_IF_GUI>(::GetProcAddress(dll, "dll_if_gui"));

	/*
	std::thread thrd(gui_hdle, if_get);

	if_gui();

	thread_finish = true;
	thrd.join();
	*/
	try {
		std::cout << "call if_gui()!\n";
		if_gui();
	}
	catch (...) {
		std::cout << "exception!" << std::endl;
	}

	if (dll) ::FreeLibrary(dll);

	return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します

void gui_hdle(DLL_IF_GET if_get) {
	dllif::dll_if_t if_c = { 0 };
	int value = -1;
	int prev_value = -1;
	auto sleep_time = std::chrono::seconds(1);

	while (!thread_finish) {
		if_get(&if_c);
		value = if_c.ad;
		if (value != prev_value) {
			std::cout << "value:" << value << std::endl;
			prev_value = value;
		}
		std::this_thread::sleep_for(sleep_time);
	}

	std::cout << "Thread finish!";

}
