/**
 * Problema: LeetCode 643 - Maximum Average Subarray I
 * Link: https://leetcode.com/problems/maximum-average-subarray-i/
 * * Complexidade de Tempo: O(N) - Onde N é o número de elementos no vetor 'nums'.
 * Passamos pelo vetor uma única vez: primeiro para calcular a soma da janela inicial
 * e depois para deslizar a janela até o final do array.
 * * Complexidade de Espaço: O(1) - Memória estritamente constante. As operações
 * são feitas diretamente sobre o vetor de entrada usando apenas variáveis auxiliares.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int somaAtual = 0;

        // Calcula a soma da primeira janela de tamanho k
        for (int i = 0; i < k; i++) {
            somaAtual += nums[i];
        }

        int maxSum = somaAtual;

        // Desliza a janela por todo o restante do vetor
        for (int i = k; i < nums.size(); i++) {
            // Soma o novo elemento da direita e subtrai o antigo da esquerda
            somaAtual += nums[i] - nums[i - k];

            maxSum = std::max(somaAtual, maxSum);
        }

        // Divide pelo tamanho k apenas no final para retornar a maior média
        return static_cast<double>(maxSum) / k;
    }
};
