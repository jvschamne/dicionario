#include "dicionario.h"

int funcaoHash(char *palavra){
    int index;
    if(palavra[0] >= 97) index = palavra[0]-97;
    else index = palavra[0]-65;
    return index;
}
nodeDic *criarDicionario(){
    nodeDic *dicionario = (nodeDic*) malloc(26*sizeof(nodeDic));/*aloca espaco para o dicionario*/
    for(int i=0; i<26; i++){
        /*inidicaliza a palavra o significado com \0*/
        dicionario[i].palavra[0] = '\0';
        dicionario[i].significado[0] = '\0';
    }
    return dicionario;
}

nodeDic *inserirPalavraNo(nodeDic *dicionario, char *palavra, char *significado){
    if(dicionario->palavra[0] == '\0'){
        for(int i=0; i<strlen(palavra); i++){
            dicionario->palavra[i] = palavra[i];
        }
        for(int i=0; i<strlen(significado); i++){
            dicionario->significado[i] = significado[i];
        }
        return dicionario;
    }
    else{
        if(strcmp(dicionario->palavra, palavra) < 0){
            if(dicionario->dir == NULL) dicionario->dir = criarDicionario();
            dicionario->dir = inserirPalavraNo(dicionario->dir, palavra, significado);
        }
        else{
            if(dicionario->esq == NULL) dicionario->esq = criarDicionario();
            dicionario->esq = inserirPalavraNo(dicionario->esq, palavra, significado);
        }
    }
    return dicionario;
}

nodeDic *inserirPalavra(nodeDic *dicionario, char *palavra, char *significado){
    int index = funcaoHash(palavra);
    if(dicionario[index].palavra[0] == '\0'){
        for(int i=0; i<strlen(palavra); i++){
            dicionario[index].palavra[i] = palavra[i];
        }
        for(int i=0; i<strlen(significado); i++){
            dicionario[index].significado[i] = significado[i];
        }
        return dicionario;
    }
    else{
        if(strcmp(dicionario[index].palavra, palavra) < 0){
            if(dicionario[index].dir == NULL) dicionario[index].dir = criarDicionario();
            inserirPalavraNo(dicionario[index].dir, palavra, significado);
        }
        else{
            if(dicionario[index].esq == NULL) dicionario[index].esq = criarDicionario();
            inserirPalavraNo(dicionario[index].esq, palavra, significado);
        }
    }
    return dicionario;
}

int buscaPalavraNo(nodeDic *dicionario, char *palavra){
    int found = 0;
    if(dicionario != NULL){
        if(strcmp(dicionario->palavra, palavra) < 0) found = buscaPalavraNo(dicionario->dir, palavra);
        else if(strcmp(dicionario->palavra, palavra) > 0) found = buscaPalavraNo(dicionario->esq, palavra);
        else{
            printf("'%s': %s\n", dicionario->palavra, dicionario->significado);
            return 1;
        }
    }
    return found;
}

int buscarPalavra(nodeDic *dicionario, char *palavra){
    int index = funcaoHash(palavra);
    int found = 0;
    if(dicionario != NULL){
        if(strcmp(dicionario[index].palavra, palavra) == 0){
            printf("'%s': %s\n", dicionario[index].palavra, dicionario[index].significado);
            return 1;
        }
        else{
            if(strcmp(dicionario[index].palavra, palavra) < 0) found = buscaPalavraNo(dicionario[index].dir, palavra);
            else if(strcmp(dicionario[index].palavra, palavra) > 0) found = buscaPalavraNo(dicionario[index].esq, palavra);
        }
        if(found == 0)printf("Palavra '%s' nao encontrada\n", palavra);
    }
    return found;
}

nodeDic *removerPalavraNo(nodeDic *dicionario, char *palavra){
    if(dicionario == NULL){
            return NULL;
    }
    if(strcmp(dicionario->palavra, palavra) < 0)
        dicionario->dir = removerPalavraNo(dicionario->dir, palavra);

    else if(strcmp(dicionario->palavra, palavra) > 0)
            dicionario->esq = removerPalavraNo(dicionario->esq, palavra);

    else{
        if((dicionario->esq == NULL) && (dicionario->dir == NULL)) {
                free(dicionario);
                dicionario = NULL;
            }
        else if(dicionario->dir == NULL) {
                nodeDic *tmp = dicionario;
                dicionario = dicionario->esq;
                free(tmp);
            }
        else if (dicionario->esq == NULL){
                nodeDic *tmp = dicionario;
                dicionario = dicionario->dir;
                free(tmp);
            }
        else {
            nodeDic *tmp = dicionario->esq;
            while (tmp->dir != NULL) tmp = tmp->dir;
            for(int i=0; i<strlen(tmp->palavra); i++){
                dicionario->palavra[i] = tmp->palavra[i];
            }
            for(int i=0; i<strlen(palavra); i++){
                tmp->palavra[i] = palavra[i];
            }

            dicionario->esq = removerPalavraNo(dicionario->esq, palavra);
        }
    }
    return dicionario;

}

nodeDic *removerPalavra(nodeDic *dicionario, char *palavra){
    int index = funcaoHash(palavra);
    if(dicionario == NULL){
        return NULL;
    }
    else if(strcmp(dicionario[index].palavra, palavra) == 0){
        if((dicionario[index].esq == NULL) && (dicionario[index].dir == NULL)) {
            dicionario[index].palavra[0] = '\0';
            dicionario[index].significado[0] = '\0';
            for(int i=1; i<strlen(dicionario[index].palavra); i++){
                dicionario[index].palavra[i] = ' ';
            }
            return dicionario;
        }
        else if(dicionario[index].dir == NULL) {
            for(int i=0; i<strlen(dicionario[index].esq->palavra); i++){
                dicionario[index].palavra[i] = dicionario[index].esq->palavra[i];
            }
            free(dicionario[index].esq);
        }
        else if (dicionario[index].esq == NULL){
            for(int i=0; i<strlen(dicionario[index].dir->palavra); i++){
                dicionario[index].palavra[i] = dicionario[index].dir->palavra[i];
            }
            free(dicionario[index].dir);
        }
        else {
            nodeDic *tmp = dicionario[index].esq;
            while (tmp->dir != NULL) tmp = tmp->dir;

            for(int i=0; i<strlen(tmp->palavra); i++){
                    dicionario[index].palavra[i] = tmp->palavra[i];
            }
            for(int i=0; i<strlen(palavra); i++){
                tmp->palavra[i] = palavra[i];
            }
            dicionario[index].esq = removerPalavraNo(dicionario[index].esq, palavra);
        }
    }

    else if(strcmp(dicionario[index].palavra, palavra) < 0)
        dicionario[index].dir = removerPalavraNo(dicionario[index].dir, palavra);

    else if(strcmp(dicionario[index].palavra, palavra) > 0)
        dicionario[index].esq = removerPalavraNo(dicionario[index].esq, palavra);

    return dicionario;
}

void listaPalavrasNo(nodeDic *dicionario){
    if(dicionario != NULL){
        listaPalavrasNo(dicionario->esq);
        listaPalavrasNo(dicionario->dir);
        printf("%s\n", dicionario->palavra);
    }
}

void listarPalavras(nodeDic *dicionario, int index){
    if(index <= 25){
        if(dicionario[index].palavra[0] != '\0'){
            listaPalavrasNo(dicionario[index].esq);
            printf("%s\n", dicionario[index].palavra);
            listaPalavrasNo(dicionario[index].dir);
        }
        listarPalavras(dicionario, index+1);
    }
}

void freeDicionario(nodeDic *dic){
    if (dic != NULL) {
      freeDicionario(dic->esq);
      freeDicionario(dic->dir);
      free(dic);
   }
}

void menu(nodeDic *dicionario){
    int opcao = 0;
    do{
    printf("\n----Menu:---\n");
    printf("1)Inserir palavra no Dicionario\n");
    printf("2)Listar palavras presentes no Dicionario\n");
    printf("3)Buscar uma palavra no Dicionario\n");
    printf("4)Remover uma palavra do Dicionario\n");
    printf("5)Sair\n");
    printf("Sua opcao: ");
    scanf("%d", &opcao);

    if(opcao == 1){
        char palavra[30];
        char significado[200];
        printf("Digite a palavra a ser inserida:");
        scanf("%s", palavra);
        printf("Digite o significado:");
        scanf("%s", significado);
        inserirPalavra(dicionario, palavra, significado);
    }
    else if(opcao == 2){
        printf("\n");
       listarPalavras(dicionario, 0);
    }
    else if(opcao == 3){
        char palavra[30];
        printf("Digite a palavra a ser pesquisada:");
        scanf("%s", palavra);
        buscarPalavra(dicionario, palavra);
    }
    else if(opcao == 4){
        char palavra[30];
        printf("Digite a palavra a ser removida:");
        scanf("%s", palavra);
        removerPalavra(dicionario, palavra);
    }
    else if(opcao != 5) printf("\nOpcao indisponivel, tente outra vez!\n");

    }while(opcao != 5);
}

