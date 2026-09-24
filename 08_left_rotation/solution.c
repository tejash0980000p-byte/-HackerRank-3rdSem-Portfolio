#include <stdio.h>
#include <stdlib.h>

int* rotateLeft(int d, int arr_count, int* arr, int* result_count) {
    *result_count = arr_count;
    int* rotated = (int*)malloc(arr_count * sizeof(int));
    for (int i = 0; i < arr_count; i++) {
        rotated[i] = arr[(i + d) % arr_count];
    }
    return rotated;
}

int main() {
    int n, d;
    if (scanf("%d %d", &n, &d) != 2) return 0;

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result_count;
    int* result = rotateLeft(d, n, arr, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d%s", result[i], (i == result_count - 1) ? "" : " ");
    }
    printf("\n");

    free(arr);
    free(result);
    return 0;
}
