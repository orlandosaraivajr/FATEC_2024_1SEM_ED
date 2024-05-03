/*
 * Árvore Binária.
 *
 * Prof. Me. Orlando Saraiva Jr
 *
 */
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int);
Node* insert(Node*, int);
void preOrderTraversal(Node*);
void inOrderTraversal(Node*);
void postOrderTraversal(Node*);
bool search(Node*, int);
void destroyTree(Node*);

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Percorrer a árvore em pré-ordem
    cout << "Pré-ordem: ";
    preOrderTraversal(root);
    cout << endl;

    // Percorrer a árvore em ordem
    cout << "Em ordem: ";
    inOrderTraversal(root);
    cout << endl;

    // Percorrer a árvore em pós-ordem
    cout << "Pós-ordem: ";
    postOrderTraversal(root);
    cout << endl;

    // Buscar valores na árvore
    cout << "Busca por 30: " << (search(root, 30) ? "Encontrado" : "Não encontrado") << endl;
    cout << "Busca por 45: " << (search(root, 45) ? "Encontrado" : "Não encontrado") << endl;

    // Liberar memória alocada para a árvore
    destroyTree(root);

    return 0;
}


Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

void preOrderTraversal(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

void postOrderTraversal(Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }
}

bool search(Node* root, int value) {
    if (root == NULL) {
        return false;
    }

    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

void destroyTree(Node* root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}