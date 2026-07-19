/**
 * Problema: LeetCode 125 - Valid Palindrome
 * Link: https://leetcode.com/problems/valid-palindrome/
 * * Complexidade de Tempo: O(N) - Onde N é o comprimento da string 's'.
 * Cada caractere é visitado no máximo duas vezes pelos ponteiros 'left' e 'right'.
 * * Complexidade de Espaço: O(1) - Memória constante. A análise é feita diretamente
 * na string original, sem criar cópias filtradas ou usar memória extra.
 */

#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right)
        {
            // Avança o ponteiro da esquerda se não for alfanumérico
            while (left < right && !std::isalnum(static_cast<unsigned char>(s[left])))
                left++;

            // Recua o ponteiro da direita se não for alfanumérico
            while (left < right && !std::isalnum(static_cast<unsigned char>(s[right])))
                right--;

            // Compara os caracteres em lowercase
            if (
                std::tolower(static_cast<unsigned char>(s[left])) !=
                std::tolower(static_cast<unsigned char>(s[right]))
            ) return false;

            left++;
            right--;
        }

        return true;
    }
};
