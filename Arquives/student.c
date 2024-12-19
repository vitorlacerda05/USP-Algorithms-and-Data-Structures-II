#include <stdio.h>
#include <stdlib.h>
#define STUDENTFILENAME "studentFileName.txt"
#define SIZE 3

typedef struct student_t {
    char name[20];
    int age;
    int grade;
} Student;

Student readStudentDataFromInput() {
    Student student;
    printf("nome do estudante: ");
    scanf("%s", student.name);
    printf("idade: ");
    scanf("%d", &student.age);
    printf("nota: ");
    scanf("%d", &student.grade);
    printf("\n");
    return student;
}

void writeStudentDataInFile(Student student, FILE *filePointer) {
    fprintf(filePointer, "%s", student.name);
    fprintf(filePointer, "%d", student.age);
    fprintf(filePointer, "%d", student.grade);
}

void createStudentFile() { 
    FILE *filePointer = fopen(STUDENTFILENAME, "w");
    printf("Lendo dados do teclado\n\n");
    for (int i = 0; i < SIZE; ++i) {
        Student student = readStudentDataFromInput();
        writeStudentDataInFile(student, filePointer);
    }
    fclose(filePointer);
}

Student readStudentDataInFile(FILE *filePointer) {
    Student student;
    fscanf(filePointer, "%s", student.name);
    fscanf(filePointer, "%d", &student.age);
    fscanf(filePointer, "%d", &student.grade);
    return student;
}

void printStudentData(Student student) {
    printf("Nome: %s\n", student.name);
    printf("Idade: %d\n", student.age);
    printf("Nota: %d\n\n", student.grade);
}

void readStudentFile() {
    FILE *filePointer = fopen(STUDENTFILENAME, "r");
    printf("Dados no arquivo\n\n");
    for (int i = 0; i < SIZE; ++i) {
        Student student = readStudentDataInFile(filePointer);
        printStudentData(student);
    }
    fclose(filePointer);
}

/*

Funções writes são para ler o input do usuário e escrever no arquivo
Funções reads são para ler o arquivo e escrever no prompt

1) Caso de indicador fixo:

void writeStudentDataInFile(Student student, FILE *filePointer) {
    fwrite(&student, sizeof(Student), 1, filePointer);
}

Student readStudentDataInFile(FILE *filePointer) {
    Student student;
    fread(&student, sizeof(Student), 1, filePointer);
    return student;
}

2) caso de indicador de comprimento:

void writeStudentDataInFile(Student student, FILE *filePointer) {
    int fieldSize = strlen(student.name);
    fprintf(filePointer, "%d", fieldSize);
    fwrite(student.name, fieldSize, 1, filePointer);
    fieldSize = sizeof(student.age);
    fprintf(filePointer, "%d", fieldSize);
    fwrite(&student.age, fieldSize, 1, filePointer);
    fieldSize = sizeof(student.grade);
    fprintf(filePointer, "%d", fieldSize);
    fwrite(&student.grade, fieldSize, 1, filePointer);
}

Student readStudentDataInFile(FILE *filePointer) {
    Student student;
    int fieldSize;
    fscanf(filePointer, "%d", &fieldSize);
    fread(student.name, fieldSize, 1, filePointer);
    student.name[fieldSize] = '\0’;
    fscanf(filePointer, "%d", &fieldSize);
    fread(&student.age, fieldSize, 1, filePointer);
    fscanf(filePointer, "%d", &fieldSize);
    fread(&student.grade, fieldSize, 1, filePointer);
    return student;
}

3) caso de delimitadores:

static void readCurrentInput(FILE *filePointer, char *currentInput) {
    char currentChar = fgetc(filePointer); //le cada caractere
    int currentInputIndex = 0;
    while ((currentChar != EOF) && (currentChar != DELIMITERCHAR)) {
        currentInput[currentInputIndex++] = currentChar;
        currentChar = fgetc(filePointer);
    }
    currentInput[currentInputIndex] = '\0';
}

Student readStudentDataInFile(FILE *filePointer) {
    Student student;
    char currentInput[50];
    readCurrentInput(filePointer, currentInput);
    strcpy(student.name, currentInput);
    readCurrentInput(filePointer, currentInput);
    student.age = atoi(currentInput);
    readCurrentInput(filePointer, currentInput);
    student.grade = atoi(currentInput);
    return student;
}

void writeStudentDataInFile(Student student, FILE *filePointer) {
    fprintf(filePointer, "%s" , student.name);
    fputc(DELIMITERCHAR, filePointer);
    fprintf(filePointer, "%d" , student.age);
    fputc(DELIMITERCHAR, filePointer);
    fprintf(filePointer, "%d" , student.grade);
    fputc(DELIMITERCHAR, filePointer);
}

4) Caso de keyword (normalmente usa delimitadores/tamanho fixo antes)

#include "StudentFileHandler.h"
#include <string.h>
#include <stdlib.h>

#define DELIMITERCHAR '|'
#define TAGDELIMITERCHAR '='
#define NAMETAG "NAME"
#define AGETAG "AGE"
#define GRADETAG "GRADE"
#define TOTALFIELDS 3

void writeStudentDataInFile(Student student, FILE *filePointer) {
    fprintf(filePointer, "%s", NAMETAG);
    fputc(TAGDELIMITERCHAR, filePointer);
    fprintf(filePointer, "%s", student.name);

    fputc(DELIMITERCHAR, filePointer);
    fprintf(filePointer, "%s", AGETAG);
    fputc(TAGDELIMITERCHAR, filePointer);
    fprintf(filePointer, "%d", student.age);

    fputc(DELIMITERCHAR, filePointer);
    fprintf(filePointer, "%s", GRADETAG);
    fputc(TAGDELIMITERCHAR, filePointer);
    fprintf(filePointer, "%d", student.grade);
    fputc(DELIMITERCHAR, filePointer);
}

static void readCurrentInput(FILE *filePointer, char *currentInput, char
delimiter) {
    char currentChar = fgetc(filePointer);
    int currentInputIndex = 0;
    while((currentChar != EOF) && (currentChar != delimiter)) {
        currentInput[currentInputIndex++] = currentChar;
        currentChar = fgetc(filePointer);
}
    currentInput[currentInputIndex] = '\0’;
}

Student readStudentDataInFile(FILE *filePointer) {
    Student student;
    int nFields = 0;
    char currentInput[50], currentTag[50];
    do {
        readCurrentInput(filePointer, currentTag, TAGDELIMITERCHAR);
        readCurrentInput(filePointer, currentInput, DELIMITERCHAR);
        if(strcmp(currentTag, NAMETAG) == 0)
            strcpy(student.name, currentInput);
        else if(strcmp(currentTag, AGETAG) == 0)
            student.age = atoi(currentInput);
        else if(strcmp(currentTag, GRADETAG) == 0)
            student.grade = atoi(currentInput);
        nFields++;
    } while(nFields < TOTALFIELDS);
    return student;
}


*/

int main()
{
    createStudentFile();
    readStudentFile();
    return 0;
}
