/**
 * Problema: LeetCode 141 - Linked List Cycle
 * Link: https://leetcode.com/problems/linked-list-cycle/
 * * Complexidade de Tempo: O(N) - Onde N é o número de nós na lista encadeada.
 * Se não houver ciclo, o ponteiro rápido alcançará o fim em N/2 passos. Se houver ciclo,
 * o ponteiro rápido entrará no loop e alcançará o ponteiro lento em no máximo uma distância
 * igual ao comprimento do ciclo.
 * * Complexidade de Espaço: O(1) - Memória constante, já que utilizamos apenas dois ponteiros
 * auxiliares (slow e fast), independentemente do tamanho da lista.
 */

#include <cstddef>

/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // O ponteiro rápido avança de 2 em 2, então precisamos checar tanto ele
        // quanto o próximo nó para evitar violação de acesso (nullptr exception).
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;       // Anda 1 passo
            fast = fast->next->next; // Anda 2 passos

            // Se os ponteiros se encontrarem, há um ciclo na lista encadeada
            if (slow == fast) return true;
        }

        // Se o ponteiro rápido alcançar o fim da lista, ela é linear e não tem ciclo
        return false;
    }
};
