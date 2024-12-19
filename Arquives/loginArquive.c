#include <stdio.h>
#include <stdlib.h>

typedef struct login {
    int cpf;
    char name[50], email[50];
} login1;

void createArquive() {
    // Abre um arquivo para escrita
    FILE *file = fopen("login.txt", "w");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    // Escreve uma string no arquivo
    fputs("Registro de Logins.\n", file);
    // Fecha o arquivo
    fclose(file);
}

void createLogin(login1 user){
    FILE *file = fopen("login.txt", "a");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    printf("Digite o CPF:");
    scanf("%d", &user.cpf);
    printf("Digite o Nome:");
    scanf(" %49[^\n]", user.name);
    printf("Digite o Email:");
    scanf(" %49[^\n]", user.email);

    fprintf(file, "Nome: %s, Email: %s, CPF:%d\n", user.name, user.email, user.cpf);
    
    fclose(file);
}

int main(){
    createArquive();
    int option;

    while (1) {
        login1 user;
        createLogin(user);

        printf("Deseja adicionar outro login? (1 para sim, 0 para não): ");
        scanf("%d", &option);
        if (option == 0) {
            break;
        }
    }
    return 0;
}

