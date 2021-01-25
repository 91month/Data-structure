/***********************�������ۺ�����******************************/

#include<iostream>
#include<fstream>
using namespace std;
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
typedef int Status;  // Status�Ǻ���������
typedef char TElemType; // Boolean�ǲ�������,��ֵ��TRUE��FALSE

//����������
typedef struct BiNode
{
	char data;
	struct BiNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef BiTree QElemType;
//�����еĶ���
typedef struct QNode
{
	QElemType data;
	QNode *next;
}*QueuePtr;

typedef struct
{
	QueuePtr front,rear; // ��ͷ����βָ��
}LinkQueue;
/***************����Ϊ���г������㺯��*****************************/
//��ʼ������
Status InitQueue(LinkQueue &Q)
{ // ����һ���ն���Q
    if(!(Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode))))
		exit(OVERFLOW);
	Q.front->next=NULL;
	return OK;
}
//���
Status EnQueue(LinkQueue &Q,QElemType e)
{ // ����Ԫ��eΪQ���µĶ�βԪ��
	QueuePtr p;
	if(!(p=(QueuePtr)malloc(sizeof(QNode))))
		exit(OVERFLOW);
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return OK;

}
//�ж϶ӿ�
Status QueueEmpty(LinkQueue Q)
{ // ��QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE
	if(Q.front->next==NULL)
		return TRUE;
	else
		return FALSE;
}
//����
Status DeQueue(LinkQueue &Q,QElemType &e)
{ // �����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
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
{ // �������������ն�����T
	T=NULL;
}

Status BiTreeEmpty(BiTree T)
{ // ��ʼ������������T���ڡ������������TΪ�ն��������򷵻�TRUE������FALSE
	if(T)
		return FALSE;
	else
		return TRUE;
}

/***************����Ϊ�������ۺ����㺯��*****************************/
//////////////���ٶ�����/////////////////////////////
void DestroyBiTree(BiTree T)
{ // ��ʼ������������T���ڡ�������������ٶ�����T
	if(T) // �ǿ���
	{
		if(T->lchild) // ������
			DestroyBiTree(T->lchild); // ������������
		if(T->rchild) // ���Һ���
			DestroyBiTree(T->rchild); // �����Һ�������
		free(T); // �ͷŸ����
		T=NULL; // ��ָ�븳0
	}
}

////////////////��ָ��ָ�����Ԫ��//////////////////
BiTree Point(BiTree T,TElemType s)
{ // ���ض�����T��ָ��Ԫ��ֵΪs�Ľ���ָ�롣���
	LinkQueue q;
	BiTree a;

	if(T) // �ǿ���
	{
		InitQueue(q); // ��ʼ������
		EnQueue(q,T); // ��ָ�����
		while(!QueueEmpty(q)) // �Ӳ���
		{
			DeQueue(q,a); // ���ӣ�����Ԫ�ظ���a
			if(a->data==s)
				return a;
			if(a->lchild) // ������
				EnQueue(q,a->lchild); // �������
			if(a->rchild) // ���Һ���
				EnQueue(q,a->rchild); // ����Һ���
		}
	}
	//  cout<<a->data<<endl;
	return NULL;
}

/////////////��ָ����㸳ֵ////////////////////////////////
void Assign(BiTree p,TElemType value)
{ // ��p��ָ��㸳ֵΪvalue
    p->data=value;
}
////////////////��ĳ������ӵ�ֵ�������򷵻ؿ�//////////////////////////
TElemType LeftChild(BiTree T,TElemType e)
{ // ��ʼ������������T���ڣ�e��T��ĳ����㡣�������������e�����ӡ���e������,�򷵻�"��"
	BiTree a;
	if(T) // �ǿ���
	{
		a=Point(T,e); // a�ǽ��e��ָ��
		if(a&&a->lchild) // T�д��ڽ��e��e��������
			return a->lchild->data; //����e�����ӵ�ֵ(�������.)
	}
	return ' '; // ����������ؿ�
}
////////////////��ĳ����Һ��ӵ�ֵ�������򷵻ؿ�//////////////////////////
TElemType RightChild(BiTree T,TElemType e)
{ // ��ʼ������������T���ڣ�e��T��ĳ����㡣�������������e���Һ��ӡ���e���Һ���,�򷵻�"��"
	BiTree a;
	if(T) // �ǿ���
	{
		a=Point(T,e); // a�ǽ��e��ָ��
		if(a&&a->rchild) // T�д��ڽ��e��e�����Һ���
			return a->rchild->data; // ����e���Һ��ӵ�ֵ(�������.)
	}
	return ' '; // ����������ؿ�
}


///////////���ö�����ȡĳ���˫�׵�ֵ,���Ҳ��ܣ��򷵻ؿ�////////////////////////////////////
TElemType Parent(BiTree T,TElemType e)
{ // ��ʼ������������T���ڣ�e��T��ĳ�����
	// �����������e��T�ķǸ���㣬�򷵻�����˫�ף����򷵻أ��գ�
	LinkQueue q;
	BiTree  a; //BiTree QElemType a;
	if(T) // �ǿ���
	{
		InitQueue(q); // ��ʼ������
		EnQueue(q,T); // ����ָ�����
		while(!QueueEmpty(q)) // �Ӳ���
		{
			DeQueue(q,a); // ���ӣ�����Ԫ�ظ���a
			if(a->lchild&&a->lchild->data==e||a->rchild&&a->rchild->data==e) // �ҵ�e(��������Һ���)
				return a->data;        //����e��˫�׵�ֵ
			else // û�ҵ�e������������Һ���ָ��(����ǿ�)
			{
				if(a->lchild)
					EnQueue(q,a->lchild);
				if(a->rchild)
					EnQueue(q,a->rchild);
			}
		}
	}
	return ' '; // ���ջ�û�ҵ�e
}

//////���㷨5.3 ���������˳������������//////////////////////
void CreateBiTree(BiTree &T)
{
	//�������������������н���ֵ��һ���ַ������������������ʾ�Ķ�����T
	char ch;
	cin>>ch;
	if(ch=='#')  T=NULL;	//�ݹ������������
	else
	{
		T=new BiTNode;
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);  //�ݹ鹹������
	}
}
////////////�������///////////////////////////
void InOrderTraverse(BiTree T)
{
	if(T)
	{
		InOrderTraverse(T->lchild);
		cout<<T->data;
		InOrderTraverse(T->rchild);
	}
	//�������������T�ĵݹ��㷨,�������.
}
////////////�������///////////////////////////
void PreOrderTraverse(BiTree T)
{
	if(T)
	{
		cout<<T->data;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	//�������������T�ĵݹ��㷨���������.
}
///////////////�������/////////////////////////
void PostOrderTraverse(BiTree T)
{
	if(T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout<<T->data;
	}

	//�������������T�ĵݹ��㷨,�������.

}

//////////////�������////////////////////
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

//////////////��Ҷ���� /////////////////////
int LeadCount(BiTree T)
{
	if(T==NULL)
		return 0;
	else if(T->lchild==NULL && T->rchild==NULL)
		return 1;
	else
		return LeadCount(T->lchild)+LeadCount(T->rchild);
}
////////////////������/////////////////////
int NodeCount(BiTree T)
{
	if(T==NULL)
		return 0;
	else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}
////////////////������ֵ//////////////////
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


	printf("���������������(P121ͼ5.10(b)");
	CreateBiTree(T);


	e1=Root(T);
	if(e1!=' ')
		printf("�������ĸ�Ϊ: %c\n",e1);
	else
		printf("���գ��޸�\n");
	cout<<"------------------------------------------------------\n";
	cout<<" ����Ҷ����="<<LeadCount(T)<<endl;
	cout<<" ���Ľ����="<<NodeCount(T)<<endl;
	cout<<" ����Ҷ���="<<BiTreeDepth(T)<<endl;

	printf("\n����ݹ����������:\n");
	PreOrderTraverse(T);
	printf("\n����ݹ����������:\n");
	InOrderTraverse(T);
	printf("\n����ݹ����������:\n");
	PostOrderTraverse(T);
	cout<<"\n------------------------------------------------------\n";

	printf("\n������һ������ֵ: ");
	cin>>e1;
	// cout<<e1;
	p=Point(T,e1); // pΪe1��ָ��
	if(p)
		printf("����ֵΪ%c\n",p->data);
	else
		cout<<"������ֵ����\n";
	cout<<"\n------------------------------------------------------\n";

	printf("���ı�˽���ֵ����������ֵ: ");
	cin>>e2;
	Assign(p,e2);
	printf("\n����ݹ����������:");
	PreOrderTraverse(T);

	e1=Parent(T,e2);
	if(e1!=' ')
		printf("\n%c��˫����%c",e2,e1);
	else
		printf("\n%cû��˫��\n",e2);

	e1=LeftChild(T,e2);
	if(e1!=' ')
		printf("\n%c��������%c\n",e2,e1);
	else
		printf("\n%cû������\n",e2);

	e1=RightChild(T,e2);
	if(e1!=' ')
		printf("\n%c���Һ�����%c\n",e2,e1);
	else
		printf("\n%cû���Һ���\n",e2);

	DestroyBiTree(T);
	system("pause");
	return 0;
}
