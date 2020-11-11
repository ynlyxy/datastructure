#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
void ouput(int p, int r, vector<int> AV, vector<vector<int>> AL, vector<vector<int>>Need)
{
	cout << "************Available************" << endl;
	for (int i = 0; i < r; ++i)
	{
		cout << AV[i] << " ";
	}
	cout << endl;
	cout << "**********Allocation************" << endl;
	for (int i = 0; i < p; ++i)
	{
		for (int j = 0; j < r; ++j)
		{
			cout << AL[i][j] << " ";
		}
		cout << endl;
	}
	cout << "************Need***************" << endl;
	for (int i = 0; i < p; ++i)
	{
		for (int j = 0; j < r; ++j)
		{
			cout << Need[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
bool isSafeSystem(int p, int r, vector<int> AV, vector<vector<int>> AL, vector<vector<int>>Need )
{
	vector<int> work(AV);
	vector<bool> finished(p,false);//�����Ƿ����
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
				++sum;//ÿ������ÿ���������Դ������
			}
			else
			{
				break;
			}
		}
		//�����̶�Ӧ��������Դ���������㣬�Ѵ˽��̵Ľ��������ӵ���ȫ������
		if (sum == r)
		{
			finished[i] = true;
			SafeOrder[finishnum] = i;
			++finishnum;
			for (int j = 0; j < r; ++j)
			{
				work[j] +=  AL[i][j];
			}
			i = 0;//�ҵ����������Ľ��̣�����Ҫ��ͷ����
		}
		else
		{
			++i;
		}
		if (finishnum == p)
		{
			cout << "******��״̬�´��ڰ�ȫ״̬������******" << endl;
			cout << "******��ȫ����Ϊ�� ";
			cout << "P" << SafeOrder[0] << " ";
			for (int m = 1; m < p; ++m)
			{
				cout << "P" << SafeOrder[m] <<" ";
			}
			cout << endl;
			//ouput2(p, r, AV, AL, Need);
			return true;
		}
	}
	cout << "******��״̬�ǲ���ȫ״̬������******" << endl;
	return false;
}
void requestSafe(int p, int r, vector<int> AV, vector<vector<int>> AL, vector<vector<int>>Need)
{
	int chooseprocess;
	bool ret;
	char iscontinue;
	int flag = 1;//��ʾ��ǰ����Ϸ������Ե��ð�ȫ���㷨�����Է���
	vector<int> request(r);
	while (true)
	{
		cout << "******����Ҫ������Դ�Ľ��̺ţ����ڵ���0����������";
		cin >> chooseprocess;
		if (chooseprocess >= p)
		{
			cout << "������󣡣���,�������룡����";
			cout << "�Ƿ�����������룬�ǣ�Y������N��" << endl;
			cout << "iscontinue = ";
			cin >> iscontinue;
			if (iscontinue == 'Y')
			{
				continue;
			}
			else
			{
				break;
			}
		}
		cout << "*******����ý�����Ҫ����ĸ�����Դ��:";
		for (int i = 0; i < r; ++i)
		{
			cin >> request[i];
		}
		//���󲻺Ϸ�
		for (int i = 0; i < r; ++i)
		{
			if (request[i]>Need[chooseprocess][i])
			{
				cout << endl;
				cout << "******��ǰ��������̵�������Դ�������ڸý��̵�������******" << endl;
				cout << "******��ǰ�������Դ��Ŀ��";
				for (int j = 0; j < r; ++j)
				{
					cout << request[j] << " ";
				}
				cout << endl;
				cout << "******��ǰ����������Դ��Ŀ��";
				{
					for (int n = 0; n<r; ++n)
					{
						cout << Need[chooseprocess][n] << " ";
					}
				}
				cout << endl;
				flag = 0;
				break;
			}
			else if (request[i] > AV[i])
			{
				cout << endl;
				cout << "******��ǰ��������̵�������Դ��������ϵͳ������Դ�������̵ȴ�" << endl;
				cout << "******��ǰ�������Դ��Ŀ��";
				for (int j = 0; j < r; ++j)
				{
					cout << request[j] << " ";
				}
				cout << endl;
				cout << "��ǰϵͳ������Դ��Ŀ��";
				for (int m = 0; m < r;++m)
				{
					cout << AV[m] << " ";
				}
				cout << endl;
				flag = 0;
				break;
			}
			else
			{
				flag = 1;
			}
		}
		//���󲻺Ϸ����Ӧ�Ĵ���
		if (flag == 0)
		{
			cout << "******�Ƿ�����������룬�ǣ�Y������N��******" << endl;
			cout << "iscontinue = ";
			cin >> iscontinue;
			cout << endl;
			if (iscontinue == 'Y')
			{
			    continue;
			}
			else
			{
				break;
			}
		}
		//����Ϸ����Ӧ�Ĵ���
		else if (flag==1)
		{
			for (int j = 0; j < r; ++j)
			{
				AV[j] -= request[j];
				Need[chooseprocess][j] -= request[j];
				AL[chooseprocess][j] += request[j];
			}
			cout << "******************�Է�������Դ״����************" << endl;
			ouput(p, r, AV, AL, Need);
			cout << endl;
		}
		ret = isSafeSystem(p, r, AV, AL, Need);
		int RN = 1;//��ʾ�����������
		if (ret == true)
		{
			for (int j = 0; j < r; ++j)
			{
				if (Need[chooseprocess][j]!=0)
				{
					RN = 0;
					break;
				}
				AV[j] += AL[chooseprocess][j];
				Need[chooseprocess][j] = 0;
				AL[chooseprocess][j] = 0;
				RN = 1;
			}
			if (RN == 1)
			{
				cout << "******************��������Դ״����*****************" << endl;
				ouput(p, r, AV, AL, Need);
			}
		}
		//���������ϵͳ��ȫ���㷨����ظ���ԭ����״̬��
		if (ret == false)
		{
			cout << "��ǰ��������Դ���������κν��̵�����ϵͳ�����벻��ȫ״̬���ʲ��������Դ������" << endl;
			cout << "��Դ�ָ�" << endl;
			for (int j = 0; j < r; ++j)
			{
				AV[j] += request[j];
				Need[chooseprocess][j] += request[j];
				AL[chooseprocess][j] -= request[j];
			}
			cout << "*******************�ָ������Դ״����****************" << endl;
			ouput(p, r, AV, AL, Need);
		}
		cout << "�Ƿ������������������ԣ��ǣ�Y������N��" << endl;
		cout << "iscontinue = ";
		cin >> iscontinue;
		cout << endl;
		if (iscontinue == 'Y')
		{
			continue;
		}
		else
		{
			break;
		}
	}
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
	cout << "����Available����(eg:1 2 3 )" << endl;
	for (int i = 0; i < R; ++i)
	{
		cin >> AV[i];
	}
	vector<vector<int>> AL(P, vector<int>(R, 0));//�ѷ������
	cout << "******����Allocation����******" << endl;
	for (int i = 0; i <P; ++i)
	{
		for (int j = 0; j < R; ++j)
		{
			cin >> AL[i][j];
		}
	}
	vector<vector<int>> Need(P, vector<int>(R, 0));//�������
	cout << "******����Need����*******" << endl;
	for (int i = 0; i < P; ++i)
	{
		for (int j = 0; j < R; ++j)
		{
			cin >> Need[i][j];
		}
	}
	vector<vector<int>> Max(P, vector<int>(R, 0));//���������
	cout << "******Max����*******" << endl;
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
	cout << endl;
	isSafeSystem(P, R, AV, AL, Need);
	requestSafe(P, R, AV, AL, Need);
	system("pause");
	return 0;
}
