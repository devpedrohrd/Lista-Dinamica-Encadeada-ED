/*Definir:
    -o tipo de dados "lista"
    -implementar suas funcoes*/

#include <stdio.h>
#include <stdlib.h>
#include "listaDinEncad.h"

struct elemento
{
    struct numeros dados;  // Campo dados
    struct elemento *prox; // Campo prox
};
typedef struct elemento Elem;

// função que cria uma lista Dinamica Encadeada Simples

Lista *cria_lista()
{
    Lista *li = (Lista *)malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL; // Lista aponta para null
    return li;
}

// função que destroi a lista

void libera_lista(Lista *li)
{
    if (li != NULL)
    { // Lista for diferente de null;

        Elem *no; // define o ponteiro elemento =>(no)

        while ((*li) != NULL) //  ==>> opera até a lista estiver vazia

        { // enquanto o inicio da lista for diferente de nulo

            no = *li; // no recebe o inicio da lista

            *li = (*li)->prox; // o inicio da lista aponta para o proximo elemento

            free(no); // libero no antigo
        }
        free(li); // libero a cabeça da lista
    }
}

// funcão que retorno o tamanho da lista

int tamanho_lista(Lista *li)
{
    if (li == NULL) // se a lista nao existe return 0;
        return 0;
    int cont = 0; // inicia um contador

    Elem *no = *li; // ponteiro (no) recebe o primeiro elemento da lista

    while (no != NULL) // percorre a lista nó por nó até que o (no) for null
    {
        cont++; // contador é incrementado somando 1 a cada repetiçao

        no = no->prox; // ponteiro (no) aponta para o proximo
    }
    return cont; // retorna o contador quantas vezes
}

// funçao que diz se a lista está vazia

int lista_vazia(Lista *li)
{
    if (li == NULL) // se a lista for nula => ela esta vazia
        return 1;
    if (*li == NULL)
        return 1; // se o inicio da lista aponta para null ==> não há nenhum elemento na lista
    return 0;
}
// função que insere no inicio da lista:

int insere_lista_inicio(Lista *li, struct numeros num)
{
    if (li == NULL) // se a lista não existe retorna zero!!
        return 0;
    Elem *no = (Elem *)malloc(sizeof(Elem)); // criar um novo elemento na lista

    no->dados = num; // copia os dados que serao inseridos na lista

    no->prox = (*li); // aponta para o proximo elemento da lista

    *li = no; // o elemento que foi adicionado é o inicio da lista
    return 1;
}

// função que insere no final

int insere_lista_final(Lista *li, struct numeros num)
{
    if (li == NULL)
        return 0;
    Elem *no = (Elem *)malloc(sizeof(Elem)); // cria um novo elemento na lista
    no->dados = num;
    no->prox = NULL;
    if ((*li) == NULL) // se o inicio da lista apontar para null(lista vazia);
    {
        *li = no; // o inicio recebe o elemento que foi criado
    }
    else
    {
        // percorrer até achar o ultimo elemento da lista

        Elem *aux = *li; // cria uma variavel auxiliar que recebe o inicio da lista;

        while (aux->prox != NULL) // até o aux->prox apontar para null(sempre percorre a lista com o auxiliar)
        {
            aux = aux->prox; // o auxiliar vai receber o (no) seguinte a ele
        }
        aux->prox = no; // insere o elemento que foi criado
    }
    return 1;
}
// funçao que insere no meio de uma lista ordenada

int insere_lista_ordenada(Lista *li, struct numeros num)
{
    if (li == NULL)
        return 0;
    Elem *no = (Elem *)malloc(sizeof(Elem)); // cria um novo elemento da lista
    no->dados = num;
    if (lista_vazia(li))
    { // insere no incio
        no->prox = (*li);
        *li = no;
        return 1;
    }
    else
    { // procurar onde inserir

        Elem *ant, *atual = *li; // cria dois elementos que apontam para o inicio da lista

        while (atual != NULL && atual->dados.numero < num.numero) // enquanto o elemento atual for diferente de null e o elemento da lista for menor que o numero que estiver inserindo
        {
            ant = atual;         // o anterior recebe o atual
            atual = atual->prox; // atual aponta para o proximo elemento
        }
        if (atual == *li)
        { // insere inicio
            no->prox = (*li);
            *li = no;
        }
        else
        {
            no->prox = ant->prox;
            ant->prox = no;
        }
        return 1;
    }
}

// função que remove no inicio da lista

int remove_lista_inicio(Lista *li)
{
    if (li == NULL) // se a lista nao existe retorna 0;
        return 0;
    if ((*li) == NULL) // se o inicio da lista aponta para null retorna 0(é vazia);
        return 0;

    Elem *no = *li; // elemento criado se torna o inicio da lista

    *li = no->prox; // inicio da lista recebe o proximo elemento depois do (no);

    free(no); // e o elemento que foi criado e era o inicio da lista é excluido;
    return 1;
}

// funcao que imprime os elementos da lista

void imprime_lista(Lista *li)
{
    if (li == NULL || (*li) == NULL)
        printf("\nLista vazia!");

    else
    {
        Elem *ant, *atual = *li;

        while (atual != NULL)
        {
            printf("%d ", atual->dados.numero);
            ant = atual;
            atual = atual->prox;
        }
    }
}

// funcão que remove no final

int remove_lista_final(Lista *li)
{
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;

    Elem *ant, *no = *li; // cria duas variaveis auxiliares que apontam para o inicio da lista
    /* enquanto o ponteiro anterior for diferente de null */
    while (no->prox != NULL) // percorrer a lista até o final
    {
        ant = no;      // anterior recebe o no
        no = no->prox; // e o no recebe o posterior a ele
    }
    if (no == (*li))
    {                   // no é igual ao inicio?
        *li = no->prox; // o ponteiro inicio recebe o proximo elemento
    }
    else
    {
        ant->prox = no->prox; // o anterior aponta pra onde o (no) aponta
    }
    free(no); // libera o no
    return 1;
}

// função que busca na lista um valor para excluir;

int remove_lista(Lista *li, int num)
{
    if (li == NULL)
        return 0;
    Elem *ant, *no = *li;                         // criar dois auxiliares que apontam para o inicio da lista
    while (no != NULL && no->dados.numero != num) // enquanto o no for diferente de nulo e numero armazenado for diferente de do numero pesquisado
    {
        ant = no;      // o ponteiro anterior recebe o no
        no = no->prox; // e o ponteiro no recebe o proximo elemento

        // esse while se repete até que uma das da condições forem falsas
    }
    if (no == NULL)
        return 0; // não encontrado

    if (no == *li) // remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

// funçao que busca elemento pela posição
int consulta_lista_pos(Lista *li, int pos, struct numeros *num)
{
    if (li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while (no != NULL && i < pos)
    {
        no = no->prox;
        i++;
    }
    if (no == NULL)
        return 0;
    else
    {
        *num = no->dados;
        return 1;
    }
}

// função que busca um elemento pelo valor

int consulta_lista_num(Lista *li, int n, struct numeros *num)
{
    if (li == NULL)
        return 0;
    Elem *no = *li;
    while (no != NULL && no->dados.numero != n)
    {
        no = no->prox;
    }
    if (no == NULL)
        return 0;
    else
    {
        *num = no->dados;
        return 1;
    }
}