/**
 * Problema: LeetCode 75 - Sort Colors
 * Link: https://leetcode.com/problems/sort-colors/
 * * Complexidade de Tempo: O(N) - Onde N é o número de elementos no vetor 'nums'.
 * Varremos o vetor uma única vez de ponta a ponta utilizando a lógica dos três ponteiros.
 * * Complexidade de Espaço: O(1) - Memória estritamente constante. A ordenação é feita
 * 'in-place' (diretamente no vetor original) modificando apenas os elementos via swap.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;          // Fronteira para os zeros (0)
        int mid = 0;           // Ponteiro de varredura atual
        int right = nums.size() - 1; // Fronteira para os dois (2)

        while (mid <= right)
        {
            if (nums[mid] == 0)
            {
                // Joga o 0 para o início (posição left)
                swap(nums[left], nums[mid]);
                left++;
                mid++; // Aqui podemos avançar mid porque sabemos que o elemento vindo de left era 1
            }
            else if (nums[mid] == 2)
            {
                // Joga o 2 para o fim (posição right)
                swap(nums[right], nums[mid]);
                right--;
                // CRUCIAL: Não avançamos mid aqui, pois o elemento que veio de right
                // precisa ser avaliado na próxima iteração.
                continue;
            }
            else
            {
                // Se for 1, o elemento já está na zona correta do meio. Apenas avança.
                mid++;
            }
        }
    }
};
