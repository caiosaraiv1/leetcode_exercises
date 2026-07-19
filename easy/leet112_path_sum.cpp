/**
 * Problema: LeetCode 112 - Path Sum
 * Link: https://leetcode.com/problems/path-sum/
 * * Complexidade de Tempo: O(N) - Onde N é o número total de nós na árvore.
 * No pior caso, visitaremos todos os nós até encontrar o caminho correto ou determinar que ele não existe.
 * * Complexidade de Espaço: O(H) - Onde H é a altura da árvore.
 * Corresponde à memória gasta com a pilha de recursão. No pior caso (árvore linear),
 * o espaço será O(N); no melhor caso (árvore balanceada), será O(log N).
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
    bool hasPathSum(TreeNode* root, int targetSum) {
       if (root == nullptr) return false;

       // Subtrai o valor do nó atual do objetivo restante
       targetSum -= root->val;

       // Se for um nó folha, verifica se a soma restante zerou
       if (root->left == nullptr && root->right == nullptr && targetSum == 0)
           return true;

       // Continua a busca nos subfilhos (basta que um dos caminhos seja verdadeiro)
       return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};
