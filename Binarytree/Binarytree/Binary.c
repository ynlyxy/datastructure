#define _CRT_SECURE_NO_WARNINGS 1
#include"q.h"
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)//传指针pi(位置索引），a 是一个数组名
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
void BinaryTreeDestory(BTNode* *root)//直接修改指针内容（内部和外部一致）
{
	/*if (*root)
	{
	BinaryTreeDestory(&(*root)->_left);//二级指针保存一级指针的地址
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
//二叉树有效节点的个数
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
//第k层节点的个数(以根为节点的第一层就是当前根节点这一层）
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
	//空树，返回
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
	//遍历完没有找到
	return NULL;

}
// 遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	//先序遍历（根左右）
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
	//中序遍历（左根右）#D#B#E#H#A#F#C#G#
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
	//后序遍历（左右根）##D###HEB##F##GCA
	if (root)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root->_data);
	}
	else
		printf("%c ", '#');
}

// 非递归遍历
// 层序遍历（利用队列实现，思想：根先入队，判断是否有左右孩子，有，带入队列，然后跟出队，依次带入，出队。直到队列为空）
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue pq;
	QueueInit(&pq);//初始化队列
	BTNode *cur;
	if (root)
	{
		QueuePush(&pq, root);//把二叉树的根节点入队
	}
	while (QueueEmpty(&pq) == 0)//队列不为空
	{
		cur = QueueFront(&pq);//拿到队头元素
		QueuePop(&pq);//队头元素出队
		printf("%c", cur->_data);
		//判断有无左右孩子，若有，入栈
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
	//QueueDestory(&pq);//销毁队列
}
// 判断二叉树是否是完全二叉树（基于层排序的概念）
//一个完全二叉树，利用层序遍历后，遇见一个空元素，其后都是空元素
int BinaryTreeComplete(BTNode*root)
{
	Queue pq;
	BTNode* front;
	QueueInit(&pq);
	if (root)
	{
		QueuePush(&pq, root);
	}
	while (QueueEmpty(&pq) == 0)//队列不为空
	{
		front = QueueFront(&pq);//拿到队头元素
		QueuePop(&pq);//因为是指针访问，即使pop掉，也可以通过指针找到
		//如果队头元素不为空，将左右孩子带入到队列中，没有左右孩子就带入空
		if (front)
		{
			QueuePush(&pq, front->_left);
			QueuePush(&pq, front->_right);
		}
		//若为空则结束此次循环进入下一个循环
		else
			break;
	}
	while (QueueEmpty(&pq) == 0)
	{
		front = QueueFront(&pq);
		//判断是否为空，非空则表示不是完全二叉树
		if (front)
		{
			QueueDestory(&pq);
			return 0;//表示不是一个完全二叉树
		}
		//是空就删除，继续判断下个元素是否为空
		QueuePop(&pq);
	}
	return 1;
}
//基于栈来实现
//思想：访问次序为根左右，从根开始访问，使其输出并入栈，若有左子树，访问左孩子，直到左孩子为空
//利用栈顶的元素判断节点是否有右子树，若有则使其输出并且入栈。
//左边完成同理执行右边
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
		//此时访问到了最左边的子树的右子树
		top = StackTop(&st);
		StackPop(&st);
		cur = top->_right;
	}
	printf("\n");
}
//思想：首先输出当前访问节点，如果当前节点有右孩子，使其入栈，
//如果有左孩子，就去访问左孩子，如果没有就访问栈顶元素
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
//思想：首先访问根节点，使其入栈，若是有左子树，访问左子树并使其入栈。
//直到访问的左子树为空时，拿出栈顶元素，打印并判断其是否有右子树，如果有右子树，访问右子树使其入栈
//如果无右子树，则继续拿栈顶元素
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
			//判断是否存在右子树，若有，并且右子树已经访问完，可以访问根
			//若无，访问根出栈
			if (top->_right == NULL || top->_right == prev)
			{
				printf("%c ", top->_data);
				StackPop(&st);
				prev = top;
			}
			//存在右子树并且没有被访问，就访问其右子树
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