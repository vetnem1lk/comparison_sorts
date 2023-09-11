#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Функция для заполнения массива случайными значениями.
 *
 * @param arr[] Передаваемый массив.
 * @param size Размер передаваемого массива.
 * @return void.
 */
void fillRandomArray(int arr[], unsigned short size) {
    srand(time(NULL));                         // Инициализируем генератор случайных чисел
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;                            // Генерируем случайное число от 0 до 99
    }
}

/**
 * @brief Функция для заполнения массива упорядоченными значениями по возрастанию.
 *
 * @param arr[] Передаваемый массив.
 * @param size Размер передаваемого массива.
 * @return void.
 */
void fillArrayAscending(int arr[], unsigned short size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

/**
 * @brief Функция для заполнения массива упорядоченными значениями по убыванию.
 *
 * @param arr[] Передаваемый массив.
 * @param size Размер передаваемого массива.
 * @return void.
 */
void fillArrayDescending(int arr[], unsigned short size) {
    for (int i = 0; i < size; i++) {
        arr[i] = size - 1 - i;
    }
}

/**
 * @brief Функция для сортировки массива по возрастанию сортировкой прямыми вставками.
 *
 * @param arr[] Передаваемый массив.
 * @param size Размер передаваемого массива.
 * @return elementaryCount счетчик выполненных операций.
 */
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

/**
 * @brief Функция для сортировки массива по убыванию сортировкой прямыми вставками.
 *
 * @param arr[] Передаваемый массив.
 * @param size Размер передаваемого массива.
 * @return void.
 */
void insertionSortDescending(int arr[], unsigned short size) {
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

/**
 * @brief Функция для сортировки массива сортировкой Шелла по возрастанию.
 *
 * @param arr[] Передаваемый массив.
 * @param size Размер передаваемого массива.
 * @return elementaryCount счетчик выполненных операций.
 */
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

/**
 * @brief Функция для сортировки массива сортировкой Шелла по убыванию.
 *
 * @param arr[] Передаваемый массив.
 * @param size Размер передаваемого массива.
 * @return void.
 */
void shellSortDescending(int arr[], unsigned short size) {
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

/**
 * @brief Функция для измерения выполненных операций сортировки.
 * @details Функция умеет рассчитывать время сортировки в мс и хранит в переменной timeMS.
 * @param arr[] Передаваемый массив.
 * @param size Размер передаваемого массива.
 * @param long Указатель на функцию сортировки.
 * @return elementaryCount счетчик выполненных операций при сортировке.
 */
long long measureSortingTime(int arr[], unsigned short size, long long (*sortingAlgorithm)(int[], unsigned short)) {
    clock_t start, end;
    start = clock();
    long long elementaryCount = sortingAlgorithm(arr, size);
    end = clock();
    double timeMs = ((double) (end - start)) * 1000.0 / CLOCKS_PER_SEC;
    return elementaryCount;
}

/**
 * @brief Функция для печати таблицы зависимости суммарного количества операций
сравнения и перестановки.
 */
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

int main() {
    system("chcp 65001");
    printf("%30s%80s\n", "Алгоритм прямым вставками (T1)", "Алгоритм Шелла (T2)");
    printGraph();
    return 0;
}

