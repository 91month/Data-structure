#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status 是函数返回值类型，其值是函数结果状态代码。
typedef int ElemType; //ElemType 为可定义的数据类型，此设为 int 类型
#define MAXSIZE 100//顺序表可能达到的最大长度
typedef struct
{
    int no;   //8 位学号
    char name[80]; //姓名
    ElemType  price;     //成绩
    }Student; //顺序表的定义（第一个程序用）
typedef  struct
{
    Student  *elem;     //指向数据元素的基地址
    int  length;       //线性表的当前长度
}SqList;
int  main() {
    SqList L;
    int i, choose;
    char name[80]; //功能定义，声明函数
    Status  InitList(SqList &L); //初使化链表
    Status  CreatList (SqList &L); //构建链表
    Status  TraverseList(SqList L);//显示
    Status  LocateElem(SqList L,char *name); //查找
    Status  GetElem(SqList L,int i); //获取
    Status  ListInsert(SqList &L,int i); //插入
    Status  ListDelete(SqList &L,int i); //删除
    Status  ListLength(SqList L); //链表长度
    Status  DestroyList(SqList &L); //销毁链表 //屏幕提示操作！
    cout<<"---------------------\n";
    cout<<"1. 初使化链表\n";
    cout<<"2. 构建链表\n";
    cout<<"3. 显示链表长度\n";
    cout<<"4. 显示链表内容\n";
    cout<<"5. 查找学生信息\n";
    cout<<"6. 获取学生信息\n";
    cout<<"7. 插入学生信息\n";
    cout<<"8. 删除学生信息\n";
    cout<<"9. 销毁链表\n";
    cout<<"0. 退出\n\n";
    cout<<"---------------------\n";
    choose = -1;
    while (choose != 0)
    {//函数调用
        cout<<'\n'<< "请选择:";
        cin >> choose;
        switch (choose){
            case 1://创建链表
                if (InitList(L))
                    cout << "成功建立链表";
                else
                    cout << "链表建立失败";
                break;
            case 2:   //构建链表
                (CreatList(L));
                //补充语句
                break;
            case 3://链表长度
                ListLength(L);//补充语句
                break;
            case 4://显示链表内容
                TraverseList(L);//补充语句
                break;
            case 5://查找学生信息
                cout<<"请输入需要查找信息的学生姓名：\n";
                cin>>name;+-

                \
                LocateElem(L,name);//补充语句
                break;
            case 6: //获取学生信息
                cout<<"请输入需要获取信息的学生编号：\n";
                cin>>i;
                GetElem(L,i);//补充语句
                break;
            case 7: //插入学生信息
                cout<<"请输入要插入学生的编号：\n";
                cin>>i;
                ListInsert(L,i);//补充语句
                break;
            case 8://删除学生信息
                cout<<"请输入要删除学生的编号：\n";
                cin>>i;
                //补充语句
                break;
            case 9:  //销毁链表
                if (L.length==0) cout << "成功删除链表\n\n";
                else   cout << "链表删除失败\n\n";
                break;
                }}}
Status InitList(SqList &L){
    L.elem=new Student[MAXSIZE];
    if(!L.elem) exit(OVERFLOW);
    L.length=0;
    return OK;
}
Status  TraverseList(SqList L){
cout<<"学号："<<L.elem->no<<"姓名："<<L.elem->name<<"成绩"<<L.elem->price;
}
Status  CreatList (SqList &L) {
    if (!L.elem)
    exit(OVERFLOW); //链表不存在退出
    do{
        cout<<"输入学号，姓名，成绩:\n";
        cin>>L.elem[L.length].no>>L.elem[L.length].name>>L.elem[L.length].price; //用 cin 也可
        L.length++;
        }
    while(L.elem[L.length-1].no!=0 );//输入 0 0 0 时结束
    L.length--;
}
Status  LocateElem(SqList L,char *name){
    for(int i=0;i< L.length;i++)
        if(strcmp(L.elem[i].name,name)==0)
            {cout<<i+1;break;}
    return 0;
} //查找
Status  GetElem(SqList L,int i){
    if (i<1||i>L.length)  return ERROR;
    cout<<"姓名："<<L.elem[i-1].name;
    cout<<"学号："<<L.elem[i-1].no;
    cout<<"成绩："<<L.elem[i-1].price;
    return OK;
} //获取
Status  ListInsert(SqList &L,int i){
    if((i<1)||(i>L.length+1))  return ERROR;
    if(L.length==MAXSIZE)  return ERROR;
    for(int j=L.length-1;j>=i-1;j--)
        L.elem[j+1]=L.elem[j];
    L.elem[i-1].no=i;
    ++L.length;
    cout<<"输入学号，姓名，成绩:\n";
    cin>>L.elem[i-1].no>>L.elem[i-1].name>>L.elem[i-1].price;
    return OK;
} //插入
Status  ListDelete(SqList &L,int i){
    if((i<1)||(i>L.length))  return ERROR;
    for(int j=i;j<=L.length-1;j++)
        L.elem[j-1]=L.elem[j];
    --L.length;
    return OK;
} //删除
Status  ListLength(SqList L){
    cout<<L.length;
} //链表长度
Status DestroyList(SqList &L) {
    if (L.elem)
        delete[]L.elem;    //释放存储空间
    L.length=0;
    return OK; }
