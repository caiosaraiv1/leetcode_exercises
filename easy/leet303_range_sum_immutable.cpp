/**
 * Problema: LeetCode 303 - Range Sum Query - Immutable
 * Link: https://leetcode.com/problems/range-sum-query-immutable/
 * * Complexidade de Tempo:
 * - Construtor NumArray(): O(N) - Onde N é o número de elementos no vetor 'nums'.
 * Passamos uma única vez pelo vetor original para construir a tabela de prefixos.
 * - Método sumRange(): O(1) - A soma de qualquer intervalo é calculada instantaneamente
 * através de uma única operação de subtração.
 * * Complexidade de Espaço: O(N) - Alocamos um vetor extra 'prefix' de tamanho N + 1
 * para armazenar as somas acumuladas.
 */

#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> prefix;

    NumArray(vector<int>& nums) {
        int n = nums.size();
        // Redimensiona para n + 1 para facilitar o cálculo do índice 'left = 0' sem ifs
        prefix.resize(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        // A diferença entre as posições retorna a soma acumulada do intervalo [left, right]
        return (prefix[right + 1] - prefix[left]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
