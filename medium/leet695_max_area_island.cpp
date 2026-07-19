/**
 * Problema: LeetCode 695 - Max Area of Island
 * Link: https://leetcode.com/problems/max-area-of-island/
 * * Complexidade de Tempo: O(M * N) - Onde M é o número de linhas e N é o número de colunas do grid.
 * Cada célula é visitada no máximo algumas vezes pelas validações de borda, e as células de terra
 * são "afundadas" (zeradas), garantindo que cada posição seja processada de forma linear.
 * * Complexidade de Espaço: O(M * N) - No pior cenário (onde o grid inteiro é uma única grande ilha),
 * a pilha de recursão do sistema crescerá proporcionalmente ao número total de células.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Função DFS que afunda a ilha conectada e retorna a área total mapeada
    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        // Caso base 1: Verifica se a posição atual extrapolou os limites do grid
        if (r < 0 || c < 0 ||
            r >= grid.size() ||
            c >= grid[0].size())
            return 0;

        // Caso base 2: Se encontrar água (0), este pixel não soma à área da ilha
        if (grid[r][c] == 0)
            return 0;

        // Marca a célula atual como visitada alterando-a para água (0) para evitar loops infinitos
        grid[r][c] = 0;

        // Retorna 1 (pela célula atual) mais o somatório das áreas encontradas nas 4 direções
        return 1 + dfs(grid, r, c - 1)
                 + dfs(grid, r, c + 1)
                 + dfs(grid, r - 1, c)
                 + dfs(grid, r + 1, c);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int max_area = 0;

        // Varredura linear por toda a matriz
        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[0].size(); c++)
            {
                // Sempre que encontra terra intacta (1), dispara a DFS para computar o tamanho da ilha
                if (grid[r][c] == 1)
                {
                    // Compara o tamanho da ilha recém-descoberta com o recorde atual
                    max_area = max(max_area, dfs(grid, r, c));
                }
            }
        }

        return max_area;
    }
};
