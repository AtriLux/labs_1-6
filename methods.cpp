#include "headers.h"

Books::Books(char* name, int page, int circ) // ����������� � �����������
{
	title = new char[strlen(name) + 1];
	strcpy(title, name);
	countPages = page;
	circulation = circ;
}

Books::Books() // ����������� �� ���������
{
	countPages = 10;
	circulation = 0;
	title = new char[1];
	title[0] = '\0';
}

Books::Books(const Books &B) // ����������� �����������
{
	title = new char[strlen(B.title) + 1];
	strcpy(title, B.title);
	countPages = B.countPages;
	circulation = B.circulation;
}

Books::~Books() // ����������
{
	//cout << "~Books" << endl << title << endl;
	delete [] title;
}

void Books::Print() // ������ ������� ������
{
	cout << "\n��������: " << title << endl << "���-�� �������: " << countPages << endl << "�����: " << circulation << "\n\n";
}

void Volume::Print() // ������ ������� ������
{
	cout << "\n��������: " << title << endl << "���-�� �������: " << countPages << endl 
		<< "�����: " << circulation << endl << "���: " << volume << "\n\n";
}

void Comics::Print() // ������ ������� ������
{
	cout << "\n��������: " << title << endl << "���-�� �������: " << countPages << endl 
		<< "�����: " << circulation << endl << "�������: " << rating << "\n\n";
}

Books Books::Sum(Books Book1) // �������� ���� �������� ������
{
	
	char* tempName = new char[strlen(title) + strlen(Book1.title) + 1];

	memcpy(tempName, title, strlen(title));
	memcpy(tempName + strlen(title), Book1.title, strlen(Book1.title) + 1);

	Books Book3(tempName, Book1.countPages + countPages, Book1.circulation + circulation);

	delete[] tempName;

	return Book3;
}

void Books::Change(char* name, int page, int circ) // ��������� �������� ������� ������
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

Books Books::operator +(Books &Book1) // ���������� ��������� +
{
	char* tempName = new char[strlen(title) + strlen(Book1.title) + 1];

	memcpy(tempName, title, strlen(title));
	memcpy(tempName + strlen(title), Book1.title, strlen(Book1.title) + 1);

	Books Book3(tempName, Book1.countPages + countPages, Book1.circulation + circulation);

	delete[] tempName;

	return Book3;
}

Books &Books::operator ++()
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

Node* List::Next(Node* nd)
{
	if (count == 0) { return NULL; }
	return nd->ptr;
}

Node* List::findNode(int n)
{
	Node* elem = head;
	while (n != 1) 
	{
		elem = elem->ptr;
		n--;
	}
	return elem;
}

void List::Print()
{
	if (count == 0) { cout << "������ ����" << endl; return; }
	Node* p = head;
	do {
		p->book.Print();
		p = p->ptr;
	} while (p != head);
}

Node* List::Add(Books& B, Node* nd)
{
	Node* elem, *p;
	elem = new Node;
	if (nd == NULL) 
	{
		p = head;
		head = elem;
		p->ptr = elem;
	}
	else
	{
		p = nd->ptr;	// ���������� ��������� �� ��������� �������
		nd->ptr = elem; // ���������� ���� ��������� �� �����������
	}
	elem->book = B;		// ���������� ���� ������ ������������ ����
	elem->ptr = p;		// ��������� ���� ��������� �� ��������� �������
	count++;
	return(elem);
}
