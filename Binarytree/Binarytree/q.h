#include<stdio.h>
#include<assert.h>
#include"Binarytree.h"
typedef BTNode*  QUDataType;
//对节点的结构定义
typedef struct  QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;
//对队列的结构定义
typedef struct Queue
{
	QueueNode* _front; // 队头
	QueueNode* _rear;  // 队尾
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