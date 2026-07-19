/**
 * Problema: LeetCode 103 - Binary Tree Zigzag Level Order Traversal
 * Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 * * Complexidade de Tempo: O(N) - Onde N é o número total de nós na árvore.
 * Cada nó é inserido e removido da fila exatamente uma vez. A operação std::reverse()
 * leva O(K) onde K é o número de nós no nível específico; o somatório de todos os K
 * ao longo da árvore inteira resulta em O(N).
 * * Complexidade de Espaço: O(W) - Onde W é a largura máxima da árvore (memória gasta com a fila).
 * No pior caso de uma árvore binária perfeita, o nível mais baixo armazena até N/2 nós simultaneamente.
 */

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> res;
        queue<TreeNode*> fila;

        fila.push(root);
        int nivel = 0; // Rastreia a profundidade atual para alternar a direção

        while (!fila.empty())
        {
            int tamanho = fila.size();
            vector<int> local;

            for (int i = 0; i < tamanho; i++)
            {
                TreeNode* atual = fila.front();
                fila.pop();

                local.push_back(atual->val);

                // Mantém a ordem padrão de inserção na fila (Esquerda -> Direita)
                if (atual->left != nullptr)
                    fila.push(atual->left);

                if (atual->right != nullptr)
                    fila.push(atual->right);
            }

            // Se o nível for ímpar, inverte a ordem dos elementos coletados
            if (nivel % 2 != 0) {
                reverse(local.begin(), local.end());
            }

            res.push_back(local);
            nivel++; // Avança para o próximo nível
        }

        return res;
    }
};
