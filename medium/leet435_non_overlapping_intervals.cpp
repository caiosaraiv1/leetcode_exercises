/**
 * Problema: LeetCode 435 - Non-overlapping Intervals
 * Link: https://leetcode.com/problems/non-overlapping-intervals/
 * * Complexidade de Tempo: O(N log N) - Onde N é o número total de intervalos.
 * A ordenação dos intervalos usando a função lambda consome O(N log N). O loop 'for'
 * subsequente percorre o vetor uma única vez, levando tempo O(N).
 * * Complexidade de Espaço: O(1) ou O(N) - Dependendo do espaço de pilha utilizado pelo
 * std::sort da biblioteca padrão. Nenhuma estrutura de dados adicional é alocada.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Estratégia Gulosa: Ordena os intervalos pelo ponto FINAL (índice 1).
        // Quem termina mais cedo ganha prioridade, deixando mais espaço para os próximos.
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b)
            { return a[1] < b[1]; });

        int borda = intervals[0][1]; // Rastreia o ponto final do último intervalo válido mantido
        int remove = 0;              // Contador de intervalos sobrepostos que serão removidos
        int n = intervals.size();

        for (int i = 1; i < n; i++)
        {
            // Se o início do intervalo atual for MENOR que a borda do anterior,
            // significa que existe uma sobreposição inevitável.
            if (intervals[i][0] < borda) {
                remove++; // Removemos o atual (com base na lógica greedy, manter o que termina antes é melhor)
            } else {
                // Caso contrário, não há sobreposição. Atualizamos a borda para o fim do intervalo atual.
                borda = intervals[i][1];
            }
        }

        return remove;
    }
};
