#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Books
{
private:
	char* title;		// �������� �����
	int countPages;		// ���������� �������
	int circulation;	// �����

public:
	Books(char*, int, int);		// ����������� � �����������
	Books();					// ����������� �� ���������
	Books(const Books& obj);	// ����������� �����������
	~Books();					// ����������
	void Print();				// ������
	void Change();				// ��������� ��������
	Books Sum(Books);			// �������� ��������
	Books createFunction();
};