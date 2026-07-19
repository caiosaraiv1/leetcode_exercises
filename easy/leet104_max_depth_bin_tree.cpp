/**
 * Problema: LeetCode 104 - Maximum Depth of Binary Tree
 * Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
 * * Complexidade de Tempo: O(N) - Onde N é o número total de nós na árvore,
 * pois cada nó é visitado exatamente uma vez.
 * * Complexidade de Espaço: O(H) - Onde H é a altura da árvore.
 * No pior caso (uma árvore totalmente desbalanceada/linear), a pilha de recursão
 * guardará O(N) chamadas. No melhor caso (árvore perfeitamente balanceada), será O(log N).
 */

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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int esq = maxDepth(root->left);
        int dir = maxDepth(root->right);

        return std::max(esq, dir) + 1;
    }
};
