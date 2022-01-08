#include <stdio.h>
#include <stdlib.h>

#define SIZE 50
#define true 1 == 1
#define false 1 != 1
typedef int boolean;
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} TreeNode;
TreeNode* create(TreeNode *root, int data){
    //Memory allocation for free root
    TreeNode *tmp = malloc(sizeof(TreeNode));
    //Assigning a value to a key
    tmp->key = data;
    //Nulling a pointer to the left and right subtree
    tmp->left = tmp->right = NULL;
    root = tmp;
    return root;
}
TreeNode* treeInsert(TreeNode *t, int data) {
    TreeNode *newNode;
    newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    TreeNode *current = t;
    TreeNode *parent = t;
    if (t == NULL) {
        t = newNode;
    } else {
        while (current->key != data) {
            parent = current;
            if (current->key > data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    return t;
                }
            } else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}
void printTree(TreeNode *root) {
    if (root) {
        printf("%d", root->key);
        if (root->left || root->right) {
            printf("(");
            if (root->left)
                printTree(root->left);
            else
                printf("NULL");
            printf(",");
            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}
TreeNode* getSuccessor(TreeNode *node) {
    TreeNode *current = node->right;
    TreeNode *parent = node;
    TreeNode *s = node;

    while (current != NULL) {
        parent = s;
        s = current;
        current = current->left;
    }
    if (s != node->right) {
        parent->left = s->right;
        s->right = node->right;
    }
    return s;
}
boolean treeNodeDelete(TreeNode *root, int key) {
    TreeNode *current = root;
    TreeNode *parent = root;
   boolean isLeftChild = true;

    while (current->key != key) {
        parent = current;
        if (key < current->key) {
            current = current->left;
            isLeftChild = true;
        } else {
            current = current->right;
            isLeftChild = false;
        }
        if (current == NULL)
            return false;
    }

    if (current->left == NULL && current->right == NULL) {
        if (current == root)
            root = NULL;
        else if (isLeftChild)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    else if (current->right == NULL) {
        if (isLeftChild)
            parent->left = current->left;
        else
            parent->right = current->left;
    }
    else if (current->left == NULL) {
        if (isLeftChild)
            parent->left = current->right;
        else
            parent->right = current->right;
    }
    else {
        TreeNode *successor = getSuccessor(current);
        if (current == root)
            root = successor;
        else if (isLeftChild)
            parent->left = successor;
        else
            parent->right = successor;
        successor->left = current->left;
    }
    return true;
}
//task 1
int checkTreeHeight(TreeNode *root){
    if (!root) return 0;
    //left subtree balance check
    int leftChildHeight = checkTreeHeight(root->left);
    if (leftChildHeight == -1) return -1; // -1 if not balanced
    //right subtree balance check
    int rightChildHeight = checkTreeHeight(root->right);
    if (rightChildHeight == -1) return -1; // -1 if not balanced
    //check current node balance
    int heightDiff = leftChildHeight - rightChildHeight;
    if(abs(heightDiff) > 1)
        return -1;// not balanced
    else {
        if (leftChildHeight >= rightChildHeight)
            return leftChildHeight + 1;
        else
            return rightChildHeight + 1;
    }
}
boolean checkAVL (TreeNode *root){
    if (checkTreeHeight(root) == -1)
        return false;
    else
        return true;
}
void printTreeCheck (TreeNode *root) {
    if (checkAVL(root))
        printf("Tree is balaced\n");
    else
        printf("Tree is not balaced\n");

}
//task 2
boolean treeNodeSearch(TreeNode *root, int key) {
    if (root == NULL)
        return false;
    if (root->key == key)
        return true;
    TreeNode *current = root;
    if (key < current->key)
        current = current->left;
    else
        current = current->right;
    treeNodeSearch(current, key);
}
int main()
{
    //task 1
    float balanceCheck = 0;
    for (int i = 0; i < SIZE; i++) {
        srand(i);
        TreeNode *tree = create(tree, rand());
        for (int i = 1; i < 10000; i++){
            treeInsert(tree, rand());
        }
        if (checkAVL(tree))
            balanceCheck++;
    }
    printf ("Percentage of balanced trees = %f\n",balanceCheck / SIZE * 100);

    //task 2
    TreeNode *tree2 = create(tree2, 5);
    for (int i = 0; i < 6; i++){
        treeInsert(tree2, rand() % 10);
    }
    printTree(tree2);
    int searchKey = 7;
    if (treeNodeSearch(tree2, searchKey))
        printf ("value %d found\n", searchKey);
    else
        printf ("value %d not found\n", searchKey);
    return 0;
}
