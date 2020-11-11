#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
struct process
{
	int id;//表示分区号
	int data;//表示分区大小
	int ad;//表示分区首址
	int flag = 0;//表示当前位置没有存储数据
};
//初始化分区表
void input(process *F, int n)
{
	cout << endl << "***********创建分区表************" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout <<"分区号 分区大小 分区首址(例如:1 30 40):";
		cin >> F[i].id;
		cin >> F[i].data;
		cin >> F[i].ad;
	}
}
//输出函数
void printProcess(process *F, int n)
{
	cout << endl << "分区号  分区大小   分区首址" << endl;
	for (int i = 0; i<n; i++)
	{
		if (F[i].data != 0)
		{
			cout << F[i].id << "\t" << F[i].data << "\t\t" << F[i].ad << endl;
		}
	}
}
//按照分区由小到大进行排序
void sortbigdata(process *F, int n) 
{
	process tmp[1];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (F[j + 1].data > F[j].data)
			{
				tmp[0] = F[j];
				F[j] = F[j + 1];
				F[j + 1] = tmp[0];
			}
		}
	}
}
void sortsamlldata(process *F, int n)
{
	process tmp[1];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (F[j + 1].data < F[j].data)
			{
				tmp[0] = F[j];
				F[j] = F[j + 1];
				F[j + 1] = tmp[0];
			}
		}
	}
}
void sortsamllad(process *F, int n) 
{
	process tmp[1];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (F[j + 1].ad < F[j].ad)
			{
				tmp[0] = F[j];
				F[j] = F[j + 1];
				F[j + 1] = tmp[0];
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
int main()
{
	process P[100];
	int ret;
	cout << "请输入分区块数：";
	cin >> ret;
	input(P, ret);
	printProcess(P, ret);
	int request;//请求分配作业大小
	int num;
	/*sortbigdata(P, ret);
	printProcess(P, ret);
	sortsamlldata(P, ret);
	printProcess(P, ret);
	sortsamllad(P, ret);
	printProcess(P, ret);*/
	system("pause");
	return 0;
}