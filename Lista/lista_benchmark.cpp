/*
 * Busca Sequencial x Busca Binária.
 *
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 11/05/2018
 * Atualizado em : 19/04/2024
 * 
 */
#include <iostream>
#include <chrono>

using namespace std;

// #define MAX_SIZE 2000000
#define MAX_SIZE 5000

void insertElement(int[], int& , int);
bool sequentialSearch(int [], int, int);
bool binarySearch(int [], int, int);
void bubbleSort(int [], int );
void benchmark(int [], int);


int main() {
    int myList[MAX_SIZE];
    int size = 0;
    int x;
    // Inserindo elementos na lista
    for(x = 0; x < MAX_SIZE; x++) {
        insertElement(myList, size, x);
    }
    

    // Exibindo os elementos da lista
    cout << "Elementos da lista: ";
    for (x = 0; x < size; x++) {
        cout << myList[x] << " ";
    }
    cout << endl;

    // Busca sequencial
    int valueToFind = 30;
    cout << "Busca sequencial por " << valueToFind << ": " << (sequentialSearch(myList, size, valueToFind) ? "Encontrado" : "Não encontrado") << endl;

    // Ordenando a lista para a busca binária
    bubbleSort(myList, size);

    // Busca binária
    valueToFind = 40;
    cout << "Busca binária por " << valueToFind << ": "; 
    if (binarySearch(myList, size, valueToFind) ) {
        cout << "Encontrado"  << endl;
    } else{
        cout << "Não encontrado" << endl;
    }

    benchmark(myList, 300);
    benchmark(myList, 3000);
    /*
    benchmark(myList, 30000);
    benchmark(myList, 300000);
    benchmark(myList, 9003000);
    */
    return 0;
}

void insertElement(int elements[], int& size, int value) {
    if (size < MAX_SIZE) {
        elements[size++] = value;
    } else {
        cout << "Erro: lista cheia." << endl;
    }
}

bool sequentialSearch(int elements[], int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (elements[i] == value) {
            return true;
        }
    }
    return false;
}

bool binarySearch(int elements[], int size, int value) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (elements[mid] == value) {
            return true;
        } else if (elements[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

void bubbleSort(int elements[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (elements[j] > elements[j + 1]) {
                // Troca os elementos
                int temp = elements[j];
                elements[j] = elements[j + 1];
                elements[j + 1] = temp;
            }
        }
    }
}


void benchmark(int elements[], int valueToFind) {
    cout << "\n***************************************************\n";
    cout << "Busca no Elemento " << valueToFind << endl;
    auto start = chrono::steady_clock::now();
    binarySearch(elements, MAX_SIZE, valueToFind);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "Busca binária  " << endl;
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    sequentialSearch(elements, MAX_SIZE, valueToFind);
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << "Busca sequencial " << endl;
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    cout << endl << endl;
}
