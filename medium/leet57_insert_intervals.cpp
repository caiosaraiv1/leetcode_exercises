/**
 * Problema: LeetCode 57 - Insert Interval
 * Link: https://leetcode.com/problems/insert-interval/
 * * Complexidade de Tempo: O(N) - Onde N é o número de intervalos em 'intervals'.
 * Percorremos o vetor uma única vez de ponta a ponta através dos três loops 'while' sequenciais.
 * * Complexidade de Espaço: O(1) ou O(N) - Memória estritamente constante O(1) se desconsiderarmos
 * o espaço necessário para alocar o vetor de resposta 'res'.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Se a lista original estiver vazia, basta retornar o novo intervalo
        if (intervals.empty()) return {newInterval};

        vector<vector<int>> res;
        int i = 0;
        int n = intervals.size();

        // 1. Adiciona todos os intervalos que vêm antes do novo intervalo (sem sobreposição)
        while (i < n && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }

        // 2. Mescla todos os intervalos que se sobrepõem ao novo intervalo
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        // Insere o intervalo mesclado (ou o próprio original caso não tenha havido fusão)
        res.push_back(newInterval);

        // 3. Adiciona o restante dos intervalos que vêm depois do novo intervalo (sem sobreposição)
        while (i < n && intervals[i][0] > newInterval[1])
        {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};
