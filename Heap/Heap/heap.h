#ifndef _HEAP_H_
#define _HEAP_H_

#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<assert.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;
//用数组创造一个堆
void HeapInit(Heap* hp, HPDataType* a, int n);
void HeapemptyInit(Heap *hp);
void shiftdown(HPDataType *a, int n,int root);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap *hp);
// 堆排序
void HeapSort(int* a, int n);
#endif _HEAP_H_