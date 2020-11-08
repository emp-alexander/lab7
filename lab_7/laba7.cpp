#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <malloc.h>
#include <iostream>
#include <string>
#pragma warning (disable:4996)
#define SIZE 25


class Engine {
public:
	Engine()
	{

	}
	Engine(int cylinders, int capacity, int power)
	{
		this->cylinders = cylinders;
		this->capacity = capacity;
		this->power = power;
	}
	std::string GetInfo()
	{
		return "���������: ���-�� ��������� = " + std::to_string(cylinders) + " ����� = " + std::to_string(capacity) + " �������� = " + std::to_string(power);
	}
	void Read()
	{
		puts("������� ���-�� ��������� � ���������:");
		scanf("%d", &this->cylinders);
		fflush(stdin);

		puts("������� ����� ���������:");
		scanf("%d", &this->capacity);
		fflush(stdin);

		puts("������� �������� ���������:");
		scanf("%d", &this->power);
		fflush(stdin);
	}

private:
	int cylinders;
	int capacity;
	int power;
};

class Auto_show
{
public:

	Auto_show()
	{

	}
	~Auto_show()
	{

	}

	void init(std::string brend, std::string name, int cost, int max_speed, int year, Engine eng1)
	{
		this->autoBrend = brend;
		this->autoName = name;
		this->autoCost = cost;
		this->autoMax_speed = max_speed;
		this->autoYear = year;
		this->autoeng1 = eng1;

	}

	friend void contest(Auto_show* a);

	void Display()
	{

		printf("\n�����: %s\n", this->autoBrend);
		printf("��������: %s\n", this->autoName);
		printf("���������: %d\n", this->autoCost);
		printf("������������ ��������: %d\n", this->autoMax_speed);
		printf("��� �������: %d\n", this->autoYear);
		std::cout << autoeng1.GetInfo() << std::endl << std::endl;
		//printf("\n");

	}

	void Read()
	{

		puts("������� ����� ����������:");
		scanf("%s", this->autoBrend);
		fflush(stdin);

		puts("������� �������� ����������:");
		scanf("%s", this->autoName);
		fflush(stdin);


		puts("������� ��������� ����������:");
		scanf("%d", &this->autoCost);
		fflush(stdin);

		puts("������� ������������ �������� ����������:");
		scanf("%d", &this->autoMax_speed);
		fflush(stdin);

		puts("������� ��� ������� ����������:");
		scanf("%d", &this->autoYear);
		fflush(stdin);

		autoeng1.Read();

	}

	int Add(Auto_show second)
	{
		return this->autoCost + second.autoCost;
	}



private:
	std::string autoBrend;
	std::string autoName;
	int autoCost;
	int autoMax_speed;
	int autoYear;
	Engine autoeng1;
};


void contest(Auto_show* a) {
	a->autoCost = 0;
}


int main()
{
	setlocale(LC_ALL, "ru");


	puts("������ ����������");

	Auto_show first_auto;
	Engine autoeng(4, 2, 100);
	first_auto.init("lada", "granta", 300, 150, 2017, autoeng);
	first_auto.Display();



	puts("������ ����������");
	Auto_show second_auto;
	second_auto.Read();

	second_auto.Display();

	contest(&first_auto);

	printf("��������� ���� �����������: %d\n", second_auto.Add(first_auto));


	return 0;
}