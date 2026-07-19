/**
 * Problema: LeetCode 111 - Minimum Depth of Binary Tree
 * Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/
 * * Complexidade de Tempo: O(N) - Onde N é o número total de nós na árvore. No pior caso
 * (árvore linear), podemos ter que visitar todos os nós. Porém, em média (árvores mais cheias),
 * a BFS encontra o nó folha mais raso muito antes de varrer a árvore inteira.
 * * Complexidade de Espaço: O(W) - Onde W é a largura máxima da árvore (número de nós no nível mais populoso).
 * No pior caso (uma árvore binária perfeita), o último nível contém cerca de N/2 nós, armazenados na fila.
 */

#include <queue>
#include <algorithm>

/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int profundidade = 1;
        std::queue<TreeNode*> fila;
        fila.push(root);

        while(!fila.empty())
        {
            int tamanho = fila.size();
            for (int i = 0; i < tamanho; i++)
            {
                TreeNode* atual = fila.front();
                fila.pop();

                // Primeiro nó folha encontrado garante a menor profundidade
                if (atual->left == nullptr && atual->right == nullptr)
                    return profundidade;

                if (atual->left != nullptr)
                    fila.push(atual->left);

                if (atual->right != nullptr)
                    fila.push(atual->right);
            }
            profundidade++;
        }
        return profundidade;
    }
};
