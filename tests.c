#include "tests.h"
#include "sorting_functions.h"

bool test_shellSort() {
    int arr[] = {4, 2, 7, 1, 9};
    int expected[] = {1, 2, 4, 7, 9};
    unsigned short size = sizeof(arr) / sizeof(arr[0]);

    // Вызываем функцию сортировки
    shellSortAscending(arr, size);
    for (unsigned short i = 0; i < size; ++i) {
        if (arr[i] != expected[i]) return false;
    }
    return true;
}

bool test_insertionSort() {
    int arr[] = {4, 2, 7, 1, 9};
    int expected[] = {1, 2, 4, 7, 9};
    unsigned short size = sizeof(arr) / sizeof(arr[0]);

    // Вызываем функцию сортировки
    insertionSortAscending(arr,size);
    for (unsigned short i = 0; i < size; ++i) {
        if (arr[i] != expected[i]) return false;
    }
    return true;
}
