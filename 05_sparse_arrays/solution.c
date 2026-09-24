#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 2003

typedef struct HashNode {
    char key[21];
    int count;
    struct HashNode* next;
} HashNode;

typedef struct {
    HashNode* buckets[HASH_TABLE_SIZE];
} HashTable;

unsigned int hash_string(const char* str) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % HASH_TABLE_SIZE;
}

HashTable* create_hash_table() {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

void insert_hash_table(HashTable* table, const char* str) {
    unsigned int index = hash_string(str);
    HashNode* curr = table->buckets[index];

    while (curr != NULL) {
        if (strcmp(curr->key, str) == 0) {
            curr->count++;
            return;
        }
        curr = curr->next;
    }

    HashNode* new_node = (HashNode*)malloc(sizeof(HashNode));
    strncpy(new_node->key, str, 20);
    new_node->key[20] = '\0';
    new_node->count = 1;
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
}

int search_hash_table(HashTable* table, const char* str) {
    unsigned int index = hash_string(str);
    HashNode* curr = table->buckets[index];

    while (curr != NULL) {
        if (strcmp(curr->key, str) == 0) {
            return curr->count;
        }
        curr = curr->next;
    }

    return 0;
}

void free_hash_table(HashTable* table) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        HashNode* curr = table->buckets[i];
        while (curr != NULL) {
            HashNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(table);
}

int* matchingStrings(int stringList_count, char** stringList, int queries_count, char** queries, int* result_count) {
    HashTable* table = create_hash_table();

    for (int i = 0; i < stringList_count; i++) {
        insert_hash_table(table, stringList[i]);
    }

    int* results = (int*)malloc(queries_count * sizeof(int));

    for (int i = 0; i < queries_count; i++) {
        results[i] = search_hash_table(table, queries[i]);
    }

    free_hash_table(table);
    *result_count = queries_count;
    return results;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char** stringList = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        stringList[i] = (char*)malloc(21 * sizeof(char));
        scanf("%20s", stringList[i]);
    }

    int q;
    if (scanf("%d", &q) != 1) return 0;

    char** queries = (char**)malloc(q * sizeof(char*));
    for (int i = 0; i < q; i++) {
        queries[i] = (char*)malloc(21 * sizeof(char));
        scanf("%20s", queries[i]);
    }

    int result_count = 0;
    int* results = matchingStrings(n, stringList, q, queries, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d\n", results[i]);
    }

    for (int i = 0; i < n; i++) free(stringList[i]);
    free(stringList);

    for (int i = 0; i < q; i++) free(queries[i]);
    free(queries);

    free(results);
    return 0;
}
