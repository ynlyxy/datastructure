#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
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
};
//���������Ϣ
void printProcess(process *F,int n)
{
	cout << "������ ����ʱ��    ִ��ʱ�� ��ʼʱ�� ����ʱ�� ��תʱ�� ��Ȩ��תʱ��" << endl;
	for (int i = 0; i<n; i++)
	{
		cout << F[i].name << "\t" << F[i].arivTime << "\t\t" << F[i].runTime << "   \t" << F[i].staTime << "   \t" << F[i].endTime << "   \t" << F[i].turnTime << "\t" << F[i].wtaTime << "\t" << endl;
	}
}
//���յ���ʱ���������
void sortProcess(process *F,int n)
{
	for (int i = 0; i<n-1; i++)
	{
		for (int j = i + 1; j<n; j++)
		{
			if (F[j].arivTime<F[i].arivTime)
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
//����ģ��
void runProcess(process *F,int n)
{
	//��ǰʱ��
	int time = 0;
	//��ҵ��
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
	cout << "���ھ������н�����Ϣ" << endl;
	sortProcess(Proc,n);
	printProcess(Proc,n);
	cout << endl;
	cout << "���̵���FCFS�㷨ģ����" << endl;
	runProcess(Proc,n);
	printProcess(Proc, n);
	system("pause");
}*/