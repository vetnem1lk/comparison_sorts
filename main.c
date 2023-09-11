#include <stdio.h>
#include <stdlib.h>
#include "sorting_functions.h"
#include "tests.h"

// Определение escape-последовательности для изменения цвета текста
#define GREEN_TEXT "\x1b[32m"
#define RESET_COLOR "\x1b[0m"

/**
 * @brief Функция для печати таблицы зависимости суммарного количества операций
сравнения и перестановки.
 */
void printGraph();

int main() {
    system("chcp 65001");
    printf("Тест сортировки прямой вставкой:" GREEN_TEXT "%s" RESET_COLOR "\n", test_insertionSort() ? " ПРОШЕЛ" : "false");
    printf("Тест сортировки Шелла:" GREEN_TEXT "%s" RESET_COLOR "\n", test_shellSort() ? " ПРОШЕЛ" : "false");
    printf("%30s%80s\n", "Алгоритм прямым вставками (T1)", "Алгоритм Шелла (T2)");
    printGraph();

    return 0;
}

void printGraph() {
    int step = 500;
    printf("%-15s%-15s%-15s%-15s%-20s%-15s%-15s\n", "N", "T1(best)", "T1(avg)", "T1(worst)", "T2(best)", "T2(avg)",
           "T2(worst)");
    for (unsigned short N = 500; N <= 50000; N += step) {
        int arr[N]; // Объявление массива
        printf("%-15d", N);

        fillArrayAscending(arr, N);
        long long bestCaseTimeInsertion = measureSortingTime(arr, N, insertionSortAscending);
        printf("%-15lld", bestCaseTimeInsertion);
        fillRandomArray(arr, N);
        long long avgCaseTimeInsertion = measureSortingTime(arr, N, insertionSortAscending);
        printf("%-15lld", avgCaseTimeInsertion);
        fillArrayDescending(arr, N);
        long long worstCaseTimeInsertion = measureSortingTime(arr, N, insertionSortAscending);
        printf("%-15lld", worstCaseTimeInsertion);

        fillArrayAscending(arr, N);
        long long bestCaseTimeShell = measureSortingTime(arr, N, shellSortAscending);
        printf("%-20lld", bestCaseTimeShell);
        fillRandomArray(arr, N);
        long long avgCaseTimeShell = measureSortingTime(arr, N, shellSortAscending);
        printf("%-15lld", avgCaseTimeShell);
        fillArrayDescending(arr, N);
        long long worstCaseTimeShell = measureSortingTime(arr, N, shellSortAscending);
        printf("%-15lld\n", worstCaseTimeShell);
    }
}

