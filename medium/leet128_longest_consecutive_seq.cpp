/**
 * Problema: LeetCode 128 - Longest Consecutive Sequence
 * Link: https://leetcode.com/problems/longest-consecutive-sequence/
 * * Complexidade de Tempo: O(N) - Onde N é o número de elementos no vetor 'nums'.
 * Inserir todos os elementos no hash set leva O(N). Embora haja um 'while' dentro do 'for',
 * ele só é ativado para o início de uma sequência. Na prática, cada elemento é processado
 * no máximo duas vezes, garantindo tempo linear amortizado.
 * * Complexidade de Espaço: O(N) - Memória necessária para armazenar os elementos únicos
 * do vetor dentro do 'std::unordered_set'.
 */

#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Insere todos os números no set para buscas em tempo O(1)
        unordered_set<int> conjunto(nums.begin(), nums.end());
        int maior = 0;

        for (const auto& num : conjunto)
        {
            // CRUCIAL: Só inicia a contagem se 'num' for o menor elemento de uma sequência em potencial.
            // Se o conjunto contiver 'num - 1', significa que 'num' faz parte do meio de outra sequência
            // e já será computado por completo quando o loop encontrar o início real dela.
            if (!conjunto.contains(num - 1))
            {
                int sequencia_atual = 1;
                int num_atual = num;

                // Expandindo e contando a sequência consecutiva para a direita
                while (conjunto.contains(num_atual + 1))
                {
                    sequencia_atual++;
                    num_atual++;
                }

                // Atualiza o recorde da maior sequência encontrada
                maior = max(maior, sequencia_atual);
            }
        }

        return maior;
    }
};
