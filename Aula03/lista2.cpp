/**
 * Fonte: 
 * https://github.com/PedNeto/ED_1SEM_2024/blob/master/lista02/cadCarro.cpp
*/
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


struct parcelas
{  
    string local;
    string data;
    double valorParcela;
};

typedef struct CadCliLoja
{
    string nome;
    string endereco;
    string cidade;
    string estado;
    double valorTotal;
    int qtdParcelas;
    parcelas totalParcelas[12];
} CADCLILOJA;

void cadastro_cliente(CadCliLoja& cad_cliente);
void quantidade_parcela(CadCliLoja& cad_cliente);

int main()
{   
    int TOTAL = 1;
    int i;
    CADCLILOJA minha_loja[TOTAL];

    for (i = 0; i < TOTAL; i++)
    {
        cadastro_cliente(minha_loja[i]);
        quantidade_parcela(minha_loja[i]);
    }
    
    for (i = 0; i < TOTAL; i++) {
        cout << endl;
        cout << "nome = " << minha_loja[i].nome << endl;
        cout << "endereco = " << minha_loja[i].endereco << endl;
        cout << "cidade = " << minha_loja[i].cidade << endl;
        cout << "estado = " << minha_loja[i].estado << endl;
        int qtd = minha_loja[i].qtdParcelas;
        for (int x = 0; x < qtd; x++)
        {   
            cout << endl;
            cout << x+1 <<" Parcela:" << endl;
            cout << "local = " << minha_loja[i].totalParcelas[x].local << endl;
            cout << "data = " << minha_loja[i].totalParcelas[x].data << endl;
            cout << "valorParcela = " << minha_loja[i].totalParcelas[x].valorParcela << endl;
        }
        cout << endl;
        cout <<"========================"<< endl;
    }
    
    return 0;
}

void cadastro_cliente(CadCliLoja& cad_cliente){
    cout << "Digite o nome do cliente: ";
    cin >> cad_cliente.nome;
    cout << "Digite o endereço do cliente: ";
    cin >> cad_cliente.endereco;
    cout << "Digite a cidade do cliente: ";
    cin >> cad_cliente.cidade;
    cout << "Digite o estado do cliente: ";
    cin >> cad_cliente.estado;
    cout << "Digite o valor da compra: ";
    cin >> cad_cliente.valorTotal;
    cout << "Número de Parcelas (1 a 12): ";
    cin >> cad_cliente.qtdParcelas;
}

void quantidade_parcela(CadCliLoja& cad_cliente){
    double valorParcela = cad_cliente.valorTotal / cad_cliente.qtdParcelas;

    for (int i = 0; i < cad_cliente.qtdParcelas; i++)
    {
        cout << i+1 <<" Parcela:" << endl;
        cout << "Digite o local da compra: ";
        cin >> cad_cliente.totalParcelas[i].local;
        cout << "Digite a data da compra: ";
        cin >> cad_cliente.totalParcelas[i].data;
        cad_cliente.totalParcelas[i].valorParcela = valorParcela;
    }
}