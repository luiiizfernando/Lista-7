#include <stdio.h>
#include <stdlib.h>
#include "com112_arvoreAVL.h"

int menu();

int main()
{
    ArvAVL* avl;
    int opcao = 0, tamanho, valor, x, cont = 0;
    while (opcao != 11)
    {
        opcao = menu();
        if(opcao == 1)
        {
            if(cont == 0)
            {
                avl = cria_ArvAVL();
                cont++;
                printf("arvore criada.\n\n");
            }
            printf("arvore já criada.\n\n");
        }
        if(opcao == 2)
        {
            avl = cria_ArvAVL();
            libera_ArvAVL(avl);
            printf("Arvore liberada\n");
            return 0;
        }
        if(opcao == 3)
        {
            if(cont == 0)
            {
                avl = cria_ArvAVL();
                cont++;
            }
            printf("Digite número de elementos que quer adicionar na arvore: ");
            scanf("%d", &tamanho);
            for (int i = 0; i < tamanho; i++)
            {
                printf("Digite o elemento a ser adicionado: ");
                scanf("%d", &valor);
                insere_ArvAVL(avl, valor);
            }
        }
        if(opcao == 4)
        {
            printf("Digite o valor que se quer remover: ");
            scanf("%d", &valor);
            x = remove_ArvAVL(avl, valor);
            if(x == 1)
            {
                printf("Removido com sucesso.\n\n");
            }
            else
            {
                printf("Falha ao remover elemento.\n\n");
            }
        }
        if(opcao == 5)
        {
            printf("Digite o valor que se quer consultar: ");
            scanf("%d", &valor);
            x = consulta_ArvAVL(avl, valor);
            if(x == 1)
            {
                printf("Valor encontrado.\n\n");
            }
            else
            {
                printf("Valor não encontrado.\n\n");
            }
        }
        if(opcao == 6)
        {
            printf("Arvore pré-ordem:\n");
            preOrdem_ArvAVL(avl);
            printf("\n");
        }
        if(opcao == 7)
        {
            printf("Arvore em Ordem:\n");
            emOrdem_ArvAVL(avl);
            printf("\n");
        }
        if(opcao == 8)
        {
            printf("Arvore pos-ordem:\n");
            posOrdem_ArvAVL(avl);
            printf("\n");
        }
        if(opcao == 9)
        {
            x = altura_ArvAVL(avl);
            printf("Altura arvore: ");
            printf("%d\n\n", x);
        }
        if(opcao == 10)
        {
            x = totalNO_ArvAVL(avl);
            printf("Total de Elementos: ");
            printf("%d\n\n", x);
        }
    }

    return 0;
}

int menu()
{
    int opcao;
    printf("1. Criar árvore\n");
    printf("2. Liberar árvore\n");
    printf("3. Inserir Elemento\n");
    printf("4. Remover Elemento\n");
    printf("5. Consultar Elemento\n");
    printf("6. Imprimir percurso pré-ordem\n");
    printf("7. Imprimir percurso em ordem\n");
    printf("8. Imprimeir percurso pós-ordem\n");
    printf("9. Altura da árvore\n");
    printf("10. Total de Elementos\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    return opcao;
}