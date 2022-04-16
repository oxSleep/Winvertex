#include "virt_screen.h"

RECT
GetVirtualScreen(
	VOID
) {
	RECT rcScreen = { 0 };
	EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, &rcScreen);
	return rcScreen;
}

POINT
GetVirtualScreenPos(
	VOID
) {
	RECT rcScreen = GetVirtualScreen();
	POINT ptScreen = {
		rcScreen.left,
		rcScreen.top
	};
	return ptScreen;
}

SIZE
GetVirtualScreenSize(
	VOID
) {
	RECT rcScreen = GetVirtualScreen();
	SIZE szScreen = {
		rcScreen.right - rcScreen.left,
		rcScreen.bottom - rcScreen.top
	};
	return szScreen;
}

BOOL
CALLBACK
MonitorEnumProc(
	_In_ HMONITOR hMonitor,
	_In_ HDC hdcMonitor,
	_In_ PRECT prcBounds,
	_In_ LPARAM lParam
) {
	PRECT prcParam = (PRECT)lParam;
	UnionRect(prcParam, prcParam, prcBounds);
}