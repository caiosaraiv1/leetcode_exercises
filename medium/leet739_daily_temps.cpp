/**
 * Problema: LeetCode 739 - Daily Temperatures
 * Link: https://leetcode.com/problems/daily-temperatures/
 * * Complexidade de Tempo: O(N) - Onde N é o número de elementos no vetor 'temperatures'.
 * Embora exista um loop 'while' dentro do 'for', cada índice é inserido na pilha exatamente
 * uma vez e removido dela no máximo uma vez ao longo de todo o algoritmo. Isso resulta em
 * um tempo de execução linear amortizado.
 * * Complexidade de Espaço: O(N) - Memória necessária para a nossa 'std::stack'. No pior caso
 * (temperaturas em ordem estritamente decrescente), todos os índices serão empilhados e nenhum
 * será removido até o fim do loop.
 */

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Inicializa o vetor de respostas preenchido com 0.
        // Dias que não encontrarem uma temperatura maior permanecerão com 0 automaticamente.
        vector<int> respostas(temperatures.size(), 0);
        stack<int> pilha; // Pilha monotônica que armazenará os ÍNDICES dos dias

        for (int i = 0; i < temperatures.size(); i++)
        {
            int tempAtual = temperatures[i];

            // Enquanto a temperatura atual for maior que a temperatura do índice no topo da pilha,
            // encontramos o próximo dia mais quente para o dia correspondente ao topo.
            while (!pilha.empty() && tempAtual > temperatures[pilha.top()])
            {
                int indiceAntigo = pilha.top();
                respostas[indiceAntigo] = i - indiceAntigo; // Calcula a diferença de dias
                pilha.pop();                                // Remove o dia resolvido
            }

            // Empilha o índice do dia atual para que ele espere pelo seu próximo dia mais quente
            pilha.push(i);
        }

        return respostas;
    }
};
