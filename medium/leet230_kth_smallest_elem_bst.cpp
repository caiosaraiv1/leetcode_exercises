/**
 * Problema: LeetCode 230 - Kth Smallest Element in a BST
 * Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 * * Complexidade de Tempo: O(H + K) - Onde H é a altura da árvore e K é o índice do elemento procurado.
 * O algoritmo desce até o nó mais à esquerda O(H) e depois processa exatamente K elementos até encontrar a resposta.
 * No melhor caso (árvore balanceada), isso se traduz em O(log N + K).
 * * Complexidade de Espaço: O(H) - Memória gasta com a nossa pilha ('std::stack'), que armazena no máximo
 * a quantidade de nós equivalente à altura da árvore ao mesmo tempo.
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
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) return 0;

        TreeNode* atual = root;
        stack<TreeNode*> pilha;

        // Algoritmo Iterativo de Travessia In-order (Esquerda -> Raiz -> Direita)
        while (atual != nullptr || !pilha.empty())
        {
            // 1. Vai tudo para a esquerda empilhando os nós do caminho (dos maiores para os menores)
            while (atual != nullptr)
            {
                pilha.push(atual);
                atual = atual->left;
            }

            // 2. Processa o menor nó disponível no topo da pilha
            atual = pilha.top();
            pilha.pop();

            // Decrementa o contador do k-ésimo elemento
            k--;
            // Se k chegou a zero, encontramos o elemento exato
            if (k == 0) return atual->val;

            // 3. Move para a subárvore direita para avaliar os próximos maiores elementos na sequência
            atual = atual->right;
        }

        return 0; // Retorno padrão de segurança
    }
};
