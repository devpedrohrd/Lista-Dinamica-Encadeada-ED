
#include <stdio.h>
#include <stdlib.h>
#include "listaDinEncad.h"

int main(int argc, char **argv)
{

    Lista *li; // (*li) é um ponteiro para struct elemento
    struct numeros num;
    int pos, n;

    int continuar = 1;

    do
    {
        printf("\n\tMenu de Opcao\n\n");
        printf("1. Cria Lista \n");
        printf("2. Libera lista\n");
        printf("3. Retornando o tamanho da lista\n");
        printf("4. inserindo um elemendo no inicio\n");
        printf("5. inserindo um elemendo no final\n");
        printf("6. inserindo um elemendo no meio\n");
        printf("7. removendo um elemento no inicio\n");
        printf("8. removendo um elemento no final\n");
        printf("9. buscando o elemento por posicao\n");
        printf("10. buscando o elemento por valor informado\n");
        printf("11. imprime lista\n");
        printf("0. Sair\n");

        scanf("%d", &continuar);
        system("cls || clear");

        switch (continuar)
        {
        case 1:
            li = cria_lista();
            printf("Lista criada com sucesso!");
            break;

        case 2:
            libera_lista(li);
            break;

        case 3:
            if (lista_vazia(li))
                printf("Lista vazia!\n");
            else
            {
                int tam;
                tam = tamanho_lista(li);
                printf("O tamanho a lista e:%d ", tam);
            }
            break;

        case 4:
            printf("Digite um numero a ser inserido na lista:\n");
            scanf("%d", &num.numero);

            if (insere_lista_inicio(li, num))
                printf("Elemento inserido com sucesso!");
            else
                printf("A lista não existe e precisa ser criada!");
            break;

        case 5:
            printf("Digite um numero a ser inserido na lista:\n");
            scanf("%d", &num.numero);

            if (insere_lista_final(li, num))
                printf("Elemento inserido com sucesso!");
            else
                printf("A lista não existe e precisa ser criada!");
            break;

        case 6:
            printf("Digite um numero a ser inserido na lista:\n");
            scanf("%d", &num.numero);

            if (insere_lista_ordenada(li, num))
                printf("Elemento inserido com sucesso!");
            else
                printf("A lista não existe e precisa ser criada!");
            break;

        case 0:

        case 7:
        // case 8:
            if (remove_lista_inicio(li))
                printf("Elemento excluido com sucesso!\n");
            else
            {
                printf("Lista vazia!\n");
            }
            break;

        case 8:
            if (remove_lista_final(li))
                printf("Elemento excluido com sucesso!\n");
            else
            {
                printf("Lista vazia!\n");
            }
            break;

        case 9:
            printf("Digite uma posição para buscar um elemento:\n");
            scanf("%d", &pos);
            if (consulta_lista_pos(li, pos, &num))
                printf("O numero %d foi localizado na posicao %d!", num, pos);
            else
                printf("O numero nao foi localizado na lista!");
            break;

        case 10:
            printf("Digite uma numero para buscar na lista:\n");
            scanf("%d", &n);
            if (consulta_lista_num(li, n, &num))
                printf("O numero %d foi localizado!", num);
            else
                printf("O numero nao foi localizado na lista!");
            break;

        case 11:
            imprime_lista(li);

            break;

        default:
            printf("Digite uma opção valida\n");
        }
    } while (continuar);
}
