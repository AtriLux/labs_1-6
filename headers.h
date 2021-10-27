#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <iostream>
#include <fstream>
#include <io.h>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <new>
#include <stdexcept>

#define MAX 256

using namespace std;

class Books
{
protected:
	char* title;		// �������� �����
	int countPages;		// ���������� �������
	int circulation;	// �����
public:
	Books(char*, int, int);							// ����������� � �����������
	Books();										// ����������� �� ���������
	Books(const Books& obj);						// ����������� �����������
	~Books();										// ����������
	virtual void Print();							// ������
	void Change(char* name, int page, int circ);	// ��������� ��������
	Books Sum(Books);								// �������� ��������
	Books operator +(Books& B);						// ���������� ��������� +
	friend Books operator -(Books& B1, Books& B2);	// ���������� ��������� -
	Books& operator ++();							// ���������� ����������� ����������
	Books operator ++(int);							// ���������� ������������ ����������
	operator float();								// ���������� ����������� ����
	//lab 3
	friend ofstream& operator << (ofstream& out, Books& B);
	friend fstream& operator << (fstream& out, Books& B);
	friend fstream& operator >> (fstream& in, Books& B);
};

class Node
{
	Books book;
	class Node* ptr;
	friend class List;
public:
	~Node();
};

class List
{
	Node* head;
	int count = 0;
public:
	List();
	List(Books&);
	~List();
	Node* getLast();
	Node* findNode(int);
	void Print();
	void Add(Books&, Node*);
	void Push(Books&);
	Node* Del(Node*);
	Node* Pop();
	Node* getHead() { return head; };
};

class Volume : public Books {
	int volume;
public:
	Volume(char* name, int page, int circ, int vol = 1) : Books(name, page, circ) { volume = vol; }
	Volume() : Books() { volume = 0; }
	Volume(const Volume& obj) : Books(obj) { volume = obj.volume; }
	void Print();
	Volume& operator ++();
};

class Comics : public Books {
	float rating;
public:
	Comics(char* name, int page, int circ, float rate = 0.0f) : Books(name, page, circ) { rating = rate; }
	Comics() : Books() { rating = 0.0f; }
	Comics(const Comics& obj) : Books(obj) { rating = obj.rating; }
	void Print();
	void Rating();
};