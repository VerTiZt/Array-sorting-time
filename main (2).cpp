#include <iostream>
#include <time.h>
using namespace std;
 
clock_t start;
float timing;
int main()
{
    // Создание массива и заполнение случайными числами
    int size;
    cout << "Введите количество элементов массива: ";
    cin >> size;
    srand(time(NULL));
    int* a = new int[size];
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 300 -100;
    }
    //Сортируем массив
    start = clock();
    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    timing = (float)(clock() - start) / CLOCKS_PER_SEC;
    cout << "Время сортировки массива = " << timing;
    cout << endl;
    delete[] a;
    return 0;
}

