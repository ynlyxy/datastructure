#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
void ouput(int p, int r, vector<int> AV, vector<vector<int>> AL, vector<vector<int>>Need)
{
	cout << "************Available************" << endl;
	for (int i = 0; i < r; ++i)
	{
		cout << AV[i] << " ";
	}
	cout << endl;
	cout << "**********Allocation************" << endl;
	for (int i = 0; i < p; ++i)
	{
		for (int j = 0; j < r; ++j)
		{
			cout << AL[i][j] << " ";
		}
		cout << endl;
	}
	cout << "************Need***************" << endl;
	for (int i = 0; i < p; ++i)
	{
		for (int j = 0; j < r; ++j)
		{
			cout << Need[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
bool isSafeSystem(int p, int r, vector<int> AV, vector<vector<int>> AL, vector<vector<int>>Need )
{
	vector<int> work(AV);
	vector<bool> finished(p,false);//分配是否完成
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
				++sum;//每个进程每个所需的资源数满足
			}
			else
			{
				break;
			}
		}
		//当进程对应的所有资源数量都满足，把此进程的进程序号添加到安全序列中
		if (sum == r)
		{
			finished[i] = true;
			SafeOrder[finishnum] = i;
			++finishnum;
			for (int j = 0; j < r; ++j)
			{
				work[j] +=  AL[i][j];
			}
			i = 0;//找到满足条件的进程，还是要从头遍历
		}
		else
		{
			++i;
		}
		if (finishnum == p)
		{
			cout << "******此状态下处于安全状态！！！******" << endl;
			cout << "******安全序列为： ";
			cout << "P" << SafeOrder[0] << " ";
			for (int m = 1; m < p; ++m)
			{
				cout << "P" << SafeOrder[m] <<" ";
			}
			cout << endl;
			//ouput2(p, r, AV, AL, Need);
			return true;
		}
	}
	cout << "******此状态是不安全状态！！！******" << endl;
	return false;
}
void requestSafe(int p, int r, vector<int> AV, vector<vector<int>> AL, vector<vector<int>>Need)
{
	int chooseprocess;
	bool ret;
	char iscontinue;
	int flag = 1;//表示当前输入合法，可以调用安全性算法进行试分配
	vector<int> request(r);
	while (true)
	{
		cout << "******输入要申请资源的进程号（大于等于0的正数）：";
		cin >> chooseprocess;
		if (chooseprocess >= p)
		{
			cout << "输入错误！！！,重新输入！！！";
			cout << "是否继续进行输入，是（Y），否（N）" << endl;
			cout << "iscontinue = ";
			cin >> iscontinue;
			if (iscontinue == 'Y')
			{
				continue;
			}
			else
			{
				break;
			}
		}
		cout << "*******输入该进程所要申请的各类资源数:";
		for (int i = 0; i < r; ++i)
		{
			cin >> request[i];
		}
		//请求不合法
		for (int i = 0; i < r; ++i)
		{
			if (request[i]>Need[chooseprocess][i])
			{
				cout << endl;
				cout << "******当前的请求进程的请求资源数量大于该进程的需求量******" << endl;
				cout << "******当前请求的资源数目：";
				for (int j = 0; j < r; ++j)
				{
					cout << request[j] << " ";
				}
				cout << endl;
				cout << "******当前进程所需资源数目：";
				{
					for (int n = 0; n<r; ++n)
					{
						cout << Need[chooseprocess][n] << " ";
					}
				}
				cout << endl;
				flag = 0;
				break;
			}
			else if (request[i] > AV[i])
			{
				cout << endl;
				cout << "******当前的请求进程的请求资源数量大于系统供给资源量，进程等待" << endl;
				cout << "******当前请求的资源数目：";
				for (int j = 0; j < r; ++j)
				{
					cout << request[j] << " ";
				}
				cout << endl;
				cout << "当前系统供给资源数目：";
				for (int m = 0; m < r;++m)
				{
					cout << AV[m] << " ";
				}
				cout << endl;
				flag = 0;
				break;
			}
			else
			{
				flag = 1;
			}
		}
		//请求不合法后对应的处理
		if (flag == 0)
		{
			cout << "******是否继续进行输入，是（Y），否（N）******" << endl;
			cout << "iscontinue = ";
			cin >> iscontinue;
			cout << endl;
			if (iscontinue == 'Y')
			{
			    continue;
			}
			else
			{
				break;
			}
		}
		//请求合法后对应的处理
		else if (flag==1)
		{
			for (int j = 0; j < r; ++j)
			{
				AV[j] -= request[j];
				Need[chooseprocess][j] -= request[j];
				AL[chooseprocess][j] += request[j];
			}
			cout << "******************试分配后的资源状况：************" << endl;
			ouput(p, r, AV, AL, Need);
			cout << endl;
		}
		ret = isSafeSystem(p, r, AV, AL, Need);
		int RN = 1;//表示请求等于需求
		if (ret == true)
		{
			for (int j = 0; j < r; ++j)
			{
				if (Need[chooseprocess][j]!=0)
				{
					RN = 0;
					break;
				}
				AV[j] += AL[chooseprocess][j];
				Need[chooseprocess][j] = 0;
				AL[chooseprocess][j] = 0;
				RN = 1;
			}
			if (RN == 1)
			{
				cout << "******************分配后的资源状况：*****************" << endl;
				ouput(p, r, AV, AL, Need);
			}
		}
		//如果不满足系统安全性算法，则回复到原来的状态。
		if (ret == false)
		{
			cout << "当前可利用资源不能满足任何进程的需求，系统将进入不安全状态，故不予分配资源！！！" << endl;
			cout << "资源恢复" << endl;
			for (int j = 0; j < r; ++j)
			{
				AV[j] += request[j];
				Need[chooseprocess][j] += request[j];
				AL[chooseprocess][j] -= request[j];
			}
			cout << "*******************恢复后的资源状况：****************" << endl;
			ouput(p, r, AV, AL, Need);
		}
		cout << "是否继续进行请求变量测试，是（Y），否（N）" << endl;
		cout << "iscontinue = ";
		cin >> iscontinue;
		cout << endl;
		if (iscontinue == 'Y')
		{
			continue;
		}
		else
		{
			break;
		}
	}
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
	cout << "输入Available矩阵(eg:1 2 3 )" << endl;
	for (int i = 0; i < R; ++i)
	{
		cin >> AV[i];
	}
	vector<vector<int>> AL(P, vector<int>(R, 0));//已分配矩阵
	cout << "******输入Allocation矩阵******" << endl;
	for (int i = 0; i <P; ++i)
	{
		for (int j = 0; j < R; ++j)
		{
			cin >> AL[i][j];
		}
	}
	vector<vector<int>> Need(P, vector<int>(R, 0));//尚需矩阵
	cout << "******输入Need矩阵*******" << endl;
	for (int i = 0; i < P; ++i)
	{
		for (int j = 0; j < R; ++j)
		{
			cin >> Need[i][j];
		}
	}
	vector<vector<int>> Max(P, vector<int>(R, 0));//最大分配矩阵
	cout << "******Max矩阵*******" << endl;
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
	cout << endl;
	isSafeSystem(P, R, AV, AL, Need);
	requestSafe(P, R, AV, AL, Need);
	system("pause");
	return 0;
}
