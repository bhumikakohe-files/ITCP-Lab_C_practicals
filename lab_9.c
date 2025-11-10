//AIM: 9	Assume that you have a seven-slot closed hash table (the slots are numbered o through 
//6) Write program  to final hash table that would result if you used the hash function h(k) - k mod 7.
//ROLL NO 102
#include <stdio.h>

#define SIZE 7

int hash(int key) {
    return key % SIZE;
}

void insert(int table[], int key) {
    int index = hash(key);
    int original_index = index;

    while (table[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == original_index) {
            printf("Hash table is full. Cannot insert %d\n", key);
            return;
        }
    }
    table[index] = key;
}

int main() {
    int table[SIZE];
    int n, key;

    // Initialize hash table with -1 (empty)
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    printf("Enter %d keys:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(table, key);
    }

    printf("Final hash table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Slot %d: %d\n", i, table[i]);
    }

    return 0;
}
