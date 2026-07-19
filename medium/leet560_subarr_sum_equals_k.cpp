/**
 * Problema: LeetCode 560 - Subarray Sum Equals K
 * Link: https://leetcode.com/problems/subarray-sum-equals-k/
 * * Complexidade de Tempo: O(N) - Onde N é o número de elementos no vetor 'nums'.
 * Percorremos o vetor uma única vez. As inserções e buscas no 'std::unordered_map'
 * levam tempo médio O(1).
 * * Complexidade de Espaço: O(N) - Memória gasta para armazenar as somas de prefixo
 * únicas dentro do mapa de hash. No pior caso, todas as somas de prefixo serão diferentes.
 */

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Chave: valor da soma de prefixo | Valor: frequência com que essa soma apareceu
        unordered_map<int, int> mapa;

        // Caso base essencial: uma soma acumulada de 0 já foi vista 1 vez (antes do primeiro elemento)
        mapa[0] = 1;

        int soma_atual = 0;
        int qtd_subarrays = 0;

        for (const auto& num : nums)
        {
            // Acumula a soma do prefixo até o elemento atual
            soma_atual += num;

            // Se (soma_atual - k) existe no mapa, significa que encontramos um ou mais
            // prefixos que, se removidos da soma atual, deixam um subarray que soma exatamente K.
            if (mapa.contains(soma_atual - k))
            {
                qtd_subarrays += mapa[soma_atual - k];
            }

            // Registra/atualiza a frequência da soma de prefixo atual no mapa
            mapa[soma_atual]++;
        }

        return qtd_subarrays;
    }
};
