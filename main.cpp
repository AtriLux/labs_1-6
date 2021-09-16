#include "headers.h"

int main()
{
    system("cls");
    setlocale(LC_ALL, ".ACP");

    cout << "Создание объекта с помощью конструктора с параметрами\n";
    Books paramBook = paramBook.createFunction();
    paramBook.Print();

    cout << "Создание объекта с помощью конструктора по умолчанию\n";
    Books defaultBook;
    defaultBook.Print();
    
    cout << "Создание объекта с помощью конструктора копирования\n";
    Books copyBook(paramBook);
    paramBook.Print();

    cout << "Изменение значений внутри объекта класса, созданного по умолчанию\n";
    defaultBook.Change();
    defaultBook.Print();

    cout << "Сложение двух объектов (созданный с параметрами + созданный по умолчанию и измененный)\n";
    Books sumBooks = paramBook.Sum(defaultBook);
    sumBooks.Print();
}


