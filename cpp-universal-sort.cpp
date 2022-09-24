// cpp-universal-sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

enum class Order { ASC, DESC };

/*** ПРОТОТИПЫ ФУНКЦИЙ ***/

// Сортирует элементы в массиве
void intBubbleSort(int integers[], int size, Order myOrder = Order::ASC);

// Ввод элементов в массив с консоли
void arrayInput(int integers[]);

// Вывод элементов массива на экран
void arrayPrint(int integers[]);

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "*** Сортировка целых чисел ***" << endl;
    int ints[7]; // создание массива
    arrayInput(ints);
    cout << "сортировать по убыванию(д - да/н - нет)?" << endl;
    char descOrderResponse = 'н';
    do {
        cin >> descOrderResponse;
    } while (descOrderResponse != 'д' && descOrderResponse != 'н');
    descOrderResponse == 'н' ? intBubbleSort(ints, 7) : intBubbleSort(ints, 7, Order::DESC);
    arrayPrint(ints);
}

void intBubbleSort(int integers[], int size, Order myOrder /* ПЕРЕКЛЮЧАТЕЛЬ */) // Сортирует элементы в массиве
{
    // флаг "упорядоченный ли массив" - предполагаем, что нет
    bool sortCheck = false;
    // пока массив не упорядоченный
    while (!sortCheck)
    {
        // предполагаем, что упорядоченный, и тут же проверяем это,
        // сравнивая попарно все рядом расположенные элементы
        sortCheck = true;
        for (int i = 0; i < size - 1; i++)
        {
            // результат сравнения двух рядом расположенных элементов
            int comparisonResult =
                myOrder == Order::ASC
                ? integers[i] - integers[i + 1]
                : integers[i + 1] - integers[i];
            // если два соседние элемента расположены не в желаемом порядке
            if (comparisonResult > 0)
            {
                // 1 переставляем их местами
                int temp = integers[i];
                integers[i] = integers[i + 1];
                integers[i + 1] = temp;
                // 2 отмечаем себе, что предположение не сбылось - массив еще не был упорядочен,
                // раз пришлось переставлять местами ходя бы пару элементов
                sortCheck = false;
            }
        }
    }
}

void arrayInput(int integers[]) // Ввод элементов в массив с консоли
{
    cout << "Вводите целые числа, и после каждого нажимайте клавишу Ввод" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << "Число номер " << i + 1 << " из 7: ";
        cin >> integers[i];
    }
}

void arrayPrint(int integers[]) // Вывод элементов массива на экран
{
    cout << "[ ";
    for (int i = 0; i < 7; i++)
    {
        cout << integers[i] << " ";
    }
    cout << "]";
}