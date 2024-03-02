#include <iostream>
using namespace std;
/* Desenvolva uma aplicação para cadastrar cliente que fará um crédito em 12 vezes. */
/* Insira na estrutura informações pertinentes ao cliente. */


struct cadastro_cliente{
	string nome;
	float valor_compra;
    int qtd_parcelas;
    float parcela[12];
	string loja;
};

string Nome_cliente();
float Compra_realizada();
string Nome_loja();

int main() {
	
	struct cadastro_cliente cliente1;
	
	cliente1.nome = Nome_cliente();
	cliente1.loja = Nome_loja();
	cout << "Digite o valor da compra" << endl;
	cin >> cliente1.valor_compra;
	cout << "Digite o número de parcelas" << endl;
	cin >> cliente1.qtd_parcelas;
	float valor_parcelinha = cliente1.valor_compra / cliente1.qtd_parcelas;
	for(int x=0; x < cliente1.qtd_parcelas; x++) {
		cliente1.parcela[x] = valor_parcelinha;
	}
	
	for(int x=0; x < cliente1.qtd_parcelas; x++) {
		cout << "Parcela " << x+1 << " = " << cliente1.parcela[x] << endl;
	}
	return 0;
}

string Nome_cliente(){
	string nome;
	cout << "Insira o nome do cliente: " << endl;
	cin >> nome;
	return nome;
}

float Compra_realizada(){
	float compra;
	float result;
	cout << "Insira o valor da compra: " << endl;
	cin >> compra;
	result = compra / 12;
	return result;
}

string Nome_loja(){
	string loja;
	cout << "Insira o nome da loja: " << endl;
	cin >> loja;
	return loja;
}