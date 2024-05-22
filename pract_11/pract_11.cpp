//Вариант 3

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//задание 1(Напишите шаблонную функцию для нахождения индекса первого вхождения заданного элемента в массиве любого типа данных.)
template<typename T>
int privet(T* array, int size, const T& element) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == element) {
            return i; 
        }
    }
    return -1; 
}



//задание 2(Создайте шаблонный класс "Куча", который может хранить элементы любого типа данных и обеспечивает операции вставки и удаления с учётом их приоритета.)
template<typename T>
class Kucha {
    vector<T> heap; // Исправлено название переменной

public:
    void dobavit(const T& element) {
        heap.push_back(element);
    }

    void delite(int index) {
        if (index >= 0 && index < heap.size()) {
            heap.erase(heap.begin() + index);
        }
        else {
            cout << "Индекс вне диапазона." << endl;
        }
    }

    void print() const {
        for (const auto& element : heap) {
            cout << element << " ";
        }
        cout << endl;
    }
};



int main() {
    setlocale(LC_ALL, "ru");

//задание 1
  
    // Массив целых чисел
    int intArray[] = { 1, 2, 3, 4, 5 };
    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    int intElement;
    cout << "Введите целое число для поиска в массиве intArray: " << endl;
    cin >> intElement;
    cout << "Индекс элемента " << intElement << " в intArray: " << privet(intArray, intSize, intElement) << endl;

    // Массив вещественных чисел
    double doubleArray[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    double doubleElement;
    cout << "Введите вещественное число для поиска в массиве doubleArray: " << endl;
    cin >> doubleElement;
    cout << "Индекс элемента " << doubleElement << " в doubleArray: " << privet(doubleArray, doubleSize, doubleElement) << endl;

    // Массив строк
    string stringArray[] = { "apple", "banan", "minion", "one", "two", "bedroom"};
    int stringSize = sizeof(stringArray) / sizeof(stringArray[0]);
    string stringElement;
    cout << "Введите строку для поиска в массиве stringArray: " << endl;
    getline(cin, stringElement);
    cout << "Индекс элемента \"" << stringElement << "\" в stringArray: " << privet(stringArray, stringSize, stringElement) << endl;


//задание 2
    Kucha<int> intKucha;

    string command;
    while (true) {
        cout << "Введите команду ('insert' (добавить элемент), 'remove' (удалить элемент), 'quit' (выход), 'print' (вывод всех элементов)): ";
        cin >> command;

        if (command == "insert") {
            cout << "Введите элемент для добавления: ";
            int element;
            cin >> element;
            intKucha.dobavit(element);
        }
        else if (command == "remove") {
            cout << "Введите индекс для удаления: ";
            int index;
            cin >> index;
            intKucha.delite(index);
        }
        else if (command == "print") {
            intKucha.print();
        }
        else if (command == "quit") {
            break;
        }
        else {
            cout << "Неизвестная команда. Пожалуйста, попробуйте снова." << endl;
        }
    }

    return 0;
}