/**
 * Problema: LeetCode 424 - Longest Repeating Character Replacement
 * Link: https://leetcode.com/problems/longest-repeating-character-replacement/
 * * Complexidade de Tempo: O(N) - Onde N é o comprimento da string 's'.
 * Cada caractere é visitado no máximo duas vezes: uma pelo ponteiro 'right' (expandindo)
 * e outra pelo ponteiro 'left' (encolhendo).
 * * Complexidade de Espaço: O(1) - Memória estritamente constante. O array 'freq' possui
 * tamanho fixo de 128 (cobrindo a tabela ASCII), independente do tamanho da string de entrada.
 */

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[128] = {0}; // Tabela de frequências para caracteres ASCII
        int max_len = 0;     // Armazena o comprimento máximo da substring válida
        int maxFreq = 0;     // Rastreia a maior frequência de um único caractere vista na janela
        int left = 0;

        for (int right = 0; right < s.size(); right++)
        {
            // Adiciona o caractere atual à contagem da janela
            freq[s[right]]++;

            // Atualiza a frequência máxima histórica detectada
            maxFreq = max(maxFreq, freq[s[right]]);

            // Se o número de caracteres que precisamos mudar na janela atual for maior que k,
            // significa que a janela é inválida. Encolhemos a janela pela esquerda.
            while ((right - left + 1) - maxFreq > k)
            {
                freq[s[left]]--;
                left++;
            }

            // Atualiza o comprimento máximo da substring encontrada
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};
