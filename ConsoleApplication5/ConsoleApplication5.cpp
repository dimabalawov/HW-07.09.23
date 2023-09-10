
#include <iostream>
#include <conio.h>
using namespace std;

int amount = 0;

void spaceInput()
{
    char key;
    do
    {
        cout << "Press SPACE to continue" << endl;
        key = _getch();
        if (key == 32)
            break;
    } while (key != ' ');
}
class Client
{
private:
    char* name;
    char* surname;
    char* patr;
    char* home;
    char* work;
    char* mob;
    char* email;
    int age;
public:
    Client()
    {
        name = nullptr;
        surname = nullptr;
        patr = nullptr;
        home = nullptr;
        work = nullptr;
        mob = nullptr;
        email = nullptr;
        age = 0;
    }
    Client(const char* n,const char* s,const char* p, const char* h, const char* w, const char* m, const char* e, int a)
    {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
        surname = new char[strlen(s) + 1];
        strcpy_s(surname, strlen(s) + 1, s);
        patr = new char[strlen(p) + 1];
        strcpy_s(patr, strlen(p) + 1, p);
        home = new char[strlen(h) + 1];
        strcpy_s(home, strlen(h) + 1, h);
        work = new char[strlen(w) + 1];
        strcpy_s(work, strlen(w) + 1, w);
        mob = new char[strlen(m) + 1];
        strcpy_s(mob, strlen(m) + 1, m);
        email = new char[strlen(e) + 1];
        strcpy_s(email, strlen(e) + 1, e);
        age = a;
    }
    ~Client()
    {
        delete[]name;
        delete[] surname;
        delete[] patr;
        delete[] home;
        delete[] work;
        delete[] mob;
        delete[]email;
        cout << "Destructor" << endl;
    }
    void printClient()
    {
        cout << "NAME: " << name <<endl;
        cout << "SURNAME: " << surname <<endl;
        cout << "PATRONYMIC: " << patr <<endl;
        cout << "HOMEPHONE: " << home << endl;
        cout << "WORKPHONE: " << work << endl;
        cout << "MOBILE PHONE: " << mob << endl;
        cout << "EMAIL: " << email << endl;
        cout << "AGE: " << age << endl;
    }
    void addCLient(Client* &book)
    {
        char buffer[40];
        Client* newbook = new Client[amount+1];
        for (size_t i = 0; i < amount; i++)
        {
            newbook[i] = book[i];
        }
        cout << "Enter the name of the client: ";
        cin >> buffer;
        newbook[amount].name = new char[strlen(buffer) + 1];
        strcpy_s(newbook[amount].name, strlen(buffer) + 1, buffer);
        cout << "Enter the surname of the client: ";
        cin >> buffer;
        newbook[amount].surname = new char[strlen(buffer) + 1];
        strcpy_s(newbook[amount].surname, strlen(buffer) + 1, buffer);
        cout << "Enter the patronymic of the client: ";
        cin >> buffer;
        newbook[amount].patr = new char[strlen(buffer) + 1];
        strcpy_s(newbook[amount].patr, strlen(buffer) + 1, buffer);
        cout << "Enter the homephone of the client: ";
        cin >> buffer;
        newbook[amount].home = new char[strlen(buffer) + 1];
        strcpy_s(newbook[amount].home, strlen(buffer) + 1, buffer);
        cout << "Enter the workphone of the client: ";
        cin >> buffer;
        newbook[amount].work = new char[strlen(buffer) + 1];
        strcpy_s(newbook[amount].work, strlen(buffer) + 1, buffer);
        cout << "Enter the mobile phone of the client: ";
        cin >> buffer;
        newbook[amount].mob = new char[strlen(buffer) + 1];
        strcpy_s(newbook[amount].mob, strlen(buffer) + 1, buffer);
        cout << "Enter the email of the client: ";
        cin >> buffer;
        newbook[amount].email = new char[strlen(buffer) + 1];
        strcpy_s(newbook[amount].email, strlen(buffer) + 1, buffer);
        cout << "Enter the age of the client: ";
        cin >> newbook[amount].age;
        amount++;
        delete[] book;
        book = newbook;
        cout << "Client's added" << endl;

    }
    void deleteEmployee(Client*& book)
    {
        Client* newbook = new Client[amount - 1];
        char firstname[20];
        char lastname[20];
        cout << "Enter the first name of the employee: ";
        cin >> firstname;
        cout << "Enter the  surname of the employee: ";
        cin >> lastname;
        int index = 0;
        for (int i = 0; i < amount; i++)
        {
            if (!(strcmp(firstname, book[i].name)) && !(strcmp(lastname, book[i].surname)))
            {
                index = i;
                for (size_t j = 0; j < amount; j++)
                {
                    if (j != index)
                        newbook[j] = newbook[j];
                }
                amount--;
                delete[] book;
                book = newbook;
                cout << "Client has been deleted" << endl;

            }
            else if (i == amount - 1)
                cout << "No such client has found" << endl;
        }
    }
    void search(Client* book)
    {
        char lastname[20];
        char firstname[20];
        cout << "Enter the  first name to find the client: ";
        cin >> firstname;
        cout << "Enter the last name to find the client: ";
        cin >> lastname;
        bool isFound = 0;
        for (size_t i = 0; i < amount; i++)
        {
            if (!(strcmp(lastname, book[i].surname)) && !(strcmp(firstname, book[i].name)))
            {
                book[i].printClient();
                isFound = 1;
            }
            else if (i == (amount - 1) && isFound == 0)
            {
                cout << "No clients found" << endl;
            }
        }
    }
    void showMenu(Client* &book)
    {
        short option;
        cout << "Choose the option: " << endl;
        cout << "1 - Add the client" << endl;
        cout << "2 - Delete the client" << endl;
        cout << "3 - Show all the client" << endl;
        cout << "4 - Search" << endl;

        cin >> option;
        switch (option)
        {
        case 1:
            book->addCLient(book);
            spaceInput();
            break;
        case 2:
            book->deleteEmployee(book);
            spaceInput();
            break;
        case 3:
            for (size_t i = 0; i < amount; i++)
            {
                book[i].printClient();
            }
            spaceInput();
            break;
        case 4:
            search(book);
            spaceInput();
            break;
        default:
            cout << "There is no such option";
            spaceInput();
            break;
        }
    }
};
int main()
{
    Client* book = new Client[amount];
    while (1)
    {
        book->showMenu(book);
    }
}
