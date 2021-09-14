#include "headers.h"

Books::Books(char* name, int page, int circ)
{
	title = new char[strlen(name) + 1];
	strcpy(title, name);
	countPages = page;
	circulation = circ;
}

Books::Books()
{
	countPages = 0;
	circulation = 0;
	title = new char[1];
	title[0] = '\0';
}

Books::Books(const Books &B) 
{
	title = new char[strlen(B.title) + 1];
	strcpy(title, B.title);
	countPages = B.countPages;
	circulation = B.circulation;
}

Books::~Books()
{
	//cout << title;
	delete [] title;
	cout << "Desrtuctor" << "\n\n";
}

void Books::Print()
{
	cout << "Print\n\ncountPages = " << countPages << endl << "circulation = " << circulation << endl << "title = " << title << "\n\n";
}

Books Books::Sum(Books Book1)
{
	char* tempName = new char[256];
	Books Book3(tempName, 0, 0);
	delete[] tempName;

	Book3.countPages = Book1.countPages + countPages;
	Book3.circulation = Book1.circulation + circulation;

	memcpy(Book3.title, Book1.title, strlen(Book1.title));
	memcpy(Book3.title + strlen(Book1.title), title, strlen(title) + 1);

	return Book3;
}

void Books::Change()
{
	cout << "Введите новые значения в порядке название, страницы, тираж. Если не хотите менять один из параметров, то введите 0\n\n";

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

