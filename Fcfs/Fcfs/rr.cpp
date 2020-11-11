#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<queue>
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
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (F[j].arivTime < F[i].arivTime)
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
void runRRProcess(process* F, int n)
{
	int r;
	cout << "请输入时间片大小：";
	cin >> r;
	int Time = 0;//当前时间
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
		if (qu.front().runTime <= r && qu.front().flag == 0)//如果当前执行的进程的运行时间小于一个时间片，则按照运行时间执行后退出队列
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
			cout << "进程名 到达时间    执行时间 开始时间 结束时间 周转时间 带权周转时间" << endl;
			cout << qu.front().name << "\t" << qu.front().arivTime << "\t\t" << qu.front().hastime << "   \t" << qu.front().staTime << "   \t" << qu.front().endTime << "   \t" << qu.front().turnTime << "\t" << qu.front().wtaTime << "\t" << endl;
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
	cout << "进程调度RR算法模拟结果" << endl;
	runRRProcess(Proc, n);
	system("pause");
}*/
