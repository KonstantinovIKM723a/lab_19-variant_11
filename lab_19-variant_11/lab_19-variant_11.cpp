#include <iostream>
#include "windows.h"
using namespace std;

const int N = 10;

template <class T>
T *generateNumericBasedArray(T lowValue, T highValue, int n) {
    T *temp = new T[n];
    for (int i = 0; i < n; i++) temp[i] = rand() % (int)(highValue - lowValue) + lowValue;
    return temp;
}

template <class T>
void showArray(T *a, int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

template <class T>
void sortArrayFromHighToLow(T *a, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                T t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    cout << "Масив цілих чисел: " << endl;
    auto arrayOfInt = generateNumericBasedArray(0, 50, N);
    showArray(arrayOfInt, N);
    cout << "Відсортований масив: " << endl;
    sortArrayFromHighToLow(arrayOfInt, N);
    showArray(arrayOfInt, N);

    cout << "Масив символів: " << endl;
    auto arrayOfChar = generateNumericBasedArray('a', 'z', N);
    showArray(arrayOfChar, N);
    cout << "Відсортований масив: " << endl;
    sortArrayFromHighToLow(arrayOfChar, N);
    showArray(arrayOfChar, N);

    cout << "Масив дрібних чисел: " << endl;
    auto arrayOfFloat = generateNumericBasedArray(0.5, 50.0, N);
    showArray(arrayOfFloat, N);
    cout << "Відсортований масив: " << endl;
    sortArrayFromHighToLow(arrayOfFloat, N);
    showArray(arrayOfFloat, N);
}