#include <stdio.h>
#include <stdlib.h>

void exemploFopen() {
    // Abre um arquivo para escrita
    FILE *file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    // Escreve uma string no arquivo
    fputs("This is a pen.", file);
    // Fecha o arquivo
    fclose(file);
}

void exemploFgetsFputs() {
    char buffer[100];
    // Abre um arquivo para leitura
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    // Lê e escreve o conteúdo do arquivo
    while (fgets(buffer, 100, file) != NULL) {
        fputs(buffer, stdout);
    }
    // Fecha o arquivo
    fclose(file);
}

void exemploFprintfFscanf() {
    FILE *file;
    int n;
    char name[100];

    // Abre um arquivo para escrita
    file = fopen("names.txt", "w");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    // Escreve nomes no arquivo
    for (n = 0; n < 3; n++) {
        printf("Por favor, insira um nome: ");
        scanf("%s", name);
        fprintf(file, "Nome %d [%s]\n", n + 1, name);
    }
    // Fecha o arquivo
    fclose(file);

    // Abre o arquivo para leitura
    file = fopen("names.txt", "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    // Lê e exibe os nomes do arquivo
    while (fscanf(file, "Nome %d %[^\n]\n", &n, name) != EOF) {
        printf("Nome %d %s\n", n, name);
    }
    // Fecha o arquivo
    fclose(file);
}

void exemploFwriteFread() {
    float vector[10];
    FILE *file;
    int i;

    // Abre um arquivo para escrita binária
    file = fopen("numbers.bin", "wb");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    // Escreve um vetor de floats no arquivo
    for (i = 0; i < 10; i++) {
        vector[i] = (float)i * 1.1;
    }
    fwrite(vector, sizeof(float), 10, file);
    // Fecha o arquivo
    fclose(file);

    // Abre o arquivo para leitura binária
    file = fopen("numbers.bin", "rb");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    // Lê e exibe os valores do vetor
    fread(vector, sizeof(float), 10, file);
    for (i = 0; i < 10; i++) {
        printf("%f ", vector[i]);
    }
    printf("\n");
    // Fecha o arquivo
    fclose(file);
}

void exemploFseek() {
    // Abre um arquivo para escrita
    FILE *file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    // Escreve uma string no arquivo
    fputs("This is a pen.", file);
    // Posiciona o ponteiro de escrita 9 bytes a partir do início
    fseek(file, 9, SEEK_SET);
    // Escreve uma nova string a partir da posição atual
    fputs(" apple.", file);
    // Fecha o arquivo
    fclose(file);
}

int main() {
    exemploFopen();
    exemploFgetsFputs();
    exemploFprintfFscanf();
    exemploFwriteFread();
    exemploFseek();
    return 0;
}