#include<stdio.h>
#include<stdlib.h>
#include<cassert>
//�ṹ��ӣ�һ�����ڵ����洢���ݡ�ʵ����ʹ�õ��������ݽṹ�����Ǵ�ͷ˫��
//ѭ��������������ṹ��Ȼ�ṹ���ӣ�����ʹ�ô���ʵ���Ժ�ᷢ�ֽṹ������ܶ�����
typedef int LTDataType;
//�����һ���ڵ���Ϣ
typedef struct ListNode
{
	LTDataType _elem;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
typedef struct List
{
	ListNode *_head;//ͷָ��
}List;
void ListInit(List* plist);
void ListDestory(List* plist);
void ListPushBack(List* plist, LTDataType x);
void ListPushBack(List* plist);
void ListPushFront(List* plist, LTDataType x);
void ListPopFront(List* plist);
ListNode* ListFind(List* plist, LTDataType x);
// ��pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);
// ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);
void ListRemove(List* plist, LTDataType x);

void ListPrint(List* plist);