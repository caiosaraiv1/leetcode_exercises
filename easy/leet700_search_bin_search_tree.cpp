/**
 * Problema: LeetCode 700 - Search in a Binary Search Tree
 * Link: https://leetcode.com/problems/search-in-a-binary-search-tree/
 * * Complexidade de Tempo: O(H) - Onde H é a altura da árvore.
 * No melhor caso (árvore balanceada), a complexidade é O(log N). No pior caso
 * (árvore totalmente desbalanceada/linear, parecendo uma lista encadeada), será O(N).
 * * Complexidade de Espaço: O(H) - Memória gasta com a pilha de recursão do sistema,
 * proporcional à altura da árvore. Sendo O(log N) no melhor caso e O(N) no pior caso.
 */

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
    TreeNode* searchBST(TreeNode* root, int val) {
        // Casos base: nó nulo (valor não encontrado) ou valor encontrado no nó atual
        if (root == nullptr || root->val == val) return root;

        // Se o valor procurado for menor que o do nó atual, busca na subárvore esquerda
        if (root->val > val)
        {
            return searchBST(root->left, val);
        }
        // Se o valor procurado for maior, busca na subárvore direita
        else
        {
            return searchBST(root->right, val);
        }
    }
};
