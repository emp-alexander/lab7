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
		cylinders = 6;
		capacity = 5;
		power = 50;
		
	}

	
	

	

	Engine(int cylinders, int capacity, int power)
	{
		this->cylinders = cylinders;
		this->capacity = capacity;
		this->power = power;
	}
	/*~Engine()
	{

	}*/

	virtual void sound()
	{
		std::cout << "Сильно громкий двигатель" << std::endl;
	}
	

	std::string GetInfo()
	{
		return "Двигатель: кол-во целинтров = " + std::to_string(cylinders) + " объем = " + std::to_string(capacity) + " мощность = " + std::to_string(power);
	}
	void Read()
	{
		puts("Введите кол-во целиндров в двигателе:");
		std::cin >> this->cylinders;

		puts("Введите объем двигателя:");
		std::cin >> this->capacity;

		puts("Введите мощность двигателя:");
		std::cin >> this->power;

	}



protected:
	int cylinders;
	int capacity;
	int power;
	
};

class Electrik_motor : public Engine
{

public:

	Electrik_motor(int nalichie) : Engine()
	{
		this->nalichie = nalichie;
	}


	Electrik_motor() : Engine()
	{
		nalichie = 1;
		//power_reserve = 450;
		//battery = 500;
	}

	void sound() override
	{
		std::cout << "двигатель бесшумен" << std::endl;
	}

	std::string GetInfoE()
	{
		return "Электродвигатель: " + std::to_string(nalichie);
	}

private:
	int nalichie; //1-есть электодвигатель //2- нет электородвигателя
	//int power_reserve;
	//int battery;
};

class Auto_show
{
public:



	//конструктор со всеми параметрами
	Auto_show(std::string brend, std::string name, int cost, int max_speed, int year, Electrik_motor eng1)
	{
		this->autoBrend = brend;
		this->autoName = name;
		this->autoCost = cost;
		this->autoMax_speed = max_speed;
		this->autoYear = year;
		this->autoeng1 = eng1;
	
		std::cout << "Constructor with all parameters." << std::endl;
	}


	//конструктор с 1 пармаетром

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

	//конструктор без параметров
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

	//перегр =
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
		std::cout << "Марка: " << this->autoBrend << std::endl;
		std::cout << "Название: " << this->autoName << std::endl;
		std::cout << "Стоимость: " << this->autoCost << std::endl;
		std::cout << "Максимальная скорость: " << this->autoMax_speed << std::endl;
		std::cout << "Год выпуска: " << this->autoYear << std::endl;
		std::cout << autoeng1.GetInfoE() << std::endl << std::endl;

	}

	void Read()
	{

		puts("Введите марку автомобиля:");
		std::cin >> this->autoBrend;

		puts("Введите название автомобиля:");
		std::cin >> this->autoName;

		puts("Введите стоимость автомобиля:");
		std::cin >> this->autoCost;
		//scanf("%d", &this->autoCost);
		//fflush(stdin);

		puts("Введите максимальную скорость автомобиля:");
		
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



		puts("Введите год выпуска автомобиля:");
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

	//void setEng(const Engine& eEngine)
	//{
	//	this->autoeng1 = eEngine;
	//}
	//friend std::istream& operator>>(std::istream& in, Auto_show& w);

	friend std::ostream& operator<< (std::ostream& out, const Auto_show& a);
	friend std::istream& operator>> (std::istream& in, Auto_show& a);

private:
	std::string autoBrend;
	std::string autoName;
	int autoCost;
	int autoMax_speed;
	int autoYear;
	Electrik_motor autoeng1;
	static int racing;
};




std::ostream& operator<< (std::ostream& out, const Auto_show& a)
{
	
	out << "Марка: " << a.autoBrend << std::endl;
	out << "Название: " << a.autoName << std::endl;
	out << "Стоимость: " << a.autoCost << std::endl;
	out << "Скорость: " << a.autoMax_speed << std::endl;
	out << "Год: " << a.autoYear << std::endl;

	return out;
}

std::istream& operator>> (std::istream& in, Auto_show& a)
{
	std::cout << "Введите марку:" << std::endl;
	in >> a.autoBrend;
	std::cout << "Введите название:" << std::endl;
	in >> a.autoName;
	std::cout << "Введите стоимоть:" << std::endl;
	in >> a.autoCost;
	std::cout << "Введите скорость:" << std::endl;
	in >> a.autoMax_speed;
	std::cout << "Введите год:" << std::endl;
	in >> a.autoYear;

	return in;
}

int Auto_show::racing = 4;

void contest(Auto_show* a) {
	a->autoCost = 0;
}


int main()
{
	setlocale(LC_ALL, "ru");

	

	
	Electrik_motor first(0);
	Auto_show first_auto("Car", "htyj", 200, 25, 2014, 0);
	first.sound();
	
	std::cout << first.GetInfoE() << std::endl << std::endl;

	//first_auto.Display();
	

	//puts("Первый автомобиль");
	////одномерный
	//int lenght = 0;
	//std::cout << "Input array length:" << std::endl;
	//std::cin >> lenght;
	//Auto_show* car_array = new Auto_show[lenght];

	//for (int i = 0; i < lenght; i++)
	//{
	//	car_array[i].setEng(Engine(4, 2, 100));
	//	car_array[i].Display();
	//}
	//delete[] car_array;

	////двумерный

	//std::cout << "Single-dimensional array M x N. Input  M, N: " << std::endl;
	//int m, n;
	//std::cin >> m >> n;
	//Auto_show** car_d_array = new Auto_show * [m];
	//for (int i = 0; i < m; i++)
	//{
	//	car_d_array[i] = new Auto_show[n];
	//	for (int j = 0; j < n; j++)
	//	{
	//		std::cin >> car_d_array[i][j];
	//	}
	//}

	//for (int i = 0; i < m; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//		std::cout << "Object::Auto_show[" << i << "][" << j << "]" << std::endl << car_d_array[i][j] << std::endl;
	//}


	//for (int i = 0; i < m; i++)
	//	delete[] car_d_array[i];
	//delete[] car_d_array;


	Engine* e = new Engine();
	e->sound();
	delete e;

	e = new Electrik_motor();
	e->sound();
	delete e;

	return 0;
}