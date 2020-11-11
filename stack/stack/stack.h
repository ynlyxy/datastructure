#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
//静态栈结构
//typedef int STDataType;
//#define N 10
//typedef struct stack
//{
//	STDataType _a[N];
//	int _top; // 栈顶
//}Stack;


// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;       // 栈顶
	int _capacity;  // 容量 
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);
void TestStack();