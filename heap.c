#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
   if(pq->size == 0) return NULL;
   return (void*)pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  if(pq->size == pq->capac){
      pq->capac = (pq->capac*2)+1;
      pq->heapArray = (heapElem*)realloc(pq->heapArray,sizeof(heapElem)*pq->capac);
   }

   pq->heapArray[pq->size].data = data;
   pq->heapArray[pq->size].priority = priority;

   int inf = pq->size;
   int sup = (pq->size - 1)/2;

   heapElem* elemAux = (heapElem*)malloc(sizeof(heapElem));

   while(inf > 0){
      if(pq->heapArray[inf].priority > pq->heapArray[sup].priority){
         *elemAux = pq->heapArray[sup];
         pq->heapArray[sup] = pq->heapArray[inf];
         pq->heapArray[inf] = *elemAux;
      }

      inf = sup;
      sup = (inf - 1)/2;
   }

   pq->size++;
}


void heap_pop(Heap* pq){
  heapElem* aux = (heapElem*)malloc(sizeof(heapElem)); 
  heapElem* mayor = (heapElem*)malloc(sizeof(heapElem));
  aux = pq->heapArray[0];

  
  aux = pq->heapArray[pq->size];
  pq->heapArray[pq->size] = pq->heapArray[0];
  pq->heapArray[0] = aux;

  pq->heapArray[pq->size].data = NULL;
  pq->heapArray[pq->size].priority = 0;
  pq->size--;

  mayor.data = pq->heapArray[0].data;
  mayor.priority = pq->heapArray[0].priority;
  int i;
  while(i != pq->capac){

    if (mayor.priority <= pq->heapArray[i].priority){
      aux = mayor;
      mayor = pq->heapArray[i];
      pq->heapArray[i] = aux;
    }

    i++;
  }
  }

Heap* createHeap(){
   Heap* hp = (Heap*)malloc(sizeof(Heap));
   hp->capac=3;
   hp->size=0;
   
   hp->heapArray= (heapElem*)malloc(3*sizeof(heapElem));

   return hp;
  
}
