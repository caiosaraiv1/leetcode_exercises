/**
 * Problema: LeetCode 200 - Number of Islands
 * Link: https://leetcode.com/problems/number-of-islands/
 * * Complexidade de Tempo: O(M * N) - Onde M é o número de linhas e N é o número de colunas.
 * No pior caso (onde o mapa inteiro é uma única grande ilha), visitaremos cada célula da matriz
 * exatamente uma vez através da DFS.
 * * Complexidade de Espaço: O(M * N) - No pior caso (se a matriz inteira for terra), a pilha
 * de recursão do sistema pode crescer proporcionalmente ao tamanho total do grid.
 */

#include <vector>

using namespace std;

class Solution {
public:
    // Função auxiliar DFS para explorar e "afundar" toda a terra conectada
    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        // Caso base 1: Verifica se a posição atual está fora das fronteiras do grid
        if (r < 0 || c < 0 ||
            r >= grid.size() ||
            c >= grid[0].size())
            return;

        // Caso base 2: Se encontrar água ('0'), interrompe a exploração nesta ramificação
        if (grid[r][c] == '0')
            return;

        // Marca a célula atual como visitada alterando-a para água ('0')
        grid[r][c] = '0';

        // Dispara a recursão para as 4 direções cardeais (Cima, Baixo, Esquerda, Direita)
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int res = 0;

        // Varredura linear por todas as células da matriz
        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[0].size(); c++)
            {
                // Sempre que encontramos um pedaço de terra intacto ('1'),
                // significa que descobrimos uma nova ilha isolada.
                if (grid[r][c] == '1')
                {
                    res++;
                    // A DFS vai varrer e zerar toda a terra conectada a este ponto
                    dfs(grid, r, c);
                }
            }
        }

        return res;
    }
};
