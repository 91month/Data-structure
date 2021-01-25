//算法5.11 根据赫夫曼树求赫夫曼编码
//赫夫曼树定义
#include<iostream>
#include<string.h>
using namespace std;
typedef struct
{
unsigned int weight;
unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree; // 存储赫夫曼树： HT（P139 图）

typedef char **HuffmanCode; // 存储赫夫曼编码表： HC（P139 图，二维数组）

//返回 i 个结点中权值最小的树的根结点序号
int min(HuffmanTree t,int i)
{ // 返回 i 个结点中权值最小的树的根结点序号，后面函数 select( )调用
	int j, flag;
	unsigned int k=UINT_MAX; // 取 k 为不小于可能的值(无符号整型最大值)
	for(j=1;j<=i; j++)
	if(t[j].weight<k && t[j].parent==0) // t[j]是树的根结点
	{
	    k=t[j].weight; //更改 K 的值
		flag=j; //最小结点值的序号
	}
	t[flag].parent=1; // 给选中的根结点的双亲赋 1，避免第 2 次查找该结点
	return flag;
}

//在 i 个结点中选择 2 个权值最小的树的根结点序号
void Select(HuffmanTree t,int i,int &s1,int &s2)
{ // 在 i 个结点中选择 2 个权值最小的树的根结点序号，
	//s1 为其中序号小的那个
	int j;
	s1=min(t,i); //最小结点序号
	s2=min(t,i); //次小结点序号
	if(s1>s2){
        j=s1;
        s1=s2;
        s2=j;
	}
}

//构造赫夫曼树 HT
void CreatHuffmanTree(HuffmanTree &HT,int n)
{
	int m,s1,s2,i;
	if(n<=1) return;
	m=2*n-1;
	HT=new HTNode[m+1]; //0 号单元未用，所以需要动态分配 m+1 个单元
	for(i=1;i<=m;++i) //将 1~m 号单元中的双亲、左孩子，右孩子的下标都初始化为 0
	{
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	cout<<"请输入叶子结点的权值： \n";
	for(i=1;i<=n;++i){
        cin>>HT[i].weight;
	}
	for(i=n+1;i<=m;++i){//创建
        Select(HT,i-1,s1,s2);
        HT[s1].parent=i;HT[s2].parent=i;
        HT[i].lchild=s1;HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	//以下补充语句, 详见 P138 算法；
}

//从叶子到根逆向求每个字符的赫夫曼编码，存储在编码表 HC 中
void CreatHuffmanCode(HuffmanTree &HT,HuffmanCode &HC,int n) // 返回 HC
{
	int i,start,c,f;
	HC=new char*[n+1]; //分配 n 个字符编码的头指针矢量
	char *cd=new char[n]; //分配临时存放编码的动态数组空间
	cd[n-1]='\0';
	for(i=1;i<=n;++i){
        start=n-1;
        c=i;f=HT[i].parent;
        while(f!=0){
            --start;
            if(HT[f].lchild==c) cd[start]='0';
            else cd[start]='1';
            c=f;f=HT[f].parent;
        }
        HC[i]=new char[n-start];
        strcpy(HC[i],&cd[start]);
	}
	delete cd;
	//以下补充语句, 详见 P141 算法；
}

//显示赫夫曼编码值
void show(HuffmanTree HT,HuffmanCode HC,int n)
{
	for(int i=1;i<=n;i++)
        cout<<HC[i];
}

int main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int *w,n,i;
	cout<<"请输入叶子结点的个数： \n";
	cin>>n;
	CreatHuffmanTree(HT,n);
	CreatHuffmanCode(HT,HC,n);
	show(HT,HC,n);//输出编码
}
