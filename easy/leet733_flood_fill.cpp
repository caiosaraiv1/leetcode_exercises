/**
 * Problema: LeetCode 733 - Flood Fill
 * Link: https://leetcode.com/problems/flood-fill/
 * * Complexidade de Tempo: O(N) - Onde N é o número total de pixels na imagem (Linhas * Colunas).
 * No pior caso, o algoritmo visitará todos os pixels da matriz exatamente uma vez.
 * * Complexidade de Espaço: O(N) - Memória utilizada pela pilha de recursão do sistema.
 * No pior caso (onde todos os pixels têm a mesma cor original), a profundidade da
 * recursão pode chegar ao número total de pixels na imagem.
 */

#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int og_color)
    {
        // Caso base 1: Verifica os limites da matriz (fronteiras da imagem)
        if (sr < 0 || sc < 0
        || sr >= image.size()
        || sc >= image[0].size())
            return;

        // Caso base 2: Se o pixel atual não tem a cor original, não deve ser pintado
        if (image[sr][sc] != og_color)
            return;

        // Pinta o pixel atual com a nova cor
        image[sr][sc] = color;

        // Executa a DFS recursivamente nas 4 direções adjacentes (Direita, Esquerda, Baixo, Cima)
        dfs(image, sr, sc + 1, color, og_color);
        dfs(image, sr, sc - 1, color, og_color);
        dfs(image, sr + 1, sc, color, og_color);
        dfs(image, sr - 1, sc, color, og_color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int og_color = image[sr][sc];

        // Proteção essencial contra loop infinito se a cor nova for idêntica à antiga
        if (color == og_color) return image;

        // Inicia a inundação a partir do pixel semente
        dfs(image, sr, sc, color, og_color);

        return image;
    }
};
