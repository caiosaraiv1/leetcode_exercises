/**
 * Problema: LeetCode 209 - Minimum Size Subarray Sum
 * Link: https://leetcode.com/problems/minimum-size-subarray-sum/
 * * Complexidade de Tempo: O(N) - Onde N é o número de elementos no vetor 'nums'.
 * Embora exista um 'while' dentro do 'for', cada elemento é visitado no máximo duas vezes:
 * uma quando o ponteiro 'right' o adiciona à soma e outra quando 'left' o remove.
 * * Complexidade de Espaço: O(1) - Memória estritamente constante. O algoritmo opera
 * 'in-place' utilizando apenas variáveis locais para armazenar os índices e os somatórios.
 */

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_length = INT_MAX;
        int sum = 0;
        int left = 0;

        // Expande a janela movendo o ponteiro da direita
        for (int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];

            // Enquanto a soma atual satisfizer ou superar o target,
            // tentamos encolher a janela pela esquerda para achar o menor tamanho válido
            while (left <= right && sum >= target)
            {
                // Atualiza o comprimento mínimo da subárvore/janela encontrada
                min_length = std::min(min_length, right - left + 1);

                // Remove o elemento que está saindo da janela e avança o ponteiro esquerdo
                sum -= nums[left];
                left++;
            }
        }

        // Se 'min_length' continuar sendo INT_MAX, significa que nenhuma combinação atingiu o target
        return min_length == INT_MAX ? 0 : min_length;
    }
};
