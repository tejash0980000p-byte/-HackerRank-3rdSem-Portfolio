#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicVector;

void vector_init(DynamicVector *v) {
    v->size = 0;
    v->capacity = 2;
    v->data = (int *)malloc(v->capacity * sizeof(int));
}

void vector_push(DynamicVector *v, int val) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = val;
}

void vector_free(DynamicVector *v) {
    if (v->data) {
        free(v->data);
    }
}

int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) {
    DynamicVector *arr = (DynamicVector *)malloc(n * sizeof(DynamicVector));
    for (int i = 0; i < n; i++) {
        vector_init(&arr[i]);
    }

    int lastAnswer = 0;
    int *results = (int *)malloc(queries_rows * sizeof(int));
    int count = 0;

    for (int i = 0; i < queries_rows; i++) {
        int query_type = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];

        int idx = (x ^ lastAnswer) % n;

        if (query_type == 1) {
            vector_push(&arr[idx], y);
        } else if (query_type == 2) {
            int elem_idx = y % arr[idx].size;
            lastAnswer = arr[idx].data[elem_idx];
            results[count++] = lastAnswer;
        }
    }

    for (int i = 0; i < n; i++) {
        vector_free(&arr[i]);
    }
    free(arr);

    *result_count = count;
    return results;
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    int **queries = (int **)malloc(q * sizeof(int *));
    for (int i = 0; i < q; i++) {
        queries[i] = (int *)malloc(3 * sizeof(int));
        scanf("%d %d %d", &queries[i][0], &queries[i][1], &queries[i][2]);
    }

    int result_count = 0;
    int *results = dynamicArray(n, q, 3, queries, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d\n", results[i]);
    }

    for (int i = 0; i < q; i++) {
        free(queries[i]);
    }
    free(queries);
    free(results);

    return 0;
}
