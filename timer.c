#include "timer.h"
#include "payload.h"
DWORD dwTimeElapsed;

VOID
InitTimer(
	_In_ UINT uDelay
) {
	SetTimer(NULL, 0, uDelay, TimerProc);

	MSG msg = { 0 };
	while (TRUE){
		if (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}
	}
}

VOID
CALLBACK
TimerProc(
	HWND hwndTImer,
	UINT uMsg,
	UINT_PTR ulTimerID,
	DWORD dwTime

) {
	dwTimeElapsed = dwTime;
}