#include<iostream>
using namespace std;
struct job
{
	int id;//������
	int partnum;//������С
	int partaddress;//����ʼַ
	//int flag = 1;//���Բ����ڴ滮�� Ϊ0 ��ʾ�����Բ����ڴ滮��
};
void Print(job *P, int n) //��ӡ�����������ҵ���ʱ�䡣������
{
	cout << "������" << "  " << "������С" << " " << "����ʼַ" << endl;
	for (int i = 0; i < n; i++)
	{
		if (P->partnum != 0)
		{
			cout << P->id << "\t" << P->partnum << "\t" << P->partaddress << endl;
		}
		P++;
	}
}
void bigsortaddress(job * P, int n) //��ַ����
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if ((P + j)->partaddress >(P + j + 1)->partaddress)
			{
				string tmp;
				int tmp1;
				int tmp2;

				tmp1 = (P + j)->partnum;
				(P + j)->partnum = (P + j + 1)->partnum;
				(P + j + 1)->partnum = tmp1;

				tmp2 = (P + j)->partaddress;
				(P + j)->partaddress = (P + j + 1)->partaddress;
				(P + j + 1)->partaddress = tmp2;
			}
		}
	}
}
void smallsort(job * P, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if ((P + j)->partnum >(P + j + 1)->partnum)
			{
				string tmp;
				int tmp1;
				int tmp2;

				tmp1 = (P + j)->partnum;
				(P + j)->partnum = (P + j + 1)->partnum;
				(P + j + 1)->partnum = tmp1;

				tmp2 = (P + j)->partaddress;
				(P + j)->partaddress = (P + j + 1)->partaddress;
				(P + j + 1)->partaddress = tmp2;
			}
		}
	}
}
void bigsort(job * P, int n) //������С����
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if ((P + j)->partnum <(P + j + 1)->partnum)
			{
				string tmp;
				int tmp1;
				int tmp2;

				tmp1 = (P + j)->partnum;
				(P + j)->partnum = (P + j + 1)->partnum;
				(P + j + 1)->partnum = tmp1;

				tmp2 = (P + j)->partaddress;
				(P + j)->partaddress = (P + j + 1)->partaddress;
				(P + j + 1)->partaddress = tmp2;
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



//int main()
//{
//	int n;//�����������Էż�����ҵ
//	cout << "�����������ĳ���" << endl;
//	cin >> n;
//	job P[100];
//	cout << "����������� ������С ����ʼַ" << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> P[i].id >> P[i].partnum >> P[i].partaddress;
//	}
//	int Part;
//	int num;
//	cout << "1:BF  2:WF  3:FF  4:NF " << endl;
//	cout << "������Ҫ���е��㷨ѡ��->";
//	cin >> num;
//	switch (num)
//	{
//	case 1:
//		while (1)
//		{
//			smallsort(P, n);
//			cout << "���з�����" << endl;
//			Print(P, n);
//			cout << "������Ҫ�������ҵ��С" << endl;
//			cin >> Part;
//			if (!(BF(P, n, Part)))
//			{
//				Print(P, n);
//			}
//			else
//			{
//				cout << "�ڴ����ʧ��" << endl;
//			}
//			int go;
//			cout << "�Ƿ�Ҫ�������� �� 1->��  2->��" << endl;
//			cin >> go;
//			if (go == 2)
//			{
//				break;
//			}
//
//		}
//
//		break;
//	case 2:
//		while (1)
//		{
//			bigsort(P, n);
//			cout << "���з�����" << endl;
//			Print(P, n);
//			cout << "������Ҫ�������ҵ��С" << endl;
//			cin >> Part;
//			if (!(WF(P, n, Part)))
//			{
//				Print(P, n);
//			}
//			else
//			{
//				cout << "�ڴ����ʧ��" << endl;
//			}
//			int go;
//			cout << "�Ƿ�Ҫ�������� �� 1->��  2->��" << endl;
//			cin >> go;
//			if (go == 2)
//			{
//				break;
//			}
//		}
//		break;
//	case 3:
//		while (1)
//		{
//			bigsortaddress(P, n);
//			cout << "���з�����" << endl;
//			Print(P, n);
//			cout << "������Ҫ�������ҵ��С" << endl;
//			cin >> Part;
//			if (!(FF(P, n, Part)))
//			{
//				Print(P, n);
//			}
//			else
//			{
//				cout << "�ڴ����ʧ��" << endl;
//			}
//			int go;
//			cout << "�Ƿ�Ҫ�������� �� 1->��  2->��" << endl;
//			cin >> go;
//			if (go == 2)
//			{
//				break;
//			}
//		}
//		break;
//	case 4:
//		while (1)
//		{
//			bigsortaddress(P, n);
//			cout << "���з�����" << endl;
//			Print(P, n);
//			cout << "������Ҫ�������ҵ��С" << endl;
//			cin >> Part;
//			if (!(NF(P, n, Part)))
//			{
//				Print(P, n);
//			}
//			else
//			{
//				cout << "�ڴ����ʧ��" << endl;
//			}
//			int go;
//			cout << "�Ƿ�Ҫ�������� �� 1->��  2->��" << endl;
//			cin >> go;
//			if (go == 2)
//			{
//				break;
//			}
//		}
//		break;
//	default:
//		break;
//	}
//	system("pause");
//	return 0;
//}