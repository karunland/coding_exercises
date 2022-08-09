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
void destroy(node *head);

int main()
{
    node *new = create(6);
    new = insert(new, 12);
    new = insert(new, 11);
    new = insert(new, 10);
    new = insert(new, 9);

    // i even impress myself sometimes, Gzzzz

    // printf("%d\n", new->number);
    // printf("%d\n", new->node->number);
    // printf("%d\n", new->node->node->number);
    // printf("%d\n", new->node->node->node->number);
    // printf("%d\n", new->node->node->node->node->number);

    for (node *tmp = new; tmp != NULL; tmp = tmp->node)
    {
        // Within the node, we'll just print the number stored:
        printf("%i\n", tmp->number);
    }
    
    // works perfectly
    destroy(new);
    
    // for (node *tmp = new; tmp != NULL; tmp = tmp->node)
    // {
        // Within the node, we'll just print the number stored:
        // printf("%i\n", tmp->number);
    // }
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
    new->node = head;

    return new;
}

void destroy(node *head)
{
    // 
    if (head->node == NULL)
    {
        printf("if\n");
        free(head);
        return;
    }
    else
    {
        printf("else\n");
        destroy(head->node);
        free(head);
        return;
        
    }
}
