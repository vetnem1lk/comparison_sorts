#include <stdio.h>
#include <stdlib.h>
#include <xlsxwriter.h>
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

lxw_workbook *workbook;
lxw_worksheet *worksheet;

int main() {
    system("chcp 65001");
    printf("Тест сортировки прямой вставкой:" GREEN_TEXT "%s" RESET_COLOR "\n",
           test_insertionSort() ? " ПРОШЕЛ" : "false");
    printf("Тест сортировки Шелла:" GREEN_TEXT "%s" RESET_COLOR "\n", test_shellSort() ? " ПРОШЕЛ" : "false");
    printf("%30s%80s\n", "Алгоритм прямым вставками (T1)", "Алгоритм Шелла (T2)");

    printGraph();
    workbook_close(workbook);

    return 0;
}

void printGraph() {
    int step = 500;
    int row = 0;
    int col = 0;

    workbook = workbook_new("iSortPlot.xlsx");
    worksheet = workbook_add_worksheet(workbook, "by Klimentev");

    worksheet_write_string(worksheet, row, col, "Алгоритм прямым вставками (T1)", NULL);
    worksheet_write_string(worksheet, row, col + 6, "Алгоритм Шелла (T2)", NULL);
    worksheet_write_string(worksheet, row + 1, col, "N", NULL);
    worksheet_write_string(worksheet, row + 1, col + 1, "T1(best)", NULL);
    worksheet_write_string(worksheet, row + 1, col + 2, "T1(avg)", NULL);
    worksheet_write_string(worksheet, row + 1, col + 3, "T1(worst)", NULL);
    worksheet_write_string(worksheet, row + 1, col + 5, "T2(best)", NULL);
    worksheet_write_string(worksheet, row + 1, col + 6, "T2(avg)", NULL);
    worksheet_write_string(worksheet, row + 1, col + 7, "T2(worst)", NULL);
    printf("%-15s%-15s%-15s%-15s%-20s%-15s%-15s\n", "N", "T1(best)", "T1(avg)", "T1(worst)", "T2(best)", "T2(avg)",
           "T2(worst)");
    row++;
    for (unsigned short N = 500; N <= 50000; N += step) {
        row++;

        int arr[N];
        printf("%-15d", N);
        worksheet_write_number(worksheet, row, col, (int) N, NULL);

        fillArrayAscending(arr, N);
        long long bestCaseTimeInsertion = measureSortingTime(arr, N, insertionSortAscending);
        printf("%-15lld", bestCaseTimeInsertion);
        worksheet_write_number(worksheet, row, col + 1, (double) bestCaseTimeInsertion, NULL);

        fillRandomArray(arr, N);
        long long avgCaseTimeInsertion = measureSortingTime(arr, N, insertionSortAscending);
        printf("%-15lld", avgCaseTimeInsertion);
        worksheet_write_number(worksheet, row, col + 2, (double) avgCaseTimeInsertion, NULL);

        fillArrayDescending(arr, N);
        long long worstCaseTimeInsertion = measureSortingTime(arr, N, insertionSortAscending);
        printf("%-15lld", worstCaseTimeInsertion);
        worksheet_write_number(worksheet, row, col + 3, (double) worstCaseTimeInsertion, NULL);

        fillArrayAscending(arr, N);
        long long bestCaseTimeShell = measureSortingTime(arr, N, shellSortAscending);
        printf("%-20lld", bestCaseTimeShell);
        worksheet_write_number(worksheet, row, col + 5, (double) bestCaseTimeShell, NULL);

        fillRandomArray(arr, N);
        long long avgCaseTimeShell = measureSortingTime(arr, N, shellSortAscending);
        printf("%-15lld", avgCaseTimeShell);
        worksheet_write_number(worksheet, row, col + 6, (double) avgCaseTimeShell, NULL);

        fillArrayDescending(arr, N);
        long long worstCaseTimeShell = measureSortingTime(arr, N, shellSortAscending);
        printf("%-15lld\n", worstCaseTimeShell);
        worksheet_write_number(worksheet, row, col + 7, (double) worstCaseTimeShell, NULL);
    }

    // Создаем объекты для диаграммы
    lxw_chart *chart = workbook_add_chart(workbook, LXW_CHART_LINE);
    lxw_chart_series *serBestIns = chart_add_series(chart, "=Sheet1!$A$3:$A$102", "=Sheet1!$B$3:$B$102");
    lxw_chart_series *serAvgIns = chart_add_series(chart, "=Sheet1!$A$3:$A$102", "=Sheet1!$C$3:$C$102");
    lxw_chart_series *serWorstIns = chart_add_series(chart, "=Sheet1!$A$3:$A$102", "=Sheet1!$D$3:$D$102");
    lxw_chart_series *serBestShell = chart_add_series(chart, "=Sheet1!$A$3:$A$102", "=Sheet1!$F$3:$F$102");
    lxw_chart_series *serAvgShell = chart_add_series(chart, "=Sheet1!$A$3:$A$102", "=Sheet1!$G$3:$G$102");
    lxw_chart_series *serWorstShell = chart_add_series(chart, "=Sheet1!$A$3:$A$102", "=Sheet1!$H$3:$H$102");
    chart_series_set_name(serBestIns, "=Sheet1!$B$2");
    chart_series_set_name(serAvgIns, "=Sheet1!$C$2");
    chart_series_set_name(serWorstIns, "=Sheet1!$D$2");
    chart_series_set_name(serBestShell, "=Sheet1!$F$2");
    chart_series_set_name(serAvgShell, "=Sheet1!$G$2");
    chart_series_set_name(serWorstShell, "=Sheet1!$H$2");

    // Настраиваем заголовки и метки осей
    chart_title_set_name(chart, "График");
    chart_axis_set_name(chart->x_axis, "Размер массива (N)");
    chart_axis_set_name(chart->y_axis, "Количество операций");


    // Вставляем диаграмму в лист
    worksheet_insert_chart(worksheet, CELL("J2"), chart);
}

