#include <stack>
#include <iostream>
#include <clocale>
#include <conio.h>
//Заполнить стек значениями произвольно выбранного типа. Поменять местами первый и последний элементы стека.
//заполнять будем int'ами
//Стек (от англ. stack — «стопка») — это способ организации данных в памяти компьютера,
//который соответствует принципу LIFO (англ. last in — first out, «последним пришёл — первым вышел»).
//как стопка с тарелками
using namespace std;

void insertStack(std::stack<int> &stack1){//заполнение стека элементами типа int
    int num;
    cout<<"Введите новое число\n";
    cin>>num;
    stack1.push(num);
    cout<<"Число "<<num<<" Добавлено в стек ";
}
void outputStack(std::stack<int> stack1,string stackname){
    int i=1;
    cout<<"\n************************************************\n";
    //cout<< typeid(stack1).name()<<"\n";
    cout << "\nВывод стека "<<stackname<<" на экран"<<"\n";
    int size1 = stack1.size();
    cout<<"Размер выводимого стека равен "<< size1<<"\n";
    if (size1!=0){
            while(size1!=0){

                    cout << i << " элемент стека равен " << stack1.top()<<"\n";
                    stack1.pop();
                    size1 = stack1.size();
                    i++;
            }
    }

    cout<<"\n*************************************************\n";
}

void swapElem(std::stack<int> &stack1){//функция перемены 1 и последнего элемента местами
    std::stack<int> stack2{stack1};
    std::stack<int> stack3;//второй стек,для поиска последнего элемента-полная копия 1 стека
    int firstelem = stack2.top();
    int size1 = stack2.size();
    int size2 = stack2.size();//второй счетчик чтобы сравнивать с ним 1
    int lastelem;//переменная для последнего значения стека4
    while(size1!=0){
        size1 = stack2.size();
    //ищем последний элемент
        //cout<<"\nРазмер стека2 в данный момент равен "<<size1<<"\n";
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
    while(size1!=0){//стек 2 к этому моменту пустой стек 3 полный
        if(size1==1){
            stack2.push(lastelem);
            stack3.pop();//в этом цикле обратно переворачиваем стек и меняем местами элементы
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
    cout<<"Введите размер стека-> ";
    cin>>N;
    for(int i=1;i<=N;i++){
        insertStack(stack1);
    }
    swapElem(stack1);
    outputStack(stack1,"stack1");
    return 0;
}
