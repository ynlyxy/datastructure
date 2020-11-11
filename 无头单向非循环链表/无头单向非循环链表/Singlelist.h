#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>
typedef int Datatype;
//����ڵ�
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
// ɾ��ָ��������, �ָ�����˳�򲻱䣬С����ǰ��
SinglelistNode* Singlelistpartition(Singlelist *sl, Datatype x);
//����һ���ο�������ͬ��������ͬ����һ����������
SinglelistNode* SinglelistdeleteDuplication(Singlelist *sl);
SinglelistNode* Singlelistreverse(Singlelist*sl);