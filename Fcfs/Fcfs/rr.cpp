#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<queue>
using namespace std;
//���̽ṹ��
/*struct process
{
	string name;//������
	float arivTime;//����ʱ��
	float runTime;//��������ʱ��
	float staTime;//���̿�ʼִ��ʱ��
	float endTime;//�������ʱ��
	float turnTime;//������תʱ��
	float wtaTime;//��Ȩ��תʱ��
	float hastime;//��ʾ��ǰ�����Ѿ������˶���ʱ��
	int flag = 0;//���̻�û��ִ�����
	int qucome = 0;//��ʾ�����Ƿ�����������
	int sum = 0;//��ʾ���̽�����еĴ���
};
//���������Ϣ
void printProcess(process *F, int n)
{
	cout << "������ ����ʱ��    ִ��ʱ�� ��ʼʱ�� ����ʱ�� ��תʱ�� ��Ȩ��תʱ��" << endl;
	for (int i = 0; i<n; i++)
	{
		cout << F[i].name << "\t" << F[i].arivTime << "\t\t" << F[i].runTime << "   \t" << F[i].staTime << "   \t" << F[i].endTime << "   \t" << F[i].turnTime << "\t" << F[i].wtaTime << "\t" << endl;
	}
}
//���������Ϣ
void input(process *F, int n)
{
	cout << endl << "��������" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << "�������" << i + 1 << "�����̵����֡�����ʱ�䡢����ʱ��(����:A 12 8):";
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
//���յ���ʱ���������
void sortProcess(process *F, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (F[j].arivTime < F[i].arivTime)
			{
				string Na;
				int aT, rT;//����ڵ���Ϣ
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
	cout << "������ʱ��Ƭ��С��";
	cin >> r;
	int Time = 0;//��ǰʱ��
	queue<process> qu;
	while (qu.empty())//���Ȱѵ�һ������Ľ��̶���
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
		if (qu.front().runTime <= r && qu.front().flag == 0)//�����ǰִ�еĽ��̵�����ʱ��С��һ��ʱ��Ƭ����������ʱ��ִ�к��˳�����
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
			qu.front().flag = 1;//�˳���ִ�����
			//�鿴��ǰ������еĽ��У��Ͷ���
			for (int i = 1; i < n; ++i)
			{
				if (F[i].arivTime <= Time && F[i].qucome <= 0)
				{
					++F[i].sum;
					F[i].qucome = 1;
					qu.push(F[i]);
				}
			}
			cout << "������ ����ʱ��    ִ��ʱ�� ��ʼʱ�� ����ʱ�� ��תʱ�� ��Ȩ��תʱ��" << endl;
			cout << qu.front().name << "\t" << qu.front().arivTime << "\t\t" << qu.front().hastime << "   \t" << qu.front().staTime << "   \t" << qu.front().endTime << "   \t" << qu.front().turnTime << "\t" << qu.front().wtaTime << "\t" << endl;
			qu.pop();
		}
		else
		{
			//qu.front().staTime = Time;
			Time += r;
			qu.front().endTime = Time;
			qu.front().runTime -= r;
			//�鿴��ǰ������еĽ��У��Ͷ���
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
	cout << "��������ҵ����";
	cin >> n;
	input(Proc, n);
	printProcess(Proc, n);
	sortProcess(Proc, n);
	cout << "���̵���RR�㷨ģ����" << endl;
	runRRProcess(Proc, n);
	system("pause");
}*/
