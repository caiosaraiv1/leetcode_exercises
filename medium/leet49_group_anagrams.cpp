/**
 * Problema: LeetCode 49 - Group Anagrams
 * Link: https://leetcode.com/problems/group-anagrams/
 * * Complexidade de Tempo: O(N * K log K) - Onde N é a quantidade de strings no vetor 'strs'
 * e K é o comprimento da maior string. Para cada uma das N palavras, nós a ordenamos,
 * o que leva O(K log K) de tempo. As operações no hash map levam tempo médio O(1).
 * * Complexidade de Espaço: O(N * K) - Memória necessária para armazenar todas as strings
 * e seus agrupamentos dentro do unordered_map.
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Chave: string ordenada (assinatura do anagrama) | Valor: lista de palavras originais
        unordered_map<string, vector<string>> mapa;

        for (auto& str : strs)
        {
            string copia = str;
            sort(copia.begin(), copia.end());

            // Agrupa a palavra original sob a mesma assinatura ordenada
            mapa[copia].push_back(str);
        }

        vector<vector<string>> res;
        // Otimização: Reserva memória prévia para evitar realocações dinâmicas no vetor de resposta
        res.reserve(mapa.size());

        for (auto& par : mapa)
        {
            // Otimização: Move o vetor de strings sem duplicar os dados na Heap (O(1) por vetor)
            res.push_back(move(par.second));
        }

        return res;
    }
};
