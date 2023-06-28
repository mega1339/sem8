#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition(char **arr, int low, int high) {
    int pivot = strlen(arr[high]);
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (strlen(arr[j]) <= pivot) {
            i++;
            char *temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    char *temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quicksort(char **arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("enter count of strings: ");
    scanf("%d", &n);

    // Выделение памяти для массива указателей на строки
    char **arr = (char **)malloc(n * sizeof(char *));

    // Ввод строк
    printf("enter strings:\n");
    for (int i = 0; i < n; i++) {
        char buffer[100];
        scanf("%s", buffer);

        // Выделение памяти для текущей строки
        int length = strlen(buffer);
        arr[i] = (char *)malloc((length + 1) * sizeof(char));
        strncpy(arr[i], buffer, length);
        arr[i][length] = '\0';
    }

    // Сортировка массива строк по длине
    quicksort(arr, 0, n - 1);

    // Вывод отсортированных строк
    printf("sorted strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
