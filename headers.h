#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Books
{
private:
	char* title;		// название книги
	int countPages;		// количество страниц
	int circulation;	// тираж

public:
	Books(char*, int, int);		// конструктор с параметрами
	Books();					// конструктор по умолчанию
	Books(const Books& obj);	// конструктор копирования
	~Books();					// деструктор
	void Print();				// печать
	void Change();				// изменение значений
	Books Sum(Books);			// сложение объектов
	Books createFunction();
};