/**
 * Problema: LeetCode 56 - Merge Intervals
 * Link: https://leetcode.com/problems/merge-intervals/
 * * Complexidade de Tempo: O(N log N) - Onde N é o número total de intervalos.
 * A ordenação dos intervalos leva O(N log N). O loop subsequente percorre o vetor
 * apenas uma vez, levando tempo O(N). Portanto, o tempo de ordenação domina a complexidade.
 * * Complexidade de Espaço: O(1) ou O(N) - Dependendo da memória interna utilizada pelo
 * algoritmo de ordenação (std::sort). Desconsiderando o espaço necessário para armazenar
 * o vetor de resposta 'res'.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Se o vetor estiver vazio, retorna um resultado vazio
        if (intervals.empty()) return {};

        vector<vector<int>> res;

        // Ordena os intervalos pelo ponto inicial (essencial para a lógica linear)
        sort(intervals.begin(), intervals.end());

        // Insere o primeiro intervalo como base de comparação
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            // Se o início do intervalo atual for menor ou igual ao fim do último intervalo mesclado...
            if (intervals[i][0] <= res.back()[1]) {
                // ...existe sobreposição. Funde os intervalos atualizando o ponto final para o maior valor.
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            } else {
                // Caso contrário, não há sobreposição. Adiciona o novo intervalo de forma independente.
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};
