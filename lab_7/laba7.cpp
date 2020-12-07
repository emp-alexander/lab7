#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <malloc.h>
#include <iostream>
#include <string>
#include <fstream>
#pragma warning (disable:4996)
#define SIZE 25


class Engine {
public:
	Engine()
	{
		cylinders = 6;
		capacity = 5;
		this->power = new int(50);
		
	}

	Engine(const Engine& oth)
	{
		std::cout << "Constructor deep copy" << std::endl;
		cylinders = oth.cylinders;
		capacity = oth.capacity;
		power = new int(*oth.power);

	}

	

	

	Engine(int cylinders, int capacity, int power)
	{
		this->cylinders = cylinders;
		this->capacity = capacity;
		this->power = new int(power);
	}
	~Engine()
	{

	}

	
	

	std::string GetInfo()
	{
		return "���������: ���-�� ��������� = " + std::to_string(cylinders) + " ����� = " + std::to_string(capacity) + " �������� = " + std::to_string(*power);
	}
	void Read()
	{
		puts("������� ���-�� ��������� � ���������:");
		std::cin >> this->cylinders;

		puts("������� ����� ���������:");
		std::cin >> this->capacity;

		puts("������� �������� ���������:");
		std::cin >> *this->power;

	}

	Engine& operator=(const Engine& oth)
	{
		
		cylinders = oth.cylinders;
		capacity = oth.capacity;
		power = new int(*oth.power);

		return *this;
	}

private:
	int cylinders;
	int capacity;
	int* power;
	
};

class Auto_show
{
public:



	//����������� �� ����� �����������
	Auto_show(std::string brend, std::string name, int cost, int max_speed, int year, Engine eng1)
	{
		this->autoBrend = brend;
		this->autoName = name;
		this->autoCost = cost;
		this->autoMax_speed = max_speed;
		this->autoYear = year;
		this->autoeng1 = eng1;
		std::cout << "Constructor with all parameters." << std::endl;
	}


	//����������� � 1 ����������

	Auto_show(int year)
	{
		autoBrend = "Lada";
		autoName = "Niva";
		autoCost = 100;
		autoMax_speed = 150;
		this->autoYear = year;
		std::cout << "Constructor with one parameter." << std::endl;
	}

	Auto_show(const Auto_show& a) :
		autoBrend(a.autoBrend),
		autoName(a.autoName),
		autoCost(a.autoCost),
		autoMax_speed(a.autoMax_speed),
		autoYear(a.autoYear),
		autoeng1(a.autoeng1)
	{
		std::cout << "Contstructor shallow copy." << std::endl;
	}

	//����������� ��� ����������
	Auto_show()
	{
		autoBrend = "Lada";
		autoName = "Niva";
		autoCost = 100;
		autoMax_speed = 150;
		autoYear = 2015;
		std::cout << "Constructor without parameters." << std::endl;
	}


	~Auto_show()
	{

	}

	//������ =
	Auto_show& operator= (const Auto_show &oth)
	{
		autoBrend = oth.autoBrend;
		autoName = oth.autoName;
		autoCost = oth.autoCost;
		autoMax_speed = oth.autoMax_speed;
		autoYear = oth.autoYear;
		autoeng1 = oth.autoeng1;
		return *this;
	}



	
	friend void contest(Auto_show* a);

	void Display()
	{
		std::cout << "�����: " << this->autoBrend << std::endl;
		std::cout << "��������: " << this->autoName << std::endl;
		std::cout << "���������: " << this->autoCost << std::endl;
		std::cout << "������������ ��������: " << this->autoMax_speed << std::endl;
		std::cout << "��� �������: " << this->autoYear << std::endl;
		std::cout << autoeng1.GetInfo() << std::endl << std::endl;

	}

	void Read()
	{

		puts("������� ����� ����������:");
		std::cin >> this->autoBrend;

		puts("������� �������� ����������:");
		std::cin >> this->autoName;

		puts("������� ��������� ����������:");
		std::cin >> this->autoCost;
		//scanf("%d", &this->autoCost);
		//fflush(stdin);

		puts("������� ������������ �������� ����������:");
		
		try
		{
			std::cin >> this->autoMax_speed;
			if (autoMax_speed < 0)
				throw "Speed cannot be negative";
		}
		catch (const char* exception)
		{
			std::cerr << "Error:" << exception << '\n';
		}



		puts("������� ��� ������� ����������:");
		std::cin >> this->autoYear;

		autoeng1.Read();

	}

	int Add(Auto_show second)
	{
		return this->autoCost + second.autoCost;
	}

	int operator+ (Auto_show& dif)
	{
		return autoCost + dif.autoCost;
	}


	int operator++()
	{
		return ++autoCost;
	}

	int operator++(int)
	{
		return ++autoYear;
	}

	void CostAddr(int& autoCost)
	{
		autoCost = this->autoCost;
		return;
	}

	void SpeedPtr(int* autoMax_speed)
	{
		*autoMax_speed = this->autoMax_speed;
		return;
	}
	static int Racing() {
		return racing;
	}

	static void Racingset(int r) {
		racing = r;
	}



private:
	std::string autoBrend;
	std::string autoName;
	int autoCost;
	int autoMax_speed;
	int autoYear;
	Engine autoeng1;
	static int racing;
};

int Auto_show::racing = 4;

void contest(Auto_show* a) {
	a->autoCost = 0;
}


int main()
{
	setlocale(LC_ALL, "ru");
	std::string path = "CarFile.txt";

	puts("������ ����������");

	

	///////
	Engine autoeng(4, 2, 100);
	Auto_show first_auto;
	Auto_show two_auto(2013);
	Auto_show auto3("BMW", "M5", 500, 290, 2019, autoeng);

	Auto_show tmp_auto;
	tmp_auto.Read();
	tmp_auto.Display();

	//////�������.
	//
	//Auto_show* car3;
	//try {
	//	Engine autoeng3(6, 2, 100);
	//	car3 = new Auto_show("BMW", "M3", 300, 230, 2018, autoeng3);
	//	car3->Display();
	//}
	//catch (std::bad_alloc) {
	//	std::cerr << "Exception::No memmory!" << std::endl;
	//}
	//
	//delete car3;

	std::ifstream fin;
	fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);

	try
	{
		std::cout << "������� ������� ����!" << std::endl;
		fin.open(path);
		std::cout << "���� ������!" << std::endl;
	}
	catch (const std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
		std::cout << "Error open file" << std::endl;
	}



	return 0;
}