/*
 * Benckmarks de ordenação.
 *
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 26/04/2024
  * 
 */
#include <iostream>
#include <chrono>

using namespace std;

#define MAX_SIZE 10

void insertElement(int[], int& , int);
void printElements(int []);

void bubbleSort(int [] );
void benchmark(int []);
void mergeSort(int [], int , int );
void merge(int [], int , int, int );

int main() {
    int myList[MAX_SIZE];
    int size = 0;
    int x, i;

    srand((unsigned)time(0)); 
    for(x = 0; x < MAX_SIZE; x++) {
        i = (rand()%MAX_SIZE) + 1; 
        insertElement(myList, size, i);
    }

    printElements(myList);
    benchmark(myList);
    printElements(myList);
    return 0;
}

void insertElement(int elements[], int& size, int value) {
    if (size < MAX_SIZE) {
        elements[size++] = value;
    } else {
        cout << "Erro: lista cheia." << endl;
    }
}

void printElements(int elements[]) {
    for (int x = 0; x < MAX_SIZE; x++) {
        std::cout << elements[x] << " ";
    }
    std::cout << std::endl;
}

void bubbleSort(int elements[]) {
    for (int i = 0; i < MAX_SIZE - 1; ++i) {
        for (int j = 0; j < MAX_SIZE - i - 1; ++j) {
            if (elements[j] > elements[j + 1]) {
                int temp = elements[j];
                elements[j] = elements[j + 1];
                elements[j + 1] = temp;
            }
        }
    }
}

void quickSort(int elements[], int low, int high) {
    if (low < high) {
        int pivot = elements[low]; // escolhe o primeiro elemento como pivô
        int i = low + 1;
        int j = high;

        while (i <= j) {
            while (i <= high && elements[i] <= pivot) {
                i++;
            }
            while (j >= low && elements[j] > pivot) {
                j--;
            }
            if (i < j) {
                std::swap(elements[i], elements[j]);
            }
        }
        std::swap(elements[low], elements[j]);

        quickSort(elements, low, j - 1); // ordena os elementos menores que o pivô
        quickSort(elements, j + 1, high); // ordena os elementos maiores que o pivô
    }
}

void merge(int elements[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = elements[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = elements[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            elements[k] = L[i];
            i++;
        } else {
            elements[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        elements[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        elements[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int elements[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(elements, l, m);
        mergeSort(elements, m + 1, r);

        merge(elements, l, m, r);
    }
}

void benchmark(int elements[]) {
    cout << "\n***************************************************\n";
    auto start = chrono::steady_clock::now();
    quickSort(elements, 0, MAX_SIZE - 1);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "Tempo do Quick Sort : " << endl;
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    cout << "***************************************************\n";
    start = chrono::steady_clock::now();
    bubbleSort(elements);
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << "Tempo do Bubble Sort : " << endl;
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    cout << "***************************************************\n";

    start = chrono::steady_clock::now();
    mergeSort(elements, 0, MAX_SIZE - 1);
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << "Tempo do Merge Sort : " << endl;
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    cout << "***************************************************\n";

}
