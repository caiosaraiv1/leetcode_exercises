/**
 * Problema: LeetCode 121 - Best Time to Buy and Sell Stock
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * * Complexidade de Tempo: O(N) - Onde N é o número de dias (tamanho do vetor 'prices').
 * Percorremos o vetor uma única vez, realizando apenas operações de comparação de tempo constante O(1).
 * * Complexidade de Espaço: O(1) - Espaço em memória constante, pois utilizamos apenas algumas
 * variáveis auxiliares (min_price e profit) independentemente do tamanho da entrada.
 */

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int profit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            // Atualiza o menor preço de compra encontrado até agora
            min_price = std::min(min_price, prices[i]);

            // Calcula o lucro se vendêssemos a ação no dia atual
            int profit_now = prices[i] - min_price;

            // Atualiza o lucro máximo acumulado
            profit = std::max(profit, profit_now);
        }

        return profit;
    }
};
