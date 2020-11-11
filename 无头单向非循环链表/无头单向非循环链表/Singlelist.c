#define _CRT_SECURE_NO_WARNINGS 1
//��ͷ�����ѭ�������ṹ�򵥣�һ�㲻�ᵥ�����������ݡ�ʵ���и�������Ϊ�������ݽṹ���ӽ�
//�������ϣͰ��ͼ���ڽӱ�ȵȡ�
#include"Singlelist.h"
void SinglistInit(Singlelist *sl)
{
	assert(sl);
	sl->_head = NULL;
}
//�ͷ�ÿһ���ڵ�ռ䣬����ͷ�ͷ���
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
//��̬����һ���ڵ�
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
//β��
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
//βɾ����������ָ�룬prve ָ��ɾ���ڵ�ǰһ��λ�ã��ڵ�ɾ����prveִ��NULL
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
	//�ж�ɾ�����Ƿ���ͷ��㣬����Ҫ���¸�ͷָ�븳ֵ
	if (prev == NULL)
	{
		sl->_head = NULL;
	}
	else
		prev->_next = NULL;
}
//ͷ��
void Singlelistpushfront(Singlelist *sl, Datatype x)
{
	assert(sl);
	SinglelistNode *cur = sl->_head;
	SinglelistNode* newNode = createnode(x);
	newNode->_next = cur;
	sl->_head = newNode;//����ͷ���
}
//ͷɾ
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
//��posλ�����Ԫ��
void SinglelistInsertAfter(SinglelistNode *pos, Datatype x)
{
	assert(pos);
	SinglelistNode *newnode = createnode(x);
	SinglelistNode *next = pos->_next;
	pos->_next = newnode;
	newnode->_next = next;

}
//��posλ��ɾ��Ԫ��
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
//ɾ��ָ����һ��Ԫ��
void Singlelistremove(Singlelist *sl, Datatype x)
{
	assert(sl);
	SinglelistNode *cur = sl->_head;
	SinglelistNode *prev = NULL;
	while (cur)
	{
		if (cur->_data == x)
		{
			//�ж��Ƿ�ɾ������head��ָ�Ľڵ�
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
	//����ͷ��������
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
	////����
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
	//������ͷ�ڵ������
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
	//����
	gT->_next = NULL;
	lT->_next = gH->_next;
	Cur = lH->_next;
	free(gH);
	free(lH);
	return Cur;
}
//��ͬԪ�����ڣ��ҵ���ȫ��ɾ��
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
			//�ҵ���һ����ͬ�Ľڵ�
			while (next && cur->_data == next->_data)
			{
				if (next)//�ж��Ƿ��нڵ㣬����ᷢ������
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
	Singlelist sl;//�����������
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