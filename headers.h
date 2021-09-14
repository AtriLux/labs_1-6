#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Books
{
	char* title;		// �������� �����
	int countPages;		// ���������� �������
	int circulation;	// �����

public:
	Books(int, int, char*);		// ����������� � �����������
	Books();					// ����������� �� ���������
	Books(const Books& obj);	// ����������� �����������
	~Books();
	void Print();
	void Change();
	Books Sum(Books);
};