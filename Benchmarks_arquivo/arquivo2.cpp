#include <stdio.h>

int main() {
    FILE *outFile;
    outFile = fopen("arquivo2.txt", "w");
    if (outFile == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    fprintf(outFile, "Fatec Araras\n");
    fprintf(outFile, "Esta é uma linha de exemplo.\n");
    fclose(outFile);

    FILE *inFile;
    inFile = fopen("arquivo2.txt", "r");
    if (inFile == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    char line[100];
    printf("Conteúdo do arquivo:\n");
    while (fgets(line, sizeof(line), inFile) != NULL) {
        printf("%s", line);
    }
    fclose(inFile);
    return 0;
}
