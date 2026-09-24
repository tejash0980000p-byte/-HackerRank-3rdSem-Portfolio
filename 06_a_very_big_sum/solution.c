#include <stdio.h>
#include <stdlib.h>

long aVeryBigSum(int ar_count, long* ar) {
    long sum = 0;
    for (int i = 0; i < ar_count; i++) {
        sum += ar[i];
    }
    return sum;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long* ar = (long*)malloc(n * sizeof(long));
    for (int i = 0; i < n; i++) {
        scanf("%ld", &ar[i]);
    }

    long result = aVeryBigSum(n, ar);
    printf("%ld\n", result);

    free(ar);
    return 0;
}
