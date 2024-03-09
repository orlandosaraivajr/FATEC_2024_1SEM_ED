/**
 * Fonte: 
 * https://github.com/PedNeto/ED_1SEM_2024/blob/master/lista02/cadCarro.cpp
*/
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct revisao
{
    string local;
    string data;
};

typedef struct carro
{
    string placa;
    int ano;
    string marca;
    revisao inspecao[5];
} CARRO;

void cadastro_carro(carro& cad_carro);
void marca_revisao(carro& cad_carro);

int main()
{
    int TOTAL = 2;
    int i;
    CARRO vetor_carro[TOTAL];

    for (i = 0; i < TOTAL; i++)
    {
        cadastro_carro(vetor_carro[i]);
        marca_revisao(vetor_carro[i]);
    }
    
    for (i = 0; i < TOTAL; i++) {
        cout << endl;
        cout << "Marca = " << vetor_carro[i].marca << endl;
        cout << "Placa = " << vetor_carro[i].placa << endl;
        cout << "Ano = " << vetor_carro[i].ano << endl;
        for (int x = 0; x < 5; x++)
        {   
            cout << "Revisao "<< x+1 <<":" << endl;
            cout << "local "<< x <<" = " << vetor_carro[i].inspecao[x].local << endl;
            cout << "data "<< x <<" = " << vetor_carro[i].inspecao[x].data << endl;
        }
        cout << endl;
    }
    
    return 0;
}

void cadastro_carro(carro& cad_carro){
    cout << "Digite a marca do carro: ";
    cin >> cad_carro.marca;
    cout << "Digite a placa do carro: ";
    cin >> cad_carro.placa;
    cout << "Digite o ano do carro: ";
    cin >> cad_carro.ano;
}

void marca_revisao(carro& cad_carro){
    for (int i = 0; i < 5; i++)
    {
        cout << "Revisao "<< i+1 <<":" << endl;
        cout << "Digite a data da revisão do carro: ";
        cin >> cad_carro.inspecao[i].data;
        cout << "Digite o local da revisão do carro: ";
        cin >> cad_carro.inspecao[i].local;
    }
}