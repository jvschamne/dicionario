#include "dicionario.h"

int main(){
    int index = 0;
    nodeDic *dicionario = criarDicionario();

    dicionario = inserirPalavra(dicionario, "tomate", "uma fruta normalmente confundida com um legume");
    dicionario = inserirPalavra(dicionario, "bota", "Um tipo de calcado");
    dicionario = inserirPalavra(dicionario, "coelho", "um animal pequeno");
    dicionario = inserirPalavra(dicionario, "abacate", "uma fruta verde");
    dicionario = inserirPalavra(dicionario, "anta", "uma animal mamifero");
    dicionario = inserirPalavra(dicionario, "macdonalds", "rede de fast food");
    dicionario = inserirPalavra(dicionario, "ortopedista", "medico de pe");
    dicionario = inserirPalavra(dicionario, "solo", " superficie solida da crosta terrestre onde pisamos");
    dicionario = inserirPalavra(dicionario, "soja", "um grao");
    dicionario = inserirPalavra(dicionario, "processador", "circuito integrado capaz de efetuar o processamento de dados");
    dicionario = inserirPalavra(dicionario, "pipoca", "grao de milho estourado com o calor");
    dicionario = inserirPalavra(dicionario, "pamonha", "iguaria preparada com milho verde triturado, temperado com acucar ou sal, depois cozido e enrolado na palha do proprio milho ou da folha de bananeira.");
    dicionario = inserirPalavra(dicionario, "anao", "Aquele que apresenta nanismo, tem pouca estatura ou tamanho muito abaixo do normal.");
    dicionario = inserirPalavra(dicionario, "macaco", "um primata");
    dicionario = inserirPalavra(dicionario, "meta", "objetivo que se almeja");
    dicionario = inserirPalavra(dicionario, "coentro", "erva usada como condimento");
    dicionario = inserirPalavra(dicionario, "zebra", "um animal nativo da africa central e do sul");
    dicionario = inserirPalavra(dicionario, "disco", "Qualquer objeto chato e circula");
    dicionario = inserirPalavra(dicionario, "queijo", "Lacticinio derivado do leite coalhado");
    dicionario = inserirPalavra(dicionario, "ocio", "folga, repouso");
    dicionario = inserirPalavra(dicionario, "sol", "estrela do nosso sistema solar");

    printf("\nListando todas as palavras do dicionario:\n");
    listarPalavras(dicionario, index);

    menu(dicionario);
    freeDicionario(dicionario);
}
