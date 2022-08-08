#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int number;
    struct link *node;
} node;

node *create(int val);
node *insert(node *head, int val);
int find(node *head, int val);

int main()
{
    node *new = create(6);
    new = insert(new, 12);
    new = insert(new, 11);
    new = insert(new, 10);
    printf("%d\n", new->number);
    printf("%d\n", new->node->number);
    // printf("%d\n", new->node->node->number);

    return 0;
}

node *create(int val)
{
    node *new = malloc(sizeof(node));
    if (new == NULL)
    {
        return 0;
    }

    new->number = val;
    new->node = NULL;
    return new;
}

node *insert(node *head, int val)
{
    node *tmp = NULL;
    node *new = malloc(sizeof(node));
    
    new->number = val;
    new->node = NULL;

    for (tmp = head;; tmp = tmp->node)
    {
        if (tmp->node == NULL)
        {
            tmp->node = new;
            head = tmp;
            // free(tmp);
            return head;
        }
    }
}
