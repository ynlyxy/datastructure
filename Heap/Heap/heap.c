#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"
//用数组创造一个堆
void HeapInit(Heap* hp, HPDataType* a, int n)
{
	assert(hp&&a);
	int i = 0;
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	//先要从数组a中把元素拿过来
	for (i = 0; i < n; ++i)
	{
		hp->_a[i] = a[i];
	}
	//从最后一颗子树调整
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		shiftdown(hp->_a, n, i);
	}
	hp->_capacity = n;
	hp->_size = 0; 
}
//初始化一个空堆
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
//向下调整(大堆）
void shiftdown(HPDataType *a, int n, int root)
{
	//a为数组首地址，n为节点个数，root为当前要处理的根节点
	int parent = root;
	int child = (2 * parent) + 1;
	while (child < n)
	{
		//在左右子树上选取值大的
		if (child + 1 < n&&a[child] < a[child + 1])
		{
			++child;
		}
		//孩子节点的值大于父亲节点，交换
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = (2 * parent) + 1;
		}
		else
			//以此为根节点的子树已经是一个堆结构的树
			break;
	}
}
//void shiftdown1(Heap* hp, int n)//n是需要调整节点
//{
//	int parent = n;
//	int child;
//	while (parent*2+1<hp->_size)//如果有左孩子，循环进入
//	{
//		//如果没有右孩子，则直接等于左孩子
//		if (hp->_a[(parent * 2) + 2] >= hp->_size)
//		{
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			//做大堆(根节点总是不小于其孩子节点的值）
//			if (hp->_a[parent * 2 + 1] > hp->_a[parent * 2 + 2])
//			{
//				child = parent * 2 + 1;
//			}
//			else
//			{
//				child = parent * 2 + 2;
//			}
//		}
//		//判断根节点和左右孩子的大小
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
//向上调整（插入一个新的元素，从新的元素开始，向上调整，直到是堆结构）
void HeapUp(HPDataType* a, int n, int child)
{
	assert(a); 
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[parent], &a[child]);
			child = parent;//child一直保存插入的元素的值，parent一直就是child 的父节点
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}
void HeapPush(Heap* hp, HPDataType x)
{
	//插入节点在数组最后的位置上，使用向上调整
	assert(hp);
	int newc;
	if (hp->_capacity == hp->_size)
	{
		newc = hp->_capacity == 0 ? 10 : 2 * hp->_capacity;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*newc);
		hp->_capacity = newc;
	}
	hp->_a[hp->_size++] = x;
	HeapUp(hp->_a, hp->_size, hp->_size - 1);// hp->_size - 1最后一个元素的位置
}
void HeapPop(Heap* hp)
{
	assert(hp && hp->_size);
	if (HeapEmpty(hp) == 1)
	{
		Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
		--hp->_size;
	}
	//从根节点开始调整
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
	//为空返回0
	return hp->_capacity == 0 ? 0 : 1;
}
// 堆排序
//时间复杂度：O(N*logN+N)-->O(N)
void HeapSort(int* a, int n)//针对当输入一个字符串进行排序时，首先要建立一个堆结构
{
	int i = 0;
	int end = n - 1;
	//建堆(把数组中的元素按堆结构建立）
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
void HeapSort1(Heap* hp)//已经是一个堆结构，然后进行排序
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
//测试堆
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