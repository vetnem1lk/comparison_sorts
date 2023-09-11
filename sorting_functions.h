#ifndef COMPARISON_SORTS_SORTING_FUNCTIONS_H
#define COMPARISON_SORTS_SORTING_FUNCTIONS_H

/**
 * @brief Функция для заполнения массива случайными значениями.
 *
 * @param arr[] Передаваемый массив.
 * @param size Размер передаваемого массива.
 * @return void.
 */
void fillRandomArray(int arr[], unsigned short size);

/**
 * @brief Функция для заполнения массива упорядоченными значениями по возрастанию.
 *
 * @param arr[] Передаваемый массив.
 * @param size Размер передаваемого массива.
 * @return void.
 */
void fillArrayAscending(int arr[], unsigned short size);

/**
 * @brief Функция для заполнения массива упорядоченными значениями по убыванию.
 *
 * @param arr[] Передаваемый массив.
 * @param size Размер передаваемого массива.
 * @return void.
 */
void fillArrayDescending(int arr[], unsigned short size);

/**
 * @brief Функция для сортировки массива по возрастанию сортировкой прямыми вставками.
 *
 * @param arr[] Передаваемый массив.
 * @param size Размер передаваемого массива.
 * @return elementaryCount счетчик выполненных операций.
 */
long long insertionSortAscending(int arr[], unsigned short size);

/**
 * @brief Функция для сортировки массива по убыванию сортировкой прямыми вставками.
 *
 * @param arr[] Передаваемый массив.
 * @param size Размер передаваемого массива.
 * @return void.
 */
__attribute__((unused)) void insertionSortDescending(int arr[], unsigned short size);

/**
 * @brief Функция для сортировки массива сортировкой Шелла по возрастанию.
 *
 * @param arr[] Передаваемый массив.
 * @param size Размер передаваемого массива.
 * @return elementaryCount счетчик выполненных операций.
 */
long long shellSortAscending(int arr[], unsigned short size);

/**
 * @brief Функция для сортировки массива сортировкой Шелла по убыванию.
 *
 * @param arr[] Передаваемый массив.
 * @param size Размер передаваемого массива.
 * @return void.
 */
__attribute__((unused)) void shellSortDescending(int arr[], unsigned short size);

/**
 * @brief Функция для измерения выполненных операций сортировки.
 * @details Функция умеет рассчитывать время сортировки в мс и хранит в переменной timeMS.
 * @param arr[] Передаваемый массив.
 * @param size Размер передаваемого массива.
 * @param long Указатель на функцию сортировки.
 * @return elementaryCount счетчик выполненных операций при сортировке.
 */
long long measureSortingTime(int arr[], unsigned short size, long long (*sortingAlgorithm)(int[], unsigned short));

#endif //COMPARISON_SORTS_SORTING_FUNCTIONS_H
