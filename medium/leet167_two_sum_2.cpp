/**
 * Problema: LeetCode 167 - Two Sum II - Input Array Is Sorted
 * Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 * * Complexidade de Tempo: O(N) - Onde N é o número de elementos no vetor 'numbers'.
 * No pior caso, os ponteiros se moverão das extremidades até o centro, visitando cada elemento uma única vez.
 * * Complexidade de Espaço: O(1) - Memória estritamente constante. Não alocamos nenhuma
 * estrutura de dados adicional, pois o vetor já vem ordenado de fábrica.
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right)
        {
            int soma = numbers[left] + numbers[right];

            // Se encontramos o alvo, retorna os índices ajustados para base 1 (1-indexed)
            if (soma == target)
                return {++left, ++right};

            // Se a soma for maior que o target, precisamos de um número menor.
            // Como o vetor está ordenado, decrescemos o ponteiro da direita.
            else if (soma > target)
                right--;

            // Se a soma for menor que o target, precisamos de um número maior.
            // Avançamos o ponteiro da esquerda.
            else
                left++;
        }

        return {}; // Retorno padrão caso não encontre nenhuma dupla (embora o problema garanta que exista)
    }
};
