#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"
//�����鴴��һ����
void HeapInit(Heap* hp, HPDataType* a, int n)
{
	assert(hp&&a);
	int i = 0;
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	//��Ҫ������a�а�Ԫ���ù���
	for (i = 0; i < n; ++i)
	{
		hp->_a[i] = a[i];
	}
	//�����һ����������
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		shiftdown(hp->_a, n, i);
	}
	hp->_capacity = n;
	hp->_size = 0; 
}
//��ʼ��һ���ն�
void HeapemptyInit(Heap *hp)
{
	assert(hp);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}
void Swap(HPDataType *pa, HPDataType *pb)
{
	HPDataType *tmp;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
//���µ���(��ѣ�
void shiftdown(HPDataType *a, int n, int root)
{
	//aΪ�����׵�ַ��nΪ�ڵ������rootΪ��ǰҪ����ĸ��ڵ�
	int parent = root;
	int child = (2 * parent) + 1;
	while (child < n)
	{
		//������������ѡȡֵ���
		if (child + 1 < n&&a[child] < a[child + 1])
		{
			++child;
		}
		//���ӽڵ��ֵ���ڸ��׽ڵ㣬����
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = (2 * parent) + 1;
		}
		else
			//�Դ�Ϊ���ڵ�������Ѿ���һ���ѽṹ����
			break;
	}
}
//void shiftdown1(Heap* hp, int n)//n����Ҫ�����ڵ�
//{
//	int parent = n;
//	int child;
//	while (parent*2+1<hp->_size)//��������ӣ�ѭ������
//	{
//		//���û���Һ��ӣ���ֱ�ӵ�������
//		if (hp->_a[(parent * 2) + 2] >= hp->_size)
//		{
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			//�����(���ڵ����ǲ�С���亢�ӽڵ��ֵ��
//			if (hp->_a[parent * 2 + 1] > hp->_a[parent * 2 + 2])
//			{
//				child = parent * 2 + 1;
//			}
//			else
//			{
//				child = parent * 2 + 2;
//			}
//		}
//		//�жϸ��ڵ�����Һ��ӵĴ�С
//		if (hp->_a[parent] < hp->_a[child])
//		{
//			int tmp = hp->_a[parent];
//			hp->_a[parent] = hp->_a[child];
//			hp->_a[child] = tmp;
//			parent = child;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}
//���ϵ���������һ���µ�Ԫ�أ����µ�Ԫ�ؿ�ʼ�����ϵ�����ֱ���Ƕѽṹ��
void HeapUp(HPDataType* a, int n, int child)
{
	assert(a); 
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[parent], &a[child]);
			child = parent;//childһֱ��������Ԫ�ص�ֵ��parentһֱ����child �ĸ��ڵ�
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}
void HeapPush(Heap* hp, HPDataType x)
{
	//����ڵ�����������λ���ϣ�ʹ�����ϵ���
	assert(hp);
	int newc;
	if (hp->_capacity == hp->_size)
	{
		newc = hp->_capacity == 0 ? 10 : 2 * hp->_capacity;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*newc);
		hp->_capacity = newc;
	}
	hp->_a[hp->_size++] = x;
	HeapUp(hp->_a, hp->_size, hp->_size - 1);// hp->_size - 1���һ��Ԫ�ص�λ��
}
void HeapPop(Heap* hp)
{
	assert(hp && hp->_size);
	if (HeapEmpty(hp) == 1)
	{
		Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
		--hp->_size;
	}
	//�Ӹ��ڵ㿪ʼ����
	shiftdown(hp->_a, hp->_size, 0);
}
HPDataType HeapTop(Heap* hp)
{
	assert(hp&&hp->_size);
	{
		return hp->_a[0];
	}
}
int HeapSize(Heap* hp)
{
	assert(hp&&hp->_size);
	//assert(hp);
	return hp->_size;
}
int HeapEmpty(Heap *hp)
{
	assert(hp);
	//Ϊ�շ���0
	return hp->_capacity == 0 ? 0 : 1;
}
// ������
//ʱ�临�Ӷȣ�O(N*logN+N)-->O(N)
void HeapSort(int* a, int n)//��Ե�����һ���ַ�����������ʱ������Ҫ����һ���ѽṹ
{
	int i = 0;
	int end = n - 1;
	//����(�������е�Ԫ�ذ��ѽṹ������
	for (i = (end-2)/2; i >=0; --i)
	{
		shiftdown(a, n, i);
	}
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		--end;
		shiftdown(a, end, 0);
	}
}
void HeapSort1(Heap* hp)//�Ѿ���һ���ѽṹ��Ȼ���������
{
	int n = hp->_size;
	while (hp->_size > 1)
	{
		HeapPop(hp);
	}
	hp->_size = n;
}
void Heapprintf(Heap* hp)
{
	assert(hp);
	int i = 0;
	for (i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
//���Զ�
void heaptest()
{
	Heap hp;
	HeapemptyInit(&hp);
	HeapPush(&hp, 1);
	HeapPush(&hp, 2);
	HeapPush(&hp, 3);
	HeapPush(&hp, 4);
	HeapPush(&hp, 5);
	HeapPush(&hp, 7);
	Heapprintf(&hp);
	HeapSort1(&hp);
	Heapprintf(&hp);
	HeapPop(&hp);
	Heapprintf(&hp);
}
void heapsorttest()
{
	int i = 0;
	int arr[] = { 1, 5, 3, 8, 7, 6 };
	HeapSort(arr, (sizeof(arr) / sizeof(arr[0])));
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	heaptest(); 
	heapsorttest();
	system("pause");
	return 0;
}