#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
//进程结构体
/*struct process
{
	string name;//进程名
	float arivTime;//到达时间
	float runTime;//进程运行时间
	float staTime;//进程开始执行时间
	float endTime;//进程完成时间
	float turnTime;//进程turnTime周转时间
	float wtaTime;//带权周转时间
	int flag = 0;
};
//打印所有进程信息
void printProcess(process *F, int n)
{
	cout << "进程名 到达时间    执行时间 开始时间 结束时间 周转时间 带权周转时间" << endl;
	for (int i = 0; i<n; i++)
	{
		cout << F[i].name << "\t" << F[i].arivTime << "\t\t" << F[i].runTime << "   \t" << F[i].staTime << "   \t" << F[i].endTime << "   \t" << F[i].turnTime << "\t" << F[i].wtaTime << "\t" << endl;
	}
}
//按照到达时间进行排序
void sortProcess(process *F, int n)
{
	for (int i = 0; i<n - 1; ++i)
	{
		for (int j = i + 1; j<n; ++j)
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
	}
}
//过程模拟
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
int main()
{
	process Proc[1000];
	int n;
	cout << "请输入作业数：";
	cin >> n;
	input(Proc, n);
	printProcess(Proc, n);
	cout << "进程调度SFJ算法模拟结果" << endl;
	sortProcess(Proc, n);
	runSFJProcess(Proc, n);
	//SortedByStartTime(Proc, n);
	printProcess(Proc, n);
	system("pause");
}*/