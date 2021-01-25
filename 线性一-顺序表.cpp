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
typedef int Status; //Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣
typedef int ElemType; //ElemType Ϊ�ɶ�����������ͣ�����Ϊ int ����
#define MAXSIZE 100//˳�����ܴﵽ����󳤶�
typedef struct
{
    int no;   //8 λѧ��
    char name[80]; //����
    ElemType  price;     //�ɼ�
    }Student; //˳���Ķ��壨��һ�������ã�
typedef  struct
{
    Student  *elem;     //ָ������Ԫ�صĻ���ַ
    int  length;       //���Ա�ĵ�ǰ����
}SqList;
int  main() {
    SqList L;
    int i, choose;
    char name[80]; //���ܶ��壬��������
    Status  InitList(SqList &L); //��ʹ������
    Status  CreatList (SqList &L); //��������
    Status  TraverseList(SqList L);//��ʾ
    Status  LocateElem(SqList L,char *name); //����
    Status  GetElem(SqList L,int i); //��ȡ
    Status  ListInsert(SqList &L,int i); //����
    Status  ListDelete(SqList &L,int i); //ɾ��
    Status  ListLength(SqList L); //������
    Status  DestroyList(SqList &L); //�������� //��Ļ��ʾ������
    cout<<"---------------------\n";
    cout<<"1. ��ʹ������\n";
    cout<<"2. ��������\n";
    cout<<"3. ��ʾ������\n";
    cout<<"4. ��ʾ��������\n";
    cout<<"5. ����ѧ����Ϣ\n";
    cout<<"6. ��ȡѧ����Ϣ\n";
    cout<<"7. ����ѧ����Ϣ\n";
    cout<<"8. ɾ��ѧ����Ϣ\n";
    cout<<"9. ��������\n";
    cout<<"0. �˳�\n\n";
    cout<<"---------------------\n";
    choose = -1;
    while (choose != 0)
    {//��������
        cout<<'\n'<< "��ѡ��:";
        cin >> choose;
        switch (choose){
            case 1://��������
                if (InitList(L))
                    cout << "�ɹ���������";
                else
                    cout << "������ʧ��";
                break;
            case 2:   //��������
                (CreatList(L));
                //�������
                break;
            case 3://������
                ListLength(L);//�������
                break;
            case 4://��ʾ��������
                TraverseList(L);//�������
                break;
            case 5://����ѧ����Ϣ
                cout<<"��������Ҫ������Ϣ��ѧ��������\n";
                cin>>name;+-

                \
                LocateElem(L,name);//�������
                break;
            case 6: //��ȡѧ����Ϣ
                cout<<"��������Ҫ��ȡ��Ϣ��ѧ����ţ�\n";
                cin>>i;
                GetElem(L,i);//�������
                break;
            case 7: //����ѧ����Ϣ
                cout<<"������Ҫ����ѧ���ı�ţ�\n";
                cin>>i;
                ListInsert(L,i);//�������
                break;
            case 8://ɾ��ѧ����Ϣ
                cout<<"������Ҫɾ��ѧ���ı�ţ�\n";
                cin>>i;
                //�������
                break;
            case 9:  //��������
                if (L.length==0) cout << "�ɹ�ɾ������\n\n";
                else   cout << "����ɾ��ʧ��\n\n";
                break;
                }}}
Status InitList(SqList &L){
    L.elem=new Student[MAXSIZE];
    if(!L.elem) exit(OVERFLOW);
    L.length=0;
    return OK;
}
Status  TraverseList(SqList L){
cout<<"ѧ�ţ�"<<L.elem->no<<"������"<<L.elem->name<<"�ɼ�"<<L.elem->price;
}
Status  CreatList (SqList &L) {
    if (!L.elem)
    exit(OVERFLOW); //���������˳�
    do{
        cout<<"����ѧ�ţ��������ɼ�:\n";
        cin>>L.elem[L.length].no>>L.elem[L.length].name>>L.elem[L.length].price; //�� cin Ҳ��
        L.length++;
        }
    while(L.elem[L.length-1].no!=0 );//���� 0 0 0 ʱ����
    L.length--;
}
Status  LocateElem(SqList L,char *name){
    for(int i=0;i< L.length;i++)
        if(strcmp(L.elem[i].name,name)==0)
            {cout<<i+1;break;}
    return 0;
} //����
Status  GetElem(SqList L,int i){
    if (i<1||i>L.length)  return ERROR;
    cout<<"������"<<L.elem[i-1].name;
    cout<<"ѧ�ţ�"<<L.elem[i-1].no;
    cout<<"�ɼ���"<<L.elem[i-1].price;
    return OK;
} //��ȡ
Status  ListInsert(SqList &L,int i){
    if((i<1)||(i>L.length+1))  return ERROR;
    if(L.length==MAXSIZE)  return ERROR;
    for(int j=L.length-1;j>=i-1;j--)
        L.elem[j+1]=L.elem[j];
    L.elem[i-1].no=i;
    ++L.length;
    cout<<"����ѧ�ţ��������ɼ�:\n";
    cin>>L.elem[i-1].no>>L.elem[i-1].name>>L.elem[i-1].price;
    return OK;
} //����
Status  ListDelete(SqList &L,int i){
    if((i<1)||(i>L.length))  return ERROR;
    for(int j=i;j<=L.length-1;j++)
        L.elem[j-1]=L.elem[j];
    --L.length;
    return OK;
} //ɾ��
Status  ListLength(SqList L){
    cout<<L.length;
} //������
Status DestroyList(SqList &L) {
    if (L.elem)
        delete[]L.elem;    //�ͷŴ洢�ռ�
    L.length=0;
    return OK; }
