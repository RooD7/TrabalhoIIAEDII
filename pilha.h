/* Cabeçalhos das funções implementadas no módulo pilha.c */

typedef struct node stackNode;

typedef struct topo* stackNodePtr;

/* Cria uma pilha vazia */
stackNodePtr Pcria();

/* examina se a pilha esta vazia */
int Pvazia(stackNodePtr pilha);

/* destroi a pilha */
void Pdestroi(stackNodePtr pilha);

/* examina se a pilha esta cheia */
int Pcheia(stackNodePtr pilha);

/* retorna a quantidade de elementos na pilha */
int Ptamanho(stackNodePtr pilha);

/* retorna o elemento no topo da pilha */
int Pexamina(stackNodePtr pilha);

/* insere o elemento no topo da pilha */
void Pinsere(stackNodePtr pilha, int valor);

/* remove e retorna o elemento no topo da pilha */
int Premove(stackNodePtr pilha);