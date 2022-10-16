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
   return (void*)pq->heapArray[0].data;s
}



void heap_push(Heap* pq, void* data, int priority){
  int pos = pq->size;
	heapElem aux;
  int pAux;
	pq->heapArray[pos].data = data;
	pq->heapArray[pos].priority = priority;

	while( pos > 0 ){
      pAux = round(pos/2);
	   if(pq->heapArray[pos].priority > pq->heapArray[pAux].priority){
		aux = pq->heapArray[pos];
		pq->heapArray[pos] =  pq->heapArray[pAux];
      pq->heapArray[pAux] =  aux;
	   }
	   pos = pAux;
	}
	pq->size++;

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
   Heap* hp = (Heap*)malloc(sizeof(Heap));
   hp->capac=3;
   hp->size=0;
   
   hp->heapArray= (heapElem*)malloc(3*sizeof(heapElem));

   return hp;
  
}
