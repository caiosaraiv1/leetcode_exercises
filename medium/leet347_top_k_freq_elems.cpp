/**
 * Problema: LeetCode 347 - Top K Frequent Elements
 * Link: https://leetcode.com/problems/top-k-frequent-elements/
 * * Complexidade de Tempo: O(N log U) - Onde N é o número de elementos no vetor 'nums'
 * e U é o número de elementos únicos. Contar as frequências leva O(N). Inserir os U elementos
 * únicos no Heap leva O(U log U). Extrair os K elementos leva O(K log U).
 * * Complexidade de Espaço: O(U) - Memória necessária para armazenar os elementos únicos
 * tanto no mapa de hash quanto na priority_queue.
 */

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mapa;

        // Passo 1: Conta a frequência de cada número (Tempo: O(N))
        for (const auto& num : nums)
            mapa[num]++;

        // Passo 2: Insere no Max-Heap estruturado como pair<frequencia, numero>
        // Por padrão, o C++ ordena pares pelo primeiro elemento (.first)
        priority_queue<pair<int, int>> pq;

        for (const auto& [num, freq] : mapa)
            pq.push({freq, num});

        // Passo 3: Extrai os K elementos mais frequentes do topo do Heap
        vector<int> res;
        res.reserve(k); // Otimização: Evita realocações dinâmicas de memória

        for (int i = 0; i < k; i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
