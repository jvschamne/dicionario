#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct NodeDic{
    char palavra[30];
    char significado[200];
    struct NodeDic *esq;
    struct NodeDic *dir;
}nodeDic;

int funcaoHash(char *palavra);

nodeDic *criarDicionario();

nodeDic *inserirPalavraNo(nodeDic *dicionario, char *palavra, char *significado);

nodeDic *inserirPalavra(nodeDic *dicionario, char *palavra, char *significado);

int buscaPalavraNo(nodeDic *dicionario, char *palavra);

int buscarPalavra(nodeDic *dicionario, char *palavra);

nodeDic *removerPalavraNo(nodeDic *dicionario, char *palavra);

nodeDic *removerPalavra(nodeDic *dicionario, char *palavra);

void listaPalavrasNo(nodeDic *dicionario);
void listarPalavras(nodeDic *dicionario, int index);
void freeDicionario(nodeDic *dic);

void menu(nodeDic *dicionario);

