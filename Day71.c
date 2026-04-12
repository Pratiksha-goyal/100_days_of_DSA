// Implement a hash table using quadratic probing with formula:  h(k, i) = (h(k) + i*i) % m
#include <stdio.h>
#include <string.h>

#define EMPTY -1

int main() {
    int m, q;

    printf("Enter table size:\n");
    scanf("%d", &m);

    int hash[m];

    for (int i = 0; i < m; i++)
        hash[i] = EMPTY;

    printf("Enter number of operations:\n");
    scanf("%d", &q);

    printf("Enter operations:\n");

    while (q--) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        int h = key % m;

        if (strcmp(op, "INSERT") == 0) {
            int i = 0, index;

            while (i < m) {
                index = (h + i*i) % m;

                if (hash[index] == EMPTY) {
                    hash[index] = key;
                    break;
                }
                i++;
            }
        }
        else if (strcmp(op, "SEARCH") == 0) {
            int i = 0, index, found = 0;

            while (i < m) {
                index = (h + i*i) % m;

                if (hash[index] == key) {
                    found = 1;
                    break;
                }

                if (hash[index] == EMPTY) {
                    break;
                }

                i++;
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}