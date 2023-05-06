#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//lucas Deodato

struct no {// Estrutura de um nó da árvore
    struct no* filhos[26];
    int fim;
};

struct no* criano() {// Cria um novo nó da árvore
    struct no* n = (struct no*) malloc(sizeof(struct no));
    n->fim = 0;
    int i;
    for (i = 0; i < 26; i++) {
        n->filhos[i] = NULL;
    }
    return n;
}


void inserir(struct no* raiz, char chave[]) {// Insere uma chave na árvore TRIE
    int i, tam = strlen(chave);
    struct no* atual = raiz;
    for (i = 0; i < tam; i++) {
        int indice = chave[i] - 'a';
        if (atual->filhos[indice] == NULL) {
            atual->filhos[indice] = criano();
        }
        atual = atual->filhos[indice];
    }
    atual->fim = 1;
}


int buscar(struct no* raiz, char chave[]) {// Verifica se uma chave está presente na árvore 
    int i, tam = strlen(chave);
    struct no* atual = raiz;
    for (i = 0; i < tam; i++) {
        int indice = chave[i] - 'a';
        if (atual->filhos[indice] == NULL) {
            return 0;
        }
        atual = atual->filhos[indice];
    }
    return (atual != NULL && atual->fim);
}

int main() {
    char chaves[][20] = {"arvore", "arvoredo", "algoritmo", "aeds", "computacao", "computar", "competir", "como", "comer", "descoberta", "descobrir", "descobre", "descendente"};
    int i, quant = sizeof(chaves)/sizeof(chaves[0]);

    struct no* raiz = criano();

    
    for (i = 0; i < quant; i++) {// Insere as chaves na árvore 
        inserir(raiz, chaves[i]);
    }

    
    for (i = 0; i < quant; i++) {// Verifica se as chaves estão presentes na árvore
        if (buscar(raiz, chaves[i])) {
            printf("%s esta presente na arvore TRIE\n", chaves[i]);
        } else {
            printf("%s nao esta presente na arvore TRIE\n", chaves[i]);
        }
    }

    return 0;
}
