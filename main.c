// Inclui o arquivo de cabeçalho correspondente
#include "ordenar.h"
// Inclui a biblioteca time.h para medir o tempo de execução
#include <time.h>

int main(void) {
	srand(time(NULL));												// Inicializa o gerador de números aleatórios

	int *vetor, *vetorDecr, *vetorEspecial1, *vetorEspecial2;
	clock_t inicio, fim;											// Variáveis para medir o tempo de execução
	double tempo1, tempo2, tempo3, tempo4, tempo5;
    
    vetor = criarVetor();											// Cria o vetor dinâmico
    preencher(vetor);												// Preenche o vetor com números aleatórios
	
	printf("\t> Ordernar array aleatorio\n");
	exibir(vetor);													// Exibe o vetor antes da ordenação
	inicio = clock();												// Pega o horário inicial
	selectionSort(vetor);											// Chama a função de ordenação
	fim = clock();													// Pega o horário final
	tempo1 = (double)(fim - inicio)/ CLOCKS_PER_SEC;				// Calcula o tempo de execução

	printf("\t> Ordernar array ordenado\n");
	exibir(vetor);													// Exibe o vetor ordenado					
	inicio = clock();												// Pega o horário inicial
	selectionSort(vetor);											// Chama a função de ordenação
	fim = clock();													// Pega o horário final
	tempo2 = (double)(fim - inicio)/ CLOCKS_PER_SEC;				// Calcula o tempo de execução

	vetorDecr = inverterVetor(vetor);								// Chama a função para inverter o vetor
	
	printf("\t> Ordernar array decrescente\n");
	exibir(vetorDecr);												// Exibe o vetor decrescente
	inicio = clock();												// Pega o horário inicial
	selectionSort(vetorDecr);										// Ordena o vetor decrescente			
	fim = clock();													// Pega o horário final
	tempo3 = (double)(fim - inicio)/ CLOCKS_PER_SEC;				// Calcula o tempo de execução
	
	vetorDecr = inverterVetor(vetor);								// Inverte o vetor para criar os vetores especiais
	vetorEspecial1 = criarVetorEsp1(vetor, vetorDecr);				// Cria vetor crescente até a metade e decrescente na outra metade
	
	printf("\t> Ordernar array primeira metade cresc. e segunda metade decre.:\n");
	exibir(vetorEspecial1);											// Exibe o vetor especial 1
	inicio = clock();												// Pega o horário inicial
	selectionSort(vetorEspecial1);									// Ordena o vetor especial 1
	fim = clock();													// Pega o horário final	
	tempo4 = (double)(fim - inicio)/ CLOCKS_PER_SEC;				// Calcula o tempo de execução

	vetorDecr = inverterVetor(vetor);								// Inverte o vetor para criar o segundo vetor especial
	vetorEspecial2 = criarVetorEsp2(vetor, vetorDecr);				// Cria vetor decrescente até a metade e crescente na outra metade

	printf("\t> Ordernar array primeira metade decre. e segunda metade cresc.:\n");
	exibir(vetorEspecial2);											// Exibe o vetor especial 2
	inicio = clock();												// Pega o horário inicial				
	selectionSort(vetorEspecial2);									// Ordena o vetor especial 2	
	fim = clock();													// Pega o horário final
	tempo5 = (double)(fim - inicio)/ CLOCKS_PER_SEC;				// Calcula o tempo de execução

	exibirTempo(tempo1, tempo2, tempo3, tempo4, tempo5);			// Exibe os tempos de execução

	free(vetor);													// Libera a memória alocada
	free(vetorDecr);												// Libera a memória alocada
	free(vetorEspecial1);											// Libera a memória alocada
	free(vetorEspecial2);											// Libera a memória alocada
	return 0;
}

