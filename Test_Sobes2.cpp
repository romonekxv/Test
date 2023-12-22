#include <iostream>
using namespace std;

int N; //Размер массива

/****Функция заполнения массива****/
static void arr_in(double* arr, int N) {
    cout << "\n Заполните массив\n" << endl;
    for (int i = 0; i < N; i++) {
        cout << "arr [" << i << "] = ";
        cin >> arr[i];
    }
}

/*Функция вывода массива*/
static void arr_out(double* arr, int N) {
    cout << "\nОтсортированный массив\n";
    cout << "arr[] = { ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << "}\n\n";
}

/*Функция сортировки массива и нахождения максимальных элементов*/
static void sort(double* arr, int N) {

    double  buf1 = 0, max1 = 0, max2 = 0;                                   //Переменные максимальных элементов
    unsigned int i = 0, j = 0;                                             //и их индексы
    unsigned int max_index1 = 0, max_index2 = 0, Index1 = 0, Index2 = 0;

    /*Поиск максимальных элементов и их индексов*/
    for (j = 1; j <= (N-1); j++) {
        for (i = 0; i <= (N - j); i++) {
            if (arr[i] > max1) {
                max1 = arr[i];
                max_index1 = i;
            }
            else if (arr[i] > max2 && arr[i] != max1) {
                max2 = arr[i];
                max_index2 = i;
            }
        }
        if (j == 1) {Index1 = max_index1;}
        if (j == 2) { Index2 = max_index2; }
    }
    /*******************************************/

    cout << "max1 = " << max1 << endl;
    cout << "INDEX 1: " << Index1 << endl;
    cout << "max2 = " << max2 << endl;
    cout << "INDEX 2: " << Index2 << endl;

    /*Сортировка массива методом пузырька*/
    for (j = 1; j <= (N - 1); j++)
        for (i = 0; i < (N - j); i++) {
            if (arr[i] > arr[i + 1]) {
                buf1 = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = buf1;
            }
        }
}

int main()
{
    setlocale(0, ""); //Функция для отображения кириллицы в консоль

    cout << "Введите размер массива N>0: ";
    cin >> N;
    while (N <= 0) {
        cout << "Ошибка! Размер массива должен быть больше 0" << endl;
        cin >> N;
    }

    double* arr = new double[N]; //Объявление и инициализация динамического массива

    arr_in(arr, N);             //Заполнение массива

    cout << "\nИсходный массив" << endl;
    arr_out(arr, N);           //Вывод исходного массива

    sort(arr, N);

    arr_out(arr, N);          //Вывод отсортированного массива

    delete[] arr;            //Очистка памяти
    return 0;
}