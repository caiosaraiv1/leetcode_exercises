/**
 * Problema: LeetCode 102 - Binary Tree Level Order Traversal
 * Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
 * * Complexidade de Tempo: O(N) - Onde N é o número total de nós na árvore.
 * Cada nó é inserido e removido da fila exatamente uma vez, e processado em tempo constante.
 * * Complexidade de Espaço: O(W) - Onde W é a largura máxima da árvore (o nível com mais nós).
 * No pior caso (uma árvore binária perfeita), o último nível contém aproximadamente N/2 nós,
 * que ficarão armazenados simultaneamente na fila.
 */

#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        queue<TreeNode*> fila;
        vector<vector<int>> res;

        fila.push(root);

        while (!fila.empty())
        {
            int n = fila.size(); // Quantidade de nós no nível atual
            vector<int> local;   // Armazena os elementos do nível atual

            for (int i = 0; i < n; i++)
            {
                TreeNode* atual = fila.front();
                fila.pop();

                local.push_back(atual->val);

                // Adiciona os filhos na fila para serem processados no próximo nível
                if (atual->left != nullptr)
                    fila.push(atual->left);
                if (atual->right != nullptr)
                    fila.push(atual->right);
            }
            // Adiciona o nível processado ao resultado final
            res.push_back(local);
        }

        return res;
    }
};
