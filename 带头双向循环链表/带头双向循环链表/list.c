#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"
//动态分配一个节点
ListNode *createlistnode(LTDataType x)
{
	ListNode *newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_elem = x;
	newnode->_next = NULL;
	newnode->_prev = NULL;
	return newnode;
}
void ListInit(List* plist)
{
	assert(plist);
	ListNode *head = createlistnode(-1);
	plist->_head = head;
	head->_next = head;
	head->_prev = head;
}
//头结点需要单独释放
void ListDestory(List* plist)
{
	assert(plist);
	if (plist->_head == NULL)
	{
		return NULL;
	}
	ListNode*cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(plist->_head);
	plist->_head = NULL;
}
//尾插
void ListPushBack(List* plist, LTDataType x)
{
	/*assert(plist);
	ListNode*tail = plist->_head->_prev; 
	ListNode*newnode = createlistnode(x);
	tail->_next = newnode;
	newnode->_prev = tail;
	plist->_head->_prev = newnode;
	newnode->_next = plist->_head;*/
	ListInsert(plist, plist->_head, x);
}
//尾删
void ListPopBack(List* plist)
{
	assert(plist);
	if (plist->_head == NULL || plist->_head->_next == NULL)
	{
		return plist->_head;
	}
	ListNode* cur = plist->_head->_prev;
	ListNode* Prve = cur->_prev;
	plist->_head->_prev = Prve;
	Prve->_next = plist->_head;
	free(cur);
	cur = NULL;
}
//头插
void ListPushFront(List* plist, LTDataType x)
{
	assert(plist);
	ListNode*next = plist->_head->_next;
	ListNode*newnode = createlistnode(x);
	plist->_head->_next = newnode;
	newnode->_prev = plist->_head;
	newnode->_next = next;
	next->_prev = newnode;
}
//头删
void ListPopFront(List* plist)
{
	assert(plist);
	if (plist->_head == NULL || plist->_head->_next == NULL)
	{
		return plist->_head;
	}
	ListNode* cur = plist->_head->_next;
	ListNode* Next = cur->_next;
	plist->_head->_next = Next;
	Next->_prev = plist->_head;

}

ListNode* ListFind(List* plist, LTDataType x)
{
	assert(plist);
	if (plist->_head == NULL || plist->_head->_next == NULL)
	{
		return plist->_head;
	}
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		if (cur->_elem == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
}
// 在pos的前面进行插入
void ListInsert(List* plist,ListNode* pos, LTDataType x)
{
	assert(pos&&plist);
	ListNode*newnode = createlistnode(x);
	ListNode* Prve = pos->_prev;
	Prve->_next = newnode;
	newnode->_prev = Prve;
	newnode->_next = pos;
	pos->_prev = newnode;
}
// 删除pos位置的节点
void ListErase(List* plist, ListNode* pos)
{
	assert(pos&&plist);
	ListNode* Next = pos->_next;
	ListNode* Prve = pos->_prev;
	Prve->_next = Next;
	Next->_prev = Prve;
	free(pos);
	pos = NULL;
}
void ListPrint(List* plist)
{
	assert(plist);
	if (plist->_head == NULL)
	{
		return NULL;
	}
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		printf("%d<->", cur->_elem);
		cur = cur->_next;
	}
	printf("\n");
}
void test()
{
	List plist;//定义链表变量
	ListInit(&plist);
	ListPushBack(&plist, 2);
	ListPushBack(&plist, 1);
	ListPrint(&plist);
	ListPushFront(&plist, 3);
	ListPrint(&plist);
	ListFind(&plist, 2);
	ListPopFront(&plist);
	ListPrint(&plist);
	ListPopBack(&plist);
	ListPrint(&plist);
}
int main()
{
	test();
	system("pause");
	return 0;
}