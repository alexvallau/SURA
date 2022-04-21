#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include "hashmap.h"








pidAndName* createItem(int key, char* exeName){

    pidAndName* item = (pidAndName*)malloc(sizeof(pidAndName));
    item->key = key;
    item->exeName = (char*)malloc(strlen(exeName)+1);
    item->key = key;
    strcpy(item->exeName, exeName);
    return item;
}


hashTable* create_Table(){

    hashTable* table = (hashTable*)malloc(sizeof(hashTable));
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
    free(table); 
}

void insertItemInTable(hashTable* table,int key, char* exeName){

    int i = table->count;
    pidAndName* item = createItem(key, exeName);
    if(item == NULL){
        printf("l item est nul");
    }
    
    if(table->count == TABLE_SIZE){
        printf("HashTable est pleine");
        exit(0);
    }
    
    table->item[i] = item;
    printf("valeur de la cle: %d  valeur du mot: %s\n valeur de tableCount= %d",table->item[i]->key,table->item[i]->exeName, table->count);
    table->count = table->count+1;
}


char* searchItemInTable(hashTable* table,int pid){
    
    int i =0;
    for(;i<=table->count;i++){
        if(table->item[i]->key == pid){
            printf("pid trouve: %d\n", pid);
            return table->item[i]->exeName;
        }
    }
}

/*
int main(int argc, char **argv){
    //printf("%d\n", hash("chrome.exe"));

    hashTable* table = create_Table();

    insertItemInTable(table,15, "Premier element");
    insertItemInTable(table, 1688,"Deuxieme élement");
    insertItemInTable(table, 150, "Chrome.exe");
    
    char* el1= searchItemInTable(table, 15);
    char* el2= searchItemInTable(table, 1688);
    char* el3= searchItemInTable(table, 150);
    
    printf("el1==%s\n el2==%s\n el3==%s",el1,el2,el3);
    free_table(table);


    return 0;
}
*/
