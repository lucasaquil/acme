#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "verificacao.h"
#include "cores.h"

void listarClientes()
{
    cliente clnt;
    char escolha;

    do {
        FILE *pFile = fopen("clientes.dat", "rb");
        if (pFile == NULL) {
            printf("Arquivo 'clientes.dat' não encontrado. Criando um novo...\n");
            pFile = fopen("clientes.dat", "wb");
            if (pFile == NULL) {
                perror("Erro ao criar o arquivo");
                return;
            }
            fclose(pFile);
            return; // Retorna ao menu ou finaliza a função após criar o arquivo vazio
        }

        printf("\n ========================================================================");
        printf("\n \tClientes \n");
        printf("\n%-6s %-20s %-20s %-15s %-15s %-15s %-30s\n",
               "Código", "Nome", "Empresa", "Departamento", "Telefone", "Celular", "Email");
        printf("==============================================================================\n");

        // Leitura e exibição dos clientes
        while (fread(&clnt, sizeof(cliente), 1, pFile) == 1) {
            printf("%-6d %-20s %-20s %-15s %-15s %-15s %-30s\n",
                   clnt.codigo, clnt.nome, clnt.empresa, clnt.departamento,
                   clnt.telefone, clnt.celular, clnt.email);
        }

        printf("\n ========================================================================\n");

        fclose(pFile);

        // Opção para continuar ou sair
        printf("\nDigite '0' para voltar ao menu principal ou qualquer outra tecla para listar novamente: ");
        scanf(" %c", &escolha);
    } while (escolha != '0');

    // Opcional: limpeza de tela
    system("cls");
}

