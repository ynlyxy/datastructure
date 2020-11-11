#include<iostream>
using namespace std;
struct job
{
	int id;//分区号
	int partnum;//分区大小
	int partaddress;//分区始址
	//int flag = 1;//可以参与内存划分 为0 表示不可以参与内存划分
};
void Print(job *P, int n) //打印的最后计算的作业完成时间。。。。
{
	cout << "分区号" << "  " << "分区大小" << " " << "分区始址" << endl;
	for (int i = 0; i < n; i++)
	{
		if (P->partnum != 0)
		{
			cout << P->id << "\t" << P->partnum << "\t" << P->partaddress << endl;
		}
		P++;
	}
}
void bigsortaddress(job * P, int n) //地址排序
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if ((P + j)->partaddress >(P + j + 1)->partaddress)
			{
				string tmp;
				int tmp1;
				int tmp2;

				tmp1 = (P + j)->partnum;
				(P + j)->partnum = (P + j + 1)->partnum;
				(P + j + 1)->partnum = tmp1;

				tmp2 = (P + j)->partaddress;
				(P + j)->partaddress = (P + j + 1)->partaddress;
				(P + j + 1)->partaddress = tmp2;
			}
		}
	}
}
void smallsort(job * P, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if ((P + j)->partnum >(P + j + 1)->partnum)
			{
				string tmp;
				int tmp1;
				int tmp2;

				tmp1 = (P + j)->partnum;
				(P + j)->partnum = (P + j + 1)->partnum;
				(P + j + 1)->partnum = tmp1;

				tmp2 = (P + j)->partaddress;
				(P + j)->partaddress = (P + j + 1)->partaddress;
				(P + j + 1)->partaddress = tmp2;
			}
		}
	}
}
void bigsort(job * P, int n) //分区大小排序
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if ((P + j)->partnum <(P + j + 1)->partnum)
			{
				string tmp;
				int tmp1;
				int tmp2;

				tmp1 = (P + j)->partnum;
				(P + j)->partnum = (P + j + 1)->partnum;
				(P + j + 1)->partnum = tmp1;

				tmp2 = (P + j)->partaddress;
				(P + j)->partaddress = (P + j + 1)->partaddress;
				(P + j + 1)->partaddress = tmp2;
			}
		}
	}
}
int flag = 0;
int NF(job * P, int n, int part)
{
	for (int i = flag; i < n; i++)
	{
		if (P[i].partnum >= part)
		{
			P[i].partnum = P[i].partnum - part;
			P[i].partaddress = P[i].partaddress + part;
			flag = i + 1;
			if (flag >= n)
			{
				flag = flag % n;
			}
			return 0;
		}
	}
	return -1;
}


int FF(job * P, int n, int part)//首次适应算法
{

	for (int i = 0; i < n; i++)
	{
		if (P[i].partnum >= part)
		{
			P[i].partnum = P[i].partnum - part;
			P[i].partaddress = P[i].partaddress + part;
			return 0;
		}
	}
	return -1;
}

int BF(job * P, int n, int part)//最佳适应算法
{

	//smallsort(P, n); //从大到小，找到第一个不满足作业需求的即停止
	for (int i = 0; i < n; i++)
	{
		if (P[i].partnum >= part)
		{
			P[i].partnum = P[i].partnum - part;
			P[i].partaddress = P[i].partaddress + part;
			/*if (P[i].partnum < 5)
			{
			P[i].flag = 0;
			}*/
			//smallsort(P, n);
			return 0;
		}
	}
	return -1;
}


int WF(job *P, int n, int part) //最坏适应算法
{
	for (int i = 0; i < n; i++)
	{
		if (P[i].partnum >= part)
		{
			P[i].partnum = P[i].partnum - part;
			P[i].partaddress = P[i].partaddress + part;
			/*if (P[i].partnum < 5)
			{
			P[i].flag = 0;
			}*/
			//smallsort(P, n);
			return 0;
		}
	}
	return -1;
}



//int main()
//{
//	int n;//代表分区表可以放几道作业
//	cout << "请输入分区表的长度" << endl;
//	cin >> n;
//	job P[100];
//	cout << "请输入分区号 分区大小 分区始址" << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> P[i].id >> P[i].partnum >> P[i].partaddress;
//	}
//	int Part;
//	int num;
//	cout << "1:BF  2:WF  3:FF  4:NF " << endl;
//	cout << "请输入要进行的算法选择->";
//	cin >> num;
//	switch (num)
//	{
//	case 1:
//		while (1)
//		{
//			smallsort(P, n);
//			cout << "空闲分区表" << endl;
//			Print(P, n);
//			cout << "请输入要分配的作业大小" << endl;
//			cin >> Part;
//			if (!(BF(P, n, Part)))
//			{
//				Print(P, n);
//			}
//			else
//			{
//				cout << "内存分配失败" << endl;
//			}
//			int go;
//			cout << "是否要继续分配 ： 1->是  2->否" << endl;
//			cin >> go;
//			if (go == 2)
//			{
//				break;
//			}
//
//		}
//
//		break;
//	case 2:
//		while (1)
//		{
//			bigsort(P, n);
//			cout << "空闲分区表" << endl;
//			Print(P, n);
//			cout << "请输入要分配的作业大小" << endl;
//			cin >> Part;
//			if (!(WF(P, n, Part)))
//			{
//				Print(P, n);
//			}
//			else
//			{
//				cout << "内存分配失败" << endl;
//			}
//			int go;
//			cout << "是否要继续分配 ： 1->是  2->否" << endl;
//			cin >> go;
//			if (go == 2)
//			{
//				break;
//			}
//		}
//		break;
//	case 3:
//		while (1)
//		{
//			bigsortaddress(P, n);
//			cout << "空闲分区表" << endl;
//			Print(P, n);
//			cout << "请输入要分配的作业大小" << endl;
//			cin >> Part;
//			if (!(FF(P, n, Part)))
//			{
//				Print(P, n);
//			}
//			else
//			{
//				cout << "内存分配失败" << endl;
//			}
//			int go;
//			cout << "是否要继续分配 ： 1->是  2->否" << endl;
//			cin >> go;
//			if (go == 2)
//			{
//				break;
//			}
//		}
//		break;
//	case 4:
//		while (1)
//		{
//			bigsortaddress(P, n);
//			cout << "空闲分区表" << endl;
//			Print(P, n);
//			cout << "请输入要分配的作业大小" << endl;
//			cin >> Part;
//			if (!(NF(P, n, Part)))
//			{
//				Print(P, n);
//			}
//			else
//			{
//				cout << "内存分配失败" << endl;
//			}
//			int go;
//			cout << "是否要继续分配 ： 1->是  2->否" << endl;
//			cin >> go;
//			if (go == 2)
//			{
//				break;
//			}
//		}
//		break;
//	default:
//		break;
//	}
//	system("pause");
//	return 0;
//}