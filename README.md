#include <iostream>
using namespace std;
struct Node //описание узла списка
{
    string data; //информационное поле
    string data1;
    string data2;
    Node* next; //указатель на следующий элемент
};
struct Queue //описание очереди
{
    int size; //счетчик размера очереди
    Node* first = nullptr; //указатель на начало очереди
    Node* last = nullptr; //указатель на конец очереди
};
void Creation(Queue* Q) //описание структуры очереди
{
    Q->first = new Node;
    Q->first->next = NULL;
    Q->last = Q->first;
    cout << "Введите название фильма: ";
    cin >> Q->first->data;
    cout << "Введите год фильма: ";
    cin >> Q->first->data1;
    cout << "Введите автора фильма: ";
    cin >> Q->first->data2;
}



bool Full(Queue* Q) //проверка очереди на пустоту
{
    if (Q->first == NULL && Q->last == NULL) return true;
    else return false;
}

bool proverka(Queue* Q) //проверка очереди на пустоту
{
    if (Q->first == NULL && Q->last == NULL)
    {
        cout << "Очередь пуста" << endl;
        return true;
    }
    else
    {
        cout << "Очередь не пуста" << endl;
        return false;
    }

}

void Top(Queue* Q) //вывод начального элемента
{
    cout << "Название фильма: " << Q->first->data << " \n";
    cout << "Год фильма: " << Q->first->data1 << " \n";
    cout << "Автор фильма: " << Q->first->data2 << " \n";
    cout << "Адресс фильма: " << Q->first << " \n";
}

void Add(Queue* Q) //добавление элемента в очередь
{
    string value, value1, value2;

    if (Q->last == NULL)
    {
        Q->first = new Node;
        Q->first->next = NULL;
        Q->last = Q->first;
        cout << "Введите название фильма: ";
        cin >> Q->first->data;
        cout << "Введите год фильма: ";
        cin >> Q->first->data1;
        cout << "Введите автора фильма: ";
        cin >> Q->first->data2;
    }
    else {
        cout << "Введите название фильма: ";
        cin >> value;
        cout << "Введите год фильма: ";
        cin >> value1;
        cout << "Введите автора фильма: ";
        cin >> value2;
        Q->last->next = new Node;
        Q->last = Q->last->next;
        Q->last->data = value;
        Q->last->data1 = value1;
        Q->last->data2 = value2;
        Q->last->next = NULL; //обнуление указателя на следующий элемент
        cout << "\nЭлемент добавлен\n\n";
    }
}

void Delete(Queue* Q) //удаление элемента
{
    if (Full(Q)) cout << "Очередь пуста" << endl;
    else
    {
        Node* temp = Q->first;
        Q->first = Q->first->next;
        delete temp;
        cout << "Элемент удален" << endl;
    }
    if (Q->first == NULL)
    {
        Q->last = NULL;
    }

}
void DeleteALL(Queue* Q) //удаление всей очереди
{
    while (Q->first != NULL)
    {
        Node* temp = Q->first;
        Q->first = Q->first->next;
        delete temp;
    }
    if (Q->first == NULL)
    {
        Q->last = NULL;
    }
    cout << "\nОчередь удалена\n\n";
}

int Size(Queue* Q) //размер очереди
{
	int size = 0;
	Node* temp = Q->first;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
    return size;
}

int main() //главная функция
{
    char k;
    setlocale(LC_ALL, "Rus");
    Queue* Q = new Queue;
    cout << "Вы хотите создать очередь? ( Y - да, N - нет )\n\n";
    cin >> k;
    if (k == 'Y')
    {
        Creation(Q);
        char number;
        do
        {
            cout << "1. Добавить элемент" << endl;
            cout << "2. Удалить элемент" << endl;
            cout << "3. Вывести верхний элемент" << endl;
            cout << "4. Узнать размер очереди" << endl;
            cout << "5. Проверка на наличие элементов" << endl;
            cout << "6. Удалить всю очередь" << endl;
            cout << "0. Выйти\n\n";
            cout << "Номер команды > "; cin >> number;
            switch (number)
            {
            case '1': Add(Q);
                break;
            case '2':
                if (Full(Q))
                    cout << endl << "Очередь пуста\n\n";
                else
                    Delete(Q);
                break;
            case '3':
                if (Full(Q))
                    cout << endl << "Очередь пуста\n\n";
                else
                {
                    Top(Q); Delete(Q);
                }
                break;
            case '4':
                if (Full(Q))
                    cout << endl << "Очередь пуста\n\n";
                else
                {
                    cout << "\nРазмер очереди: " << Size(Q) << "\n\n"; DeleteALL(Q);
                }
                break;
            case '5':
                proverka(Q);
                break;
            case '6':
                DeleteALL(Q);
                break;
            case '0': break;
            default: cout << endl << "Команда не определена\n\n";
                break;
            }
        } while (number != '0');
        system("pause");
    }
    else if (k == 'N') {
        cout << "Спасибо, до свидания !\n\n";
    }
}
