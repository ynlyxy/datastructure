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
	float turnTime;//����turnTime��תʱ��
	float wtaTime;//��Ȩ��תʱ��
	int flag = 0;
};
//��ӡ���н�����Ϣ
void printProcess(process *F, int n)
{
	cout << "������ ����ʱ��    ִ��ʱ�� ��ʼʱ�� ����ʱ�� ��תʱ�� ��Ȩ��תʱ��" << endl;
	for (int i = 0; i<n; i++)
	{
		cout << F[i].name << "\t" << F[i].arivTime << "\t\t" << F[i].runTime << "   \t" << F[i].staTime << "   \t" << F[i].endTime << "   \t" << F[i].turnTime << "\t" << F[i].wtaTime << "\t" << endl;
	}
}
//���յ���ʱ���������
void sortProcess(process *F, int n)
{
	for (int i = 0; i<n - 1; ++i)
	{
		for (int j = i + 1; j<n; ++j)
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
//����ģ��
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
int main()
{
	process Proc[1000];
	int n;
	cout << "��������ҵ����";
	cin >> n;
	input(Proc, n);
	printProcess(Proc, n);
	cout << "���̵���SFJ�㷨ģ����" << endl;
	sortProcess(Proc, n);
	runSFJProcess(Proc, n);
	//SortedByStartTime(Proc, n);
	printProcess(Proc, n);
	system("pause");
}*/