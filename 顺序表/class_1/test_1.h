#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<assert.h>
typedef int SLdatatype;
//静态开辟
/*#define LIST_INIT_SIZE 50
typedef struct Seqlist{
	Seqlist array[LIST_INIT_SIZE];//定长数组
	int _size;
}Seqlist;*/
//动态开辟
typedef struct Seqlist{
	SLdatatype* arr;//指向动态开辟的数组
	int _size;//有效数据个数
	int _capacity;//容量空间的大小
}Seqlist;
void SeqlistInit(Seqlist* psl);
void SeqlistDestory(Seqlist* psl);
//尾插
void Seqlistpushback(Seqlist* psl, SLdatatype x);
//尾删
void Seqlistpopback(Seqlist* psl);
void Seqlistprintf(Seqlist* psl);
//插入
void SeqListInsert(Seqlist* psl, size_t pos, SLdatatype x);

//检查容量
void CheckCapacity(Seqlist* psl);
//头插
void SeqListPushFront(Seqlist* psl, SLdatatype x);
//头删
void SeqListPopFront(Seqlist* psl);
//查找
void SeqListFind(Seqlist* psl, SLdatatype x);
//删除任意位置
void SeqListErase(Seqlist* psl, size_t pos);