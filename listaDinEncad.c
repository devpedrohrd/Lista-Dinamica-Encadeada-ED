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
    // Aloca memória para a estrutura Lista (ponteiro para o primeiro elemento da lista)
    Lista *li = (Lista *)malloc(sizeof(Lista));

    // Verifica se a alocação de memória foi bem-sucedida
    if (li != NULL)
        *li = NULL; // Inicializa a lista como vazia (inicio da lista aponta para NULL)

    // Retorna o ponteiro para a lista (pode ser NULL se a alocação de memória falhou)
    return li;
}

// função que destroi a lista

void libera_lista(Lista *li)
{
    if (li != NULL)
    { // Verifica se a lista não é nula

        Elem *no; // Declara um ponteiro para o elemento da lista (nó)

        while ((*li) != NULL)
        { // Loop enquanto a lista não estiver vazia

            no = *li; // Atribui o ponteiro para o início da lista ao nó

            *li = (*li)->prox; // Move o início da lista para o próximo elemento

            free(no); // Libera a memória do nó antigo
        }

        free(li); // Libera a memória da cabeça da lista
    }
}

// funcão que retorno o tamanho da lista

int tamanho_lista(Lista *li)
{
    if (li == NULL) // se a lista nao existe return 0;
        return 0;
    int cont = 0; // inicia um contador

    Elem *no = *li; // cria um ponteiro (no) que recebe o inicio da lista

    while (no != NULL) // percorre a lista nó por nó até que o (no) for null
    {
        cont++; // contador é incrementado somando 1 a cada repetiçao

        no = no->prox; // ponteiro (no) aponta para o proximo
    }
    return cont; // retorna o contador quantas vezes foi repetido
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

    no->dados = num; // copia os dados que serao inseridos na lista para o elemento criado

    no->prox = (*li); // o elemento criado aponta para o inicio da lista

    *li = no; //  e o inicio da lista recebe o elemento criado
    return 1;
}

// função que insere no final
int insere_lista_final(Lista *li, struct numeros num)
{
    if (li == NULL)
        return 0; // Retorna 0 se a lista for nula (inexistente)

    Elem *no = (Elem *)malloc(sizeof(Elem)); // Aloca memória para um novo elemento da lista

    if (no == NULL)
    {
        return 0; // Retorna 0 se a alocação de memória falhar
    }

    no->dados = num; // Define os dados do novo elemento

    no->prox = NULL; // O próximo elemento após este é NULL

    if ((*li) == NULL) // Verifica se a lista está vazia
    {
        *li = no; // O início da lista recebe o novo elemento
    }
    else
    {
        Elem *aux = *li; // Cria uma variável auxiliar que começa no início da lista

        while (aux->prox != NULL) // Percorre até encontrar o último elemento da lista
        {
            aux = aux->prox; // Move o auxiliar para o próximo elemento
        }

        aux->prox = no; // Insere o novo elemento no final da lista
    }

    return 1; // Retorna 1 para indicar sucesso na inserção
}

// funçao que insere no meio de uma lista ordenada
int insere_lista_ordenada(Lista *li, struct numeros num)
{
    if (li == NULL)
        return 0; // Retorna 0 se a lista for nula

    // Aloca memória para um novo elemento da lista
    Elem *no = (Elem *)malloc(sizeof(Elem));

    // Define os dados do novo elemento como o número fornecido
    no->dados = num;
    no->prox = NULL; // Inicializa o próximo como NULL

    if (lista_vazia(li))
    { // Se a lista estiver vazia, insere no início
        *li = no;
        return 1; // Retorna 1 para indicar sucesso na inserção
    }
    else
    { // Caso contrário, procure onde inserir

        Elem *ant = NULL, *atual = *li; // Cria dois elementos que apontam para o início da lista

        while (atual != NULL && atual->dados.numero < num.numero)
        {
            ant = atual;         // O elemento anterior recebe o elemento atual
            atual = atual->prox; // O elemento atual avança para o próximo
        }

        if (ant == NULL)
        { // Insere no início da lista
            no->prox = *li;
            *li = no;
        }
        else
        { // Insere no meio ou final da lista
            no->prox = ant->prox;
            ant->prox = no;
        }

        return 1; // Retorna 1 para indicar sucesso na inserção
    }
}

// função que remove no inicio da lista

int remove_lista_inicio(Lista *li)
{
    if (li == NULL) // se a lista nao existe retorna 0;
        return 0;
    if ((*li) == NULL) // se o inicio da lista aponta para null retorna 0(é vazia);
        return 0;

    Elem *no = *li; // elemento criado aponta para o inicio da lista

    *li = no->prox; // atualiza o ponteiro de inicio da lista para o proximo elemento;

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
        return 0; // Retorna 0 se a lista for nula (inexistente)

    if ((*li) == NULL)
        return 0; // Retorna 0 se a lista estiver vazia

    Elem *ant, *no = *li; // Cria duas variáveis auxiliares que apontam para o início da lista

    while (no->prox != NULL)
    {
        ant = no;      // A variável "ant" recebe o nó atual
        no = no->prox; // A variável "no" avança para o próximo nó

        // este while se repete até encontrar o ultimo elemento
    }

    if (no == (*li))
    {                   // Se o nó a ser removido for o primeiro
        *li = no->prox; // Atualiza o ponteiro de início para o próximo elemento
    }
    else
    {
        ant->prox = no->prox; // Atualiza o ponteiro do nó anterior para onde o "no" aponta
    }

    free(no); // Libera a memória do último nó

    return 1; // Retorna 1 para indicar sucesso na remoção
}
// função que busca na lista um valor para excluir;

int remove_lista(Lista *li, int num)
{
    if (li == NULL)
        return 0; // Retorna 0 se a lista for nula (inexistente)

    Elem *ant, *no = *li; // Cria duas variáveis auxiliares que apontam para o início da lista

    while (no != NULL && no->dados.numero != num)
    {
        ant = no;      // A variável "ant" recebe o nó atual
        no = no->prox; // A variável "no" avança para o próximo nó

        // Este while se repete até encontrar o elemento a ser removido ou chegar ao final da lista
    }

    if (no == NULL)
        return 0; // Retorna 0 se o elemento não foi encontrado na lista

    if (no == *li)
    {                   // Se o nó a ser removido for o primeiro
        *li = no->prox; // Atualiza o ponteiro de início para o próximo elemento
    }
    else
    {
        ant->prox = no->prox; // Atualiza o ponteiro do nó anterior para onde o "no" aponta
    }
    free(no); // Libera a memória do nó removido

    return 1; // Retorna 1 para indicar sucesso na rem
}
// funçao que busca elemento pela posição
int consulta_lista_pos(Lista *li, int pos, struct numeros *num)
{
    // Verifica se a lista é nula ou a posição é inválida
    if (li == NULL || pos <= 0)
        return 0; // Retorna 0 para indicar falha

    // Inicializa um ponteiro que aponta para o inicio da lista
    Elem *no = *li;

    // Inicializa um contador para rastrear a posição atual na lista
    int cont = 1;

    // Percorre a lista até a posição desejada ou o final da lista
    while (no != NULL && cont < pos)
    {
        cont++;
        no = no->prox;
    }

    // Se chegamos ao final da lista sem encontrar a posição desejada, retorna 0
    if (no == NULL)
        return 0;
    else
    {
        // Se encontramos a posição desejada, copia os dados para a estrutura 'num'
        *num = no->dados;

        // Retorna 1 para indicar sucesso na consulta
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