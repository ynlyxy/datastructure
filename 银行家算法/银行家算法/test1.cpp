#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
/*bool isSafeSystem(int p, int r, vector<int> AV, vector<vector<int>> AL, vector<vector<int>>Need)
{
	vector<int> work(AV);
	vector<bool> finished(p, false);//分配是否完成
	vector<int>SafeOrder(p, -1);//安全序列
	int sum = 0;//满足进程资源的个数
	int finishnum = 0;//满足条件已经进行分配的进程的个数
	int i = 0;
	while (i < p)
	{
		sum = 0;
		for (int j = 0; j < r; ++j)
		{
			if (Need[i][j] <= work[j] && finished[i] == false)
			{
				++sum;//每个进程所需的资源数满足
			}
			else
			{
				break;
			}
		}
		//当进程对应的所有资源数量都满足是，把此进程的进程序号添加到安全序列中
		if (sum == r)
		{
			finished[i] = true;
			SafeOrder[finishnum] = i;
			++finishnum;
			for (int j = 0; j < r; ++j)
			{
				work[j] += AL[i][j];
			}
			i = 0;//找到满足条件的进程，还是要从头遍历
		}
		else
		{
			++i;
		}
		if (finishnum == p)
		{
			cout << "此状态下处于安全状态！！！" << endl;
			cout << "安全序列为： ";
			cout << "P" << SafeOrder[0] << "-->";
			for (int m = 1; m < p; ++m)
			{
				cout << "P" << SafeOrder[m];
			}
			cout << endl;
			return true;
		}
	}
	cout << "此状态是不安全状态！！！" << endl;
	return false;
}
int main()
{
	int P;//进程个数
	int R;//资源种类
	cout << "请输入进程个数" << endl;
	cin >> P;
	cout << "请输入资源种类" << endl;
	cin >> R;
	vector<int> AV(R);//目前系统还有的资源种类个数
	cout << "***输入当前可利用资源数!***(eg:1 2 3 )" << endl;
	for (int i = 0; i < R; ++i)
	{
		cin >> AV[i];
	}
	vector<vector<int>> AL(P, vector<int>(R, 0));//已分配矩阵
	cout << "*****输入已分配矩阵*****" << endl;
	for (int i = 0; i <P; ++i)
	{
		for (int j = 0; j < R; ++j)
		{
			cin >> AL[i][j];
		}
	}
	vector<vector<int>> Need(P, vector<int>(R, 0));//尚需矩阵
	cout << "*****输入尚需矩阵*****" << endl;
	for (int i = 0; i < P; ++i)
	{
		for (int j = 0; j < R; ++j)
		{
			cin >> Need[i][j];
		}
	}
	vector<vector<int>> Max(P, vector<int>(R, 0));//最大分配矩阵
	cout << "*****最大分配矩阵*****" << endl;
	for (int i = 0; i < P; ++i)
	{
		for (int j = 0; j < R; ++j)
		{
			Max[i][j] = Need[i][j] + AL[i][j];
		}
	}
	for (int i = 0; i < P; ++i)
	{
		for (int j = 0; j < R; ++j)
		{
			cout << Max[i][j] << " ";
		}
		cout << endl;
	}
	isSafeSystem(P, R, AV, AL, Need);
	system("pause");
	return 0;
}*/