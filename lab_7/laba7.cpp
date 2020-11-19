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
		std::cout << "Марка: " << this->autoBrend << std::endl;
		std::cout << "Название: " << this->autoName << std::endl;
		std::cout << "Стоимость: " << this->autoCost << std::endl;
		std::cout << "Максимальная скорость: " << this->autoMax_speed << std::endl;
		std::cout << "Год выпуска: " << this->autoYear << std::endl;
		std::cout << autoeng1.GetInfo() << std::endl << std::endl;

	}

	void Read()
	{

		puts("Введите марку автомобиля:");
		std::cin >> this->autoBrend;

		puts("Введите название автомобиля:");
		std::cin >> this->autoName;

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


	puts("Первый автомобиль");

	Auto_show first_auto;
	Engine autoeng(4, 2, 100);
	first_auto.init("lada", "granta", 300, 150, 2017, autoeng);
	first_auto.Display();

	Auto_show::Racingset(5);

	std::cout << "Acceleration to 100: " << Auto_show::Racing() << std::endl;


	return 0;
}