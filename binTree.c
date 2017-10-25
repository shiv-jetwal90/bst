#include<stdio.h>
#include<malloc.h>
typedef struct node
{
    struct node *lchild;
    struct node *rchild;
    int data;
}Node;
void insert(struct node *, int, struct node *);
void show(struct node *);
int size(struct node *, int);
int main()
{
    Node root;
    int i, n;
    scanf("%d", &n);
    root.lchild = NULL;
    root.rchild = NULL;
    root.data = n;

    for(i = 1; ; i++)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        insert(&root, n, NULL);
    }
    show(&root);
    printf("Size = %d\n", size(&root, 0));
    return 0;
}

void insert(struct node * node, int val, struct node *prev)
{
    if(node == NULL)
    {
        Node *p;
        p = (Node *) malloc(sizeof(struct node));
        p -> data = val;
        p -> lchild = NULL;
        p -> rchild = NULL;
        if(val < prev -> data)
            prev -> lchild = p;
        else
            prev -> rchild = p;
    }
    else
    {
        if(val < node -> data)
            insert(node -> lchild, val, node);
        else
            insert(node -> rchild, val, node);
    }
}

void show(struct node * node)
{
    if(node == NULL)
        ;
    else
    {
        show(node -> lchild);
        printf("%d\n", node -> data);
        show(node -> rchild);
    }
}


int size(struct node *node, int n)
{
    if(node == NULL)
        return 0;
    else
    {
        size(node -> lchild, n);
        n += 1;
        size(node -> rchild, n);
    }
    return n;
}
