#include<iostream>
using namespace std;
#define MAXSIZE 100
#define OK 1;

typedef struct {
	int key;//�ؼ�����
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
		cout << "��ʼ������";
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
	int j = 1;//�ճ�ST.R[0]��λ��
	for (int i = 1; i < MAXSIZE; i++)
	{
		L.R[i].key = j;
		L.length++;
		j++;
	}
	return 1;
}

int Search_Seq1(SSTable ST, int key) {
	//��˳���ST��˳�������ؼ��ֵ���key������Ԫ�ء����ҵ�������ֵΪ
	//��Ԫ���ڱ��е�λ�ã�����Ϊ0
	for (int i = ST.length; i>=1; --i) {
		if (ST.R[i].key==key)
			return i;		//�Ӻ���ǰ��
	}
	return 0;
}// Search_Seq

int Search_Seq2(SSTable ST, int key) {
	//��˳���ST��˳�������ؼ��ֵ���key������Ԫ�ء����ҵ�������ֵΪ
	//��Ԫ���ڱ��е�λ�ã�����Ϊ0
	ST.R[0].key==key;  //���ڱ���
	int i = 0;
	for (i=ST.length;ST.R[i].key!=key;--i);		//�Ӻ���ǰ��
	return i;
}// Search_Seq2

int Search_Bin(SSTable ST, int key) {
	// �������ST���۰������ؼ��ֵ���key������Ԫ�ء����ҵ�������ֵΪ
	// ��Ԫ���ڱ��е�λ�ã�����Ϊ0
	int low = 1, high = ST.length;							//�ò��������ֵ
	int  mid;
	while (low<=high)
	{
		mid=(low+high)/2;
		if (key==ST.R[mid].key)
			return mid;      						//�ҵ�����Ԫ��
		else if (key<ST.R[mid].key)
			high=mid-1;							//������ǰһ�ӱ���в���
		else
			low=mid+1;                       	//�����ں�һ�ӱ���в���
	}//while
	return 0;										//���в����ڴ���Ԫ��
}// Search_Bin

void Show(int result, int testkey)
{
	if (result == 0)
		cout << "δ�ҵ�" << testkey << endl;
	else
		cout << "�ҵ�" << testkey << "λ��Ϊ" << result << endl;
	return;
}
int main()
{
	SSTable ST;
	int testkey1 = 7, testkey2 = 200;
	int result;

	InitList_SSTable(ST);      //��ʹ������ 1~ MAXSIZE �Ĳ��ұ�
	cout<<"-------------------1.˳�����-------------------\n";
	Insert_SSTable1(ST);
	result = Search_Seq1(ST, testkey1);
	Show(result, testkey1);     //��ʾ���ҽ��
	result = Search_Seq1(ST, testkey2);
	Show(result, testkey2);

	cout<<"-------------------2.�������ڵ�˳�����-------------------\n";
	InitList_SSTable(ST);
	Insert_SSTable2(ST); //���� 1~ MAXSIZE �Ĳ��ұ�
	result = Search_Seq2(ST, testkey1);
	Show(result, testkey1); //��ʾ���ҽ��
	result = Search_Seq2(ST, testkey2);
	Show(result, testkey2); //��ʾ���ҽ��

	cout<<"-------------------3.�۰����-------------------\n";
	InitList_SSTable(ST);
	Insert_SSTable2(ST); //���� 1~ MAXSIZE �Ĳ��ұ�
	result = Search_Bin(ST, testkey1);
	Show(result, testkey1); //��ʾ���ҽ��
	result = Search_Bin(ST, testkey2);
	Show(result, testkey2); //��ʾ���ҽ��

	/////////////////���º�������ѧ��ɣ�����Ҫ��//////////////////////////////
	/*cout<<"-------------------4.�ֿ����-------------------\n";
	Insert_SSTable1(ST);
	//result = Search_Block(ST, testkey1);
	//Show(result, testkey1);     //��ʾ���ҽ��
	//result = Search_Block(ST, testkey2);
	//Show(result, testkey2);

	getchar();
}




