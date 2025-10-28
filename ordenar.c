#include "ordenar.h"

// Função para criar um vetor dinâmico de tamanho TAM
int *criarVetor(){
    int *vetor = malloc(TAM * sizeof(int));
    return vetor;  
}
// Função para exibir os elementos do vetor
void exibir(int *vetor){
	for(int i=0; i < TAM; i++) {
		printf(" %d |", *vetor);
		vetor++;
	}
    printf("\n");
}
// Função para exibir os tempos de execução
void exibirTempo(double tempo1, double tempo2, double tempo3, double tempo4, double tempo5){
    printf("\n\t> Tempos de execucao\n");
    printf("Tempo de ordernar uma array aleatorio: %f sec\n", tempo1);
    printf("Tempo de ordernar uma array ordenado: %f sec\n", tempo2);
    printf("Tempo de ordernar uma array decrescente: %f sec\n", tempo3);
    printf("Tempo de ordernar uma primeira metade cresc. e segunda metade decre.: %f sec\n", tempo4);
    printf("Tempo de ordernar uma primeira metade decre. e segunda metade cresc.: %f sec\n", tempo5);
}
// Função para ordenar o vetor usando o algoritmo de Selection Sort
int *selectionSort(int *vetor){
    int i, j, indiceMenor, temp;
    // Percorre todo o vetor
    for (i = 0; i < TAM - 1; i++) {
        indiceMenor = i;
        // Encontra o menor elemento no vetor não ordenado
        for (j = i + 1; j < TAM; j++) {
            if (vetor[j] < vetor[indiceMenor]) {
                indiceMenor = j;
            }
        }
        // Troca o menor elemento encontrado com o primeiro elemento do vetor não ordenado
        if (indiceMenor != i) {
            temp = vetor[i];
            vetor[i] = vetor[indiceMenor];
            vetor[indiceMenor] = temp;
        }
    }
    return vetor;
}
// Função para preencher o vetor com números aleatórios
void preencher(int *vetor){
	for(int i = 0; i < TAM; i++)
        vetor[i] = rand()% (TAM+1);
}
// Função para inverter a ordem dos elementos do vetor
int *inverterVetor(int *vetor){
    int *vetorDecrescente = criarVetor(), j = 0;
    for(int i = TAM-1; i >= 0; i--){
        vetorDecrescente[j] = vetor[i];
        j++;
    }
    return vetorDecrescente;
}

// Função para criar um vetor com a primeira metade em ordem crescente e a segunda metade em ordem decrescente
int *criarVetorEsp1(int *vetorCresc, int *vetorDecre){
    int *novoVetor = criarVetor();
    int c = 0;
    for(int i = 0; i < TAM/2; i++){
        novoVetor[i] = vetorCresc[i];
    }
    
    for(int i = TAM/2; i < TAM; i++){
        novoVetor[i] = vetorDecre[c];
        c++;
    }

    return novoVetor;
}
// Função para criar um vetor com a primeira metade em ordem decrescente e a segunda metade em ordem crescente
int *criarVetorEsp2(int *vetorCresc, int *vetorDecre){
    int *novoVetor = criarVetor();
    int c = TAM/2 - 1;
    for(int i = 0; i < TAM/2; i++){
        novoVetor[i] = vetorCresc[c];
        c--;
    }
    c = TAM/2;
    for(int i = TAM/2; i < TAM; i++){
        novoVetor[i] = vetorDecre[c];
        c--;
        
    }
    return novoVetor;
}