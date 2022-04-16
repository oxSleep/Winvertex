#include <Windows.h>
#include "payload.h"
#include "timer.h"

INT
WINAPI

wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ INT nShowCmd
) {
	CreateThread(NULL, 0, (PTHREAD_START_ROUTINE)InitTimer, (PVOID)10, 0, NULL);
	ExecutePayload(Payload1, 1000000);
}