/***********************二叉树综合运算******************************/

#include<iostream>
#include<fstream>
using namespace std;
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
typedef int Status;  // Status是函数的类型
typedef char TElemType; // Boolean是布尔类型,其值是TRUE或FALSE

//二叉链表定义
typedef struct BiNode
{
	char data;
	struct BiNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef BiTree QElemType;
//链队列的定义
typedef struct QNode
{
	QElemType data;
	QNode *next;
}*QueuePtr;

typedef struct
{
	QueuePtr front,rear; // 队头、队尾指针
}LinkQueue;
/***************以下为队列常用运算函数*****************************/
//初始化队列
Status InitQueue(LinkQueue &Q)
{ // 构造一个空队列Q
    if(!(Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode))))
		exit(OVERFLOW);
	Q.front->next=NULL;
	return OK;
}
//入队
Status EnQueue(LinkQueue &Q,QElemType e)
{ // 插入元素e为Q的新的队尾元素
	QueuePtr p;
	if(!(p=(QueuePtr)malloc(sizeof(QNode))))
		exit(OVERFLOW);
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return OK;

}
//判断队空
Status QueueEmpty(LinkQueue Q)
{ // 若Q为空队列，则返回TRUE，否则返回FALSE
	if(Q.front->next==NULL)
		return TRUE;
	else
		return FALSE;
}
//出队
Status DeQueue(LinkQueue &Q,QElemType &e)
{ // 若队列不空，删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR
    QueuePtr p;
	if(Q.front==Q.rear)
		return ERROR;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)
		free(p);
	return OK;

}


void InitBiTree(BiTree &T)
{ // 操作结果：构造空二叉树T
	T=NULL;
}

Status BiTreeEmpty(BiTree T)
{ // 初始条件：二叉树T存在。操作结果：若T为空二叉树，则返回TRUE，否则FALSE
	if(T)
		return FALSE;
	else
		return TRUE;
}

/***************以下为二叉树综合运算函数*****************************/
//////////////销毁二叉树/////////////////////////////
void DestroyBiTree(BiTree T)
{ // 初始条件：二叉树T存在。操作结果：销毁二叉树T
	if(T) // 非空树
	{
		if(T->lchild) // 有左孩子
			DestroyBiTree(T->lchild); // 销毁左孩子子树
		if(T->rchild) // 有右孩子
			DestroyBiTree(T->rchild); // 销毁右孩子子树
		free(T); // 释放根结点
		T=NULL; // 空指针赋0
	}
}

////////////////把指针指向给定元素//////////////////
BiTree Point(BiTree T,TElemType s)
{ // 返回二叉树T中指向元素值为s的结点的指针。另加
	LinkQueue q;
	BiTree a;

	if(T) // 非空树
	{
		InitQueue(q); // 初始化队列
		EnQueue(q,T); // 根指针入队
		while(!QueueEmpty(q)) // 队不空
		{
			DeQueue(q,a); // 出队，队列元素赋给a
			if(a->data==s)
				return a;
			if(a->lchild) // 有左孩子
				EnQueue(q,a->lchild); // 入队左孩子
			if(a->rchild) // 有右孩子
				EnQueue(q,a->rchild); // 入队右孩子
		}
	}
	//  cout<<a->data<<endl;
	return NULL;
}

/////////////给指定结点赋值////////////////////////////////
void Assign(BiTree p,TElemType value)
{ // 给p所指结点赋值为value
    p->data=value;
}
////////////////求某结果左孩子的值，如无则返回空//////////////////////////
TElemType LeftChild(BiTree T,TElemType e)
{ // 初始条件：二叉树T存在，e是T中某个结点。操作结果：返回e的左孩子。若e无左孩子,则返回"空"
	BiTree a;
	if(T) // 非空树
	{
		a=Point(T,e); // a是结点e的指针
		if(a&&a->lchild) // T中存在结点e且e存在左孩子
			return a->lchild->data; //返回e的左孩子的值(补充语句.)
	}
	return ' '; // 其余情况返回空
}
////////////////求某结果右孩子的值，如无则返回空//////////////////////////
TElemType RightChild(BiTree T,TElemType e)
{ // 初始条件：二叉树T存在，e是T中某个结点。操作结果：返回e的右孩子。若e无右孩子,则返回"空"
	BiTree a;
	if(T) // 非空树
	{
		a=Point(T,e); // a是结点e的指针
		if(a&&a->rchild) // T中存在结点e且e存在右孩子
			return a->rchild->data; // 返回e的右孩子的值(补充语句.)
	}
	return ' '; // 其余情况返回空
}


///////////利用队列求取某结点双亲的值,如找不能，则返回空////////////////////////////////////
TElemType Parent(BiTree T,TElemType e)
{ // 初始条件：二叉树T存在，e是T中某个结点
	// 操作结果：若e是T的非根结点，则返回它的双亲，否则返回＂空＂
	LinkQueue q;
	BiTree  a; //BiTree QElemType a;
	if(T) // 非空树
	{
		InitQueue(q); // 初始化队列
		EnQueue(q,T); // 树根指针入队
		while(!QueueEmpty(q)) // 队不空
		{
			DeQueue(q,a); // 出队，队列元素赋给a
			if(a->lchild&&a->lchild->data==e||a->rchild&&a->rchild->data==e) // 找到e(是其左或右孩子)
				return a->data;        //返回e的双亲的值
			else // 没找到e，则入队其左右孩子指针(如果非空)
			{
				if(a->lchild)
					EnQueue(q,a->lchild);
				if(a->rchild)
					EnQueue(q,a->rchild);
			}
		}
	}
	return ' '; // 树空或没找到e
}

//////用算法5.3 先序遍历的顺序建立二叉链表//////////////////////
void CreateBiTree(BiTree &T)
{
	//按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T
	char ch;
	cin>>ch;
	if(ch=='#')  T=NULL;	//递归结束，建空树
	else
	{
		T=new BiTNode;
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);  //递归构造子树
	}
}
////////////中序遍历///////////////////////////
void InOrderTraverse(BiTree T)
{
	if(T)
	{
		InOrderTraverse(T->lchild);
		cout<<T->data;
		InOrderTraverse(T->rchild);
	}
	//中序遍历二叉树T的递归算法,补充语句.
}
////////////先序遍历///////////////////////////
void PreOrderTraverse(BiTree T)
{
	if(T)
	{
		cout<<T->data;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	//先序遍历二叉树T的递归算法，补充语句.
}
///////////////后序遍历/////////////////////////
void PostOrderTraverse(BiTree T)
{
	if(T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout<<T->data;
	}

	//后序遍历二叉树T的递归算法,补充语句.

}

//////////////求树深度////////////////////
int BiTreeDepth(BiTree T)
{
	int m,n;
	if(T == NULL ) return 0;
	else
	{	m=BiTreeDepth(T->lchild);
	n=BiTreeDepth(T->rchild);
	if(m>n) return (m+1);
	else return (n+1);
	}
}

//////////////求叶子数 /////////////////////
int LeadCount(BiTree T)
{
	if(T==NULL)
		return 0;
	else if(T->lchild==NULL && T->rchild==NULL)
		return 1;
	else
		return LeadCount(T->lchild)+LeadCount(T->rchild);
}
////////////////求结点数/////////////////////
int NodeCount(BiTree T)
{
	if(T==NULL)
		return 0;
	else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}
////////////////求根结点值//////////////////
TElemType Root(BiTree T)
{
	if(T)
		return T->data;
    else return ' ';
}

int main()
{
	BiTree T,p;
	TElemType e1,e2;
	int islelect;


	printf("请先序输入二叉树(P121图5.10(b)");
	CreateBiTree(T);


	e1=Root(T);
	if(e1!=' ')
		printf("二叉树的根为: %c\n",e1);
	else
		printf("树空，无根\n");
	cout<<"------------------------------------------------------\n";
	cout<<" 树的叶子数="<<LeadCount(T)<<endl;
	cout<<" 树的结点数="<<NodeCount(T)<<endl;
	cout<<" 树的叶深度="<<BiTreeDepth(T)<<endl;

	printf("\n先序递归遍历二叉树:\n");
	PreOrderTraverse(T);
	printf("\n中序递归遍历二叉树:\n");
	InOrderTraverse(T);
	printf("\n后序递归遍历二叉树:\n");
	PostOrderTraverse(T);
	cout<<"\n------------------------------------------------------\n";

	printf("\n请输入一个结点的值: ");
	cin>>e1;
	// cout<<e1;
	p=Point(T,e1); // p为e1的指针
	if(p)
		printf("结点的值为%c\n",p->data);
	else
		cout<<"输入结点值错误！\n";
	cout<<"\n------------------------------------------------------\n";

	printf("欲改变此结点的值，请输入新值: ");
	cin>>e2;
	Assign(p,e2);
	printf("\n先序递归遍历二叉树:");
	PreOrderTraverse(T);

	e1=Parent(T,e2);
	if(e1!=' ')
		printf("\n%c的双亲是%c",e2,e1);
	else
		printf("\n%c没有双亲\n",e2);

	e1=LeftChild(T,e2);
	if(e1!=' ')
		printf("\n%c的左孩子是%c\n",e2,e1);
	else
		printf("\n%c没有左孩子\n",e2);

	e1=RightChild(T,e2);
	if(e1!=' ')
		printf("\n%c的右孩子是%c\n",e2,e1);
	else
		printf("\n%c没有右孩子\n",e2);

	DestroyBiTree(T);
	system("pause");
	return 0;
}
