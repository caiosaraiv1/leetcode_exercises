/**
 * Problema: LeetCode 515 - Find Largest Value in Each Tree Row
 * Link: https://leetcode.com/problems/find-largest-value-each-tree-row/
 * * Complexidade de Tempo: O(N) - Onde N é o número total de nós na árvore.
 * Cada nó é inserido e removido da fila exatamente uma vez, com processamento constante O(1).
 * * Complexidade de Espaço: O(W) - Onde W é a largura máxima da árvore (o nível com mais nós).
 * No pior caso de uma árvore binária perfeita, o nível mais baixo armazena até N/2 nós simultaneamente na fila.
 */

#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

// A definição do struct TreeNode fica comentada para referência futura:
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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return {};

        queue<TreeNode*> fila;
        vector<int> res;

        fila.push(root);

        while (!fila.empty())
        {
            int n = fila.size(); // Quantidade de nós na linha/nível atual
            int max_v = INT_MIN; // Inicializa com o menor valor possível para coletar o máximo com segurança

            for (int i = 0; i < n; i++)
            {
                TreeNode* atual = fila.front();
                fila.pop();

                // Atualiza o maior valor encontrado nesta linha até o momento
                max_v = max(max_v, atual->val);

                // Insere os filhos para processamento no próximo nível
                if (atual->left != nullptr)
                    fila.push(atual->left);

                if (atual->right != nullptr)
                    fila.push(atual->right);
            }
            // Guarda o maior valor consolidado da linha atual
            res.push_back(max_v);
        }

        return res;
    }
};
