#define _CRT_SECURE_NO_WARNINGS 1
#include"test_1.h"
void SeqlistInit(Seqlist* psl)
{
	assert(psl);
	psl->arr = NULL;
	psl->_capacity = 0;
	psl->_size = 0;
}
void SeqlistDestroy(Seqlist* psl)
{
	assert(psl);
	if (psl->arr)
	{
		free(psl->arr);
		psl->arr = NULL;
		psl->_size = 0;
		psl->_capacity = 0;
	}
}
void CheckCapacity(Seqlist* psl)
{
	assert(psl);
	if (psl->_capacity == psl->_size)
	{
		int newcapacity = (psl->_capacity == 0 ? 5 : 2 * psl->_capacity);//��������
		psl->arr = (SLdatatype*)realloc(psl->arr, newcapacity*sizeof(SLdatatype));//����ռ�
		assert(psl->arr);
		psl->_capacity = newcapacity;
	}
}
//β��
void Seqlistpushback(Seqlist* psl, SLdatatype x)
{
	assert(psl);
	CheckCapacity(psl);
	psl->arr[psl->_size] = x;
	++psl->_size;
}
//ͷ�壨������Ԫ������ƶ����ڳ��ʼ��λ�ã�
void SeqListPushFront(Seqlist* psl, SLdatatype x)
{
	int i = 0;
	assert(psl);
	CheckCapacity(psl);
	for (i = psl->_size; i >= 0; --i)
	{
		psl->arr[i+1] = psl->arr[i];
	}
	psl->arr[0] = x;
	++psl->_size;
}
//βɾ��������Ч������һ��
void Seqlistpopback(Seqlist* psl)
{
	assert(psl);
	if (psl->_size == 0)
	{
		return;
	}
	psl->_size--;
}
//ͷɾ���ѵ�һ��Ԫ�ظ����ǣ�����Ԫ��������ǰ�ߣ�
void SeqListPopFront(Seqlist* psl)
{
	assert(psl);
	int i = 0;
	if (psl->_size == 0)
	{
		return;
	}
	for (i = 0; i < psl->_size; ++i)
	{
		psl->arr[i] = psl->arr[i + 1];
	}
	psl->_size--;
}
void Seqlistprintf(Seqlist* psl)
{
	assert(psl);
	int i = 0;
	for (i = 0; i < psl->_size; i++)
	{
		printf("%d->", psl->arr[i]);
	}
	printf("\n");
}
//��posλ����Ԫ�أ���ԭ�е�posλ�ü�֮��λ�õ�Ԫ������ƶ����ڳ�pos��λ�ã�
void SeqListInsert(Seqlist* psl, size_t pos, SLdatatype x)
{
	assert(psl);
	if (psl->_size >= psl->_capacity)
	{
		return;
	}
	int end = psl->_size;
	while (end > pos)
	{
		psl->arr[end] = psl->arr[end - 1];
		--end;
	}
	psl->arr[pos] = x;
	++(psl->_size);
}
//���ң�����Ԫ�����ݲ��ң�
void SeqListFind(Seqlist* psl, SLdatatype x)
{
	assert(psl);
	if (psl->_size >= psl->_capacity)
	{
		return;
	}
	int i = 0;
	for (i = 0; i < psl->_size; ++i)
	{
		if (psl->arr[i] == x)
		{
			printf("�ҵ��ˣ�Ԫ��λ���ڵ�%d", i);
			break;
		}
		else
			printf("�޴�Ԫ��");
	}
	printf("\n");
}
//ɾ������λ�õĽڵ㣨��posλ��֮���Ԫ����ǰ�ƶ�������posλ�ã�
void SeqListErase(Seqlist* psl, size_t pos)
{
	assert(psl);
	if (psl->_size >= psl->_capacity)
	{
		return;
	}
	int i = pos;
	for (i = pos; i < psl->_size; ++i)
	{
		psl->arr[i] = psl->arr[i + 1];
	}
	--(psl->_size);
}
void test()
{
	Seqlist psl;//����˳������
	SeqlistInit(&psl);
	SeqListPushFront(&psl, 3);
	SeqListPushFront(&psl, 4);
	SeqListPushFront(&psl, 5);
	Seqlistprintf(&psl);
	//Seqlistpushback(&psl, 5);
	//Seqlistpushback(&psl, 6);
	//Seqlistpushback(&psl, 7);
	//Seqlistprintf(&psl);
	//Seqlistpopback(&psl);
	Seqlistpopback(&psl);
	Seqlistprintf(&psl);
	SeqListPopFront(&psl);
	Seqlistprintf(&psl);
	SeqListInsert(&psl, 2, 7);
	Seqlistprintf(&psl); 
	SeqListFind(&psl, 4);
	SeqListErase(&psl, 3);
	Seqlistprintf(&psl);


}
int main()
{
	test();
	system("pause");
	return 0;
}