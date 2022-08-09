#include <stdio.h>
#include <stdlib.h>

// Represents a node
typedef struct node
{
    int number;
    struct node *next;
}
node;

// make linked && ./linked

int main(void)
{
    // List of size 0, initially not pointing to anything
    node *list = NULL;

    // Add number to list
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 1;
    n->next = NULL;
    // We create our first node, store the value 1 in it, and leave the next
    // pointer to point to nothing. Then, our list variable can point to it.
    list = n;

    // Add number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    // Now, we go our first node that list points to, and sets the next pointer
    // on it to point to our new node, adding it to the end of the list:
    list->next = n;
    printf("number 1.-> %d\n", list->number);
    // Add number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    // We can follow multiple nodes with this syntax, using the next pointer
    // over and over, to add our third new node to the end of the list:
    list->next->next = n;
    // Normally, though, we would want a loop and a temporary variable to add
    // a new node to our list.

    // Print list
    // Here we can iterate over all the nodes in our list with a temporary
    // variable. First, we have a temporary pointer, tmp, that points to the
    // list. Then, our condition for continuing is that tmp is not NULL, and
    // finally, we update tmp to the next pointer of itself.
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        // Within the node, we'll just print the number stored:
        printf("%i\n", tmp->number);
    }

    // Free list
    // Since we're freeing each node as we go along, we'll use a while loop
    // and follow each node's next pointer before freeing it, but we'll see
    // this in more detail in Problem Set 5.
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}

