/**
 * Problema: LeetCode 98 - Validate Binary Search Tree
 * Link: https://leetcode.com/problems/validate-binary-search-tree/
 * * Complexidade de Tempo: O(N) - Onde N é o número total de nós na árvore.
 * No pior caso (árvore válida ou falha no último nó), visitaremos cada nó exatamente uma vez.
 * * Complexidade de Espaço: O(H) - Onde H é a altura da árvore.
 * Corresponde à memória gasta pela nossa pilha ('std::stack'). No pior caso (árvore linear),
 * o espaço será O(N); no melhor caso (árvore perfeitamente balanceada), será O(log N).
 */

#include <stack>

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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;

        TreeNode* atual = root;
        stack<TreeNode*> pilha;
        TreeNode* anterior = nullptr; // Rastreia o nó visitado imediatamente antes

        // Algoritmo Iterativo de Travessia In-order (Esquerda -> Raiz -> Direita)
        while (atual != nullptr || !pilha.empty())
        {
            // 1. Vai tudo para a esquerda empilhando os nós do caminho
            while (atual != nullptr)
            {
                pilha.push(atual);
                atual = atual->left;
            }

            // 2. Processa o nó do topo da pilha (Raiz local)
            atual = pilha.top();
            pilha.pop();

            // Propriedade da BST: O valor atual DEVE ser maior que o anterior na ordem de visita
            if (anterior != nullptr && atual->val <= anterior->val)
                return false;

            // Atualiza o ponteiro do nó anterior
            anterior = atual;

            // 3. Move para a subárvore direita
            atual = atual->right;
        }

        return true;
    }
};
