#include <stdio.h>
#include <stdlib.h>

#define HASH_MAX 50000

unsigned int hash_function(char *str)
{
    int sum = 0;
    for (int i = 0; str[i] != NULL; i++)
    {
        sum += str[i];
    }
    return sum % HASH_MAX;
}
typedef struct Ht_item Ht_item;

// Define the Hash Table Item here
struct Ht_item
{
    char *key;
    char *value;
};

typedef struct HashTable HashTable;

// Define the Hash Table here
struct HashTable
{
    // Contains an array of pointers
    // to items
    Ht_item **items;
    int size;
    int count;
};

int main(void)
{

    return 0;
}
