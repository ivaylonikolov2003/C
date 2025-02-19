#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

int flag = 0;

struct node* createNode(struct node* root, int data)
{
    if (root == NULL)
    {
        struct node* node = (struct node*)malloc(sizeof(struct node));
        if (node == NULL)
        {
            fprintf(stderr, "Error allocating memory for vertex");
            exit(EXIT_FAILURE);
        }
    
        node->data = data;
        node->left = NULL;
        node->right = NULL;
 
        return (node);
    }

    if (data < root->data) {
        root->left = createNode(root->left, data);
    } 
    else if (data >= root->data) {
        root->right = createNode(root->right, data);
    }
    
    return root;   
}

void searchForSameValues(struct node* root, int data) {
    if (root == NULL || flag == 2) {
        return;
    }

    if (root->data == data && flag < 2) {
        flag++;
        if (root->data == data && flag == 2) {
            printf("The tree has at least two vertices with the same values.\n");
            return;
        }
    }

    searchForSameValues(root->left, data);
    searchForSameValues(root->right, data);
}
void checkTree(struct node* root) {
    if (root == NULL || flag == 2) {
        return;
    }

    flag = 0;
    searchForSameValues(root, root->data);
    checkTree(root->left);
    checkTree(root->right);
}

int main() {
    struct node* root = NULL;

    root = createNode(root, 5);
    root = createNode(root, 3);
    root = createNode(root, 8);
    root = createNode(root, 3); 
    root = createNode(root, 7);

    checkTree(root);
    return 0;
}