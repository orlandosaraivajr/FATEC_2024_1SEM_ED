/*
 * Exemplo do uso de fila com uso de vetor.
 *
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 12/12/2023
 */
 #include <iostream>

using namespace std;

const int MAX_SIZE = 20;

// Definição da estrutura 
struct Queue {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
};

void initializeQueue(Queue *);
void displayQueue(Queue *);
bool isEmpty(Queue *);
bool isFull(Queue *);
void enqueue(Queue *, int);
void dequeue(Queue *);

int main() {
    Queue fila;
    initializeQueue(&fila);

    enqueue(&fila, 1);
    enqueue(&fila, 2);
    enqueue(&fila, 3);
    
    displayQueue(&fila);
    dequeue(&fila);
    dequeue(&fila);

    enqueue(&fila, 4);
    displayQueue(&fila);
    return 0;
}

// Função para inicializar a fila
void initializeQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Função para verificar se a fila está vazia
bool isEmpty(Queue *q) {
    return (q->size == 0);
}

// Função para verificar se a fila está cheia
bool isFull(Queue *q) {
    return (q->size == MAX_SIZE);
}

// Função para enfileirar um elemento na fila
void enqueue(Queue *q, int value) {
    if (!isFull(q)) {
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->data[q->rear] = value;
        q->size++;
        cout << "Elemento " << value << " enfileirado com sucesso." << endl;
    } else {
        cout << "Erro: a fila está cheia." << endl;
    }
}

// Função para desenfileirar um elemento da fila
void dequeue(Queue *q) {
    if (!isEmpty(q)) {
        int removedValue = q->data[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
        q->size--;
        cout << "Elemento " << removedValue << " desenfileirado com sucesso." << endl;
    } else {
        cout << "Erro: a fila está vazia." << endl;
    }
}

// Função para exibir a fila
void displayQueue(Queue *q) {
    if (!isEmpty(q)) {
        cout << "Fila:";
        int i = q->front;
        int count = 0;
        while (count < q->size) {
            cout << " " << q->data[i];
            i = (i + 1) % MAX_SIZE;
            count++;
        }
        cout << endl;
    } else {
        cout << "Fila vazia." << endl;
    }
}