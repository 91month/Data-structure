/***���ӵĻ�������***/

#include<iostream>
#include<fstream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef student QElemType;
typedef int Status;
typedef char SElemType;

//- - - - - ���е���ʽ�洢�ṹ- - - - - 
typedef struct QNode {
	QElemType data;
	**����**
} QNode, *QueuePtr;

typedef struct {
	QueuePtr front; //��ͷָ��
	QueuePtr rear; //��βָ��
} LinkQueue;

//�㷨3.16�����ӵĳ�ʼ��
Status InitQueue(LinkQueue &Q) {//����һ���ն���Q
	**����** //�����½����Ϊͷ��㣬��ͷ�Ͷ�βָ��ָ��˽��
	Q.front->next = NULL; //ͷ����ָ�����ÿ�
	return OK;
}

//�㷨3.17�����ӵ����
Status EnQueue(LinkQueue &Q, QElemType e) {//����Ԫ��eΪQ���µĶ�βԪ��
	QueuePtr p;
	**����**		//Ϊ���Ԫ�ط�����ռ䣬��ָ��pָ��
	p->data = e; 	//���½����������Ϊe
	**����**
	Q.rear->next = p; 	//���½����뵽��β
	**����** 			//�޸Ķ�βָ��
	return OK;
}

//�㷨3.18�����ӵĳ���
Status DeQueue(LinkQueue &Q, QElemType &e) {//ɾ��Q�Ķ�ͷԪ�أ���e������ֵ 
	QueuePtr p;
	if (**����**)
		return ERROR; 		//�����пգ��򷵻�ERROR
	**����** 				//pָ���ͷԪ��
	e = p->data; 			//e�����ͷԪ�ص�ֵ
	**����** //�޸�ͷָ��
	if (Q.rear == p)
		Q.rear = Q.front; //���һ��Ԫ�ر�ɾ����βָ��ָ��ͷ���
	**����**  //�ͷ�ԭ��ͷԪ�صĿռ�
	return OK;
}

//�㷨3.19��ȡ���ӵĶ�ͷԪ��
SElemType GetHead(LinkQueue Q) {//����Q�Ķ�ͷԪ�أ����޸Ķ�ͷָ��
	if (**����**) //���зǿ�
		return **����**; //���ض�ͷԪ�ص�ֵ����ͷָ�벻��
}

int main() {
	int choose, flag = 0;
	LinkQueue Q;
	QElemType e, j;
	cout << "1.��ʼ��\n";
	cout << "2.���\n";
	cout << "3.����ͷԪ��\n";
	cout << "4.����\n";
	cout << "0.�˳�\n\n";

	choose = -1;
	while (choose != 0) {
		cout << "��ѡ��:";
		cin >> choose;
		switch (choose) {
		case 1://�㷨3.16�����ӵĳ�ʼ��
			if (InitQueue(Q)) {
				flag = 1;
				cout << "�ɹ��Զ��н��г�ʼ��\n\n";
			} else
				cout << "��ʼ������ʧ��\n\n";
			break;
		case 2: {//�㷨3.17�����ӵ����
			fstream file;
			file.open("QNode.txt");
			if (!file) {
				cout << "����δ�ҵ��ļ���\n\n" << endl;
				exit(ERROR);
			}
			if (flag) {
				flag = 1;
				cout << "��ӵ�Ԫ������Ϊ��\n";
				while (!file.eof()) {
					file >> j;
					if (file.fail())
						break;
					else {
						EnQueue(Q, j);
						cout << j << "  ";
					}
				}
				cout << endl << endl;
			} else
				cout << "����δ������������ѡ��\n\n";
			file.close();
		}
			break;
		case 3://�㷨3.19��ȡ���ӵĶ�ͷԪ��
			if (flag != -1 && flag != 0)
				cout << "��ͷԪ��Ϊ��\n" << GetHead(Q) << endl << endl;
			else
				cout << "��������Ԫ�أ�������ѡ��\n" << endl;
			break;
		case 4://�㷨3.18�����ӵĳ���
			cout << "���ε����Ķ�ͷԪ��Ϊ:\n";
			while (DeQueue(Q, e)) {
				flag = -1;
				cout << e << "  ";
			}
			cout << endl << endl;
			break;
		}
	}
	return 0;
}