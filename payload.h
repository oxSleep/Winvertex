#pragma once 
#include <Windows.h>

typedef VOID(VERTEX_PAYLOAD)(_In_ INT t, _In_ HDC hdcScreen);

extern
VOID
ExecutePayload(
	VERTEX_PAYLOAD payload,
	INT nTime
);

extern VERTEX_PAYLOAD Payload1;