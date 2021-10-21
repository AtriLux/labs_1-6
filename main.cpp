#include "headers.h"

int l = 0;

Books operator -(Books& B1, Books& B2) 
{
    if (strlen(B1.title) > strlen(B2.title)) {
        char* tempName = new char[strlen(B1.title) - strlen(B2.title) + 1];
        memcpy(tempName, B1.title, strlen(B1.title) - strlen(B2.title) + 1);
        tempName[strlen(B1.title) - strlen(B2.title)] = '\0';
        Books B3(tempName, B1.countPages - B2.countPages, B1.circulation - B2.circulation);
        delete[] tempName;
        return B3;
    }
    else {
        char* tempName = new char[strlen(B2.title) - strlen(B1.title) + 1];
        memcpy(tempName, B2.title, strlen(B2.title) - strlen(B1.title) + 1);
        tempName[strlen(B2.title) - strlen(B1.title)] = '\0';
        Books B3(tempName, B2.countPages - B1.countPages, B2.circulation - B1.circulation);
        delete[] tempName;
        return B3;
    }
}

ofstream& operator <<(ofstream& out, Books& B)
{
    out << B.title << " " << B.countPages << " " << B.circulation;
    return out;
}

fstream& operator <<(fstream& out, Books& B) 
{
    int p1 = B.countPages, p2, c1 = B.circulation, c2;
    l = strlen(B.title);

    out.write(B.title, l);
    out.write((char*)&B.countPages, sizeof(int));
    out.write((char*)&B.circulation, sizeof(int));

    return out;
}

fstream& operator >>(fstream& in, Books& B)
{
    char* tempT = new char[l+1];
    in.read(tempT, l);
    tempT[l] = '\0';
    int tempP = 0, tempC = 0;

    in.read((char*)&tempP, sizeof(int));
    in.read((char*)&tempC, sizeof(int));

    B.Change(tempT, tempP, tempC);

    return in;
}

int main()
{
    system("cls");
    setlocale(LC_ALL, ".ACP");

    cout << "Создание объекта с помощью конструктора с параметрами\n";
    int page, circ;
    char* tempName = new char[256];
    cout << "\nВведите название, кол-во страниц, тираж:\n";
    cin >> tempName >> page >> circ;
    Books paramBook(tempName, page, circ);
    //lab 4
    Volume Onegin(tempName, page + 1, circ + 1);
    //Comics SpiderMan(tempName, page, circ);
    delete[] tempName;
    
    Books defaultBook;

    /*lab 4
    Books *p = new Volume;
    (*p).Print();

    ++Onegin;
    Onegin.Print();

    Comics SpiderMan;
    SpiderMan.Rating();
    SpiderMan.Print();*/

    /*
    //cout << "Создание объекта с помощью конструктора по умолчанию\n";
    //Books defaultBook;
    //defaultBook.Print();
    //
    //cout << "Создание объекта с помощью конструктора копирования\n";
    //Books copyBook(paramBook);
    //copyBook.Print();

    //cout << "Изменение значений внутри объекта класса, созданного по умолчанию\n";
    //cout << "\nВведите новые значения в порядке: название, страницы, тираж. Если не хотите менять один из параметров, то введите 0\n\n";
    //int page, circ;
    //char* name = new char[256];
    //cin >> name >> page >> circ;
    //defaultBook.Change(name, page, circ);
    //defaultBook.Print();

    //cout << "Сложение двух объектов (созданный с параметрами + созданный по умолчанию и измененный)\n";
    //Books sumBooks = paramBook.Sum(defaultBook);
    //sumBooks.Print();

    //Books* pBook = new Books(sumBooks);
    //pBook->Print();
    //delete pBook;

    //cout << "Перегрузка оператора вычитания\n";
    //Books minBooks = paramBook - defaultBook;
    //minBooks.Print();

    //cout << "Перегрузка оператора сложения\n";
    //Books sumBooks = paramBook.operator+(defaultBook);
    //sumBooks.Print();

    //cout << "Перегрузка оператора префиксного инкремента\n";
    //(++sumBooks).Print();
    //sumBooks.Print();

    //cout << "Перегрузка оператора постфиксного инкремента\n";
    //(sumBooks++).Print();
    //sumBooks.Print();

    //cout << "Перегрузка операции приведения типа\n";
    //cout << fixed;
    //cout.precision(3);
    //cout << float(sumBooks);
    */

    /*lab 3
    ofstream out("prekol.txt");
    if (out.is_open())
    {
        out << paramBook;
    }
    out.close();

    fstream fout("prekolByte.bin", ios::out | ios::binary);
    if (fout.is_open())
    {
        fout << paramBook;
    }
    fout.close();

    fstream fin("prekolByte.bin", ios::in | ios::binary);
    if (fin.is_open())
    {
        fin >> defaultBook;
    }
    fin.close();
    defaultBook.Print();
    */

    List list(paramBook);
    list.Add(defaultBook, NULL);
    list.Add(Onegin, NULL);
    //некорректно работает
    //при добавлении в голову второй элемент всегда указывает на эту голову
    //т.е. сразу теряются все последующие элементы
    //если добавлять не в голову, то все норм
    list.Print();
}
