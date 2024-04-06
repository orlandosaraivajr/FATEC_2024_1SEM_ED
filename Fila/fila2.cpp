/*
 * Exemplo do uso de fila com alocação dinâmica.
 *
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 12/12/2023
 */
 #include <iostream>

using namespace std;

// Definição da estrutura do nó
struct NO {
    int valor;
    NO* prox;
};

// Definição da estrutura da fila
struct Queue {
    NO* frente;
    NO* tras;
};

void initializeQueue(Queue *);
bool isEmpty(Queue *);
void enqueue(Queue *, int);
void dequeue(Queue *);
void displayQueue(Queue *);
void destroyQueue(Queue *);
bool buscaFila(Queue *, int);

int main() {
    Queue fila;
    initializeQueue(&fila);
    displayQueue(&fila);
    enqueue(&fila, 1);
    enqueue(&fila, 2);
    enqueue(&fila, 3);
    displayQueue(&fila);
    dequeue(&fila);
    dequeue(&fila);
    displayQueue(&fila);
    enqueue(&fila, 4);
    enqueue(&fila, 5);
    displayQueue(&fila);

    /*
    int elementoProcurado = 10;
    if (buscaFila(&fila, elementoProcurado)) {
        cout << "O elemento " << elementoProcurado << " está na fila." << endl;
    } else {
        cout << "O elemento " << elementoProcurado << " não está na fila." << endl;
    }
    enqueue(&fila, 10);
    if (buscaFila(&fila, elementoProcurado)) {
        cout << "O elemento " << elementoProcurado << " está na fila." << endl;
    } else {
        cout << "O elemento " << elementoProcurado << " não está na fila." << endl;
    }
	*/

    destroyQueue(&fila);
    return 0;
}


// Função para inicializar a fila
void initializeQueue(Queue *q) {
    q->frente = NULL;
    q->tras = NULL;
}

// Função para verificar se a fila está vazia
bool isEmpty(Queue *q) {
    return (q->frente == NULL);
}

// Função para enfileirar um elemento na fila
void enqueue(Queue *q, int value) {
    NO* novoNo = new NO;
    novoNo->valor = value;
    novoNo->prox = NULL;
    if (isEmpty(q)) {
        q->frente = novoNo;
    } else {
        q->tras->prox = novoNo;
    }
    q->tras = novoNo;
    cout << "Elemento " << value << " enfileirado com sucesso." << endl;
}

// Função para desenfileirar um elemento da fila
void dequeue(Queue *q) {
    if (!isEmpty(q)) {
        NO* temp = q->frente;
        q->frente = q->frente->prox;
        delete temp;
    } else {
        cout << "Erro: a fila está vazia." << endl;
    }
}

// Função para exibir a fila
void displayQueue(Queue *q) {
    if (!isEmpty(q)) {
        cout << "Fila:";
        NO* atual = q->frente;
        while (atual != NULL) {
            cout << " " << atual->valor;
            atual = atual->prox;
        }
        cout << endl;
    } else {
        cout << "Fila vazia." << endl;
    }
}

// Função para liberar a memória alocada pela fila
void destroyQueue(Queue *q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
}

