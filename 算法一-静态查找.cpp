#include<iostream>
using namespace std;
#define MAXSIZE 100
#define OK 1;

typedef struct {
	int key;//关键字域
}ElemType;

typedef struct {
	ElemType *R;
	int length;
}SSTable;

int InitList_SSTable(SSTable &L)
{
	L.R = new ElemType[MAXSIZE];
	if (!L.R)
	{
		cout << "初始化错误";
		return 0;
	}
	L.length = 0;
	return OK;
}

int Insert_SSTable1(SSTable &L)
{
	int j = 0;
	for (int i = 0; i < MAXSIZE; i++)
	{
		L.R[i].key = j;
		L.length++;
		j++;
	}
	return 1;
}

int Insert_SSTable2(SSTable &L)
{
	int j = 1;//空出ST.R[0]的位置
	for (int i = 1; i < MAXSIZE; i++)
	{
		L.R[i].key = j;
		L.length++;
		j++;
	}
	return 1;
}

int Search_Seq1(SSTable ST, int key) {
	//在顺序表ST中顺序查找其关键字等于key的数据元素。若找到，则函数值为
	//该元素在表中的位置，否则为0
	for (int i = ST.length; i>=1; --i) {
		if (ST.R[i].key==key)
			return i;		//从后往前找
	}
	return 0;
}// Search_Seq

int Search_Seq2(SSTable ST, int key) {
	//在顺序表ST中顺序查找其关键字等于key的数据元素。若找到，则函数值为
	//该元素在表中的位置，否则为0
	ST.R[0].key==key;  //“哨兵”
	int i = 0;
	for (i=ST.length;ST.R[i].key!=key;--i);		//从后往前找
	return i;
}// Search_Seq2

int Search_Bin(SSTable ST, int key) {
	// 在有序表ST中折半查找其关键字等于key的数据元素。若找到，则函数值为
	// 该元素在表中的位置，否则为0
	int low = 1, high = ST.length;							//置查找区间初值
	int  mid;
	while (low<=high)
	{
		mid=(low+high)/2;
		if (key==ST.R[mid].key)
			return mid;      						//找到待查元素
		else if (key<ST.R[mid].key)
			high=mid-1;							//继续在前一子表进行查找
		else
			low=mid+1;                       	//继续在后一子表进行查找
	}//while
	return 0;										//表中不存在待查元素
}// Search_Bin

void Show(int result, int testkey)
{
	if (result == 0)
		cout << "未找到" << testkey << endl;
	else
		cout << "找到" << testkey << "位置为" << result << endl;
	return;
}
int main()
{
	SSTable ST;
	int testkey1 = 7, testkey2 = 200;
	int result;

	InitList_SSTable(ST);      //初使化生成 1~ MAXSIZE 的查找表
	cout<<"-------------------1.顺序查找-------------------\n";
	Insert_SSTable1(ST);
	result = Search_Seq1(ST, testkey1);
	Show(result, testkey1);     //显示查找结果
	result = Search_Seq1(ST, testkey2);
	Show(result, testkey2);

	cout<<"-------------------2.带监视哨的顺序查找-------------------\n";
	InitList_SSTable(ST);
	Insert_SSTable2(ST); //生成 1~ MAXSIZE 的查找表
	result = Search_Seq2(ST, testkey1);
	Show(result, testkey1); //显示查找结果
	result = Search_Seq2(ST, testkey2);
	Show(result, testkey2); //显示查找结果

	cout<<"-------------------3.折半查找-------------------\n";
	InitList_SSTable(ST);
	Insert_SSTable2(ST); //生成 1~ MAXSIZE 的查找表
	result = Search_Bin(ST, testkey1);
	Show(result, testkey1); //显示查找结果
	result = Search_Bin(ST, testkey2);
	Show(result, testkey2); //显示查找结果

	/////////////////以下函数可自学完成，不做要求//////////////////////////////
	/*cout<<"-------------------4.分块查找-------------------\n";
	Insert_SSTable1(ST);
	//result = Search_Block(ST, testkey1);
	//Show(result, testkey1);     //显示查找结果
	//result = Search_Block(ST, testkey2);
	//Show(result, testkey2);

	getchar();
}




