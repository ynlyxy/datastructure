#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
//˳���ʵ��ջ
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;//��ʼ��Ϊ��ջ
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
//��ջ��˳����β��
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	int newc;
	//�ж�����
	if (ps->_capacity == ps->_top)
	{
		newc = ps->_capacity == 0 ? 10 : 2 * ps->_capacity;
		//ps->_a = (STDataType*)malloc(sizeof(STDataType));
		ps->_a = (STDataType*)realloc(ps->_a, newc*(sizeof(STDataType)));
		ps->_capacity = newc;
	}
	//����
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
//�пա��ǿշ���1
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
//�Ƚ����
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
	//StackDestory(&ps����
}
int main()
{
	TestStack();
	system("pause");
	return 0;
}