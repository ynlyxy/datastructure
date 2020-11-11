#define _CRT_SECURE_NO_WARNINGS 1
#include"q.h"
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)//��ָ��pi(λ����������a ��һ��������
{
	if (a[*pi] != '#')
	{
		BTNode *root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pi];
		++(*pi);
		root->_left = BinaryTreeCreate(a, pi);
		++(*pi);
		root->_right = BinaryTreeCreate(a, pi);
		return root;
	}
	else
		return NULL;
}
void BinaryTreeDestory(BTNode* *root)//ֱ���޸�ָ�����ݣ��ڲ����ⲿһ�£�
{
	/*if (*root)
	{
	BinaryTreeDestory(&(*root)->_left);//����ָ�뱣��һ��ָ��ĵ�ַ
	BinaryTreeDestory(&(*root)->_right);
	free(*root);
	*root = NULL;
	}*/
	BTNode* curroot = *root;
	if (curroot)
	{
		BinaryTreeDestory(&curroot->_left);
		BinaryTreeDestory(&curroot->_right);
		free(curroot);
		*root = NULL;
	}
}
//void BinaryTreeDestory(BTNode* root)
//{
//	if (root)
//	{
//		BinaryTreeDestory(root->_left);
//		BinaryTreeDestory(root->_right);
//		free(root);
//		root = NULL;
//	}
//}
//��������Ч�ڵ�ĸ���
int BinaryTreeSize(BTNode* root)
{
	if (root)
	{
		return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
	}
	else
		return 0;
}
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL&&root->_right == NULL)
	{
		return 1;
	}
	return  BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
//��k��ڵ�ĸ���(�Ը�Ϊ�ڵ�ĵ�һ����ǵ�ǰ���ڵ���һ�㣩
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1)+BinaryTreeLevelKSize(root->_right, k - 1);
}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
    BTNode* ret;
	if (root->_data == x)
	{
		return root;
	}
	//����������
	if (root == NULL)
	{
		return NULL;
	}
	ret = BinaryTreeFind(root->_left, x);
	if (ret)
		return ret;
	ret = BinaryTreeFind(root->_right, x);
	if (ret)
		return ret;
	//������û���ҵ�
	return NULL;

}
// ���� 
void BinaryTreePrevOrder(BTNode* root)
{
	//��������������ң�
	if (root)
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
	else
		printf("%c ", '#');
}
void BinaryTreeInOrder(BTNode* root)
{
	//�������������ң�#D#B#E#H#A#F#C#G#
	if (root)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreeInOrder(root->_right);
	}
	else
		printf("%c ", '#');
}
void BinaryTreePostOrder(BTNode* root)
{
	//������������Ҹ���##D###HEB##F##GCA
	if (root)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root->_data);
	}
	else
		printf("%c ", '#');
}

// �ǵݹ����
// ������������ö���ʵ�֣�˼�룺������ӣ��ж��Ƿ������Һ��ӣ��У�������У�Ȼ������ӣ����δ��룬���ӡ�ֱ������Ϊ�գ�
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue pq;
	QueueInit(&pq);//��ʼ������
	BTNode *cur;
	if (root)
	{
		QueuePush(&pq, root);//�Ѷ������ĸ��ڵ����
	}
	while (QueueEmpty(&pq) == 0)//���в�Ϊ��
	{
		cur = QueueFront(&pq);//�õ���ͷԪ��
		QueuePop(&pq);//��ͷԪ�س���
		printf("%c", cur->_data);
		//�ж��������Һ��ӣ����У���ջ
		if (cur->_left)
		{
		    QueuePush(&pq, cur->_left);
		}
		if (cur->_right)
		{
			QueuePush(&pq, cur->_right);
		}
		printf("\0");
	}
	//QueueDestory(&pq);//���ٶ���
}
// �ж϶������Ƿ�����ȫ�����������ڲ�����ĸ��
//һ����ȫ�����������ò������������һ����Ԫ�أ�����ǿ�Ԫ��
int BinaryTreeComplete(BTNode*root)
{
	Queue pq;
	BTNode* front;
	QueueInit(&pq);
	if (root)
	{
		QueuePush(&pq, root);
	}
	while (QueueEmpty(&pq) == 0)//���в�Ϊ��
	{
		front = QueueFront(&pq);//�õ���ͷԪ��
		QueuePop(&pq);//��Ϊ��ָ����ʣ���ʹpop����Ҳ����ͨ��ָ���ҵ�
		//�����ͷԪ�ز�Ϊ�գ������Һ��Ӵ��뵽�����У�û�����Һ��Ӿʹ����
		if (front)
		{
			QueuePush(&pq, front->_left);
			QueuePush(&pq, front->_right);
		}
		//��Ϊ��������˴�ѭ��������һ��ѭ��
		else
			break;
	}
	while (QueueEmpty(&pq) == 0)
	{
		front = QueueFront(&pq);
		//�ж��Ƿ�Ϊ�գ��ǿ����ʾ������ȫ������
		if (front)
		{
			QueueDestory(&pq);
			return 0;//��ʾ����һ����ȫ������
		}
		//�ǿվ�ɾ���������ж��¸�Ԫ���Ƿ�Ϊ��
		QueuePop(&pq);
	}
	return 1;
}
//����ջ��ʵ��
//˼�룺���ʴ���Ϊ�����ң��Ӹ���ʼ���ʣ�ʹ���������ջ���������������������ӣ�ֱ������Ϊ��
//����ջ����Ԫ���жϽڵ��Ƿ�����������������ʹ�����������ջ��
//������ͬ��ִ���ұ�
void BinaryTreePrevOrderNonR(BTNode* root)
{
	Stack st;
	StackInit(&st);
	BTNode *cur = root;
	BTNode* top;
	while (cur || StackEmpty(&st) == 0)
	{
		while (cur)
		{
			printf("%c ", cur->_date);
			StackPush(&st, cur);
			cur = cur->_left;
		}
		//��ʱ���ʵ�������ߵ�������������
		top = StackTop(&st);
		StackPop(&st);
		cur = top->_right;
	}
	printf("\n");
}
//˼�룺���������ǰ���ʽڵ㣬�����ǰ�ڵ����Һ��ӣ�ʹ����ջ��
//��������ӣ���ȥ�������ӣ����û�оͷ���ջ��Ԫ��
void BinaryTreePrevOrderNonR(BTNode* root)
{
	Stack st;
	StackInit(&st);
	BTNode *cur = root;
	while (cur)
	{
		printf("%c ", cur->_data);
		if (cur->_left)
		{
			cur = cur->_left;
		}
		else
		{
			cur = StackTop(&st);
			StackPop(&st);
		}
		if (cur->_right)
		{
			StackPush(&st, cur->_right);
		}
	}
}
//˼�룺���ȷ��ʸ��ڵ㣬ʹ����ջ����������������������������ʹ����ջ��
//ֱ�����ʵ�������Ϊ��ʱ���ó�ջ��Ԫ�أ���ӡ���ж����Ƿ����������������������������������ʹ����ջ
//��������������������ջ��Ԫ��
void BinaryTreeInOrderNonR(BTNode* root)
{
	Stack st;
	StackInit(&st);
	BTNode *cur = root;
	while (cur || StackEmpty(&st) == 0)
	{
		while (cur)
		{
			StackPush(&st, cur);
			cur = cur->_left;
		}
		cur = StackTop(&st);
		printf("%c ", cur->_data);
		StackPop(&st);
		cur = cur->_right;
	}
	printf("\n");
}
void BinaryTreePostOrderNonR(BTNode* root)
{
	Stack st;
	StackInit(&st);
	BTNode *cur = root;
	BTNode *prev = NULL;
	BTNode *top;
	{
		while (cur || StackEmpty(&st) == 0)
		{
			while (cur)
			{
				StackPush(&st, cur);
				cur = cur->_left;
			}
			top = StackTop(&st);
			//�ж��Ƿ���������������У������������Ѿ������꣬���Է��ʸ�
			//���ޣ����ʸ���ջ
			if (top->_right == NULL || top->_right == prev)
			{
				printf("%c ", top->_data);
				StackPop(&st);
				prev = top;
			}
			//��������������û�б����ʣ��ͷ�����������
			else
				cur = top->_right;
		}
	}
}

void TestBinaryTree()
{
	int i = 0;
	char a[] = { 'A', 'B', 'D', '#', '#', 'E', '#', 'H', '#', '#', 'C', 'F', '#', '#', 'G', '#','#' };
	BTNode* root = BinaryTreeCreate(a, &i);
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	//BinaryTreeDestory(&root);
	printf("%d", BinaryTreeSize(root));
}
void Test2()
{
	int i = 0;
	int ret;
	char a2[] = { 'a', 'b', 'd', 'g', '#', '#', 'h', '#', '#', 'z', '#', '#', 'c', 'e', '#', '#', 'f', '#', '#' };
	BTNode* root = BinaryTreeCreate(a2, &i);
	BinaryTreeLevelOrder(root);
	ret = BinaryTreeComplete(root);
}
int main()
{
	//TestBinaryTree();
	Test2();
	system("pause");
	return 0;
}