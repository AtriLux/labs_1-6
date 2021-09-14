#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Books
{
	char* title;		// название книги
	int countPages;		// количество страниц
	int circulation;	// тираж

public:
	Books(int, int, char*);		//  онструктор с параметрами
	Books();					//  онструктор по умолчанию
	Books(const Books& obj);	//  онструктор копировани€
	~Books();
	void Print();
	void Change();
	Books Sum(Books);
};