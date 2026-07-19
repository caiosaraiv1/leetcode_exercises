/**
 * Problema: LeetCode 226 - Invert Binary Tree
 * Link: https://leetcode.com/problems/invert-binary-tree/
 * * Complexidade de Tempo: O(N) - Onde N é o número total de nós na árvore,
 * já que precisamos visitar e espelhar cada nó exatamente uma vez.
 * * Complexidade de Espaço: O(H) - Onde H é a altura da árvore.
 * Memória gasta com a pilha de recursão. No pior caso (árvore linear), o espaço é O(N);
 * no melhor caso (árvore balanceada), o espaço é O(log N).
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
    TreeNode* invertTree(TreeNode* root) {
        // Caso base: árvore vazia
        if (root == nullptr) return nullptr;

        // Inverte recursivamente as subárvores esquerda e direita
        TreeNode *esq = invertTree(root->left);
        TreeNode *dir = invertTree(root->right);

        // Troca os ponteiros dos filhos do nó atual (espelhamento)
        TreeNode *temp = esq;
        root->left = dir;
        root->right = temp;

        return root;
    }
};
