#include <stdio.h>
#include <stdlib.h>

//fun��o pra ordenar o vetor, recebe o vetor e o tamanho dele
void bubbleSort(int *vetor, int tamanho) {

    //indice para o atual valor
    int atual = 0;

    //indice para o proximo valor
    int proximo = 0;

    //auxiliar de troca
    int auxiliar = 0;

    //para o atual em 1 e o atual sendo menor q o maximo
    for (atual = 1; atual < tamanho; atual++) {

        //o proximo em zero sendo menor que o tamanho maximo -1 para nao chegar no final
        for (proximo = 0; proximo < tamanho-1; proximo++) {

            //se o valor na posi��o do proximo for maoir que o proximo mais (pos seguinte)
            if (vetor[proximo] > vetor[proximo+1]) {

                //o auxiliar recebe o valor no proximo
                auxiliar = vetor[proximo];

                //o proximo recebe o da frente
                vetor[proximo] = vetor[proximo+1];

                //o da frente recebe o auxiliar que tava segurando o valor
                vetor[proximo+1] = auxiliar;

            }
        }
    }
}

//fun��o de busca binaria, recebe o vetor, o inicio do vetor por posi��o, o fim e a chave que busca
int PesquisaBinaria (int vetor[], int inicio, int fim, int chave){

    int i;

    //o i vai representar o meio do vetor em posi��o
    i = (inicio+fim)/2;

    //se o vetor na posi��o i (que � o meio), for oque busca ja retorna o resultado
    if(vetor[i] == chave){
        printf("\n\nValor encontrado na posicao [%d]\n\n", i);
    }

    //se o vetor na posi��o i for menor que a chave que busca
    if(vetor[i] < chave){
        //vai chamar recursivamente a fun��o enviando dessa vez o come�o sendo o meio mais 1,
        //pois o valor da chave � maior
        return PesquisaBinaria(vetor, i+1, fim, chave);
    }
    else{
        //se nao for menor que oque busca, logo � menor, entao vai chamar a
        //fun��o enviando o fim - 1, pois o valor da chave � menor
        return PesquisaBinaria(vetor, inicio, i-1, chave);
    }

}



int main()
{
    //cria o vetor e a chave (numero que deseja)
    int vetor[5];
    int chave = 0;

    //preencher o vetor
    for(int i = 0; i < 5; i++){
        printf("Insira valores: ");
        fflush(stdin);
        scanf("%d", &vetor[i]);
    }

    //pede a chave
    printf("\n\nInsira a chave: ");
    fflush(stdin);
    scanf("%d", &chave);

    //printa o antes
    printf("\n\nVetor inserido: ");

    for(int i = 0; i < 5; i++){
        printf("| %d ", vetor[i]);
    }

    // ordena
    bubbleSort(vetor, 5);

    //printa o depois
    printf("\n\nVetor ordenado: ");

    for(int i = 0; i < 5; i++){
        printf("| %d ", vetor[i]);
    }
    printf("\n\n");

    //chama a fun��o de busca binaria
    PesquisaBinaria(vetor, 0, 4, chave);


    return 0;
}
