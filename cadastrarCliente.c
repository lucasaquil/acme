
#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"

void cadastrarCliente(){
    FILE * pFile;       // Declara um ponteiro para o arquivo chamado pFile.
    cliente *clnt; // Declara um ponteiro para a estrutura chamada clientes.

    clnt = (cliente *)calloc(1, sizeof(cliente));// Aloca memoria para a estrutura clientes.

    pFile = fopen("clientes.dat", "ab"); // Abre o arquivo "clientes.txt" em modo de apéndice(append).

    clnt[0].codigo = obterProximoCodigoCliente(); // Atribui o proximo código disponivel ao campo "codigo" da estrutura clientes.

    fflush(stdin); // Limpa o buffer de entrada padrão (stdin).

    printf("Insira o nome do cliente: ");
    fgets(clnt->nome, sizeof(clnt->nome), stdin);
    clnt->nome[strcspn(clnt->nome, "\n")] = '\0'; // Remove o '\n' final

    printf("Insira a empresa do cliente: ");
    fgets(clnt->empresa, sizeof(clnt->empresa), stdin);
    clnt->empresa[strcspn(clnt->empresa, "\n")] = '\0';

    printf("Insira o departamento: ");
    fgets(clnt->departamento, sizeof(clnt->departamento), stdin);
    clnt->departamento[strcspn(clnt->departamento, "\n")] = '\0';

    printf("Insira o telefone para contato: ");
    fgets(clnt->telefone, sizeof(clnt->telefone), stdin);
    clnt->telefone[strcspn(clnt->telefone, "\n")] = '\0';

    printf("Insira o celular para contato: ");
    fgets(clnt->celular, sizeof(clnt->celular), stdin);
    clnt->celular[strcspn(clnt->celular, "\n")] = '\0';

    printf("Insira o email para contato: ");
    fgets(clnt->email, sizeof(clnt->email), stdin);
    clnt->email[strcspn(clnt->email, "\n")] = '\0';

    fwrite(&clnt[0], sizeof(cliente), 1, pFile); // Escreve os dados da estrutura clientes no arquivo.

    fclose(pFile); // fecha o arquivo "cliente.txt".

    system("cls");

    printf("\nCliente %s cadastrado com sucesso!\n", clnt[0].nome);
}
