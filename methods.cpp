#include "headers.h"

Books Books::createFunction() // функция создания нового объекта класса через конструктор с параметрами
{
	int page, circ;
	char* tempName = new char[256];
	cout << "\nВведите название, кол-во страниц, тираж:\n";
	cin >> tempName >> page >> circ;
	Books object(tempName, page, circ); // конструктор с параметрами
	delete[] tempName;
	return object;
}

Books::Books(char* name, int page, int circ) // конструктор с параметрами
{
	title = new char[strlen(name) + 1];
	strcpy(title, name);
	countPages = page;
	circulation = circ;
}

Books::Books() // конструктор по умолчанию
{
	countPages = 0;
	circulation = 0;
	title = new char[256];
	title[0] = '\0';
}

Books::Books(const Books &B) // конструктор копирования
{
	title = new char[strlen(B.title) + 1];
	strcpy(title, B.title);
	countPages = B.countPages;
	circulation = B.circulation;
}

Books::~Books() // деструктор
{
	delete [] title;
}

void Books::Print() // печать объекта класса
{
	cout << "\nНазвание: " << title << endl << "Кол-во страниц: " << countPages << endl << "Тираж: " << circulation << "\n\n";
}

Books Books::Sum(Books Book1) // сложение двух объектов класса
{
	Books Book3;

	Book3.countPages = Book1.countPages + countPages;
	Book3.circulation = Book1.circulation + circulation;

	memcpy(Book3.title, title, strlen(title));
	memcpy(Book3.title + strlen(title), Book1.title, strlen(Book1.title) + 1);

	return Book3;
}

void Books::Change() // изменение значений объекта класса
{
	cout << "\nВведите новые значения в порядке: название, страницы, тираж. Если не хотите менять один из параметров, то введите 0\n\n";

	int page, circ;
	char* name = new char[256];

	cin >> name >> page >> circ;

	if (name[0] != '0')
	{
		title = name;
	}
	if (page != 0)
	{
		countPages = page;
	}
	if (circ != 0)
	{
		circulation = circ;
	}
}

