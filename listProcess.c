
#include "listProcess.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>




pidAndName* createItem(int key, char* exeName){

    pidAndName* item = (pidAndName*)malloc(sizeof(pidAndName));
    item->key = key;
    item->exeName = (char*)malloc(strlen(exeName)+1);
    if(item->exeName == NULL){
      fprintf(stderr," Malloc failed in item \n");
    }
    item->key = key;
    strcpy(item->exeName, exeName);
    return item;
}


hashTable* create_Table(){

    hashTable* table = (hashTable*)malloc(sizeof(hashTable));
    if(table == NULL){
      fprintf(stderr, "Malloc failed in table ");
    }
    int i = 0;
    
    table->size = TABLE_SIZE;
    table->count =0;
    table->item = (pidAndName**)calloc(table->size, sizeof(pidAndName));
    for(; i< table->size; i++){
        table->item[i]= NULL;
    }
    return table;
}

void free_item(pidAndName* item){
    
    free(item->exeName);
    free(item);
}

void free_table(hashTable* table){
    int i=0;
    for(; i<table->size;i++){
        pidAndName* item = table->item[i];
        if(item != NULL){
            free_item(item);
        }
    }
    free(table->item);
    free(table); 
}

void insertItemInTable(hashTable* table,int key, char* exeName){

    int i = table->count;
    pidAndName* item = createItem(key, exeName);
    if(item == NULL){
        printf("l item est nul");
    }
    
    if(table->count == TABLE_SIZE){
       // printf("HashTable est pleine");
        exit(0);
    }
    
    table->item[i] = item;
    //printf("valeur de la cle: %d  valeur du mot: %s\n valeur de tableCount= %d",table->item[i]->key,table->item[i]->exeName, table->count);
    table->count = table->count+1;
}


char* searchItemInTable(hashTable* table,int pid){
    
    int i =0;
    for(;i<=table->count;i++){
        if(table->item[i]->key == pid){
            //printf("pid trouve: %d\n", pid);
            return table->item[i]->exeName;
        }
    }
}

hashTable* GetProcessList( )
{
  HANDLE hProcessSnap;
  HANDLE hProcess;
  PROCESSENTRY32 pe32;
  DWORD dwPriorityClass;
  hashTable* table = create_Table();

  // Take a snapshot of all processes in the system.
  hProcessSnap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
  if( hProcessSnap == INVALID_HANDLE_VALUE )
  {
    printError( TEXT("") );
    
  }

  // Set the size of the structure before using it.
  pe32.dwSize = sizeof( PROCESSENTRY32 );

  // Retrieve information about the first process,
  // and exit if unsuccessful
  if( !Process32First( hProcessSnap, &pe32 ) )
  {
   
    CloseHandle( hProcessSnap );          // clean the snapshot object
  
  }

  // Now walk the snapshot of processes, and
  // display information about each process in turn
  do
  {
    dwPriorityClass = 0;
    hProcess = OpenProcess( PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID );
    if( hProcess == NULL )
      printError( TEXT("") );
    else
    {
      dwPriorityClass = GetPriorityClass( hProcess );
      if( !dwPriorityClass )
        printError( TEXT("") );
      CloseHandle( hProcess );
    }
    insertItemInTable(table, pe32.th32ProcessID , pe32.szExeFile );
  } while( Process32Next( hProcessSnap, &pe32 ));
  CloseHandle( hProcessSnap );
  return table;
}

//code de la documentation
void printError( TCHAR* msg )
{
  DWORD eNum;
  TCHAR sysMsg[256];
  TCHAR* p;

  eNum = GetLastError( );
  FormatMessage( FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
         NULL, eNum,
         MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
         sysMsg, 256, NULL );

  // Trim the end of the line and terminate it with a null
  p = sysMsg;
  while( ( *p > 31 ) || ( *p == 9 ) )
    ++p;
  do { *p-- = 0; } while( ( p >= sysMsg ) &&
                          ( ( *p == '.' ) || ( *p < 33 ) ) );

  // Display the message
  //_tprintf( TEXT("\n  WARNING: %s failed with error %d (%s)"), msg, eNum, sysMsg );
}