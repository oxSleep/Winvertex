#pragma once
#include <Windows.h>

extern DWORD dwTimeElapsed;


extern
VOID
InitTimer(
	_In_ UINT uDelay
);

extern
VOID
CALLBACK
TimerProc(
	_In_ HWND hwndTImer,
	_In_  UINT uMsg,
	_In_  UINT_PTR ulTimerID,
	_In_  DWORD dwTime
);