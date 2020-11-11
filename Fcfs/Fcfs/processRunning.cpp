#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include<queue>
using namespace std;
//进程结构体
struct process
{
	string name;//进程名
	float arivTime;//到达时间
	float runTime;//进程运行时间
	float staTime;//进程开始执行时间
	float endTime;//进程完成时间
	float turnTime;//进程周转时间
	float wtaTime;//带权周转时间
	float hastime;//表示当前进程已经运行了多少时间
	int flag = 0;//进程还没有执行完毕
	int qucome = 0;//表示进程是否进入就绪队列
	int sum = 0;//表示进程进入队列的次数
};
//输出进程信息
void printProcess(process *F, int n)
{
	cout << "进程名 到达时间    执行时间 开始时间 结束时间 周转时间 带权周转时间" << endl;
	for (int i = 0; i<n; i++)
	{
		cout << F[i].name << "\t" << F[i].arivTime << "\t\t" << F[i].runTime << "   \t" << F[i].staTime << "   \t" << F[i].endTime << "   \t" << F[i].turnTime << "\t" << F[i].wtaTime << "\t" << endl;
	}
}
//输入进程信息
void input(process *F, int n)
{
	cout << endl << "创建进程" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << "请输入第" << i + 1 << "个进程的名字、到达时间、服务时间(例如:A 12 8):";
		cin >> F[i].name;
		cin >> F[i].arivTime;
		cin >> F[i].runTime;
		F[i].endTime = 0;
		F[i].staTime = 0;
		F[i].turnTime = 0;
		F[i].wtaTime = 0;
		F[i].hastime = F[i].runTime;
	}
}
//按照到达时间进行排序
void sortProcess(process *F, int n)
{
	for (int i = 0; i<n - 1; i++)
	{
		for (int j = i + 1; j<n; j++)
		{
			if (F[j].arivTime<F[i].arivTime)
			{
				string Na;
				int aT, rT;//保存节点信息
				Na = F[i].name;
				F[i].name = F[j].name;
				F[j].name = Na;
				aT = F[i].arivTime;
				F[i].arivTime = F[j].arivTime;
				F[j].arivTime = aT;
				rT = F[i].runTime;
				F[i].runTime = F[j].runTime;
				F[j].runTime = rT;
			}
		}
	}
}
//FCFS算法过程模拟
void runProcess(process *F, int n)
{
	//当前时间
	int time = 0;
	//作业数
	int num = 0;
	while (num < n)
	{
		if (time >= F[num].arivTime)
		{
			F[num].staTime = time;
			F[num].endTime = F[num].staTime + F[num].runTime;
			F[num].turnTime = F[num].endTime - F[num].arivTime;
			F[num].wtaTime = F[num].turnTime / F[num].runTime;
			time = F[num].endTime;
			++num;
		}
		else
		{
			++time;
		}
	}
}
//SJF过程模拟
void runSFJProcess(process *A, int n)
{
	int CurrentTime = 0;//当前时间
	int num = 0;//作业数
	while (num < n)
	{
		if (CurrentTime >= A[0].arivTime && A[0].flag == 0)
		{
			A[0].staTime = CurrentTime;
			A[0].endTime = A[0].staTime + A[0].runTime;
			CurrentTime = CurrentTime + A[0].runTime;
			A[0].turnTime = A[0].endTime - A[0].arivTime;
			A[0].wtaTime = A[0].turnTime / A[0].runTime;
			CurrentTime = A[0].endTime;
			A[0].flag = 1;
			++num;
		}
		else if (CurrentTime >= A[num].arivTime && num > 0)
		{
			int sum = 0;//统计当前可执行进程的个数
			int tmp;
			for (int k = 0; k < n; ++k)
			{
				if (A[k].flag == 1)
				{
					continue;
				}
				if (A[k].flag == 0 && A[k].arivTime <= CurrentTime)
				{
					++sum;
					tmp = k;
				}
			}
			if (sum == 1)
			{
				A[tmp].staTime = CurrentTime;
				A[tmp].endTime = A[tmp].staTime + A[tmp].runTime;
				CurrentTime = CurrentTime + A[tmp].runTime;
				A[tmp].turnTime = A[tmp].endTime - A[tmp].arivTime;
				A[tmp].wtaTime = A[tmp].turnTime / A[tmp].runTime;
				CurrentTime = A[tmp].endTime;
				A[tmp].flag = 1;
				++num;
			}
			else if (sum > 1)
			{
				int minprocess;//保存当前找到最小运行时间的作业的索引
				for (int l = 0; l < n; ++l)
				{
					if (A[l].flag == 0)
					{
						minprocess = l;
						break;
					}
				}
				for (int m = 0; m < n; ++m)
				{
					if (A[m].flag == 1)
					{
						continue;
					}
					else
					{
						if (A[m].runTime < A[minprocess].runTime)
						{
							minprocess = m;
						}
					}
				}
				A[minprocess].staTime = CurrentTime;
				A[minprocess].endTime = A[minprocess].staTime + A[minprocess].runTime;
				CurrentTime = CurrentTime + A[minprocess].runTime;
				A[minprocess].turnTime = A[minprocess].endTime - A[minprocess].arivTime;
				A[minprocess].wtaTime = A[minprocess].turnTime / A[minprocess].runTime;
				CurrentTime = A[minprocess].endTime;
				A[minprocess].flag = 1;
				++num;
			}
		}
		else
		{
			CurrentTime++;
		}
	}
}
//时间片的输出函数
void printProcess1(process *F, int n)
{
	int flag = 0;
	process tmp;
	for (int i = 0; i < n - 1; ++i)
	{
		flag = 0;
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (F[j].arivTime>F[j + 1].arivTime)
			{
				tmp = F[j];
				F[j] = F[j + 1];
				F[j + 1] = tmp;
				flag = 1;
			}
		}
	}
	cout << "进程名 到达时间    执行时间 开始时间 结束时间 周转时间 带权周转时间" << endl;
	for (int i = 0; i<n; i++)
	{
		cout << F[i].name << "\t" << F[i].arivTime << "\t\t" << F[i].hastime << "   \t" << F[i].staTime << "   \t" << F[i].endTime << "   \t" << F[i].turnTime << "\t" << F[i].wtaTime << "\t" << endl;
	}
}
void runRRProcess(process* F, int n)
{
	int r;
	cout << "请输入时间片大小：";
	cin >> r;
	int Time = 0;//当前时间
	process tmp[10];//保存执行完成的进程
	for (int i = 0; i < n; ++i)
	{
		tmp[i] = F[i];
	}
	queue<process> qu;
	while (qu.empty())//首先把第一个到达的进程队列
	{
		if (F[0].arivTime <= Time && F[0].qucome == 0)
		{
			++F[0].sum;
			F[0].qucome = 1;
			qu.push(F[0]);
		}
		else
		{
			++Time;
		}
	}
	while (!qu.empty())
	{
		if (qu.front().sum == 1)
		{
			qu.front().staTime = Time;
		}
		if (qu.front().runTime <= r)//如果当前执行的进程的运行时间小于一个时间片，则按照运行时间执行后退出队列
		{
			//qu.front().staTime = Time;
			if (qu.front().sum == 1)
			{
				qu.front().endTime += qu.front().staTime + qu.front().runTime;
			}
			else
			{
				qu.front().endTime = qu.front().runTime + Time;
			}
			qu.front().turnTime = qu.front().endTime - qu.front().arivTime;
			qu.front().wtaTime = qu.front().turnTime / qu.front().hastime;
			Time = qu.front().endTime;
			qu.front().flag = 1;//此程序执行完毕
			//保存到tmp数组里
			int f = 0;
			while (f < n)
			{
				if (tmp[f].flag == 0)
				{
					tmp[f].flag = qu.front().flag;
					tmp[f].arivTime = qu.front().arivTime;
					tmp[f].endTime = qu.front().endTime;
					tmp[f].hastime = qu.front().hastime;
					//tmp[f].runTime = qu.front().runTime;
					tmp[f].staTime = qu.front().staTime;
					tmp[f].name = qu.front().name;
					tmp[f].turnTime = qu.front().turnTime;
					tmp[f].wtaTime = qu.front().wtaTime;
					break;
				}
				else
				{
					++f;
				}
			}
			//查看当前可入队列的进行，送队列
			for (int i = 1; i < n; ++i)
			{
				if (F[i].arivTime <= Time && F[i].qucome <= 0)
				{
					++F[i].sum;
					F[i].qucome = 1;
					qu.push(F[i]);
				}
			}
			qu.pop();
		}
		else
		{
			//qu.front().staTime = Time;
			Time += r;
			qu.front().endTime = Time;
			qu.front().runTime -= r;
			//查看当前可入队列的进行，送队列
			for (int i = 1; i < n; ++i)
			{
				if (F[i].arivTime <= Time && F[i].qucome <= 0)
				{
					++F[i].sum;
					F[i].qucome = 1;
					qu.push(F[i]);
				}
			}
			++qu.front().sum;
			qu.push(qu.front());
			qu.pop();
		}
	}
	printProcess1(tmp, n);
}
int main()
{
	process Proc[1000];
	int n;
	cout << "请输入作业数：";
	cin >> n;
	input(Proc, n);
	printProcess(Proc, n);
	sortProcess(Proc, n);
	int ret;
	cout << "请选择一种算法：" << endl;
	cout << "0.退出！！" << endl;
	cout << "1.FCFS算法" << endl;
	cout << "2.SFJ算法" << endl;
	cout << "3.RR算法" << endl;
	while (cin >> ret)
	{
		switch (ret)
		{
		case 0:
			exit(0);
		case 1:
			cout << "进程调度FCFS算法模拟结果" << endl;
			runProcess(Proc, n);
			printProcess(Proc, n);
			break;
		case 2:
			cout << "进程调度SJF算法模拟结果" << endl;
			runSFJProcess(Proc, n);
			printProcess(Proc, n);
			break;
		case 3:
			cout << "进程调度RR算法模拟结果" << endl;
			runRRProcess(Proc, n);
		default:
			break;
		}
	}
	system("pause");
}