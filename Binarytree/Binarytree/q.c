#define _CRT_SECURE_NO_WARNINGS 1
#include"q.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = pq->_rear = NULL;
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	if (pq->_front == NULL)
	{
		return pq->_front;
	}
	QueueNode* cur = pq->_front;
	while (cur)
	{
		QueueNode*Next = cur->_next;
		free(cur);
		cur = Next;
	}
	pq->_front = pq->_rear = NULL;
}
QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}
void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);
	//判断是否是第一个插入的元素，头是空的
	if (pq->_front == NULL)
	{
		pq->_front = pq->_rear = BuyQueueNode(x);
	}
	else
	{
		pq->_rear->_next = BuyQueueNode(x);
		//更新链表尾部指针的位置
		pq->_rear = pq->_rear->_next;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	if (pq->_front)
	{
		QueueNode* Next = pq->_front->_next;
		free(pq->_front);
		pq->_front = Next;
		//删除的是最后一个元素
		if (pq->_front == NULL)
		{
			pq->_rear = NULL;
		}
	}
	else
		pq->_front = pq->_front->_next;
}
QUDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->_front->_data;
}
QUDataType QueueBack(Queue* pq)
{
	assert(pq);
	return pq->_rear->_data;
}
//为空返回1
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front == NULL;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	int count = 0;
	QueueNode* cur;
	cur = pq->_front;
	while (cur)
	{
		++count;
		cur = cur->_next;
	}
	return count;
}