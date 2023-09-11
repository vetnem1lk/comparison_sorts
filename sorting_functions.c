#include <stdlib.h>
#include <time.h>
#include "sorting_functions.h"

void fillRandomArray(int *arr, unsigned short size) {
    srand(time(NULL));                         // Инициализируем генератор случайных чисел
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;                            // Генерируем случайное число от 0 до 99
    }
}

void fillArrayAscending(int *arr, unsigned short size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

void fillArrayDescending(int *arr, unsigned short size) {
    for (int i = 0; i < size; i++) {
        arr[i] = size - 1 - i;
    }
}

long long insertionSortAscending(int arr[], unsigned short size) {
    long long elementaryCount = 0;
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            elementaryCount += 2;                             // Увеличиваем счетчик сравнений
        }
        arr[j + 1] = key;
        elementaryCount++;                                    // Увеличиваем счетчик перестановок
    }
    return elementaryCount;
}

__attribute__((unused)) void insertionSortDescending(int arr[], unsigned short size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

long long shellSortAscending(int arr[], unsigned short size) {
    long long elementaryCount = 0;                            // Сбрасываем счетчики операций
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                elementaryCount += 2;                         // Увеличиваем счетчик сравнений
            }
            arr[j] = temp;
            elementaryCount++;                                // Увеличиваем счетчик перестановок
        }
    }
    return elementaryCount;
}

__attribute__((unused)) void shellSortDescending(int *arr, unsigned short size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

long long measureSortingTime(int *arr, unsigned short size, long long int (*sortingAlgorithm)(int *, unsigned short)) {
    clock_t start, end;
    start = clock();
    long long elementaryCount = sortingAlgorithm(arr, size);
    end = clock();
    double timeMs = ((double) (end - start)) * 1000.0 / CLOCKS_PER_SEC;
    return elementaryCount;
}

