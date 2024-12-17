#ifndef CLIENTES_H
#define CLIENTES_H
#include <stdbool.h>

typedef struct cliente {
    int codigo;
    char nome[80];
    char empresa[80];
    char departamento[50];
    char telefone[15];
    char celular[16];
    char email[60];
} cliente;

void cadastrarCliente();
void listarClientes();
void pesquisarCliente();
int obterProximoCodigoCliente();

#endif

