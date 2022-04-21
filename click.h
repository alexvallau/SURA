#ifndef CLICK_H
#define CLICK_H


#include<windows.h>

HHOOK hMouse;


LRESULT CALLBACK MouseProc(
  _In_ int    nCode,
  _In_ WPARAM wParam,
  _In_ LPARAM lParam
);


#endif