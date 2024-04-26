#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outFile("arquivo.txt");
    if (!outFile) {
        std::cerr << "Erro ao abrir o arquivo de saída." << std::endl;
        return 1;
    }
    outFile << "Fatec Araras" << std::endl;
    outFile << "Esta é uma linha de exemplo." << std::endl;
    outFile.close();

    std::ifstream inFile("arquivo.txt");
    if (!inFile) {
        std::cerr << "Erro ao abrir o arquivo de entrada." << std::endl;
        return 1;
    }

    std::string line;
    std::cout << "Conteúdo do arquivo:" << std::endl;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }
    inFile.close();

    return 0;
}
