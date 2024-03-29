/*
Terceiro programa em C++
Cadastro de aluno

Prof. Me. Orlando Saraiva Jr
*/
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string recebe_nome_aluno();
string recebe_disciplina_aluno();
float recebe_nota_1();
float recebe_nota_2();

int main(int argc, char *argv[]){
    struct cadastro {
        string nome;
        string disciplina;
        float nota_1;
        float nota_2;
    };

    struct cadastro cadastro01;

    struct cadastro cadastro02;
    
    cadastro01.nome = recebe_nome_aluno();
    cadastro01.disciplina = recebe_disciplina_aluno();
    cadastro01.nota_1 = recebe_nota_1();
    cadastro01.nota_2 = recebe_nota_2();

    cout << "Nome = " << cadastro01.nome << endl;
    cout << "Disciplina = " << cadastro01.disciplina << endl;
    cout << "Nota 1 = " << cadastro01.nota_1 << endl;
    cout << "Nota 2 = " << cadastro01.nota_2 << endl;
    cout << "Média Simples = " << (cadastro01.nota_1 + cadastro01.nota_2) / 2 << endl;
    return 0;
}

string recebe_nome_aluno() {
    string nome_recebido;
    cout << "Digite o nome do aluno: ";
    cin >> nome_recebido;
    return nome_recebido;
}

string recebe_disciplina_aluno() {
    string disciplina;
    cout << "Digite a disciplina cursada: ";
    cin >> disciplina;
    return disciplina;
}

float recebe_nota_1() {
    string nota;
    float nota_1;
    cout << "Digite a nota do aluno: ";
    cin >> nota_1;
    return nota_1;
}

float recebe_nota_2() {
    string nota;
    float nota_2;
    cout << "Digite a nota do aluno: ";
    cin >> nota_2;
    return nota_2;
}
