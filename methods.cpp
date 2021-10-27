#include "headers.h"

Books::Books(char* name, int page, int circ) // конструктор с параметрами
{
	title = new char[strlen(name) + 1];
	strcpy(title, name);
	countPages = page;
	circulation = circ;
}

Books::Books() // конструктор по умолчанию
{
	countPages = 10;
	circulation = 0;
	title = new char[1];
	title[0] = '\0';
}

Books::Books(const Books& B) // конструктор копирования
{
	title = new char[strlen(B.title) + 1];
	strcpy(title, B.title);
	countPages = B.countPages;
	circulation = B.circulation;
}

Books::~Books() // деструктор
{
	//cout << "~Books" << endl << title << endl;
	delete[] title;
}

void Books::Print() // печать объекта класса
{
	cout << "\nНазвание: " << title << endl << "Кол-во страниц: " << countPages << endl << "Тираж: " << circulation << "\n\n";
}

void Volume::Print() // печать объекта класса
{
	cout << "\nНазвание: " << title << endl << "Кол-во страниц: " << countPages << endl
		<< "Тираж: " << circulation << endl << "Том: " << volume << "\n\n";
}

void Comics::Print() // печать объекта класса
{
	cout << "\nНазвание: " << title << endl << "Кол-во страниц: " << countPages << endl
		<< "Тираж: " << circulation << endl << "Рейтинг: " << rating << "\n\n";
}

Books Books::Sum(Books Book1) // сложение двух объектов класса
{

	char* tempName = new char[strlen(title) + strlen(Book1.title) + 1];

	memcpy(tempName, title, strlen(title));
	memcpy(tempName + strlen(title), Book1.title, strlen(Book1.title) + 1);

	Books Book3(tempName, Book1.countPages + countPages, Book1.circulation + circulation);

	delete[] tempName;

	return Book3;
}

void Books::Change(char* name, int page, int circ) // изменение значений объекта класса
{

	if (name[0] != '0')
	{
		delete[] title;
		title = new char[strlen(name) + 1];
		memcpy(title, name, strlen(name) + 1);
	}
	if (page != 0)
	{
		countPages = page;
	}
	if (circ != 0)
	{
		circulation = circ;
	}
	delete[] name;
}

void Comics::Rating() {
	srand(static_cast<unsigned int>(time(0)));
	rating = (float)(rand() % 50) / 10.0;
}

Books Books::operator +(Books& Book1) // перегрузка оператора +
{
	char* tempName = new char[strlen(title) + strlen(Book1.title) + 1];

	memcpy(tempName, title, strlen(title));
	memcpy(tempName + strlen(title), Book1.title, strlen(Book1.title) + 1);

	Books Book3(tempName, Book1.countPages + countPages, Book1.circulation + circulation);

	delete[] tempName;

	return Book3;
}

Books& Books::operator ++()
{
	++countPages;
	++circulation;
	return *this;
}

Volume& Volume::operator ++()
{
	++countPages;
	++circulation;
	++volume;
	return *this;
}

Books Books::operator ++(int)
{
	Books B(*this);
	countPages++;
	circulation++;
	return B;
}

Books::operator float()
{
	return (float)countPages;
}

List::List()
{
	Node* nd = new Node;
	nd->ptr = nd;
	head = nd;
	count++;
}

List::List(Books& B)
{
	Node* nd = new Node;
	nd->book = B;
	nd->ptr = nd;
	head = nd;
	count++;
}

Node::~Node()
{
	//cout << "~Node" << endl;
	//book.Print();
}

List::~List()
{
	//cout << "~List" << endl;
	//head->book.Print();
}

Node* List::findNode(int n)
{
	Node* elem = head;
	
	cout << "find" << n << endl;

	while (n != 0)
	{
		elem = elem->ptr;
		n--;
	}

	elem->book.Print();
	cout << "-----\n";

	return elem;
}

Node* List::getLast()
{
	Node* elem = head;
	int k = count;
	while (k != 1) 
	{
		elem = elem->ptr;
		k--;
	};

	//cout << "last\n";
	//elem->book.Print();
	//cout << "-----\n";

	return elem;
}

void List::Print()
{
	if (count == 0) { cout << "Список пуст" << endl; return; }
	Node* p = head;
	do {
		p->book.Print();
		p = p->ptr;
	} while (p != head);
}

void List::Add(Books& B, Node* nd)
{
	Node* elem = new Node, *p;
	if (nd == NULL)
	{
		getLast()->ptr = elem;
		p = head;
		head = elem;

		elem->ptr = p;
		elem->book = B;

	}
	else
	{
		p = nd->ptr;		// сохранение указателя на следующий элемент
		nd->ptr = elem;		// предыдущий узел указывает на создаваемый
		elem->book = B;		// сохранение поля данных добавляемого узла
		elem->ptr = p;		// созданный узел указывает на следующий элемент
	}

	count++;
}

void List::Push(Books& B) 
{
	Node* elem = new Node, *p, *nd = getLast();

	p = nd->ptr;		
	nd->ptr = elem;		
	elem->book = B;		
	elem->ptr = p;

	count++;
}

Node* List::Del(Node* elem) {
	Node* p;

	p = elem;
	while (p->ptr != elem) // поиск предыдущего узла
	{
		p = p->ptr;
	}
	p->ptr = elem->ptr;
	count--;

	return(elem);
}

Node* List::Pop() {
	Node* p = getLast(), *elem = getLast();

	while (p->ptr != elem) // поиск предыдущего узла
	{
		p = p->ptr;
	}
	p->ptr = elem->ptr;
	count--;

	return(elem);
}
