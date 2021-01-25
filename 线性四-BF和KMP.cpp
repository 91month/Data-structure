#include<cstring>
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define MAX_STR_LEN 255 // �û����� 255(1 ���ֽ�)���ڶ�����󴮳�
typedef char SString[MAX_STR_LEN+1]; // 0 �ŵ�Ԫ��Ŵ��ĳ���
typedef int Status;

void get_next(SString T,int next[]);
void get_nextval(SString T,int nexttval[]);
void StrAssign(SString T,char *chars)//����һ����ֵ���� chars �Ĵ� T
void StrPrint(SString T) // ����ַ��� T
int StrLength(SString S)//���ش� S ��Ԫ�ظ���
Status Concat(SString T,SString S1,SString S2) // �� T ���� S1 �� S2 ����

int main()
{
    int i,*next;
    char ch1[80],ch2[80];
    SString S1,S2,S,SUB; // ��������������һ����Ԫ�洢���ĳ���
    cout<<"�������һ���ַ���:";
    cin>>ch1;
    StrAssign(S1,ch1);
    StrPrint(S1);
    cout<<"������ڶ����ַ���:";
    cin>>ch2;
    StrAssign(S2,ch2);
    StrPrint(S2);
    cout<<"------------------------------------------------\n";
    cout<<"��һ���ַ�������Ϊ��"<<StrLength(S1)<<endl;
    cout<<"�ڶ����ַ�������Ϊ��"<<StrLength(S2)<<endl;
    cout<<"============���������ַ�����������==============\n";
    Concat(  �������  );
    cout<<"��������Ϊ��"<<StrLength(S)<<endl;
    cout<<"����Ϊ��";
    StrPrint(S);
    cout<<"�������Ӵ�:";
    cin>>ch2;
    StrAssign(SUB,ch2);
    cout<<"�Ӵ�����Ϊ��"<<StrLength(SUB)<<endl;
    cout<<"---------------BE ƥ���㷨��ʵ��-------------------\n";
    i=Index(S,SUB,1); // �����㷨 4.6 ��ô� s2 �� s1 ���״�ƥ���λ�� i
    if(i)
        cout<<"�������Ӵ��ڵ�%d ���ַ����״�ƥ��\n"<<i;
    else
        cout<<"�������Ӵ�ƥ�䲻�ɹ�\n";
    cout<<"---------------KMP ƥ���㷨��ʵ��-------------------\n";
    next=new int[StrLength(SUB)+1];
    get_next(SUB,next); // �����㷨 4.7����� next ���飬���� p ��
    cout<<"�Ӵ��� next ����Ϊ: ";
    for(i=1; i<=StrLength(SUB); i++)
        cout<<*(next+i);
    cout<<("\n");
    i=Index_KMP(   �������  );  // �����㷨 4.6 ��ô� s2 �� s1 ���״�ƥ���λ�� i
    if(i)
        cout<<"�������Ӵ��ڵ�%d ���ַ����״�ƥ��\n"<<i;
    else
        cout<<"�������Ӵ�ƥ�䲻�ɹ�\n";
    cout<<"---------------KMP �Ľ�ƥ���㷨��ʵ��---------------\n";
    get_nextval(SUB,next); // �����㷨 4.8����� next ���飬���� p ��
    cout<<"�Ӵ��� nextval ����Ϊ: ";
    for(i=1; i<=StrLength(SUB); i++)
        cout<<*(next+i);
    cout<<"\n";
    i=Index_KMP(  �������  ); // �����㷨 4.6 ��ô� s2 �� s1 ���״�ƥ���λ�� i
    if(i)
        cout<<"�������Ӵ��ڵ�%d ���ַ����״�ƥ��\n"<<i;
    else
        cout<<"�������Ӵ�ƥ�䲻�ɹ�\n";
}

Status StrAssign(SString T,char *chars)
{
    int i;
    if(strlen(chars)>MAX_STR_LEN)
        return ERROR;
    else
    {
        T[0]=strlen(chars);
        for(i=1; i<=T[0]; i++)
            T[i]=*(chars+i-1);//�������
        return OK;
    }
}

void StrPrint(SString T)
{
    int i;
    for(i=1; i<=T[0]; i++)
        cout<<T[i];
    cout<<"\n";
}


int StrLength(SString S)
{
    return  S[0];//�������
}


Status Concat(SString T, SString S1,SString S2) // �㷨 4.2 ��
{
    int i;
    if(S1[0]+S2[0]<=MAX_STR_LEN)
    {
        // δ�ض�
        for(i=1; i<=S1[0]; i++)
            ;//�������
        for(i=1; i<=S2[0]; i++)
            ;//�������
        T[0]=S1[0]+S2[0];
        return OK;
    }
    else
    {
        // �ض� S2
        for(i=1; i<=S1[0]; i++)
            T[i]=S1[i];
        for(i=1; i<=MAX_STR_LEN-S1[0]; i++)
            ;//�������
        T[0]=MAX_STR_LEN;
        return ERROR;
    }
}


void get_next(SString T,int next[]){
    int i=1;
    next[1]=0;
    int j=0;
    while(i<T.Length)
    {
        if(j==0||T.ch[i]==T.ch[j]){
            ++j;
            ++i;
            next[i]=j;
        }
        else j=next[j];
    }
}


void get_nextval(SString T,int nexttval[]){
    int i=1;
    nexttval[1]=0;
    int j=0;
    while(i<T.Length){
        if(j==0||T.ch[i]=T.ch[j]){
            ++i;
            ++j;
            if(T.ch[i]!=T.ch[j]) nexttval[i]=j;
            else nexttval[i]=nexttval[j];
        }
        else j=nexttval[j];
    }
}





