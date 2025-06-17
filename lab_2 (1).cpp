#include <cstdio>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <locale>
using namespace std;

struct Tsizes {
	float width;
	float lenght;
};
struct Trobot_footballers {
	int id;
	int role;//1 в защите 0 в атаке
	int position[2];
	bool hasball;
	float speed;
	float dir_speed[2];//координаты вектора скорости робота
	Tsizes size_robot;
};

//тип данных для имени файла
string TName = "DefaultFile";

char TName2[25]{};//название файла для методов языка c
//тип данных для файловой переменной
typedef FILE TFile;
//переменная для робота
Trobot_footballers Robot;

//файловая переменная
TFile* f;
//флаг выбора файла для работы
int flag = 0;

std::fstream potok;

bool fl = 0;

void menu(void)//меню обновления базы футболистов
{
	system("cls");
	std::cout << "******** М Е Н Ю ********\n\n"
		<< "[1]-Создание нового робота в базе\n"
		<< "[2]-Добавление робота в базу\n"
		<< "[3]-Удаление робота из базы\n"
		<< "[4]-Просмотр всей базы роботов-футболистов\n"
		<< "[5]-Обновление данных о роботе с заданным номером\n"
		<< "[6]-Поиск робота по названию.\n"
		<< "[ ESC ]-Выход\n";
}

void InputRobot(Trobot_footballers &Robot)
{
	cin.clear(); //очистить поток и затем выставить позиционирование в 0
	while (!isspace(cin.get())) //Избавиться от результатов неверного ввода
		continue;

	std::cout << "Добавление нового робота в базу:\n";

	std::cout << "id робота ->"; //gets(Tovar.name);

	cin >> Robot.id;

	std::cout << "\nХарактеристики робота\n";

	std::cout << "Длина->";
	cin >> Robot.size_robot.lenght;

	std::cout << "Ширина->";
	cin >> Robot.size_robot.width;

	std::cout << "Роль->";
	cin >> Robot.role;

	std::cout << "Позиция x(целое число)->";
	cin >> Robot.position[0];

	std::cout << "Позиция y(целое число)->";
	cin >> Robot.position[1];

	std::cout << "Имеет мяч->";
	cin >> Robot.hasball;

	std::cout << "Скорость->";
	cin >> Robot.speed;

	cin.clear(); //очистить поток и затем выставить позиционирование в 0
	while (!isspace(cin.get()))
		continue;            //Избавиться от результатов неверного ввода

}

void OutputRobot(Trobot_footballers Robot)
{
	std::cout << "ID робота: " << Robot.id << "\n"
		<< "Длина,ширина робота: "
		<< Robot.size_robot.lenght << "," << Robot.size_robot.width << ":" << "\n"
		<< "Роль на поле 1-атака,0-защита" << Robot.role << "\n"
		<< "Позиция робота " << Robot.position << "\n"
		<< "Скорость робота " << Robot.speed << "\n";
}

void CreateOpenFile(string &TName,int& flag,std::fstream &potok,const char *&TName2,FILE *opfile)
{
	char ch;
	flag = 0;
	char *TName3;
	std::cout << "Введите имя файла для работы-->";
    opfile = fopen(TName2,"r");
	string buf;//буфер для чтения данных названия файла

	getline(cin,buf);//получаем название файла из буфера

	TName = buf;
	fgets(TName3,25,potok);
    TName2=TName3;
	potok.open(TName, std::ios::ate);
	cout << "Файл с именем " << TName << "открыт/создан\n";
	getch();
}

void AddRobot(string TName, Trobot_footballers& Robot, int flag,std::fstream &potok)
{
	if (flag)
	{
		InputRobot(Robot);
		////fwrite(&Robot, sizeof(Robot), 1, f);
		//int id;
		//int role;//1 в защите 0 в атаке
		//int position[2];
		//bool hasball;
		//float speed;
		//float dir_speed[2];//координаты вектора скорости робота
		//Tsizes size_robot;
		potok << "ID "<<Robot.id<<";\n";
		potok << "Role " << Robot.role << ";\n";
		potok << "Position:x,y " << Robot.position[0]<< "," << Robot.position[1] << ";\n";
		potok << "HasBall " << Robot.hasball << ";\n";
		potok << "Speed " << Robot.speed << ";\n";
		potok << "Dir_speed:x,y " << Robot.dir_speed[0]<< "," << Robot.dir_speed[1] << ";\n";
		potok.close();
	}
	else
	{
		std::cout << "\nВыберите файл для работы.\n"
			<< "Нажмите [ 1 ] в разделе М Е Н Ю.";
		getch();
	}
}

void VivodFile(string TName,std::fstream &potok)
{

	int i = 0;
	if (flag)
	{
        potok.open(TName,std::ios::in);
		string content;
		std::cout << "********  Вывод файла на экран  ********\n"
			<< "****************************************\n";
		if (potok.is_open())
		{
			while (std::getline(potok, content))
			{
				cout << content << endl;
			}
		}
		getch();
		potok.close();
	}
	else
	{
		std::cout << "\nВыберите файл для работы.\n"
			<< "Нажмите [ 1 ] в разделе М Е Н Ю.";
		getch();
	}

}

long filesize(TFile* f)
{
	long curpos, length;

	curpos = ftell(f);		//запоминаем текущее положение
	fseek(f, 0L, SEEK_END);	//перемещаем на конец файла
	length = ftell(f);		//запоминаем положение в конце файла
	fseek(f, curpos, SEEK_SET);	//перемещаем на старое положение
	return length;
}

void UpdateRobot(string TName, Trobot_footballers& Robot, int flag,std::fstream &potok)
{
	long i = 0;
	if (flag)
	{

        potok.open(TName,std::ios::app);
		std::cout << "********  Обновление записи с заданным номером  ********\n\n"
			<< "********************************************************\n\n"
			<< "Введите номер записи для обновления "
			<< "из "
			<< (filesize(f) / sizeof(Robot))
			<< " --> ";
		cin >> i;
		fpos_t q;//переменная спец класса которая хранит номер позиции для функции setpos или getpos
		//перемещаемся на запись с номером i
		fseek(f, (i - 1) * sizeof(Robot), SEEK_CUR);
		//запоминаем текущее положение
		fgetpos(f, &q);

		fread(&Robot, sizeof(Robot), 1, f);
		OutputRobot(Robot);
		std::cout << "****************************************\n";

		char ch;
		std::cout << "Обновить данные?\nНажмите [ Y ] / [ N ]\n";
		do
		{
			ch = getch();
			if (ch == 'Y' || ch == 'y')
			{
				//вводим новые значения
				InputRobot(Robot);
				//переходим на старое место
				fsetpos(f, &q);
				//записываем новые значения
				fwrite(&Robot, sizeof(Robot), 1, f);
				std::cout << "Данные обновлены.\n";
			}
			if (ch == 'N' || ch == 'n')
			{
				std::cout << "Данные не обновлены.\n";
			}
		} while (!(ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n'));
		std::cout << "\nДля продолжения нажмите любую клавишу\n";
		getch();
		potok.close();
	}
	else
	{
		std::cout << "\nВыберите файл для работы.\n"
			<< "Нажмите [ 1 ] в разделе М Е Н Ю.";
		getch();
	}
}

void DeleteRobot(const char TName2, Trobot_footballers& Robot, int flag)
{
	long i=0, k=0;	// сервисные переменные: i - номер записи для удаления
  					// k - номер записи, записываемой во временный файл "Temp"
  TFile *g;			// описание новой файловой переменной
  if ( flag )
    {
	f = fopen(&TName2, "r");

	cout<<"********  Удаление записи с заданным номером  ********\n\n"
	    <<"********************************************************\n\n"
	    <<"Введите номер записи для удаления "
	    <<"из "
	    <<(filesize(f)/sizeof(Robot))
	    <<" --> ";
	cin >> i;

	//перемещаемся на запись с номером i
	fseek(f, (i-1) * sizeof(Robot) , SEEK_CUR);
	fread(&Robot , sizeof(Robot), 1, f);
	OutputRobot(Robot);
	cout<<"****************************************\n";

	char ch;
	cout<<"Удалить данные?\nНажмите [ Y ] / [ N ]\n";
	do
	   {
	   //clrscr();
	   ch = getch();
	   if (ch == 'Y' || ch == 'y')
		{
		fseek(f, 0L, SEEK_SET);
		cout<<"****"<< ftell(f);
		g = fopen("Temp", "w");
		while ( fread(&Robot, sizeof(Robot) , 1, f)  )
		  {
		  	if (k != (i-1) ) fwrite(&Robot, sizeof(Robot), 1, g);
		  	k++;
		  }
		cout<<"Данные обновлены.\n";
		fclose(g);
		fclose(f);
		remove(&TName2); 	//удаляем старый файл
		rename("Temp", &TName2);//переименовываем временный файл
		}
	   if (ch == 'N' || ch == 'n')
		{
			cout<<"Данные не обновленны.\n";
		}
	   }
	while ( ! (ch =='Y' || ch=='y' || ch=='N'  || ch=='n'));
    cout<<"\nДля продолжения нажмите любую клавашу\n";
    getch();
    //fclose(f);
    }
    else
    {
      cout<<"\nВыберите файл для работы.\n"
          <<"Нажмите [ 1 ] в разделе М Е Н Ю.";
      getch();
    }
}

void SearchRobot()
{
	int i = 0;
    const char id= Robot.id;
	if (flag)
	{
		f = fopen(TName2, "r");
		char search[15];
		std::cout << "Введите id робота для поиска --> ";
		cin.getline(search, 15);

		std::cout << "********  Поиск робота в базе данных  ********\n"
			<< "****************************************\n";
		while (fread(&Robot, sizeof(Robot), 1, f))
		{


			if (strcmp(search, &id) == 0)
			{
				std::cout << "Номер записи = " << i + 1 << "\n\n";
				OutputRobot(Robot);
				std::cout << "****************************************" << sizeof(Robot) << "\n";
				i++;
				if (i % 3 == 0)  //вывод по несколько роботов
				{
					getch();
					system("cls");
					std::cout << "********  Поиск робота в базе данных  ********\n"
						<< "****************************************\n";
				}
			}
		}

		getch();
		fclose(f);
	}
	else
	{
		std::cout << "\nВыберите файл для работы.\n"
			<< "Нажмите [ 1 ] в разделе М Е Н Ю.";
		getch();
	}
}

int main()
{
	setlocale(0, "Russian");
	char ch;
	system("cls");
	Trobot_footballers Robot;
	string TName = "DefaultFile";//название файла
	const char *  TName2 = "DefaultFile";//для старых функций
	std::fstream potok;
	do
	{
		menu();
		ch = getch();
		switch (ch)
		{
		case '1':
		    system("cls");
			CreateOpenFile( TName,flag,potok,TName2); //создание и открытие файла базы данных
			break;
		case '2':
		    system("cls");
			InputRobot( Robot);
			AddRobot(TName,Robot,flag,potok) ;//запись данных в файл
			//getch();
			break;
		case '3':
		    system("cls");
			std::cout << "Удаление робота из базы данных\n";
			DeleteRobot(*TName2,Robot,flag);//TODO
			getch();
			break;
		case '4':
		    system("cls");	// вывод файла на экран
			VivodFile(TName,potok);
			break;
		case '5':
		    system("cls");		//Обновление записи с заданным номером
			UpdateRobot(TName,Robot, flag,potok);
			break;
		case '6':
			system("cls");
			std::cout << "Выполнение задания в соответствии с вариантом\n";
			SearchRobot();
			getch();

			break;
		}
	} while (ch != 27);
	return 0;
}
