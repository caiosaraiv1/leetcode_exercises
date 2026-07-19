/**
 * Problema: LeetCode 1456 - Maximum Number of Vowels in a Substring of Given Length
 * Link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
 * * Complexidade de Tempo: O(N) - Onde N é o comprimento da string 's'.
 * O primeiro loop processa os K primeiros caracteres. O segundo loop percorre o restante
 * da string realizando apenas operações constantes O(1) de checagem de caractere.
 * * Complexidade de Espaço: O(1) - Memória estritamente constante, pois usamos apenas
 * variáveis locais para contagem e controle de índices.
 */

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Função auxiliar para verificar se um caractere é uma vogal minúscula
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int num = 0;

        // Passo 1: Conta as vogais presentes na primeira janela de tamanho fixo 'k'
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) num++;
        }

        int numMax = num; // Rastreia o recorde máximo de vogais encontrado

        // Passo 2: Desloca a janela ao longo do restante da string
        for (int i = k; i < s.size(); i++) {
            // Se o caractere que está saindo da janela (pela esquerda) for uma vogal, decrementa
            if (isVowel(s[i - k])) num--;

            // Se o novo caractere que está entrando na janela (pela direita) for uma vogal, incrementa
            if (isVowel(s[i])) num++;

            // Atualiza o recorde máximo de vogais em uma única janela
            numMax = max(numMax, num);
        }

        return numMax;
    }
};
