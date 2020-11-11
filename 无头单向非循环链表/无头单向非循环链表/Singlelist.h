#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>
typedef int Datatype;
//链表节点
typedef struct SinglelistNode
{
	Datatype _data;
	struct SinglelistNode* _next;
}SinglelistNode;
typedef struct Singlist
{
	SinglelistNode* _head;
}Singlelist;
void SinglelistInit(Singlelist *sl);
void SinglelistDestory(Singlelist *sl);
SinglelistNode *createnode(Datatype x);
void Singlelistprintf(Singlelist *sl);
void Singlelistpushbck(Singlelist *sl, Datatype x);
void Singlelistpopback(Singlelist *sl);
void Singlelistpushfront(Singlelist *sl, Datatype x);
void Singlelistpopfront(Singlelist *sl);
void SinglelistInsertAfter(SinglelistNode *pos, Datatype x);
void SinglelistEraseAfter(SinglelistNode *pos);
void Singlelistremove(Singlelist *sl, Datatype x);
// 删除指定的数据, 分割链表，顺序不变，小的在前。
SinglelistNode* Singlelistpartition(Singlelist *sl, Datatype x);
//给定一个参考数除相同的数，相同的数一个都不留。
SinglelistNode* SinglelistdeleteDuplication(Singlelist *sl);
SinglelistNode* Singlelistreverse(Singlelist*sl);