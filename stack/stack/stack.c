#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
//顺序表实现栈
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;//初始化为空栈
}
void StackDestory(Stack* ps)
{
	assert(ps);
	if (ps->_a != NULL)
	{
		free(ps->_a);
	}
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}
//入栈，顺序表的尾插
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	int newc;
	//判断容量
	if (ps->_capacity == ps->_top)
	{
		newc = ps->_capacity == 0 ? 10 : 2 * ps->_capacity;
		//ps->_a = (STDataType*)malloc(sizeof(STDataType));
		ps->_a = (STDataType*)realloc(ps->_a, newc*(sizeof(STDataType)));
		ps->_capacity = newc;
	}
	//插入
	ps->_a[ps->_top++] = x;
}
void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->_top)
	{
		--ps->_top;
	}
}
STDataType StackTop(Stack* ps)
{
	assert(ps && ps->_a != NULL);
	return ps->_a[ps->_top - 1];
}
//判空。是空返回1
STDataType StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 1:0;
}
STDataType StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
//先进后出
void Stackprintf(Stack *ps)
{
	assert(ps);
	while (StackEmpty(ps)!=1)
	{
		printf("%d<-", StackTop(ps));
		StackPop(ps);
	}
	printf("\n");
}


void TestStack()
{
	Stack ps;
	/*StackInit(&ps);
	StackPush(&ps, 5);
	StackPush(&ps, 4);
	StackPush(&ps, 3);
	StackPush(&ps, 2);
	StackPop(&ps);
	Stackprintf(&ps);
	StackSize(&ps);*/
	//StackDestory(&ps）；
}
int main()
{
	TestStack();
	system("pause");
	return 0;
}