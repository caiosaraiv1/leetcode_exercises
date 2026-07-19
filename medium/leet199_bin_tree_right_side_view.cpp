/**
 * Problema: LeetCode 199 - Binary Tree Right Side View
 * Link: https://leetcode.com/problems/binary-tree-right-side-view/
 * * Complexidade de Tempo: O(N) - Onde N é o número total de nós na árvore.
 * Cada nó é inserido e removido da fila exatamente uma vez.
 * * Complexidade de Espaço: O(W) - Onde W é a largura máxima da árvore.
 * No pior caso (uma árvore binária perfeita), o último nível conterá até N/2 nós,
 * que serão mantidos simultaneamente na estrutura da fila.
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
    vector<int> rightSideView(TreeNode* root) {
        // Caso base: se a árvore for vazia, retorna um vetor vazio
        if (root == nullptr) return {};

        queue<TreeNode*> fila;
        vector<int> res;

        fila.push(root);

        while (!fila.empty())
        {
            int n = fila.size(); // Quantidade de nós presentes no nível atual

            for (int i = 0; i < n; i++)
            {
                TreeNode* atual = fila.front();
                fila.pop();

                // Garante a inserção padrão na fila (Esquerda antes da Direita)
                if (atual->left != nullptr)
                    fila.push(atual->left);

                if (atual->right != nullptr)
                    fila.push(atual->right);

                // Se 'i' for igual a 'n - 1', estamos processando o último nó do nível atual.
                // Na perspectiva da direita, este é o único nó visível deste nível.
                if (i == n - 1)
                    res.push_back(atual->val);
            }
        }

        return res;
    }
};
