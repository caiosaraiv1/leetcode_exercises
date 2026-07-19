/**
 * Problema: LeetCode 11 - Container With Most Water
 * Link: https://leetcode.com/problems/container-with-most-water/
 * * Complexidade de Tempo: O(N) - Onde N é o número de elementos no vetor 'height'.
 * Os ponteiros 'left' e 'right' começam nas extremidades e se movem um em direção ao outro.
 * Cada elemento é avaliado no máximo uma vez, resultando em uma única passada.
 * * Complexidade de Espaço: O(1) - Memória estritamente constante. A análise é feita
 * diretamente sobre o vetor de entrada utilizando apenas variáveis auxiliares para armazenar os índices e as áreas.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        // Calcula a área inicial com a largura máxima
        int maxArea = (right - left) * std::min(height[left], height[right]);

        while (left < right)
        {
            // Move sempre o ponteiro que aponta para a menor altura,
            // pois ele é o fator limitante para o cálculo da área.
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }

            // Calcula a nova área e atualiza o máximo se necessário
            int newArea = (right - left) * std::min(height[left], height[right]);
            maxArea = std::max(maxArea, newArea);
        }

        return maxArea;
    }
};
