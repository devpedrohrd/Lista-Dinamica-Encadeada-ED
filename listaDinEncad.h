/*Definir:
    -Prototipos das funções
    -O tipos de dados armazenados na lista
    -o ponteiro "lista"*/

struct numeros
{
    int numero;
};

typedef struct elemento *Lista; // Ponteiro "*Lista"

// função que cria uma lista dinâmica simples
Lista *cria_lista();
// funcão que destroi a lista
void libera_lista(Lista *li);
// funçao que retorna o tamanho do lista
int tamanho_lista(Lista *li);
// funçao que retorna se a lista está vazia
int lista_vazia(Lista *li);
// funçao que insere no inicio da lista
int insere_lista_inicio(Lista *li, struct numeros num);
// função que insere no final
int insere_lista_final(Lista *li, struct numeros num);
// funçao que insere no meio de uma lista ordenada
int insere_lista_ordenada(Lista *li, struct numeros num);
// função que remove um elemento no inicio da lista
int remove_lista_inicio(Lista *li);
// função que remove no final
int remove_lista_final(Lista *li);
// função que busca na lista um valor para excluir;
int remove_lista(Lista *li, int num);
// funçao que busca elemento pela posição
int consulta_lista_pos(Lista *li, int pos, struct numeros *num);
// função que busca um elemento pelo valor
int consulta_lista_num(Lista *li, int n, struct numeros *num);
// função que imprime a lista
void imprime_lista(Lista *li);
