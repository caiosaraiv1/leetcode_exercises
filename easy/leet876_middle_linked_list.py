"""
Problema: LeetCode 876 - Middle of the Linked List
Link: https://leetcode.com/problems/middle-of-the-linked-list/

Complexidade de Tempo: O(N) - Onde N é o número de nós na lista encadeada.
Passamos pela lista apenas uma vez, pois o ponteiro rápido alcança o fim em N/2 passos.

Complexidade de Espaço: O(1) - Memória constante.
Usamos apenas duas variáveis de referência (slow e fast), independente do tamanho da lista.
"""

from typing import Optional

class ListNode:
      def __init__(self, val=0, next=None):
            self.val = val
            self.next = next

class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = head
        fast = head

        # O ponteiro 'fast' avança de dois em dois nós.
        # Se a lista tiver um número par de nós, o critério 'fast.next is not None'
        # garante que retornaremos o segundo nó do meio, exatamente como o LeetCode pede.
        while fast is not None and fast.next is not None:
            slow = slow.next       # Avança 1 nó
            fast = fast.next.next  # Avança 2 nós

        return slow
