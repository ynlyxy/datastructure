#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include<queue>
using namespace std;
//���̽ṹ��
struct process
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
	for (int i = 0; i<n - 1; i++)
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
//FCFS�㷨����ģ��
void runProcess(process *F, int n)
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
//SJF����ģ��
void runSFJProcess(process *A, int n)
{
	int CurrentTime = 0;//��ǰʱ��
	int num = 0;//��ҵ��
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
			int sum = 0;//ͳ�Ƶ�ǰ��ִ�н��̵ĸ���
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
				int minprocess;//���浱ǰ�ҵ���С����ʱ�����ҵ������
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
//ʱ��Ƭ���������
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
	cout << "������ ����ʱ��    ִ��ʱ�� ��ʼʱ�� ����ʱ�� ��תʱ�� ��Ȩ��תʱ��" << endl;
	for (int i = 0; i<n; i++)
	{
		cout << F[i].name << "\t" << F[i].arivTime << "\t\t" << F[i].hastime << "   \t" << F[i].staTime << "   \t" << F[i].endTime << "   \t" << F[i].turnTime << "\t" << F[i].wtaTime << "\t" << endl;
	}
}
void runRRProcess(process* F, int n)
{
	int r;
	cout << "������ʱ��Ƭ��С��";
	cin >> r;
	int Time = 0;//��ǰʱ��
	process tmp[10];//����ִ����ɵĽ���
	for (int i = 0; i < n; ++i)
	{
		tmp[i] = F[i];
	}
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
		if (qu.front().runTime <= r)//�����ǰִ�еĽ��̵�����ʱ��С��һ��ʱ��Ƭ����������ʱ��ִ�к��˳�����
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
			//���浽tmp������
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
	printProcess1(tmp, n);
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
	int ret;
	cout << "��ѡ��һ���㷨��" << endl;
	cout << "0.�˳�����" << endl;
	cout << "1.FCFS�㷨" << endl;
	cout << "2.SFJ�㷨" << endl;
	cout << "3.RR�㷨" << endl;
	while (cin >> ret)
	{
		switch (ret)
		{
		case 0:
			exit(0);
		case 1:
			cout << "���̵���FCFS�㷨ģ����" << endl;
			runProcess(Proc, n);
			printProcess(Proc, n);
			break;
		case 2:
			cout << "���̵���SJF�㷨ģ����" << endl;
			runSFJProcess(Proc, n);
			printProcess(Proc, n);
			break;
		case 3:
			cout << "���̵���RR�㷨ģ����" << endl;
			runRRProcess(Proc, n);
		default:
			break;
		}
	}
	system("pause");
}