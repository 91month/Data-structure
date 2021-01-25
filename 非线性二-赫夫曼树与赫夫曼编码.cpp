//�㷨5.11 ���ݺշ�������շ�������
//�շ���������
#include<iostream>
#include<string.h>
using namespace std;
typedef struct
{
unsigned int weight;
unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree; // �洢�շ������� HT��P139 ͼ��

typedef char **HuffmanCode; // �洢�շ�������� HC��P139 ͼ����ά���飩

//���� i �������Ȩֵ��С�����ĸ�������
int min(HuffmanTree t,int i)
{ // ���� i �������Ȩֵ��С�����ĸ������ţ����溯�� select( )����
	int j, flag;
	unsigned int k=UINT_MAX; // ȡ k Ϊ��С�ڿ��ܵ�ֵ(�޷����������ֵ)
	for(j=1;j<=i; j++)
	if(t[j].weight<k && t[j].parent==0) // t[j]�����ĸ����
	{
	    k=t[j].weight; //���� K ��ֵ
		flag=j; //��С���ֵ�����
	}
	t[flag].parent=1; // ��ѡ�еĸ�����˫�׸� 1������� 2 �β��Ҹý��
	return flag;
}

//�� i �������ѡ�� 2 ��Ȩֵ��С�����ĸ�������
void Select(HuffmanTree t,int i,int &s1,int &s2)
{ // �� i �������ѡ�� 2 ��Ȩֵ��С�����ĸ������ţ�
	//s1 Ϊ�������С���Ǹ�
	int j;
	s1=min(t,i); //��С������
	s2=min(t,i); //��С������
	if(s1>s2){
        j=s1;
        s1=s2;
        s2=j;
	}
}

//����շ����� HT
void CreatHuffmanTree(HuffmanTree &HT,int n)
{
	int m,s1,s2,i;
	if(n<=1) return;
	m=2*n-1;
	HT=new HTNode[m+1]; //0 �ŵ�Ԫδ�ã�������Ҫ��̬���� m+1 ����Ԫ
	for(i=1;i<=m;++i) //�� 1~m �ŵ�Ԫ�е�˫�ס����ӣ��Һ��ӵ��±궼��ʼ��Ϊ 0
	{
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	cout<<"������Ҷ�ӽ���Ȩֵ�� \n";
	for(i=1;i<=n;++i){
        cin>>HT[i].weight;
	}
	for(i=n+1;i<=m;++i){//����
        Select(HT,i-1,s1,s2);
        HT[s1].parent=i;HT[s2].parent=i;
        HT[i].lchild=s1;HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	//���²������, ��� P138 �㷨��
}

//��Ҷ�ӵ���������ÿ���ַ��ĺշ������룬�洢�ڱ���� HC ��
void CreatHuffmanCode(HuffmanTree &HT,HuffmanCode &HC,int n) // ���� HC
{
	int i,start,c,f;
	HC=new char*[n+1]; //���� n ���ַ������ͷָ��ʸ��
	char *cd=new char[n]; //������ʱ��ű���Ķ�̬����ռ�
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
	//���²������, ��� P141 �㷨��
}

//��ʾ�շ�������ֵ
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
	cout<<"������Ҷ�ӽ��ĸ����� \n";
	cin>>n;
	CreatHuffmanTree(HT,n);
	CreatHuffmanCode(HT,HC,n);
	show(HT,HC,n);//�������
}
