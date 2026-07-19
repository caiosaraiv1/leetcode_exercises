/**
 * Problema: LeetCode 452 - Minimum Number of Arrows to Burst Balloons
 * Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
 * * Complexidade de Tempo: O(N log N) - Onde N é o número total de balões (intervalos).
 * A ordenação dos elementos com a função lambda customizada consome O(N log N).
 * O loop subsequente varre o vetor linearmente em tempo O(N).
 * * Complexidade de Espaço: O(1) ou O(N) - Dependendo do espaço de pilha utilizado pelo
 * std::sort da biblioteca padrão. Nenhuma estrutura de dados extra é alocada.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        // Abordagem Gulosa: Ordena os balões pelo ponto FINAL (índice 1).
        // Atirar no ponto onde o balão termina maximiza a chance de pegar balões futuros.
        sort(points.begin(), points.end(),
            [] (const vector<int>& a, const vector<int>& b)
            { return a[1] < b[1]; });

        // Aloca a primeira flecha para a borda final do primeiro balão
        int borda = points[0][1];
        int flechas = 1;
        int n = points.size();

        for (int i = 1; i < n; i++)
        {
            // Se o ponto inicial do balão atual for ESTRITAMENTE MAIOR que a borda da nossa
            // última flecha, significa que este balão começa depois que a flecha passou.
            if (points[i][0] > borda)
            {
                flechas++;             // Precisamos de uma nova flecha
                borda = points[i][1];  // Atualiza a borda para o fim deste novo balão
            }
            // Caso contrário (points[i][0] <= borda), a flecha atual também estoura este balão.
        }

        return flechas;
    }
};
