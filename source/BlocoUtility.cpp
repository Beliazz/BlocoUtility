// ClearEventManager.cpp : Defines the exported functions for the DLL application.
//
// Windows6
#include <Windows.h>
#include <WindowsX.h>
#pragma comment(lib, "winmm.lib" )
#pragma comment(lib, "comctl32.lib" )

BOOL APIENTRY DllMain( HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
	)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}


