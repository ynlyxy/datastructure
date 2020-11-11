#define _CRT_SECURE_NO_WARNINGS 1
//无头单向非循环链表：结构简单，一般不会单独用来存数据。实际中更多是作为其他数据结构的子结
//构，如哈希桶、图的邻接表等等。
#include"Singlelist.h"
void SinglistInit(Singlelist *sl)
{
	assert(sl);
	sl->_head = NULL;
}
//释放每一个节点空间，最后释放头结点
void SinglelistDestory(Singlelist *sl)
{
	assert(sl);
	SinglelistNode* cur = sl->_head;
	while (cur)
	{
		SinglelistNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	sl->_head = NULL;
}
//动态分配一个节点
SinglelistNode *createnode(Datatype x)
{
	SinglelistNode *newnode = (SinglelistNode*)malloc(sizeof(SinglelistNode));
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}
void Singlelistprintf(Singlelist *sl)
{
	assert(sl);
	SinglelistNode *cur = sl->_head;
	while (cur)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
//尾插
void Singlelistpushbck(Singlelist *sl, Datatype x)
{
	assert(sl);
	if (sl->_head == NULL)
	{
		/*sl->_head = (SinglelistNode*)malloc(sizeof(SinglelistNode));
		sl->_head->_data = x;
		sl->_head->next = NULL;*/
		sl->_head = createnode(x);
	}
	else
	{
		SinglelistNode* cur = sl->_head;
		while (cur->_next)
		{
			cur = cur->_next;
		}
		/*sl->_head = (SinglelistNode*)malloc(sizeof(SinglelistNode));
		cur->next->_data = x;
		cur->next->next = NULL;*/
		cur->_next = createnode(x);
	}
}
//尾删，定义两个指针，prve 指向被删除节点前一个位置，节点删除后，prve执行NULL
void Singlelistpopback(Singlelist *sl)
{
	assert(sl);
	SinglelistNode *cur = sl->_head;
	SinglelistNode *prev = NULL;
	if (cur == NULL)
		return;
	while (cur->_next)
	{
		prev = cur;
		cur = cur->_next;
	}
	free(cur);
	cur = NULL;
	//判断删除的是否是头结点，若是要重新给头指针赋值
	if (prev == NULL)
	{
		sl->_head = NULL;
	}
	else
		prev->_next = NULL;
}
//头插
void Singlelistpushfront(Singlelist *sl, Datatype x)
{
	assert(sl);
	SinglelistNode *cur = sl->_head;
	SinglelistNode* newNode = createnode(x);
	newNode->_next = cur;
	sl->_head = newNode;//更新头结点
}
//头删
void Singlelistpopfront(Singlelist *sl)
{
	assert(sl);
	SinglelistNode *cur = sl->_head;
	SinglelistNode *next = sl->_head->_next;
	if (sl->_head == NULL)
	{
		return;
	}
	free(cur);
	cur = NULL;
	sl->_head = next;
}
//在pos位后插入元素
void SinglelistInsertAfter(SinglelistNode *pos, Datatype x)
{
	assert(pos);
	SinglelistNode *newnode = createnode(x);
	SinglelistNode *next = pos->_next;
	pos->_next = newnode;
	newnode->_next = next;

}
//在pos位后删除元素
void SinglelistEraseAfter(SinglelistNode *pos)
{
	assert(pos);
	SinglelistNode* cur = pos->_next;
	SinglelistNode* next = pos->_next->_next;
	if (cur == NULL)
		return;
	else
	{
		free(cur);
		cur = NULL;
		pos->_next = next;
	}
}
//删除指定的一个元素
void Singlelistremove(Singlelist *sl, Datatype x)
{
	assert(sl);
	SinglelistNode *cur = sl->_head;
	SinglelistNode *prev = NULL;
	while (cur)
	{
		if (cur->_data == x)
		{
			//判断是否删除的是head所指的节点
			if (prev == NULL)
			{
				sl->_head = cur->_next;
			}
			else
			{
				prev->_next = cur->_next;
			}
			free(cur);
			cur = NULL;
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}
}
SinglelistNode* Singlelistpartition(Singlelist *sl, Datatype x)
{
	//不带头结点的链表
	//SinglelistNode *gH, *gT, *lH, *lT,*cur;
	//gH = gT = lH = lT = NULL;
	//if (sl->_head == NULL)
	//{
	//	return;
	//}
	//cur = sl->_head;
	//while (cur)
	//{
	//	if (cur->_data < x)
	//	{
	//		if (lH == NULL)
	//		{
	//			lH = lT = cur;
	//		}
	//		else
	//		{
	//			lT->_next = cur;
	//			lT = lT->_next;
	//		}
	//	}
	//	else
	//	{
	//		if (gH == NULL)
	//		{
	//			gH = gT = cur;
	//		}
	//		else
	//		{
	//			gT->_next = cur;
	//			gT = gT->_next;
	//		}
	//	}
	//	cur = cur->_next;
	//}
	////断链
	//if (gT)
	//{
	//	gT->_next = NULL;
	//}
	//if (lH != NULL)
	//{
	//	lT->_next = gH;
	//	return lH;
	//}
	//else
	//	return gH;
	//创建带头节点的链表
	SinglelistNode *gH, *gT, *lH, *lT, *Cur;
	gT = gH = (SinglelistNode*)malloc(sizeof(SinglelistNode));
	lT = lH = (SinglelistNode*)malloc(sizeof(SinglelistNode));
	if (sl->_head == NULL)
	{
		return sl->_head;
	}
	Cur = sl->_head;
	while (Cur)
	{
		if (Cur->_data < x)
		{
			lT->_next = Cur;
			lT = lT->_next;
		}
		else
		{
			gT->_next = Cur;
			gT = gT->_next;
		}
		Cur = Cur->_next;
	}
	//断链
	gT->_next = NULL;
	lT->_next = gH->_next;
	Cur = lH->_next;
	free(gH);
	free(lH);
	return Cur;
}
//相同元素相邻，找到后全部删除
SinglelistNode* SinglelistdeleteDuplication(Singlelist *sl)
{
	SinglelistNode* cur, *prve, *next ,*tmp;
	if (sl->_head == NULL || sl->_head->_next == NULL)
	{
		return sl->_head;
	}
	prve = NULL;
	cur = sl->_head;
	next = sl->_head->_next;
	while (next)
	{
		if (cur->_data != next->_data)
		{
			prve = cur;
			cur = next;
			next = next->_next;
		}
		else
		{
			//找到第一个相同的节点
			while (next && cur->_data == next->_data)
			{
				if (next)//判断是否还有节点，否则会发生错误
				{
					next = next->_next;
				}
				cur->_next = next;
			}
		}
	}
	return sl->_head;
}
SinglelistNode* Singlelistreverse(Singlelist* sl)
{
	assert(sl);
	SinglelistNode* prve, *next;
	if (sl->_head == NULL || sl->_head->_next == NULL)
	{
		return sl->_head;
	}
	prve = NULL;
	next = NULL;
	while (sl->_head!=NULL)
	{
		next = sl->_head->_next;
		sl->_head->_next = prve;
		prve = sl->_head;
		sl->_head = next;
	}
	return prve;
}
void test()
{
	Singlelist sl;//定义链表变量
	SinglistInit(&sl);
	Singlelistpushbck(&sl, 3);
	Singlelistpushbck(&sl, 1);
	Singlelistpushbck(&sl, 1);
	//SinglelistInsertAfter(sl._head->_next, 5);
	Singlelistprintf(&sl);
	//Singlelistreverse(&sl);
	//Singlelistprintf(&sl);
	//Singlelistpopback(&sl);
	//SinglelistEraseAfter(sl._head->_next);
	//Singlelistprintf(&sl);
	//Singlelistremove(&sl, 6);
	//Singlelistprintf(&sl);
	/*Singlelistpartition(&sl, 4);
	Singlelistprintf(&sl);*/
	SinglelistdeleteDuplication(&sl);
	Singlelistprintf(&sl);
}
int main()
{
	test();
	system("pause");
	return 0;
}