#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
} *root;

void insert(Node *node, int data) {
    if (data < node->data) {
        if (node->left == nullptr)
            node->left = new Node{data, nullptr, nullptr};
        else
            insert(node->left, data);
    } else if (data > node->data) {
        if (node->right == nullptr)
            node->right = new Node{data, nullptr, nullptr};
        else
            insert(node->right, data);
    }
}

void insert(int data) {
    if (root == nullptr) {
        root = new Node{data, nullptr, nullptr};
        return;
    }
    insert(root, data);
}

bool isLeaf(Node *node) {
    return node->left == nullptr && node->right == nullptr;
}

bool isFullParent(Node *node) {
    return node->left != nullptr && node->right != nullptr;
}

Node *remove(Node *node, int data) {
    if (node == nullptr)
        return nullptr;
    if (data < node->data)
        node->left = remove(node->left, data);
    else if (data > node->data)
        node->right = remove(node->right, data);
    else {
        if (isLeaf(node)) {
            free(node);
            return nullptr;
        }
        if (!isFullParent(node)) {
            Node *tempNode = (node->left != nullptr) ? node->left : node->right;
            free(node);
            return tempNode;
        }

        Node *nextHighest = node->right;
        Node *prevNode;

        while (nextHighest->left != nullptr) {
            prevNode = nextHighest;
            nextHighest = nextHighest->left;
        }

        if (prevNode != nullptr) {
            prevNode->left = (nextHighest->right != nullptr) ? nextHighest->right : nullptr;
            nextHighest->right = node->right;
        }
        nextHighest->left = node->left;

        free(node);
        return nextHighest;
    }
    return node;
}

void remove(int data) {
    root = remove(root, data);
}

void displayInOrder(Node *node) {
    if (node == nullptr)
        return;
    displayInOrder(node->left);
    cout << node->data << ", ";
    displayInOrder(node->right);
}

void displayInOrder() {
    displayInOrder(root);
}

int main() {
    insert(5);
    insert(10);
    insert(7);
    insert(9);
    insert(8);
    insert(3);
    insert(1);
    insert(4);
displayInOrder();
    remove(3);

    return 0;
}