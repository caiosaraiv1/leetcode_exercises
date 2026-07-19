/**
 * Problema: LeetCode 1343 - Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
 * Link: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
 * * Complexidade de Tempo: O(N) - Onde N é o número de elementos no vetor 'arr'.
 * O primeiro loop processa os primeiros K elementos. O segundo loop percorre o restante do
 * vetor executando apenas operações aritméticas simples de tempo constante O(1).
 * * Complexidade de Espaço: O(1) - Memória estritamente constante. O algoritmo opera
 * inteiramente 'in-place', utilizando apenas variáveis locais para os somatórios e contadores.
 */

#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int qtd_subarrays = 0;
        int somaAtual = 0;

        // Alvo matemático otimizado: evita divisões custosas e ponto flutuante
        int soma_alvo = threshold * k;

        // Passo 1: Calcula a soma da primeira janela de tamanho fixo 'k'
        for (int i = 0; i < k; i++) {
            somaAtual += arr[i];
        }

        // Verifica a primeira janela
        if (somaAtual >= soma_alvo) {
            qtd_subarrays++;
        }

        // Passo 2: Desloca a janela de tamanho fixo elemento por elemento ao longo do vetor
        for (int i = k; i < arr.size(); i++) {
            // Atualização da janela em O(1): adiciona o novo elemento (arr[i])
            // e remove o elemento mais antigo que ficou para trás (arr[i - k])
            somaAtual += arr[i] - arr[i - k];

            // Se a soma da janela atual bater ou superar a meta, contabiliza o subarray
            if (somaAtual >= soma_alvo) {
                qtd_subarrays++;
            }
        }

        return qtd_subarrays;
    }
};
