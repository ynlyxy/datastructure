#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
struct process
{
	int id;//��ʾ������
	int data;//��ʾ������С
	int ad;//��ʾ������ַ
	int flag = 0;//��ʾ��ǰλ��û�д洢����
};
//��ʼ��������
void input(process *F, int n)
{
	cout << endl << "***********����������************" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout <<"������ ������С ������ַ(����:1 30 40):";
		cin >> F[i].id;
		cin >> F[i].data;
		cin >> F[i].ad;
	}
}
//�������
void printProcess(process *F, int n)
{
	cout << endl << "������  ������С   ������ַ" << endl;
	for (int i = 0; i<n; i++)
	{
		if (F[i].data != 0)
		{
			cout << F[i].id << "\t" << F[i].data << "\t\t" << F[i].ad << endl;
		}
	}
}
//���շ�����С�����������
void sortbigdata(process *F, int n) 
{
	process tmp[1];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (F[j + 1].data > F[j].data)
			{
				tmp[0] = F[j];
				F[j] = F[j + 1];
				F[j + 1] = tmp[0];
			}
		}
	}
}
void sortsamlldata(process *F, int n)
{
	process tmp[1];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (F[j + 1].data < F[j].data)
			{
				tmp[0] = F[j];
				F[j] = F[j + 1];
				F[j + 1] = tmp[0];
			}
		}
	}
}
void sortsamllad(process *F, int n) 
{
	process tmp[1];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (F[j + 1].ad < F[j].ad)
			{
				tmp[0] = F[j];
				F[j] = F[j + 1];
				F[j + 1] = tmp[0];
			}
		}
	}
}
int flag = 0;
int NF(job * P, int n, int part)
{
	for (int i = flag; i < n; i++)
	{
		if (P[i].partnum >= part)
		{
			P[i].partnum = P[i].partnum - part;
			P[i].partaddress = P[i].partaddress + part;
			flag = i + 1;
			if (flag >= n)
			{
				flag = flag % n;
			}
			return 0;
		}
	}
	return -1;
}


int FF(job * P, int n, int part)//�״���Ӧ�㷨
{

	for (int i = 0; i < n; i++)
	{
		if (P[i].partnum >= part)
		{
			P[i].partnum = P[i].partnum - part;
			P[i].partaddress = P[i].partaddress + part;
			return 0;
		}
	}
	return -1;
}

int BF(job * P, int n, int part)//�����Ӧ�㷨
{

	//smallsort(P, n); //�Ӵ�С���ҵ���һ����������ҵ����ļ�ֹͣ
	for (int i = 0; i < n; i++)
	{
		if (P[i].partnum >= part)
		{
			P[i].partnum = P[i].partnum - part;
			P[i].partaddress = P[i].partaddress + part;
			/*if (P[i].partnum < 5)
			{
			P[i].flag = 0;
			}*/
			//smallsort(P, n);
			return 0;
		}
	}
	return -1;
}
int WF(job *P, int n, int part) //���Ӧ�㷨
{
	for (int i = 0; i < n; i++)
	{
		if (P[i].partnum >= part)
		{
			P[i].partnum = P[i].partnum - part;
			P[i].partaddress = P[i].partaddress + part;
			/*if (P[i].partnum < 5)
			{
			P[i].flag = 0;
			}*/
			//smallsort(P, n);
			return 0;
		}
	}
	return -1;
}
int main()
{
	process P[100];
	int ret;
	cout << "���������������";
	cin >> ret;
	input(P, ret);
	printProcess(P, ret);
	int request;//���������ҵ��С
	int num;
	/*sortbigdata(P, ret);
	printProcess(P, ret);
	sortsamlldata(P, ret);
	printProcess(P, ret);
	sortsamllad(P, ret);
	printProcess(P, ret);*/
	system("pause");
	return 0;
}