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
		return "Двигатель: кол-во целинтров = " + std::to_string(cylinders) + " объем = " + std::to_string(capacity) + " мощность = " + std::to_string(power);
	}
	void Read()
	{
		puts("Введите кол-во целиндров в двигателе:");
		scanf("%d", &this->cylinders);
		fflush(stdin);

		puts("Введите объем двигателя:");
		scanf("%d", &this->capacity);
		fflush(stdin);

		puts("Введите мощность двигателя:");
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

		printf("\nМарка: %s\n", this->autoBrend);
		printf("Название: %s\n", this->autoName);
		printf("Стоимость: %d\n", this->autoCost);
		printf("Максимальная скорость: %d\n", this->autoMax_speed);
		printf("Год выпуска: %d\n", this->autoYear);
		std::cout << autoeng1.GetInfo() << std::endl << std::endl;
		//printf("\n");

	}

	void Read()
	{

		puts("Введите марку автомобиля:");
		scanf("%s", this->autoBrend);
		fflush(stdin);

		puts("Введите название автомобиля:");
		scanf("%s", this->autoName);
		fflush(stdin);


		puts("Введите стоимость автомобиля:");
		scanf("%d", &this->autoCost);
		fflush(stdin);

		puts("Введите максимальную скорость автомобиля:");
		scanf("%d", &this->autoMax_speed);
		fflush(stdin);

		puts("Введите год выпуска автомобиля:");
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


	puts("Первый автомобиль");

	Auto_show first_auto;
	Engine autoeng(4, 2, 100);
	first_auto.init("lada", "granta", 300, 150, 2017, autoeng);
	first_auto.Display();



	puts("Второй автомобиль");
	Auto_show second_auto;
	second_auto.Read();

	second_auto.Display();

	contest(&first_auto);

	printf("Стоимость двух автомобилей: %d\n", second_auto.Add(first_auto));


	return 0;
}