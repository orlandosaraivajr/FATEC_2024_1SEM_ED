/*

Fonte: 
https://github.com/valdirGarcia/Estrutura_de_Dados_fatec/blob/main/atividade%20fun%C3%A7%C3%A3o.cpp
*/
#include <iostream>

using namespace std;

int soma(int n) {
	
    int resultado = 0;
    
    for (int i = n; i >= 1; --i) {
        resultado += i;
    }
    
    return resultado;
}

int main() {
	
	int numero;
	
    cout << "Digite um n�mero: " << endl;
    cin >> numero;
    
    int resultado = soma(numero);
    
    cout << "A soma dos numeros de " << numero << " ate 1 e: " << resultado << endl;
    
    
    return 0;
}
