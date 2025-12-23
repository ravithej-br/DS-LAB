#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

/* Insert using Linear Probing */
void insert(int key)
{
    int index = key % SIZE;
    int startIndex = index;

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;

        if (index == startIndex)
        {
            printf("Hash table is full. Cannot insert %d\n", key);
            return;
        }
    }

    hashTable[index] = key;
}

/* Display hash table */
void display()
{
    int i;
    printf("\nHash Table:\n");
    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] != -1)
            printf("Index %d : %d\n", i, hashTable[i]);
        else
            printf("Index %d : Empty\n", i);
    }
}

int main()
{
    int i, n, key;

    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of employee records (max %d): ", SIZE);
    scanf("%d", &n);

    if (n > SIZE)
    {
        printf("Error: Number of records exceeds table size\n");
        return 0;
    }

    printf("Enter 4-digit employee keys:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);

        if (key < 1000 || key > 9999)
        {
            printf("Invalid key %d (not 4-digit). Skipped.\n", key);
            continue;
        }

        insert(key);
    }

    display();

    return 0;
}
