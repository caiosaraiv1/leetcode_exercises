/**
 * Problema: LeetCode 3 - Longest Substring Without Repeating Characters
 * Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * * Complexidade de Tempo: O(N) - Onde N é o tamanho da string 's'. Embora haja um loop
 * while interno, cada caractere é visitado no máximo duas vezes: uma pelo ponteiro 'right'
 * e outra pelo ponteiro 'left'.
 * * Complexidade de Espaço: O(1) - Memória constante. O array 'visited' possui tamanho fixo de 128,
 * independente do tamanho da string de entrada.
 */

#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;

        // Inicializa explicitamente com false para evitar lixo de memória
        bool visited[128] = {false};
        int max_substring = INT_MIN;
        int left = 0;

        for (int right = 0; right < s.size(); right++)
        {
            char c = s[right];

            // Se o caractere já foi visto na janela atual, encolhe a janela pela esquerda
            while (left <= right && visited[c])
            {
                visited[s[left]] = false;
                left++;
            }

            // Marca o caractere atual como visitado e expande a janela
            visited[c] = true;

            // Calcula o tamanho da janela atual (right - left + 1) e atualiza o máximo
            max_substring = std::max(max_substring, right - left + 1);
        }

        return max_substring;
    }
};
