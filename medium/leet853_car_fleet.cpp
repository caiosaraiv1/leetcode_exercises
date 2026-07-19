/**
 * Problema: LeetCode 853 - Car Fleet
 * Link: https://leetcode.com/problems/car-fleet/
 * * Complexidade de Tempo: O(N log N) - Onde N é o número total de carros.
 * O cálculo dos tempos leva O(N). A ordenação do vetor de pares consome O(N log N).
 * O loop subsequente que manipula a pilha percorre os elementos de forma estritamente linear O(N).
 * * Complexidade de Espaço: O(N) - Memória alocada para o vetor 'carros' contendo os pares
 * de posição/tempo e para a estrutura de 'std::stack'.
 */

#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        // Armazena o par: {posição_inicial, tempo_até_o_destino}
        vector<pair<int, double>> carros;
        carros.reserve(n);

        // Passo 1: Calcula o tempo isolado de cada carro e monta o vetor (Tempo: O(N))
        for (int i = 0; i < n; i++)
        {
            double tempo = (double)(target - position[i]) / speed[i];
            carros.push_back({position[i], tempo});
        }

        // Passo 2: Ordena os carros pela posição inicial de forma DECRESCENTE (Tempo: O(N log N))
        // Processamos do carro mais próximo do destino para o mais distante.
        sort(carros.rbegin(), carros.rend());

        stack<double> pilha; // Guarda o tempo limite do líder de cada frota

        // Passo 3: Avalia a formação de frotas de frente para trás (Tempo: O(N))
        for (int i = 0; i < n; i++)
        {
            double tempo_atual = carros[i].second;

            // Se a pilha estiver vazia ou se o carro de trás demorar MAIS tempo do que o
            // líder da frota da frente, ele não conseguirá alcançá-lo. Cria uma nova frota.
            if (pilha.empty() || tempo_atual > pilha.top())
            {
                pilha.push(tempo_atual);
            }
            // Caso contrário (tempo_atual <= pilha.top()), o carro de trás alcança o da frente
            // e passa a fazer parte da mesma frota (o tempo do líder da frente se mantém estável).
        }

        // O tamanho da pilha corresponde exatamente ao número total de frotas independentes
        return pilha.size();
    }
};
