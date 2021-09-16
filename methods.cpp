#include "headers.h"

Books Books::createFunction() // ������� �������� ������ ������� ������ ����� ����������� � �����������
{
	int page, circ;
	char* tempName = new char[256];
	cout << "\n������� ��������, ���-�� �������, �����:\n";
	cin >> tempName >> page >> circ;
	Books object(tempName, page, circ); // ����������� � �����������
	delete[] tempName;
	return object;
}

Books::Books(char* name, int page, int circ) // ����������� � �����������
{
	title = new char[strlen(name) + 1];
	strcpy(title, name);
	countPages = page;
	circulation = circ;
}

Books::Books() // ����������� �� ���������
{
	countPages = 0;
	circulation = 0;
	title = new char[256];
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
	delete [] title;
}

void Books::Print() // ������ ������� ������
{
	cout << "\n��������: " << title << endl << "���-�� �������: " << countPages << endl << "�����: " << circulation << "\n\n";
}

Books Books::Sum(Books Book1) // �������� ���� �������� ������
{
	Books Book3;

	Book3.countPages = Book1.countPages + countPages;
	Book3.circulation = Book1.circulation + circulation;

	memcpy(Book3.title, title, strlen(title));
	memcpy(Book3.title + strlen(title), Book1.title, strlen(Book1.title) + 1);

	return Book3;
}

void Books::Change() // ��������� �������� ������� ������
{
	cout << "\n������� ����� �������� � �������: ��������, ��������, �����. ���� �� ������ ������ ���� �� ����������, �� ������� 0\n\n";

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

