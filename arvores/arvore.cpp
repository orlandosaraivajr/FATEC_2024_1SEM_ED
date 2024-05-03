/*
 * Árvore.
 *
 * Prof. Me. Orlando Saraiva Jr
 *
 */
#include <iostream>

using namespace std;

struct Node {
    char data;
    Node* firstChild;
    Node* nextSibling;
};

Node* createNode(char);
void addChild(Node*, Node*);
void preOrderTraversal(Node*);
void inOrderTraversal(Node*);
void postOrderTraversal(Node*);
void destroyTree(Node*);

int main() {
    // Criar a raiz da árvore
    Node* root = createNode('a');

    // Inserir filhos na raiz
    Node* node_b = createNode('b');
    Node* node_c = createNode('c');
    Node* node_d = createNode('d');
    addChild(root, node_b);
    addChild(root, node_c);
    addChild(root, node_d);

    // Inserir filhos do primeiro nó
    Node* node_e = createNode('e');
    Node* node_f = createNode('f');
    Node* node_g = createNode('g');
    addChild(node_b, node_e);
    addChild(node_b, node_f);
    addChild(node_b, node_g);

    // Inserir filhos do segundo nó
    Node* node_h = createNode('h');
    addChild(node_c, node_h);

    // Inserir filhos do terceiro nó
    addChild(node_d, createNode('i'));
    addChild(node_d, createNode('j'));

    
    addChild(node_f, createNode('k'));
    addChild(node_h, createNode('l'));
    addChild(node_h, createNode('m'));
    

    // Percorrer os nós da árvore
    cout << "Pré-ordem: ";
    preOrderTraversal(root);
    cout << endl;
    cout << "Em ordem: ";
    inOrderTraversal(root);
    cout << endl;
    cout << "Pós-ordem: ";
    postOrderTraversal(root);
    cout << endl;

    destroyTree(root);

    return 0;
}


Node* createNode(char value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

void addChild(Node* parent, Node* child) {
    if (parent->firstChild == NULL) {
        parent->firstChild = child;
    } else {
        Node* sibling = parent->firstChild;
        while (sibling->nextSibling != NULL) {
            sibling = sibling->nextSibling;
        }
        sibling->nextSibling = child;
    }
}

// Função para percorrer a árvore em pré-ordem
void preOrderTraversal(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrderTraversal(root->firstChild);
        preOrderTraversal(root->nextSibling);
    }
}

// Função para percorrer a árvore em ordem
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->firstChild);
        cout << root->data << " ";
        inOrderTraversal(root->nextSibling);
    }
}

// Função para percorrer a árvore em pós-ordem
void postOrderTraversal(Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->firstChild);
        postOrderTraversal(root->nextSibling);
        cout << root->data << " ";
    }
}

// Função para liberar a memória alocada para a árvore
void destroyTree(Node* root) {
    if (root != NULL) {
        destroyTree(root->firstChild);
        destroyTree(root->nextSibling);
        delete root;
    }
}