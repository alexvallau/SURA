#include <Windows.h>
#include <stdio.h>
#include<WinUser.h>
#include <ctype.h>
#include <processthreadsapi.h>
#include <stdbool.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <stdbool.h>
#include "listProcess.h"


MSLLHOOKSTRUCT MouseStruct;

LRESULT CALLBACK MouseProc(
  _In_ int    nCode,
  _In_ WPARAM wParam,
  _In_ LPARAM lParam
){

    
    HWND   windowHandle;
    DWORD processID;
    TCHAR Buffer[MAX_PATH];
    HANDLE hProcessSnap;
    PROCESSENTRY32 pe32;
    hashTable* table ;


    MouseStruct = *(MSLLHOOKSTRUCT*)lParam;
    if(nCode == HC_ACTION || nCode > 0 ){
        switch(wParam){
            printf("%d", wParam);
            case WM_LBUTTONDOWN:
                {
                    windowHandle = GetForegroundWindow();
                    table = GetProcessList();
                    DWORD currentProcID = GetWindowThreadProcessId(windowHandle, &processID);
                    printf("le nom de l'item sur le quel je clique est: %s le nombre d'item est %d", searchItemInTable(table, processID), table->count);
                   
                   free_table(table);
                    break;
                }    
                 
         }    
    }
     
      
     return CallNextHookEx(NULL, nCode, wParam, lParam);

}