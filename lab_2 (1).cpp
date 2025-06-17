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
	int role;//1 � ������ 0 � �����
	int position[2];
	bool hasball;
	float speed;
	float dir_speed[2];//���������� ������� �������� ������
	Tsizes size_robot;
};

//��� ������ ��� ����� �����
string TName = "DefaultFile";

char TName2[25]{};//�������� ����� ��� ������� ����� c
//��� ������ ��� �������� ����������
typedef FILE TFile;
//���������� ��� ������
Trobot_footballers Robot;

//�������� ����������
TFile* f;
//���� ������ ����� ��� ������
int flag = 0;

std::fstream potok;

bool fl = 0;

void menu(void)//���� ���������� ���� �����������
{
	system("cls");
	std::cout << "******** � � � � ********\n\n"
		<< "[1]-�������� ������ ������ � ����\n"
		<< "[2]-���������� ������ � ����\n"
		<< "[3]-�������� ������ �� ����\n"
		<< "[4]-�������� ���� ���� �������-�����������\n"
		<< "[5]-���������� ������ � ������ � �������� �������\n"
		<< "[6]-����� ������ �� ��������.\n"
		<< "[ ESC ]-�����\n";
}

void InputRobot(Trobot_footballers &Robot)
{
	cin.clear(); //�������� ����� � ����� ��������� ���������������� � 0
	while (!isspace(cin.get())) //���������� �� ����������� ��������� �����
		continue;

	std::cout << "���������� ������ ������ � ����:\n";

	std::cout << "id ������ ->"; //gets(Tovar.name);

	cin >> Robot.id;

	std::cout << "\n�������������� ������\n";

	std::cout << "�����->";
	cin >> Robot.size_robot.lenght;

	std::cout << "������->";
	cin >> Robot.size_robot.width;

	std::cout << "����->";
	cin >> Robot.role;

	std::cout << "������� x(����� �����)->";
	cin >> Robot.position[0];

	std::cout << "������� y(����� �����)->";
	cin >> Robot.position[1];

	std::cout << "����� ���->";
	cin >> Robot.hasball;

	std::cout << "��������->";
	cin >> Robot.speed;

	cin.clear(); //�������� ����� � ����� ��������� ���������������� � 0
	while (!isspace(cin.get()))
		continue;            //���������� �� ����������� ��������� �����

}

void OutputRobot(Trobot_footballers Robot)
{
	std::cout << "ID ������: " << Robot.id << "\n"
		<< "�����,������ ������: "
		<< Robot.size_robot.lenght << "," << Robot.size_robot.width << ":" << "\n"
		<< "���� �� ���� 1-�����,0-������" << Robot.role << "\n"
		<< "������� ������ " << Robot.position << "\n"
		<< "�������� ������ " << Robot.speed << "\n";
}

void CreateOpenFile(string &TName,int& flag,std::fstream &potok,const char *&TName2,FILE *opfile)
{
	char ch;
	flag = 0;
	char *TName3;
	std::cout << "������� ��� ����� ��� ������-->";
    opfile = fopen(TName2,"r");
	string buf;//����� ��� ������ ������ �������� �����

	getline(cin,buf);//�������� �������� ����� �� ������

	TName = buf;
	fgets(TName3,25,potok);
    TName2=TName3;
	potok.open(TName, std::ios::ate);
	cout << "���� � ������ " << TName << "������/������\n";
	getch();
}

void AddRobot(string TName, Trobot_footballers& Robot, int flag,std::fstream &potok)
{
	if (flag)
	{
		InputRobot(Robot);
		////fwrite(&Robot, sizeof(Robot), 1, f);
		//int id;
		//int role;//1 � ������ 0 � �����
		//int position[2];
		//bool hasball;
		//float speed;
		//float dir_speed[2];//���������� ������� �������� ������
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
		std::cout << "\n�������� ���� ��� ������.\n"
			<< "������� [ 1 ] � ������� � � � �.";
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
		std::cout << "********  ����� ����� �� �����  ********\n"
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
		std::cout << "\n�������� ���� ��� ������.\n"
			<< "������� [ 1 ] � ������� � � � �.";
		getch();
	}

}

long filesize(TFile* f)
{
	long curpos, length;

	curpos = ftell(f);		//���������� ������� ���������
	fseek(f, 0L, SEEK_END);	//���������� �� ����� �����
	length = ftell(f);		//���������� ��������� � ����� �����
	fseek(f, curpos, SEEK_SET);	//���������� �� ������ ���������
	return length;
}

void UpdateRobot(string TName, Trobot_footballers& Robot, int flag,std::fstream &potok)
{
	long i = 0;
	if (flag)
	{

        potok.open(TName,std::ios::app);
		std::cout << "********  ���������� ������ � �������� �������  ********\n\n"
			<< "********************************************************\n\n"
			<< "������� ����� ������ ��� ���������� "
			<< "�� "
			<< (filesize(f) / sizeof(Robot))
			<< " --> ";
		cin >> i;
		fpos_t q;//���������� ���� ������ ������� ������ ����� ������� ��� ������� setpos ��� getpos
		//������������ �� ������ � ������� i
		fseek(f, (i - 1) * sizeof(Robot), SEEK_CUR);
		//���������� ������� ���������
		fgetpos(f, &q);

		fread(&Robot, sizeof(Robot), 1, f);
		OutputRobot(Robot);
		std::cout << "****************************************\n";

		char ch;
		std::cout << "�������� ������?\n������� [ Y ] / [ N ]\n";
		do
		{
			ch = getch();
			if (ch == 'Y' || ch == 'y')
			{
				//������ ����� ��������
				InputRobot(Robot);
				//��������� �� ������ �����
				fsetpos(f, &q);
				//���������� ����� ��������
				fwrite(&Robot, sizeof(Robot), 1, f);
				std::cout << "������ ���������.\n";
			}
			if (ch == 'N' || ch == 'n')
			{
				std::cout << "������ �� ���������.\n";
			}
		} while (!(ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n'));
		std::cout << "\n��� ����������� ������� ����� �������\n";
		getch();
		potok.close();
	}
	else
	{
		std::cout << "\n�������� ���� ��� ������.\n"
			<< "������� [ 1 ] � ������� � � � �.";
		getch();
	}
}

void DeleteRobot(const char TName2, Trobot_footballers& Robot, int flag)
{
	long i=0, k=0;	// ��������� ����������: i - ����� ������ ��� ��������
  					// k - ����� ������, ������������ �� ��������� ���� "Temp"
  TFile *g;			// �������� ����� �������� ����������
  if ( flag )
    {
	f = fopen(&TName2, "r");

	cout<<"********  �������� ������ � �������� �������  ********\n\n"
	    <<"********************************************************\n\n"
	    <<"������� ����� ������ ��� �������� "
	    <<"�� "
	    <<(filesize(f)/sizeof(Robot))
	    <<" --> ";
	cin >> i;

	//������������ �� ������ � ������� i
	fseek(f, (i-1) * sizeof(Robot) , SEEK_CUR);
	fread(&Robot , sizeof(Robot), 1, f);
	OutputRobot(Robot);
	cout<<"****************************************\n";

	char ch;
	cout<<"������� ������?\n������� [ Y ] / [ N ]\n";
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
		cout<<"������ ���������.\n";
		fclose(g);
		fclose(f);
		remove(&TName2); 	//������� ������ ����
		rename("Temp", &TName2);//��������������� ��������� ����
		}
	   if (ch == 'N' || ch == 'n')
		{
			cout<<"������ �� ����������.\n";
		}
	   }
	while ( ! (ch =='Y' || ch=='y' || ch=='N'  || ch=='n'));
    cout<<"\n��� ����������� ������� ����� �������\n";
    getch();
    //fclose(f);
    }
    else
    {
      cout<<"\n�������� ���� ��� ������.\n"
          <<"������� [ 1 ] � ������� � � � �.";
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
		std::cout << "������� id ������ ��� ������ --> ";
		cin.getline(search, 15);

		std::cout << "********  ����� ������ � ���� ������  ********\n"
			<< "****************************************\n";
		while (fread(&Robot, sizeof(Robot), 1, f))
		{


			if (strcmp(search, &id) == 0)
			{
				std::cout << "����� ������ = " << i + 1 << "\n\n";
				OutputRobot(Robot);
				std::cout << "****************************************" << sizeof(Robot) << "\n";
				i++;
				if (i % 3 == 0)  //����� �� ��������� �������
				{
					getch();
					system("cls");
					std::cout << "********  ����� ������ � ���� ������  ********\n"
						<< "****************************************\n";
				}
			}
		}

		getch();
		fclose(f);
	}
	else
	{
		std::cout << "\n�������� ���� ��� ������.\n"
			<< "������� [ 1 ] � ������� � � � �.";
		getch();
	}
}

int main()
{
	setlocale(0, "Russian");
	char ch;
	system("cls");
	Trobot_footballers Robot;
	string TName = "DefaultFile";//�������� �����
	const char *  TName2 = "DefaultFile";//��� ������ �������
	std::fstream potok;
	do
	{
		menu();
		ch = getch();
		switch (ch)
		{
		case '1':
		    system("cls");
			CreateOpenFile( TName,flag,potok,TName2); //�������� � �������� ����� ���� ������
			break;
		case '2':
		    system("cls");
			InputRobot( Robot);
			AddRobot(TName,Robot,flag,potok) ;//������ ������ � ����
			//getch();
			break;
		case '3':
		    system("cls");
			std::cout << "�������� ������ �� ���� ������\n";
			DeleteRobot(*TName2,Robot,flag);//TODO
			getch();
			break;
		case '4':
		    system("cls");	// ����� ����� �� �����
			VivodFile(TName,potok);
			break;
		case '5':
		    system("cls");		//���������� ������ � �������� �������
			UpdateRobot(TName,Robot, flag,potok);
			break;
		case '6':
			system("cls");
			std::cout << "���������� ������� � ������������ � ���������\n";
			SearchRobot();
			getch();

			break;
		}
	} while (ch != 27);
	return 0;
}
