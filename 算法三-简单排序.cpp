//算法8.1 直接插入排序
#include <iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
#define  MAXSIZE  20          						//顺序表的最大长度
typedef struct
{
	int key;                //排序关键字
	char *otherinfo;		//其他数据项，可无
}ElemType;

//顺序表的存储结构
typedef struct
{
    ElemType *r;	         						//存储空间的基地址
    int  length;            						//顺序表长度
}SqList;											//顺序表类型

void Create_Sq(SqList &L)
{
	int i,n;
	cout<<"请输入数据个数，不超过"<<MAXSIZE<<"个。"<<endl;
	cin>>n;											//输入个数
	cout<<"请输入待排序的数据:\n";
	while(n>MAXSIZE)
	{
		cout<<"个数超过上限，不能超过"<<MAXSIZE<<"，请重新输入"<<endl;
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

//case：1
void InsertSort(SqList &L)
{
   //对顺序表L做直接插入排序
	int i,j;
	for(i=2;i<=L.length;++i)
		if(L.r[i].key<L.r[i-1].key)
		{   										//"<"，需将r[i]插入有序子表
			L.r[0]=L.r[i];				 			//将待插入的记录暂存到监视哨中
            L.r[i]=L.r[i-1];	            		//r[i-1]后移
            for(j=i-2; L.r[0].key<L.r[j].key;--j)	//从后向前寻找插入位置
				L.r[j+1]=L.r[j];					//记录逐个后移，直到找到插入位置
            L.r[j+1]=L.r[0];						//将r[0]即原r[i]，插入到正确位置
		}											//if
}													//InsertSort

//case：2
void BInsertSort(SqList &L){
	//对顺序表L做折半插入排序
	int i,j,low,high,m;
	for(i=2;i<=L.length;++i)
	{
		L.r[0]=L.r[i];          					//将待插入的记录暂存到监视哨中
		low=1;
		high=i-1;        					        //置查找区间初值
		while(low<=high)
		{											//在r[low..high]中折半查找插入的位置
			m=(low+high)/2;             			//折半
			if(L.r[0].key<L.r[m].key)  high=m-1;	//插入点在前一子表
			else  low=m+1;					   		//插入点在后一子表
		}//while
		for(j=i-1;j>=high+1;--j)
		{
			L.r[j+1]=L.r[j];	//记录后移
		}
		L.r[high+1]=L.r[0];					//将r[0]即原r[i]，插入到正确位置
    }												//for
}													//BInsertSort

void ShellInsert(SqList &L,int dk)
{
	//对顺序表L做一趟增量是dk的希尔插入排序
	int i,j;
	for(i=dk+1;i<=L.length;++i)
	{
		if(L.r[i].key<L.r[i-dk].key)
		{										//需将L.r[i]插入有序增量子表
			L.r[0]=L.r[i];						//暂存在L.r[0]
			for(j=i-dk;j>0&& L.r[0].key<L.r[j].key;j-=dk)
			{
				L.r[j+dk]=L.r[j];				//记录后移，直到找到插入位置
			}
			L.r[j+dk]=L.r[0];					//将r[0]即原r[i]，插入到正确位置
		}
    }//for
}

//case：3											//ShellInsert
void ShellSort(SqList &L,int dt[ ],int t){
   //按增量序列dt[0..t-1]对顺序表L作t趟希尔排序
	int k;
    for(k=0;k<t;++k)
        ShellInsert(L,dt[k]);			 		//一趟增量为dt[t]的希尔插入排序
}												//ShellSort

//case：4
void BubbleSort(SqList &L)
{
	//对顺序表L做冒泡排序
	int m,j,flag;
	ElemType t;
    m=L.length-1; flag=1; 				//flag用来标记某一趟排序是否发生交换
    while((m>0)&&(flag==1))
	{
		flag=0;           				//flag置为0，如果本趟排序没有发生交换，则不会执行下一趟排序
        for(j=1;j<=m;j++)
			if(L.r[j].key>L.r[j+1].key)
			{
				flag=1;					//flag置为1，表示本趟排序发生了交换
				t=L.r[j];L.r[j]=L.r[j+1];L.r[j+1]=t;  //交换前后两个记录
			}							//if
		--m;
    }									//while
}										//BubbleSort

int Partition(SqList &L,int low,int high)
{
	//对顺序表L中的子表r[low..high]进行一趟排序，返回枢轴位置
	int pivotkey;
	L.r[0]=L.r[low];                    	//用子表的第一个记录做枢轴记录
	pivotkey=L.r[low].key;		   			//枢轴记录关键字保存在pivotkey中
	while(low<high)
	{										//从表的两端交替地向中间扫描
		while(low<high&& L.r[high].key>=pivotkey)
			--high;
		L.r[low]=L.r[high];					//将比枢轴记录小的记录移到低端
		while(low<high&&L.r[low].key<=pivotkey)
			++low;
		L.r[high]=L.r[low]	;					//将比枢轴记录大的记录移到高端
	}//while
	L.r[low]=L.r[0];						//枢轴记录到位
	return  low;							//返回枢轴位置
}//Partition

void QSort(SqList &L,int low,int high)
{	//调用前置初值：low=1; high=L.length;
    //对顺序表L中的子序列L.r[low..high]做快速排序
	int pivotloc;
    if(low<high)
	{										//长度大于1
       pivotloc=Partition(L,low,high); 		//将L.r[low..high]一分为二，pivotloc是枢轴位置
       QSort(L,low,pivotloc-1)	;				//对左子表递归排序
       QSort(L,pivotloc+1,high)	;        	//对右子表递归排序
	}
}											//QSort

//case 5：
void QuickSort(SqList &L)
{
   //对顺序表L做快速排序
   QSort(L,1,L.length);
}											//QuickSort

//case 6:
void SelectSort(SqList &L)
{
   //对顺序表L做简单选择排序
	int i,j,k;
	ElemType t;
    for(i=1;i<L.length;++i)
	{  												//在L.r[i..L.length] 中选择关键字最小的记录
		k=i;
        for(j=i+1;j<=L.length;++j)
			if(L.r[j].key<L.r[k].key)
				k=j;			                    //k指向此趟排序中关键字最小的记录
		if(k!=i)
		{
			t=L.r[i]; L.r[i]=L.r[k]; L.r[k]=t;
		} //交换r[i]与r[k]
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
		cout<<"1： 直接插入法排序： \n";
		cout<<"2： 折半插入法排序： \n";
		cout<<"3： 希尔排序： \n";
		cout<<"4： 冒泡法排序： \n";
		cout<<"5： 快速排序： \n";
		cout<<"6： 简单选择法排序： \n";
		cout<<"0： 结束： \n";
		cout<<"=========================================\n";
		cout << "请选择:";
		cin >> choose;
		switch (choose)
		{
		case 1:
			InsertSort(L);
			cout<<"排序后的结果为： "<<endl;
			show(L);
			break;

		case 2:
			BInsertSort(L);
			cout<<"排序后的结果为： "<<endl;
			show(L);
			break;

		case 3:
			{int i,t;//增量数组的长度
			int *dt=new int[MAXSIZE];//增量数组
			cout<<"请输入增量个数： \n";
			cin>>t;
			for(i=0;i<t;i++)
			{
				cout<<"第"<<i+1<<"个增量:\n";
				cin>>dt[i];
			}
			ShellSort(L,dt,t);
			cout<<"排序后的结果为： "<<endl;
			show(L);
			break;}

		case 4:
			BubbleSort(L);
			cout<<"排序后的结果为： "<<endl;
			show(L);
			break;

		case 5:
			QuickSort(L);
			cout<<"排序后的结果为： "<<endl;
			show(L);
			break;

		case 6:
			SelectSort (L);
			cout<<"排序后的结果为： "<<endl;
			show(L);
			break;

        default:
            break;
        }
        if(choose==0)
		{
			cout<<"运行结束， 谢谢使用！ \n";
			exit(0);
		}
    }while(choose!=0);
}
