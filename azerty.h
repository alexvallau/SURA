#ifndef AZERTY_H
#define AZERTY_h

#include <Windows.h>
#include <stdio.h>
#include<WinUser.h>
#include <ctype.h>
#include <processthreadsapi.h>
#include <stdbool.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <stdbool.h>


HHOOK hKeyboard;

LRESULT CALLBACK LowLevelKeyboardProc(
  _In_ int    nCode,
  _In_ WPARAM wParam,
  _In_ LPARAM lParam
);






#endif