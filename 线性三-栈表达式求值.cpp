#include<iostream>
#define OK 1
#define ERROR 0
typedef int Status

typedef struct SNode
{
    int data;
    struct SNode *next;
} SNode, *LinkStack;
const char oper[7] = { '+', '-', '*', '/', '(', ')', '#' };//���������������

Status InitStack(LinkStack &s){
    s=NULL;
    return 0;
}

bool StackEmpty(LinkStack s){
    if(s==NULL) return 0;
}

Status Push(LinkStack &s, SElemType e){
    p=new SNode;
    p->data=e;
    p->next=s
    s=p;
    return OK;
}

Status Pop(LinkStack &s, SElemType &e){
    e=s->data;
    p=s;
    s=s->next;
    delete p;
    return OK;
}

Status GetTop(LinkStack &s){
    if(s!=NULL)
        return s->data;
}

char EvaluateExpression();

int main()
{
    char res;
    int c;
    while (1)
    {
        cout<<"---------------------------------" <<endl;
        cout<<"0-9���ڵĶ���ʽ����" <<endl;
        cout<<"1.����" <<endl;
        cout<<"0.�˳�\n"<<endl;
        cout<<"ѡ��";
        cin>>c;
        switch(c)
        {
            case 1:
            {
                cout << "������Ҫ����ı��ʽ���������ͽ������0-9�ķ�Χ�ڣ���#��������" << endl;
                res = EvaluateExpression( );//�㷨3.22 ���ʽ��ֵ
                cout << "������Ϊ" <<res -48 << endl << endl;
            };
            break;
            case 0:
                cout << "�˳��ɹ�\n" << endl;
                exit(0);
            default:
                break;
        }
    }
}



bool In(char ch){
    for (int i = 0; i < 7; i++)
        if (ch == oper[i])  return true;
    return false;
}


char Precede(char theta1, char theta2){
    if ((theta1 == '(' && theta2 == ')' ) || (theta1 == '#' && theta2 == '#' ))
        return '=';
    else if (theta1 == '('||theta1 =='#'||theta2== '('||(theta1=='+'||theta1=='-') && (theta2 == '*'||theta2 =='/'))
        return '<';
    else
        return '>';
}

char Operate(char  first, char theta, char  second){
    switch (theta)
    {
        case '+':  return (first - '0') + (second - '0') + 48; //ΪʲôҪ��0��Ҫ��48?
        case '-':  return (first - '0') - (second - '0') + 48;
        case '*':  return (first - '0') * (second - '0') + 48;
        case '/':  return (first - '0') / (second - '0') + 48;
    }
    return 0;
}

char EvaluateExpression(){
    InitStack(OPND);
    InitStack(OPTR);
    Push(OPTR,'#');
    cin>>ch;
    while(ch!='#'||GetTop(OPTR)!='#'){
        if(!In(ch)){Push(OPND,ch);cin>>ch;}
        else
            switch(Precede(GetTop(OPTR),ch)){
                case '<':
                    Push(OPTR,ch);cin>>ch;
                    break;
                case '>':
                    Pop(OPTR,theta);
                    Pop(OPND,b);
                    Pop(OPND,a);
                    Push(OPND,Operate(a,theta,b));
                    break;
                case '=':
                    Pop(OPTR,x);
                    cin>>ch;
                    break;
            }
    }
    return GetTop(OPND);
}



