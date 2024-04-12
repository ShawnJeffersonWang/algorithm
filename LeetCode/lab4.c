#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int value) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node *buildTree() {
    int value;
    scanf("%d", &value);
    if (value == -1) {
        return NULL;
    }
    struct Node *root = newNode(value);
    // printf("Enter left subtree of %d: ", value);
    root->left = buildTree();
    // printf("Enter right subtree of %d: ", value);
    root->right = buildTree();
    return root;
}

void levelOrderTraversal(struct Node *root) {
    if (root == NULL) {
        return;
    }
    struct Node *queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct Node *node = queue[front++];
        printf("%d ", node->data);
        if (node->left != NULL) {
            queue[rear++] = node->left;
        }
        if (node->right != NULL) {
            queue[rear++] = node->right;
        }
    }
}

void postorderTraversal(struct Node *root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

void iterativePreorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    struct Node *stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        struct Node *node = stack[top--];
        printf("%d ", node->data);
        if (node->right != NULL) {
            stack[++top] = node->right;
        }
        if (node->left != NULL) {
            stack[++top] = node->left;
        }
    }
}

void iterativeInorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    struct Node *stack[100];
    int top = -1;
    struct Node *current = root;
    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void iterativePostorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    struct Node *stack1[100];
    struct Node *stack2[100];
    int top1 = -1;
    int top2 = -1;
    stack1[++top1] = root;
    while (top1 >= 0) {
        struct Node *node = stack1[top1--];
        stack2[++top2] = node;
        if (node->left != NULL) {
            stack1[++top1] = node->left;
        }
        if (node->right != NULL) {
            stack1[++top1] = node->right;
        }
    }
    while (top2 >= 0) {
        struct Node *node = stack2[top2--];
        printf("%d ", node->data);
    }
}

int main() {
    printf("Enter the preorder sequence (-1 for NULL): ");
    struct Node *root = buildTree();
    // 其他操作或遍历代码...
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");
    printf("Level order traversal: ");
    levelOrderTraversal(root);
    printf("\n");
    printf("Iterative Preorder traversal: ");
    iterativePreorder(root);
    printf("\n");
    printf("Iterative Inorder traversal: ");
    iterativeInorder(root);
    printf("\n");
    printf("Iterative Postorder traversal: ");
    iterativePostorder(root);
    printf("\n");
    return 0;
}