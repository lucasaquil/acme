#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "clientes.h"
#include "cores.h"
#define MAX_LEN 128

void pesquisarCliente()
{

    do
    {
        cliente clnt;
        FILE *pFile;
        pFile = fopen("clientes.txt", "r");

        int escolha, codigo = 0;
        char nome[MAX_LEN] = {' '};

        int read = 0;

        escolha = verificacao('2', "\nDeseja pesquisar o cliente pelo nome ou codigo? (1 - Nome, 2 - Codigo, 0 - Sair): ",  RED "\nInsira um opção válida. Tente novamente." RESET);

        if (escolha == '1')
        {
            printf("\nInsira o nome do cliente: ");
            fflush(stdin);
            scanf("%[^\n]s", nome);
        }
        else if(escolha == '2')
            codigo = verificacaoCodigo("\nInsira o código do cliente: ", RED "\nInsira um código válido. Tente novamente." RESET);

        printf("\n=========================================================");
        printf("\nCliente\n");
        printf(GREEN "\nCódigo " RESET RED "\t Nome " RESET "\t\t");

        int clienteEncontrado = 0;

        while (fread(&clnt, sizeof(cliente), 1, pFile) == 1)
        {
            if (escolha == '1' || escolha == '2')
            {
                if (strcasecmp(nome, clnt.nome) == 0 || clnt.codigo == codigo)
                {
                    clienteEncontrado = 1;
                    printf("\n%-9i%-20s", clnt.codigo, clnt.nome);
                    break;
                }
            }
        }

        if(escolha == '0') break;

        int escolhaPedido;
        int escolhaFuncao;

        do
        {
            if (clienteEncontrado)
            {
                printf("\n\nDados do cliente %s:\n[", clnt.nome);
                printf("\n\nEmpresa do cliente %s:\n[", clnt.empresa);
                printf("\n\nDepartamento do cliente %s:\n[", clnt.departamento);
                printf("\n\nTelefone do cliente %s:\n[", clnt.telefone);
                printf("\n\nCelular do cliente %s:\n[", clnt.celular);
                printf("\n\nemail do cliente %s:\n[", clnt.email);



                printf("]\n");
            }
            else
            {
                printf(RED "CLIENTE NÃO ECONTRADO!!!" RESET);
                system("cls");
            }
        }
        while(escolhaPedido != '0');

        fclose(pFile);
    }
    while (1);

    system("cls");
}

