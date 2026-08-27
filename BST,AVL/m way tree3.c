#include <stdio.h>
#include <stdlib.h>

#define M 3

typedef struct Node {
    int key[M - 1];
    struct Node *child[M];
    int n;
} Node;

Node *createNode(int key)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->key[0] = key;
    newNode->n = 1;

    for (int i = 0; i < M; i++)
        newNode->child[i] = NULL;

    return newNode;
}

void insert(Node *root, int key)
{
    int i;

    /* Find correct position */
    for (i = 0; i < root->n && key > root->key[i]; i++);

    /* Duplicate key */
    if (i < root->n && key == root->key[i])
        return;

    /*
     * For a simple M-way search tree,
     * insert only when the node is a leaf.
     */
    if (root->child[i] == NULL) {
        if (root->n < M - 1) {
            /* Shift keys */
            for (int j = root->n; j > i; j--)
                root->key[j] = root->key[j - 1];

            root->key[i] = key;
            root->n++;
        }
        else {
            /*
             * Node is full.
             * Create a new child.
             */
            Node *newNode = createNode(key);

            if (key < root->key[0]) {
                newNode->child[0] = root->child[0];
                root->child[0] = newNode;
            }
            else {
                newNode->child[0] = root->child[root->n];
                root->child[root->n] = newNode;
            }
        }
    }
    else {
        insert(root->child[i], key);
    }
}

void inorder(Node *root)
{
    if (root == NULL)
        return;

    for (int i = 0; i < root->n; i++) {
        inorder(root->child[i]);
        printf("%d ", root->key[i]);
    }

    inorder(root->child[root->n]);
}

int main()
{
    Node *root = createNode(20);

    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);

    printf("Inorder traversal: ");
    inorder(root);

    return 0;
}

