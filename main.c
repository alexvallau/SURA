#include <Windows.h>
#include <stdio.h>
#include <processthreadsapi.h>
#include <stdbool.h>
#include "azerty.h"
#include "click.h"
#include <TlHelp32.h>

int main(void){

   
 
    hMouse = SetWindowsHookExA(WH_MOUSE_LL, MouseProc, NULL, 0);
    hKeyboard = SetWindowsHookExA(WH_KEYBOARD_LL, LowLevelKeyboardProc, NULL, 0);

    printf("Mouse Hook is %s", (hMouse!=NULL)?"NOT NULL":"NULL");
    printf("Mouse Hook is %s", (hKeyboard!=NULL)?"NOT NULL":"NULL");

    //structure
    MSG msg;

    while(1){
        while(PeekMessage(&msg, 0, 0, 0, PM_REMOVE)){
            if(msg.message == WM_QUIT)
                break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            UnhookWindowsHookEx(hMouse);
            UnhookWindowsHookEx(hKeyboard);    
            
        }
        Sleep(10);
    }           
                                                             
    
    return msg.wParam;
}