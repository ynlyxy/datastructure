#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
//��̬ջ�ṹ
//typedef int STDataType;
//#define N 10
//typedef struct stack
//{
//	STDataType _a[N];
//	int _top; // ջ��
//}Stack;


// ֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;       // ջ��
	int _capacity;  // ���� 
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);
void TestStack();