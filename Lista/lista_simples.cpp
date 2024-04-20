/*
 * Lista Ordenada.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 19/04/2024
 * 
 */
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertAtBeginning(Node*, int);
Node* insertAtEnd(Node*, int);
Node* removeFromBeginning(Node*);
Node* remove_at_position(Node*, int);
void display(Node*);
bool search(Node*, int);
void destroy(Node*);

int main() {
    Node* list = NULL;

    list = insertAtEnd(list, 10);
    list = insertAtEnd(list, 20);
    list = insertAtEnd(list, 30);
    list = insertAtEnd(list, 40);
    list = insertAtEnd(list, 50);
    
    list = insertAtBeginning(list, 1);
    list = insertAtBeginning(list, 5);

    cout << "Lista: ";
    display(list);

    int posicao = 3;
    list = remove_at_position(list, posicao);
    cout << "Lista após remover o elemento da posicao" << posicao << ": ";
    display(list);
    list = remove_at_position(list, 30);
    display(list);

    int valor = 20;
    cout << "O valor " << valor << " está presente na lista? " << (search(list, valor) ? "Sim" : "Não") << endl;
    
    list = removeFromBeginning(list);
    display(list);

    destroy(list);

    return 0;
}

Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node* removeFromBeginning(Node* head) {
    if (head == NULL) {
        cout << "A lista está vazia." << endl;
        return NULL;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* remove_at_position(Node* head, int position) {
    if (head == NULL) {
        cout << "A lista está vazia." << endl;
        return NULL;
    }

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    Node* previous = NULL;
    int count = 0;

    while (current != NULL && count < position) {
        previous = current;
        current = current->next;
        count++;
    }

    if (current == NULL) {
        cout << "Posição inválida." << endl;
        return head;
    }

    previous->next = current->next;
    delete current;
    return head;
}

void display(Node* head) {
    if (head == NULL) {
        cout << "A lista está vazia." << endl;
        return;
    }

    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

bool search(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void destroy(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}
