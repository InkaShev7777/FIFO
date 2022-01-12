#include <iostream>
using namespace std;
template<typename T>
struct Node
{
    T value;
    Node* next;
    Node()
    {

    }
    Node(Node* node)
    {
        next = nullptr;
        value = node->value;
    }
};
template<typename T>
class List {
    Node<T>* head;
    int size;
public:
    List()
    {
        this->head = nullptr;
        this->size = 0;
    }
    int getSize()
    {
        return this->size;
    }
    void Add(T value)
    {
        if (this->head == nullptr)
        {
            this->head = new Node<T>();
            this->head->value = value;
            this->head->next = nullptr;
        }
        else
        {
            Node<T>* tmp = this->head;
            while (tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
            tmp->next = new Node<T>();
            tmp->next->value = value;
            tmp->next->next = nullptr;
        }
        size++;
    }

    void print() {
        Node<T>* iter = this->head;
        
            while (iter != nullptr)
            {
                cout << "Adres: " << iter << "\tValue: " << iter->value << "\tNext: " << iter->next << "\n";
                iter = iter->next;
            }
         delete iter;
    }

    Node<T>* dell()
    {
        Node<T>* iter = this->head;
        if (this->size > 0)
        {
            if (iter != nullptr)
            {
                Node<T>* ret = new Node<T>(iter);
                // delete iter;
                iter = iter->next;
                this->head = iter;
                size--;
                return ret;
            }
        }
        else
        {
            size--;
        }
    }
};
int main()
{
    List<int> list;
    setlocale(0, "");
    int vibor;
    Node<int>* ret;
    do
    {
        cout << "\t\tМеню\n";
        cout << "1 - Добавление элемента\n";
        cout << "2 - Вывод списка\n";
        cout << "3 - Удаление элементов логикой FIFO\n";
        cout << "0 - Выход\n";
        cout << "Сделайте свой выбор: ";
        cin >> vibor;
        switch (vibor)
        {
        case 1:
            system("cls");
            int a;
            cout << "Введите элемент который хотите добавить: ";
            cin >> a;
            list.Add(a);
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            list.print();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            ret = list.dell();
            if (list.getSize() >= 0)
            {
                cout<< "Новый адрес: " << ret << "\tЗначение: " << ret->value<<"\tNext: "<<ret->next<< "\n";
            }
            else
            {
                cout << "Список пуст!!!\n";
            }
            system("pause");
            system("cls");
            break;
        }
    } while (vibor != 0);
}


