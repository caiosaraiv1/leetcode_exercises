/**
 * Problema: LeetCode 1 - Two Sum
 * Link: https://leetcode.com/problems/two-sum/
 * * Complexidade de Tempo: O(N) - Onde N é o número de elementos no vetor 'nums'.
 * Passamos pelo vetor apenas uma vez e as operações de
 * busca e inserção no unordered_map levam tempo médio O(1).
 * * Complexidade de Espaço: O(N) - No pior caso, precisaremos armazenar quase todos
 * os elementos do vetor no hash map antes de encontrar o par.
 */

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // x + y = target
        // target - x = y
        unordered_map<int, int> mapa;

        for (int i = 0; i < nums.size(); i++)
        {
            // .contains() requer suporte a C++20
            if (mapa.contains(target - nums[i]))
                return {mapa[target - nums[i]], i};

            mapa[nums[i]] = i;
        }

        return {};
    }
};
