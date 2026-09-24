#include <stdio.h>
#include <stdlib.h>

void plusMinus(int arr_count, int* arr) {
    int pos = 0, neg = 0, zero = 0;
    for (int i = 0; i < arr_count; i++) {
        if (arr[i] > 0) pos++;
        else if (arr[i] < 0) neg++;
        else zero++;
    }
    printf("%.6f\n", (double)pos / arr_count);
    printf("%.6f\n", (double)neg / arr_count);
    printf("%.6f\n", (double)zero / arr_count);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    plusMinus(n, arr);

    free(arr);
    return 0;
}
