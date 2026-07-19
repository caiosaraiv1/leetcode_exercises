/**
 * Problema: LeetCode 637 - Average of Levels in Binary Tree
 * Link: https://leetcode.com/problems/average-of-levels-in-binary-tree/
 * * Complexidade de Tempo: O(N) - Onde N é o número total de nós na árvore.
 * Cada nó é inserido e removido da fila exatamente uma vez.
 * * Complexidade de Espaço: O(W) - Onde W é a largura máxima da árvore (número máximo de nós em um único nível).
 * No pior caso (uma árvore binária perfeita), o último nível contém aproximadamente N/2 nós,
 * que estarão simultaneamente na fila.
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
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == nullptr) return {};

        vector<double> res;
        queue<TreeNode*> fila;
        fila.push(root);

        while (!fila.empty())
        {
            int tamanho = fila.size(); // Quantidade de nós no nível atual
            long long soma = 0;        // long long evita overflow no somatório

            for (int i = 0; i < tamanho; i++)
            {
                TreeNode* atual = fila.front();
                fila.pop();

                // Adiciona os filhos na fila para o próximo nível
                if (atual->left != nullptr)
                    fila.push(atual->left);

                if (atual->right != nullptr)
                    fila.push(atual->right);

                soma += atual->val;
            }
            // Calcula a média do nível e adiciona ao resultado
            res.push_back(static_cast<double>(soma) / tamanho);
        }
        return res;
    }
};
