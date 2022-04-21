#ifndef HASHMAP_H
#define HASMPAH_H


#define TABLE_SIZE 100000

typedef struct pidAndName{
    int key;
    char * exeName;

}pidAndName;

typedef struct hashTable{
    pidAndName** item;
    int size;
    int count; 
    
}hashTable;


pidAndName* createItem(int key, char* exeName);
hashTable* create_Table();
void free_item(pidAndName* item);
void free_table(hashTable* table);
void insertItemInTable(hashTable* table,int key, char* exeName);
char* searchItemInTable(hashTable* table,int pid);




#endif