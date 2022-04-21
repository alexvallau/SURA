

#ifndef LIST_H
#define LIST_H

#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>






typedef struct pidAndName{
    int key;
    char * exeName;

}pidAndName;

typedef struct hashTable{
    pidAndName** item;
    int size;
    int count; 
    
}hashTable;

hashTable* GetProcessList( );
void printError( TCHAR* msg );
#define TABLE_SIZE 100000
pidAndName* createItem(int key, char* exeName);
hashTable* create_Table();
void free_item(pidAndName* item);
void free_table(hashTable* table);
void insertItemInTable(hashTable* table,int key, char* exeName);
char* searchItemInTable(hashTable* table,int pid);







#endif