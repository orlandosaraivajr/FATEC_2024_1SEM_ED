#include <iostream>

using namespace std;

int soma(int n) {
	
    if (n <= 1) {
    	
        return n;
        
    } else {
    	
        return n + soma(n - 1);
        
    }
}

int main() {
	
    int numero;
    
    cout << "Digite um numero: ";
    cin >> numero;
    
    cout << "A soma de " << numero << " ate 1 e " << soma(numero) << endl;
    
    return 0;
}
