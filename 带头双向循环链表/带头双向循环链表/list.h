#include<stdio.h>
#include<stdlib.h>
#include<cassert>
//结构最复杂，一般用在单独存储数据。实际中使用的链表数据结构，都是带头双向
//循环链表。另外这个结构虽然结构复杂，但是使用代码实现以后会发现结构会带来很多优势
typedef int LTDataType;
//链表的一个节点信息
typedef struct ListNode
{
	LTDataType _elem;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
typedef struct List
{
	ListNode *_head;//头指针
}List;
void ListInit(List* plist);
void ListDestory(List* plist);
void ListPushBack(List* plist, LTDataType x);
void ListPushBack(List* plist);
void ListPushFront(List* plist, LTDataType x);
void ListPopFront(List* plist);
ListNode* ListFind(List* plist, LTDataType x);
// 在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);
// 删除pos位置的节点
void ListErase(ListNode* pos);
void ListRemove(List* plist, LTDataType x);

void ListPrint(List* plist);