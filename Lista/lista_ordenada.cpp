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

Node* insertSorted(Node*, int);
void display(Node*);
void destroyList(Node*);

int main() {
    Node* ordered_list = NULL;

    display(ordered_list);
    
    ordered_list = insertSorted(ordered_list, 30);
    ordered_list = insertSorted(ordered_list, 10);
    ordered_list = insertSorted(ordered_list, 20);
    ordered_list = insertSorted(ordered_list, 50);
    ordered_list = insertSorted(ordered_list, 40);

    
    display(ordered_list);

    ordered_list = insertSorted(ordered_list, 5);
    ordered_list = insertSorted(ordered_list, 1);
    display(ordered_list);
    
    destroyList(ordered_list);

    return 0;
}

Node* insertSorted(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || value < head->data) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
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

void destroyList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}