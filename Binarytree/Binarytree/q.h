#include<stdio.h>
#include<assert.h>
#include"Binarytree.h"
typedef BTNode*  QUDataType;
//�Խڵ�Ľṹ����
typedef struct  QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;
//�Զ��еĽṹ����
typedef struct Queue
{
	QueueNode* _front; // ��ͷ
	QueueNode* _rear;  // ��β
}Queue;
void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
QueueNode* BuyQueueNode(QUDataType x);
void QueuePush(Queue* pq, QUDataType x);
void QueuePop(Queue* pq);
QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);