#include<cstring>
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define MAX_STR_LEN 255 // 用户可在 255(1 个字节)以内定义最大串长
typedef char SString[MAX_STR_LEN+1]; // 0 号单元存放串的长度
typedef int Status;

void get_next(SString T,int next[]);
void get_nextval(SString T,int nexttval[]);
void StrAssign(SString T,char *chars)//生成一个其值等于 chars 的串 T
void StrPrint(SString T) // 输出字符串 T
int StrLength(SString S)//返回串 S 的元素个数
Status Concat(SString T,SString S1,SString S2) // 用 T 返回 S1 和 S2 联接

int main()
{
    int i,*next;
    char ch1[80],ch2[80];
    SString S1,S2,S,SUB; // 定义两个串，第一个单元存储串的长度
    cout<<"请输入第一个字符串:";
    cin>>ch1;
    StrAssign(S1,ch1);
    StrPrint(S1);
    cout<<"请输入第二个字符串:";
    cin>>ch2;
    StrAssign(S2,ch2);
    StrPrint(S2);
    cout<<"------------------------------------------------\n";
    cout<<"第一个字符串长度为："<<StrLength(S1)<<endl;
    cout<<"第二个字符串长度为："<<StrLength(S2)<<endl;
    cout<<"============连接两个字符串构造主串==============\n";
    Concat(  补充参数  );
    cout<<"主串长度为："<<StrLength(S)<<endl;
    cout<<"主串为：";
    StrPrint(S);
    cout<<"请输入子串:";
    cin>>ch2;
    StrAssign(SUB,ch2);
    cout<<"子串长度为："<<StrLength(SUB)<<endl;
    cout<<"---------------BE 匹配算法及实现-------------------\n";
    i=Index(S,SUB,1); // 利用算法 4.6 求得串 s2 在 s1 中首次匹配的位置 i
    if(i)
        cout<<"主串和子串在第%d 个字符处首次匹配\n"<<i;
    else
        cout<<"主串和子串匹配不成功\n";
    cout<<"---------------KMP 匹配算法及实现-------------------\n";
    next=new int[StrLength(SUB)+1];
    get_next(SUB,next); // 利用算法 4.7，求得 next 数组，存于 p 中
    cout<<"子串的 next 数组为: ";
    for(i=1; i<=StrLength(SUB); i++)
        cout<<*(next+i);
    cout<<("\n");
    i=Index_KMP(   补充参数  );  // 利用算法 4.6 求得串 s2 在 s1 中首次匹配的位置 i
    if(i)
        cout<<"主串和子串在第%d 个字符处首次匹配\n"<<i;
    else
        cout<<"主串和子串匹配不成功\n";
    cout<<"---------------KMP 改进匹配算法及实现---------------\n";
    get_nextval(SUB,next); // 利用算法 4.8，求得 next 数组，存于 p 中
    cout<<"子串的 nextval 数组为: ";
    for(i=1; i<=StrLength(SUB); i++)
        cout<<*(next+i);
    cout<<"\n";
    i=Index_KMP(  补充参数  ); // 利用算法 4.6 求得串 s2 在 s1 中首次匹配的位置 i
    if(i)
        cout<<"主串和子串在第%d 个字符处首次匹配\n"<<i;
    else
        cout<<"主串和子串匹配不成功\n";
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
            T[i]=*(chars+i-1);//补充语句
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
    return  S[0];//补充语句
}


Status Concat(SString T, SString S1,SString S2) // 算法 4.2 改
{
    int i;
    if(S1[0]+S2[0]<=MAX_STR_LEN)
    {
        // 未截断
        for(i=1; i<=S1[0]; i++)
            ;//补充语句
        for(i=1; i<=S2[0]; i++)
            ;//补充语句
        T[0]=S1[0]+S2[0];
        return OK;
    }
    else
    {
        // 截断 S2
        for(i=1; i<=S1[0]; i++)
            T[i]=S1[i];
        for(i=1; i<=MAX_STR_LEN-S1[0]; i++)
            ;//补充语句
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





