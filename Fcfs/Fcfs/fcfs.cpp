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
	float turnTime;//进程周转时间
	float wtaTime;//带权周转时间
};
//输出进程信息
void printProcess(process *F,int n)
{
	cout << "进程名 到达时间    执行时间 开始时间 结束时间 周转时间 带权周转时间" << endl;
	for (int i = 0; i<n; i++)
	{
		cout << F[i].name << "\t" << F[i].arivTime << "\t\t" << F[i].runTime << "   \t" << F[i].staTime << "   \t" << F[i].endTime << "   \t" << F[i].turnTime << "\t" << F[i].wtaTime << "\t" << endl;
	}
}
//按照到达时间进行排序
void sortProcess(process *F,int n)
{
	for (int i = 0; i<n-1; i++)
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
//过程模拟
void runProcess(process *F,int n)
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
int main()
{
	process Proc[1000];
	int n;
	cout << "请输入作业数：";
	cin >> n;
	input(Proc, n);
	printProcess(Proc, n);
	cout << "排在就绪队列进程信息" << endl;
	sortProcess(Proc,n);
	printProcess(Proc,n);
	cout << endl;
	cout << "进程调度FCFS算法模拟结果" << endl;
	runProcess(Proc,n);
	printProcess(Proc, n);
	system("pause");
}*/