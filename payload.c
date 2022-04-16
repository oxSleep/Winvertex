#include "virt_screen.h"
#include "payload.h"
#include "timer.h"

VOID
ExecutePayload(
	_In_ VERTEX_PAYLOAD payload,
	_In_ INT nTime
) {
	HDC hdcScreen = GetDC(NULL);
	INT dwStartTime = dwTimeElapsed;
	for (INT i = 0; dwStartTime < (dwTimeElapsed + nTime); i++)
		payload(i, hdcScreen);
	ReleaseDC(NULL, hdcScreen);
}

VOID
Payload1(
	_In_ INT t,
	_In_ HDC hdcScreen
) {
	POINT ptScreen = GetVirtualScreenPos();
	SIZE  szScreen = GetVirtualScreenSize();
	t *= 10;
	BitBlt(hdcScreen, ptScreen.x, ptScreen.y, szScreen.cx, szScreen.cy, hdcScreen,
		ptScreen.x + t % (szScreen.cx * 2) - szScreen.cx, ptScreen.y + t * 2 % (szScreen.cy * 2) - szScreen.cy, NOTSRCERASE);

	BitBlt(hdcScreen, ptScreen.x, ptScreen.y, szScreen.cx, szScreen.cy, hdcScreen,
		300, ptScreen.x + t * 2 % (szScreen.cx * 2) - szScreen.cx, NOTSRCCOPY);

	//BitBlt(hdcScreen, rand() % 10 - 20, rand() % 20 - 10, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
	//BitBlt(hdcScreen, rand() % 10 - 20, rand() % 20 - 10, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);

}