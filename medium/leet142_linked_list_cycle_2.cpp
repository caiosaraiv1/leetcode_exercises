/**
 * Problema: LeetCode 142 - Linked List Cycle II
 * Link: https://leetcode.com/problems/linked-list-cycle-ii/
 * * Complexidade de Tempo: O(N) - Onde N é o número total de nós na lista encadeada.
 * A primeira fase leva no máximo O(N) para detectar o ciclo. A segunda fase percorre
 * a distância até o início do ciclo, que também é menor ou igual a O(N).
 * * Complexidade de Espaço: O(1) - Memória estritamente constante, pois manipulamos
 * apenas os ponteiros locais existentes, sem usar tabelas de hash adicionais.
 */

/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        bool temCiclo = false;

        // Fase 1: Determinar se existe um ciclo usando velocidades diferentes
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (slow == fast) {
                temCiclo = true;
                break; // Ciclo detectado, interrompe para iniciar a Fase 2
            }
        }

        // Se não houver ciclo, é impossível determinar um nó de início
        if (!temCiclo) return nullptr;

        // Fase 2: Encontrar o ponto de início do ciclo
        // Move o ponteiro lento de volta para o começo da lista
        slow = head;

        // Move ambos os ponteiros à mesma velocidade (1 passo por vez).
        // O local do recontro será o nó exato onde o ciclo começa.
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // Retorna o nó de início do ciclo (pode ser tanto 'slow' quanto 'fast')
    }
};
