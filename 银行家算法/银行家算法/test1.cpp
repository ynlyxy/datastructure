#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
/*bool isSafeSystem(int p, int r, vector<int> AV, vector<vector<int>> AL, vector<vector<int>>Need)
{
	vector<int> work(AV);
	vector<bool> finished(p, false);//�����Ƿ����
	vector<int>SafeOrder(p, -1);//��ȫ����
	int sum = 0;//���������Դ�ĸ���
	int finishnum = 0;//���������Ѿ����з���Ľ��̵ĸ���
	int i = 0;
	while (i < p)
	{
		sum = 0;
		for (int j = 0; j < r; ++j)
		{
			if (Need[i][j] <= work[j] && finished[i] == false)
			{
				++sum;//ÿ�������������Դ������
			}
			else
			{
				break;
			}
		}
		//�����̶�Ӧ��������Դ�����������ǣ��Ѵ˽��̵Ľ��������ӵ���ȫ������
		if (sum == r)
		{
			finished[i] = true;
			SafeOrder[finishnum] = i;
			++finishnum;
			for (int j = 0; j < r; ++j)
			{
				work[j] += AL[i][j];
			}
			i = 0;//�ҵ����������Ľ��̣�����Ҫ��ͷ����
		}
		else
		{
			++i;
		}
		if (finishnum == p)
		{
			cout << "��״̬�´��ڰ�ȫ״̬������" << endl;
			cout << "��ȫ����Ϊ�� ";
			cout << "P" << SafeOrder[0] << "-->";
			for (int m = 1; m < p; ++m)
			{
				cout << "P" << SafeOrder[m];
			}
			cout << endl;
			return true;
		}
	}
	cout << "��״̬�ǲ���ȫ״̬������" << endl;
	return false;
}
int main()
{
	int P;//���̸���
	int R;//��Դ����
	cout << "��������̸���" << endl;
	cin >> P;
	cout << "��������Դ����" << endl;
	cin >> R;
	vector<int> AV(R);//Ŀǰϵͳ���е���Դ�������
	cout << "***���뵱ǰ��������Դ��!***(eg:1 2 3 )" << endl;
	for (int i = 0; i < R; ++i)
	{
		cin >> AV[i];
	}
	vector<vector<int>> AL(P, vector<int>(R, 0));//�ѷ������
	cout << "*****�����ѷ������*****" << endl;
	for (int i = 0; i <P; ++i)
	{
		for (int j = 0; j < R; ++j)
		{
			cin >> AL[i][j];
		}
	}
	vector<vector<int>> Need(P, vector<int>(R, 0));//�������
	cout << "*****�����������*****" << endl;
	for (int i = 0; i < P; ++i)
	{
		for (int j = 0; j < R; ++j)
		{
			cin >> Need[i][j];
		}
	}
	vector<vector<int>> Max(P, vector<int>(R, 0));//���������
	cout << "*****���������*****" << endl;
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
	isSafeSystem(P, R, AV, AL, Need);
	system("pause");
	return 0;
}*/