#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
  ArrayList* lista = (ArrayList*) malloc(sizeof(ArrayList));
  lista -> capacity = 2;
  lista -> size = 0;
  lista -> data = NULL;
  lista -> data=  realloc(lista -> data,sizeof(ArrayList));
  
    return lista;
}

void append(ArrayList * l, void * data){
  if(l-> capacity == l->size){
    l -> data =realloc(l-> data, ((l->capacity)*2)*(sizeof(void*)));
    l->data[l->size]= data;
    l-> size ++;
    l->capacity *=2;
   
  }
  else{
    l->data[l->size]= data;
    l-> size ++;
  }
}

void push(ArrayList * l, void * data, int i){
  if(i >= l->size) return;
    
   if(l-> capacity == l->size){
     l->capacity = l->capacity *2;
     l -> data =(void**)realloc(l-> data, l->capacity*sizeof(void*));
     l->data[l->size]= data;
   }
    for(int j =(l->size); j>i ; j--)
      {
        l->data[j] = l->data[j-1];
      }
    l->data[i]= data;
    l-> size ++;
}

void* pop(ArrayList * l, int i){
  if(i >= l->size) return NULL;
  if(i<0){
    get(l,i);
    l->data[l->size] = NULL;
  }else{
    for(int j = i+1; j<l->size; j++)
      {
        l-> data[j-1]= l-> data[j];
      }
  }
  if (l-> size ==0 ) return l-> data[i];
  void* data = l->data[i];
  l-> size--;
  return data;
}

void* get(ArrayList * l, int i){
  int j;
  if(i >= l->size) return NULL;
  
  if(i<0){
    for( j = l->size; j<l->size+1 ;j--){
      if(l->data[j]==l->data[l->size+i]) return l->data[j];
    }
    
  }
  if(i>0){
    return l-> data[i];
  }
  return l->data[0];
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
  l-> capacity =2;
  l-> size  =0;
  l -> data=  realloc(l -> data,sizeof(ArrayList));
    
}
