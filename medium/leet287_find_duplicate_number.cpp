/**
 * Problema: LeetCode 287 - Find the Duplicate Number
 * Link: https://leetcode.com/problems/find-the-duplicate-number/
 * * Complexidade de Tempo: O(N) - Onde N é o número de elementos no vetor 'nums'.
 * A primeira fase (detecção do encontro dentro do ciclo) e a segunda fase (busca pelo
 * início do ciclo) realizam uma varredura estritamente linear através dos saltos de índices.
 * * Complexidade de Espaço: O(1) - Memória estritamente constante. O algoritmo opera
 * 'in-place' apenas redirecionando duas variáveis inteiras, sem alterar o vetor original.
 */

#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Inicializamos ambos os ponteiros no ponto de partida (índice 0)
        int slow = nums[0];
        int fast = nums[0];

        // Fase 1: Encontrar o ponto de encontro dentro do ciclo.
        // O loop 'do-while' garante a primeira execução antes da verificação da igualdade.
        do
        {
            slow = nums[slow];           // Avança 1 passo: slow = f(slow)
            fast = nums[nums[fast]];     // Avança 2 passos: fast = f(f(fast))
        } while (fast != slow);

        // Fase 2: Encontrar o início do ciclo (o número duplicado).
        // Reinicia o ponteiro lento para a origem do vetor
        slow = nums[0];

        // Move ambos na mesma velocidade (1 passo por vez).
        // O ponto exato de intersecção será o nó onde o ciclo começa, ou seja, o número repetido.
        while (fast != slow)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow; // Retorna o elemento duplicado
    }
};
