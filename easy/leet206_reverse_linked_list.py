"""
Problema: LeetCode 206 - Reverse Linked List
Link: https://leetcode.com/problems/reverse-linked-list/

Complexidade de Tempo: O(N) - Onde N é o número de nós na lista encadeada.
Passamos pela lista exatamente uma vez para inverter as conexões.

Complexidade de Espaço: O(1) - Memória estritamente constante.
A inversão é feita alterando apenas as referências (ponteiros) locais,
sem utilizar estruturas de dados adicionais ou memória extra da pilha de recursão.
"""

from typing import Optional

class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        if head.next is None:
            return head

        temp = head
        before = None
        after = temp.next

        while after is not None:
            after = temp.next      # Guarda o resto da lista original
            temp.next = before     # Inverte o ponteiro do nó atual para o anterior
            before = temp          # Move o ponteiro 'before' um passo à frente
            temp = after           # Move o ponteiro principal 'temp' para o próximo nó

        return before
