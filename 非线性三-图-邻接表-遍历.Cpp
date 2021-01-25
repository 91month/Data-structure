//--------　连通图以邻接表存储时的深度-广度优先搜索遍历-------//
// 理解邻接表存储方式方法
//理解连通图以邻接表存储时的深度-广度优先搜索遍历算法及实现

#include <iostream>
#include<fstream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define MVNum 100                       	//最大顶点数
#define MAXQSIZE 100						//最大队列长度

bool visited[MVNum];           				//访问标志数组，其初值为"false"
typedef char VerTexType;              		//假设顶点的数据类型为字符型
typedef int ArcType;                  		//假设边的权值类型为整型

//-------------图的邻接表---------------------
typedef struct ArcNode{                		//边结点
    int adjvex;                          	//该边所指向的顶点的位置
    struct ArcNode *nextarc;          		//指向下一条边的指针
}ArcNode;

typedef struct VNode{
    VerTexType data;                    	//顶点信息
    ArcNode *firstarc;                		//指向第一条依附该顶点的边的指针
}VNode, AdjList[MVNum];               		//AdjList表示邻接表类型

typedef struct{
    AdjList vertices;                 		//邻接表
    int vexnum, arcnum;              		//图的当前顶点数和边数
}ALGraph;



//----队列的定义及操作--------
typedef struct{
	ArcType *base;							//初始化的动态分配存储空间
	int front;								//头指针，若队列不空，指向队头元素
	int rear;								//尾指针，若队列不空，指向队尾元素的下一个位置
}sqQueue;
/////////////////////////////////////////////////////////////////////////////////////////
void InitQueue(sqQueue &Q){
	Q.base = new QElemType[MAXQSIZE]; 	//为队列分配一个最大容量为MAXSIZE的数组空间
	if (!Q.base)
		exit(OVERFLOW); 				//存储分配失败
	Q.front=Q.rear=0;			//头指针和尾指针置为零，队列为空
	return OK;
}//InitQueue

void EnQueue(sqQueue &Q, ArcType e){
	if ((Q.rear+1)%MAXQSIZE==Q.front);//尾指针在循环意义上加1后等于头指针，表明队满
		return ERROR;
	Q.base[Q.rear] = e; 				//新元素插入队尾
	Q.rear=(Q.rear+1)%MAXQSIZE; 	//队尾指针加1
	return OK;
}//EnQueue

bool QueueEmpty(sqQueue Q){
	if (Q.front==Q.rear)
		return ERROR;
}//QueueEmpty

void DeQueue(sqQueue &Q, ArcType &u){
	if (Q.front==Q.rear)
		return ERROR; 			//队空
	e = Q.base[Q.front]; 		//保存队头元素
	Q.front=(Q.front+1)%MAXQSIZE;//队头指针加1
	return OK;
}//DeQueue
/////////////////////////////////////////////////////////////////////////////////////////
int LocateVex(ALGraph G , VerTexType v){
	//确定点v在G中的位置
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vertices[i].data == v)
			return i;
		return -1;
}//LocateVex

void CreateUDG(ALGraph &G){
	//采用邻接表表示法，创建无向图G
	int i , k;
	fstream file;

	file.open("tu.txt");
	if (!file) {
		cout << "没有找到图文件!" << endl;
		exit(ERROR);
	}

	//c请输入总顶点数，总边数
	file >> G.vexnum >> G.arcnum;

    //输入各点，构造表头结点表
	for(i = 0; i < G.vexnum; ++i)
	{
		file >> G.vertices[i].data;           	//输入顶点值
		G.vertices[i].firstarc=NULL;			//初始化表头结点的指针域为NULL
    }//for
	cout << endl;



	for(k = 0; k < G.arcnum;++k){        		//输入各边，构造邻接表
		VerTexType v1 , v2;
		int i , j;

		file >> v1 >> v2;                 		//输入一条边依附的两个顶点
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		//确定v1和v2在G中位置，即顶点在G.vertices中的序号
		//将新结点*p1插入顶点vi的边表头部

		ArcNode *p1=new ArcNode;               	//生成一个新的边结点*p1
		p1->adjvex=j;                   		//邻接点序号为j
		p1->nextarc= G.vertices[i].firstarc;
		G.vertices[i].firstarc=p1;//补充语句
		//将新结点*p2插入顶点vj的边表头部
	    //以下补充语句，参考上面算法
	    ArcNode *p2=new ArcNode;
	    p2->adjvex=i;                   		//邻接点序号为j
		p2->nextarc= G.vertices[j].firstarc;
		G.vertices[j].firstarc=p2;
    }
}//CreateUDG
/***************************************************************************/
void DFS(ALGraph G, int v)
{
	//按深度优先递归遍历连通图G
	//图G为邻接表类型
	cout << G.vertices[v].data << "   ";
	visited[v] = true;    						//访问第v个顶点，并置访问标志数组相应分量值为true
	ArcNode *p = G.vertices[v].firstarc;		//p指向v的边链表的第一个边结点
	while(p != NULL){              				//边结点非空
		int w = p->adjvex;               		//表示w是v的邻接点
		if(!visited[w])  DFS(G, w);   			//如果w未访问，则递归调用DFS
	    //以下补充一条语句
	    p=p->nextarc;

	}
}//DFS

/***************************************************************************/
void BFS(ALGraph G,int v)
{
    sqQueue Q;
    ArcNode *p;
	ArcType u;

    cout << G.vertices[v].data << "   ";
    visited[v]=true;      ;     /*置已访问标记*/

	InitQueue(Q);
    EnQueue(Q, v);                          /*访问过的顶点入队列*/
    while(!QueueEmpty(Q))
    {
        DeQueue(Q, u);/*顶点出队列*/
        p=G.vertices[u].firstarc;           /*找到v的第一个邻接点*/
		while(p!=NULL)                      /*判断邻接点是否存在*/
        {
            if(!visited[p->adjvex])         /*邻接点存在未被访问*/
            {
                 //以下补充语句
                cout << G.vexs[w] <<"    ";
				visited[w] = true;		//访问w，并置访问标志数组相应分量值为true
				EnQueue(G, v);


            }
            p=p->nextarc;                   /*沿着v的邻接点链表顺序搜索*/
        }
    }
 }
/**********************************************************************/

int DisplayG(ALGraph G)
{
	int i;

	for(i = 0 ; i < G.vexnum ; ++i)
	{
		VNode temp = G.vertices[i];
		ArcNode *p = temp.firstarc;
		if(p == NULL){
			cout << G.vertices[i].data<<"|";
			cout << endl;
		}
		else{
			cout << temp.data<<"|";
			while(p){
				cout << "->";
				cout << p->adjvex;
			 //以下补充一条语句

			}
		}
		cout << endl;
	}
	return OK;
}
/**********************************************************************/

int main(){
	cout << "************算法6.6　采用邻接表表示图的深度优先搜索遍历**************" << endl << endl;
	ALGraph G;
	CreateUDG(G);
	cout << endl;
	cout << "无向连通图G创建完成！" << endl << endl;

	cout << "**************邻接表表示无向连通图*******************" << endl;
	DisplayG(G);

	cout << "********************************" << endl;
	cout << "请输入遍历连通图的起始点：";
	VerTexType c;
	cin >> c;

	int i,j;
	for(i = 0 ; i < G.vexnum ; ++i){
		if(c == G.vertices[i].data)
			break;
	}
	cout << endl;
	while(i >= G.vexnum){
		cout << "该点不存在，请重新输入！" << endl;
		cout << "请输入遍历连通图的起始点：";
		cin >> c;
		for(i = 0 ; i < G.vexnum ; ++i){
			if(c == G.vertices[i].data)
				break;
		}
	}

    cout << "深度优先搜索遍历连通图结果：" << endl;
    DFS(G , i);
	cout <<endl;
	for(j = 0 ; j <MVNum ; j++)visited[j]=false;
	cout << "广度优先搜索遍历连通图结果：" << endl;
    BFS(G , i);

	cout <<endl;
	return 0;
}//main
