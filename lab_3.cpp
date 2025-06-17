#include <stack>
#include <iostream>
#include <clocale>
#include <conio.h>
//��������� ���� ���������� ����������� ���������� ����. �������� ������� ������ � ��������� �������� �����.
//��������� ����� int'���
//���� (�� ����. stack � �������) � ��� ������ ����������� ������ � ������ ����������,
//������� ������������� �������� LIFO (����. last in � first out, ���������� ������ � ������ �����).
//��� ������ � ���������
using namespace std;

void insertStack(std::stack<int> &stack1){//���������� ����� ���������� ���� int
    int num;
    cout<<"������� ����� �����\n";
    cin>>num;
    stack1.push(num);
    cout<<"����� "<<num<<" ��������� � ���� ";
}
void outputStack(std::stack<int> stack1,string stackname){
    int i=1;
    cout<<"\n************************************************\n";
    //cout<< typeid(stack1).name()<<"\n";
    cout << "\n����� ����� "<<stackname<<" �� �����"<<"\n";
    int size1 = stack1.size();
    cout<<"������ ���������� ����� ����� "<< size1<<"\n";
    if (size1!=0){
            while(size1!=0){

                    cout << i << " ������� ����� ����� " << stack1.top()<<"\n";
                    stack1.pop();
                    size1 = stack1.size();
                    i++;
            }
    }

    cout<<"\n*************************************************\n";
}

void swapElem(std::stack<int> &stack1){//������� �������� 1 � ���������� �������� �������
    std::stack<int> stack2{stack1};
    std::stack<int> stack3;//������ ����,��� ������ ���������� ��������-������ ����� 1 �����
    int firstelem = stack2.top();
    int size1 = stack2.size();
    int size2 = stack2.size();//������ ������� ����� ���������� � ��� 1
    int lastelem;//���������� ��� ���������� �������� �����4
    while(size1!=0){
        size1 = stack2.size();
    //���� ��������� �������
        //cout<<"\n������ �����2 � ������ ������ ����� "<<size1<<"\n";
        if(size1==1){
            lastelem = stack2.top();
        }
        if(stack2.size()!=0){
            stack3.push(stack2.top());
            stack2.pop();
        }

    }
    //outputStack(stack3,"stack3");
    size1 = stack3.size();
    while(size1!=0){//���� 2 � ����� ������� ������ ���� 3 ������
        if(size1==1){
            stack2.push(lastelem);
            stack3.pop();//� ���� ����� ������� �������������� ���� � ������ ������� ��������
        }
        if(size1==size2){
            stack2.push(firstelem);
            stack3.pop();
        }
        if(!stack3.empty()){
            stack2.push(stack3.top());
            stack3.pop();
        }
        size1 = stack3.size();
    }
    stack1=stack2;
}
int main(){
    setlocale(LC_ALL,"russian");
    std::stack<int> stack1;
    int num1=1;
    int N;
    cout<<"������� ������ �����-> ";
    cin>>N;
    for(int i=1;i<=N;i++){
        insertStack(stack1);
    }
    swapElem(stack1);
    outputStack(stack1,"stack1");
    return 0;
}
