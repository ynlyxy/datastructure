#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<assert.h>
typedef int SLdatatype;
//��̬����
/*#define LIST_INIT_SIZE 50
typedef struct Seqlist{
	Seqlist array[LIST_INIT_SIZE];//��������
	int _size;
}Seqlist;*/
//��̬����
typedef struct Seqlist{
	SLdatatype* arr;//ָ��̬���ٵ�����
	int _size;//��Ч���ݸ���
	int _capacity;//�����ռ�Ĵ�С
}Seqlist;
void SeqlistInit(Seqlist* psl);
void SeqlistDestory(Seqlist* psl);
//β��
void Seqlistpushback(Seqlist* psl, SLdatatype x);
//βɾ
void Seqlistpopback(Seqlist* psl);
void Seqlistprintf(Seqlist* psl);
//����
void SeqListInsert(Seqlist* psl, size_t pos, SLdatatype x);

//�������
void CheckCapacity(Seqlist* psl);
//ͷ��
void SeqListPushFront(Seqlist* psl, SLdatatype x);
//ͷɾ
void SeqListPopFront(Seqlist* psl);
//����
void SeqListFind(Seqlist* psl, SLdatatype x);
//ɾ������λ��
void SeqListErase(Seqlist* psl, size_t pos);