/**
 * Problema: LeetCode 724 - Find Pivot Index
 * Link: https://leetcode.com/problems/find-pivot-index/
 * * Complexidade de Tempo: O(N) - Onde N é o número de elementos no vetor 'nums'.
 * Fazemos uma primeira passada para construir o vetor de prefixos O(N) e uma segunda
 * passada para encontrar o índice pivô O(N). Operações internas do loop são O(1).
 * * Complexidade de Espaço: O(N) - Alocamos um vetor extra 'prefix' de tamanho N + 1
 * para armazenar as somas acumuladas.
 */

#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        // Cria o vetor de prefixos inicializado com zero
        vector<int> prefix(n + 1, 0);

        // Preenche as somas acumuladas
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // Testamos cada índice como um possível pivô
        for (int pivot = 0; pivot < n; pivot++)
        {
            // Soma de todos os elementos estritamente à esquerda do pivô
            int left = prefix[pivot];

            // Soma de todos os elementos estritamente à direita do pivô
            int right = prefix[n] - prefix[pivot + 1];

            // Se as somas forem iguais, encontramos o pivô mais à esquerda
            if (left == right) return pivot;
        }

        return -1;
    }
};
