﻿#include "headers.h"

Books createFunction();

int main()
{
    system("cls");
    setlocale(LC_ALL, ".ACP");

    Books book = createFunction();

    //Books book;
    //book.Print();

    //Books defaultBook;
    //defaultBook.Print();
    
    //defaultBook.Change();
    //defaultBook.Print();

    Books newBook = book;
    //newBook.Print();

    Books sumBooks = book.Sum(newBook);
    sumBooks.Print();
}

Books createFunction()
{
    int page, circ;
    char* temp = new char[256];
    cout << "Введите название, кол-во страниц, тираж:" << endl;
    cin >> temp >> page >> circ;
    Books object(page, circ, temp);
    delete[] temp;
    return object;
}
