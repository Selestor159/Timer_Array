#include <iostream>
#include <time.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    const int rows = 39999;
    const int cols = 39999;

    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }


    clock_t start, end;
    double cpu_time_used;

    start = clock(); // начало измерения времени

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = i + j;
        }
    }
 
    end = clock(); // конец измерения времени
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // вычисление затраченного времени

    std::cout << "Время заполнения массива: " << cpu_time_used << " секунд." << std::endl;
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

