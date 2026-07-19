/**
 * Problema: LeetCode 15 - 3Sum
 * Link: https://leetcode.com/problems/3sum/
 * * Complexidade de Tempo: O(N^2) - Onde N é o número de elementos no vetor 'nums'.
 * A ordenação inicial leva O(N log N). Depois, o loop principal roda N vezes, e o
 * loop interno de dois ponteiros leva O(N) no pior caso. Assim, O(N log N) + O(N^2) = O(N^2).
 * * Complexidade de Espaço: O(1) ou O(N) - Dependendo da implementação do algoritmo
 * de ordenação padrão (std::sort) da biblioteca do C++ (geralmente IntroSort, que gasta O(log N) de memória).
 * Desconsiderando o espaço necessário para armazenar o vetor de resposta 'res'.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        // Ordenar é fundamental para a técnica de dois ponteiros e para evitar duplicatas
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            // Otimização: Se o número atual for maior que 0, a soma nunca será 0
            if (nums[i] > 0) break;

            // Pula elementos duplicados para o primeiro termo do trio
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    left++; // Soma muito pequena, move o ponteiro da esquerda para aumentar
                } else if (sum > 0) {
                    right--; // Soma muito grande, move o ponteiro da direita para diminuir
                } else {
                    // Trio encontrado!
                    res.push_back({nums[i], nums[left], nums[right]});

                    // Pula elementos duplicados para o segundo termo do trio
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    // Pula elementos duplicados para o terceiro termo do trio
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    // Move ambos após processar o trio válido
                    left++;
                    right--;
                }
            }
        }

        return res;
    }
};
