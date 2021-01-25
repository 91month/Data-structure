//�㷨8.1 ֱ�Ӳ�������
#include <iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
#define  MAXSIZE  20          						//˳������󳤶�
typedef struct
{
	int key;                //����ؼ���
	char *otherinfo;		//�������������
}ElemType;

//˳���Ĵ洢�ṹ
typedef struct
{
    ElemType *r;	         						//�洢�ռ�Ļ���ַ
    int  length;            						//˳�����
}SqList;											//˳�������

void Create_Sq(SqList &L)
{
	int i,n;
	cout<<"���������ݸ�����������"<<MAXSIZE<<"����"<<endl;
	cin>>n;											//�������
	cout<<"����������������:\n";
	while(n>MAXSIZE)
	{
		cout<<"�����������ޣ����ܳ���"<<MAXSIZE<<"������������"<<endl;
		cin>>n;
	}
	for(i=1;i<=n;i++)
	{
		cin>>L.r[i].key;
		L.length++;
	}
}

void show(SqList L)
{
	int i;
	for(i=1;i<=L.length;i++)
		cout<<L.r[i].key<<endl;
}

//case��1
void InsertSort(SqList &L)
{
   //��˳���L��ֱ�Ӳ�������
	int i,j;
	for(i=2;i<=L.length;++i)
		if(L.r[i].key<L.r[i-1].key)
		{   										//"<"���轫r[i]���������ӱ�
			L.r[0]=L.r[i];				 			//��������ļ�¼�ݴ浽��������
            L.r[i]=L.r[i-1];	            		//r[i-1]����
            for(j=i-2; L.r[0].key<L.r[j].key;--j)	//�Ӻ���ǰѰ�Ҳ���λ��
				L.r[j+1]=L.r[j];					//��¼������ƣ�ֱ���ҵ�����λ��
            L.r[j+1]=L.r[0];						//��r[0]��ԭr[i]�����뵽��ȷλ��
		}											//if
}													//InsertSort

//case��2
void BInsertSort(SqList &L){
	//��˳���L���۰��������
	int i,j,low,high,m;
	for(i=2;i<=L.length;++i)
	{
		L.r[0]=L.r[i];          					//��������ļ�¼�ݴ浽��������
		low=1;
		high=i-1;        					        //�ò��������ֵ
		while(low<=high)
		{											//��r[low..high]���۰���Ҳ����λ��
			m=(low+high)/2;             			//�۰�
			if(L.r[0].key<L.r[m].key)  high=m-1;	//�������ǰһ�ӱ�
			else  low=m+1;					   		//������ں�һ�ӱ�
		}//while
		for(j=i-1;j>=high+1;--j)
		{
			L.r[j+1]=L.r[j];	//��¼����
		}
		L.r[high+1]=L.r[0];					//��r[0]��ԭr[i]�����뵽��ȷλ��
    }												//for
}													//BInsertSort

void ShellInsert(SqList &L,int dk)
{
	//��˳���L��һ��������dk��ϣ����������
	int i,j;
	for(i=dk+1;i<=L.length;++i)
	{
		if(L.r[i].key<L.r[i-dk].key)
		{										//�轫L.r[i]�������������ӱ�
			L.r[0]=L.r[i];						//�ݴ���L.r[0]
			for(j=i-dk;j>0&& L.r[0].key<L.r[j].key;j-=dk)
			{
				L.r[j+dk]=L.r[j];				//��¼���ƣ�ֱ���ҵ�����λ��
			}
			L.r[j+dk]=L.r[0];					//��r[0]��ԭr[i]�����뵽��ȷλ��
		}
    }//for
}

//case��3											//ShellInsert
void ShellSort(SqList &L,int dt[ ],int t){
   //����������dt[0..t-1]��˳���L��t��ϣ������
	int k;
    for(k=0;k<t;++k)
        ShellInsert(L,dt[k]);			 		//һ������Ϊdt[t]��ϣ����������
}												//ShellSort

//case��4
void BubbleSort(SqList &L)
{
	//��˳���L��ð������
	int m,j,flag;
	ElemType t;
    m=L.length-1; flag=1; 				//flag�������ĳһ�������Ƿ�������
    while((m>0)&&(flag==1))
	{
		flag=0;           				//flag��Ϊ0�������������û�з����������򲻻�ִ����һ������
        for(j=1;j<=m;j++)
			if(L.r[j].key>L.r[j+1].key)
			{
				flag=1;					//flag��Ϊ1����ʾ�����������˽���
				t=L.r[j];L.r[j]=L.r[j+1];L.r[j+1]=t;  //����ǰ��������¼
			}							//if
		--m;
    }									//while
}										//BubbleSort

int Partition(SqList &L,int low,int high)
{
	//��˳���L�е��ӱ�r[low..high]����һ�����򣬷�������λ��
	int pivotkey;
	L.r[0]=L.r[low];                    	//���ӱ�ĵ�һ����¼�������¼
	pivotkey=L.r[low].key;		   			//�����¼�ؼ��ֱ�����pivotkey��
	while(low<high)
	{										//�ӱ�����˽�������м�ɨ��
		while(low<high&& L.r[high].key>=pivotkey)
			--high;
		L.r[low]=L.r[high];					//���������¼С�ļ�¼�Ƶ��Ͷ�
		while(low<high&&L.r[low].key<=pivotkey)
			++low;
		L.r[high]=L.r[low]	;					//���������¼��ļ�¼�Ƶ��߶�
	}//while
	L.r[low]=L.r[0];						//�����¼��λ
	return  low;							//��������λ��
}//Partition

void QSort(SqList &L,int low,int high)
{	//����ǰ�ó�ֵ��low=1; high=L.length;
    //��˳���L�е�������L.r[low..high]����������
	int pivotloc;
    if(low<high)
	{										//���ȴ���1
       pivotloc=Partition(L,low,high); 		//��L.r[low..high]һ��Ϊ����pivotloc������λ��
       QSort(L,low,pivotloc-1)	;				//�����ӱ�ݹ�����
       QSort(L,pivotloc+1,high)	;        	//�����ӱ�ݹ�����
	}
}											//QSort

//case 5��
void QuickSort(SqList &L)
{
   //��˳���L����������
   QSort(L,1,L.length);
}											//QuickSort

//case 6:
void SelectSort(SqList &L)
{
   //��˳���L����ѡ������
	int i,j,k;
	ElemType t;
    for(i=1;i<L.length;++i)
	{  												//��L.r[i..L.length] ��ѡ��ؼ�����С�ļ�¼
		k=i;
        for(j=i+1;j<=L.length;++j)
			if(L.r[j].key<L.r[k].key)
				k=j;			                    //kָ����������йؼ�����С�ļ�¼
		if(k!=i)
		{
			t=L.r[i]; L.r[i]=L.r[k]; L.r[k]=t;
		} //����r[i]��r[k]
     }												//for
}

int main()
{
	SqList L;
	L.r=new ElemType[MAXSIZE+1];
	L.length=0;
	int choose;
	Create_Sq(L);

	do{
		cout<<"=========================================\n";
		cout<<"1�� ֱ�Ӳ��뷨���� \n";
		cout<<"2�� �۰���뷨���� \n";
		cout<<"3�� ϣ������ \n";
		cout<<"4�� ð�ݷ����� \n";
		cout<<"5�� �������� \n";
		cout<<"6�� ��ѡ������ \n";
		cout<<"0�� ������ \n";
		cout<<"=========================================\n";
		cout << "��ѡ��:";
		cin >> choose;
		switch (choose)
		{
		case 1:
			InsertSort(L);
			cout<<"�����Ľ��Ϊ�� "<<endl;
			show(L);
			break;

		case 2:
			BInsertSort(L);
			cout<<"�����Ľ��Ϊ�� "<<endl;
			show(L);
			break;

		case 3:
			{int i,t;//��������ĳ���
			int *dt=new int[MAXSIZE];//��������
			cout<<"���������������� \n";
			cin>>t;
			for(i=0;i<t;i++)
			{
				cout<<"��"<<i+1<<"������:\n";
				cin>>dt[i];
			}
			ShellSort(L,dt,t);
			cout<<"�����Ľ��Ϊ�� "<<endl;
			show(L);
			break;}

		case 4:
			BubbleSort(L);
			cout<<"�����Ľ��Ϊ�� "<<endl;
			show(L);
			break;

		case 5:
			QuickSort(L);
			cout<<"�����Ľ��Ϊ�� "<<endl;
			show(L);
			break;

		case 6:
			SelectSort (L);
			cout<<"�����Ľ��Ϊ�� "<<endl;
			show(L);
			break;

        default:
            break;
        }
        if(choose==0)
		{
			cout<<"���н����� ллʹ�ã� \n";
			exit(0);
		}
    }while(choose!=0);
}
