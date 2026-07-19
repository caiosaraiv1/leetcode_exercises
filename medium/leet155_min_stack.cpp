/**
 * Problema: LeetCode 155 - Min Stack
 * Link: https://leetcode.com/problems/min-stack/
 * * Complexidade de Tempo:
 * - push(), pop(), top(), getMin(): Tudo O(1) - Todas as operações utilizam métodos
 * de fim de vetor (push_back e pop_back), que operam em tempo constante amortizado.
 * * Complexidade de Espaço: O(N) - Onde N é o número de elementos inseridos. No pior caso,
 * mantemos duas estruturas de tamanho idêntico na memória Heap.
 */

#include <vector>
#include <algorithm>

using namespace std;

class MinStack {
private:
    vector<int> pilha;    // Pilha principal para armazenar todos os valores
    vector<int> minimos;  // Pilha auxiliar para rastrear o histórico de mínimos

public:
    MinStack() {
        // Construtor padrão (os vetores já são inicializados vazios automaticamente)
    }

    void push(int value) {
        pilha.push_back(value);

        // Se a pilha de mínimos não estiver vazia, compara o novo valor com o mínimo atual
        if (!minimos.empty()) {
            minimos.push_back(min(value, minimos.back()));
        } else {
            // Caso seja o primeiro elemento, ele é obrigatoriamente o menor
            minimos.push_back(value);
        }
    }

    void pop() {
        // Mantém as duas pilhas perfeitamente sincronizadas em tamanho e histórico
        pilha.pop_back();
        minimos.pop_back();
    }

    int top() {
        return pilha.back();
    }

    int getMin() {
        return minimos.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
