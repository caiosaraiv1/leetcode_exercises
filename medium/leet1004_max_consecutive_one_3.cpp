/**
 * Problema: LeetCode 1004 - Max Consecutive Ones III
 * Link: https://leetcode.com/problems/max-consecutive-ones-iii/
 * * Complexidade de Tempo: O(N) - Onde N é o número de elementos no vetor 'nums'.
 * Cada elemento é visitado no máximo duas vezes: uma pelo ponteiro 'right' (na expansão)
 * e outra pelo ponteiro 'left' (no encolhimento).
 * * Complexidade de Espaço: O(1) - Memória estritamente constante, operando 'in-place'
 * apenas com variáveis locais auxiliares.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_len = 0;
        int left = 0;
        int num_zero = 0; // Rastreia a quantidade de zeros dentro da janela atual
        int n = nums.size();

        // Expande a janela movendo o ponteiro da direita
        for (int right = 0; right < n; right++)
        {
            // Se encontramos um zero, ele consome parte do nosso orçamento 'k'
            if (nums[right] == 0) {
                num_zero++;
            }

            // Se a quantidade de zeros na janela atual estourar o limite 'k',
            // encolhemos a janela pela esquerda até restaurar a validade
            while (left <= right && num_zero > k)
            {
                if (nums[left] == 0) {
                    num_zero--;
                }
                left++;
            }

            // Atualiza o comprimento máximo de 1s consecutivos encontrado
            max_len = max(max_len, (right - left + 1));
        }

        return max_len;
    }
};
