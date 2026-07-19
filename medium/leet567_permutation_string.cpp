/**
 * Problema: LeetCode 567 - Permutation in String
 * Link: https://leetcode.com/problems/permutation-in-string/
 * * Complexidade de Tempo: O(N) - Onde N é o comprimento da string 's2'.
 * A montagem inicial leva O(s1.size()). O loop subsequente corre o restante de 's2'
 * executando operações O(1) em cada iteração (o método 'iguais' leva tempo fixo de 128 passos).
 * * Complexidade de Espaço: O(1) - Memória estritamente constante. Os dois arrays
 * possuem tamanho fixo de 128, ocupando o mesmo espaço em qualquer cenário.
 */

#include <string>

using namespace std;

class Solution {
public:
    // Compara se as duas tabelas de frequência são idênticas em tempo O(1)
    bool iguais(const int (&a)[128], const int (&b)[128])
    {
        for (int i = 0; i < 128; i++)
        {
            if (a[i] != b[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        // Se s1 for maior que s2, é impossível uma permutação de s1 caber em s2
        if (s1.size() > s2.size()) return false;

        int freq1[128] = {0};
        int freq2[128] = {0};

        // Popula a tabela de s1 e inicializa a primeira janela de tamanho fixo em s2
        for (int right = 0; right < s1.size(); right++)
        {
            freq1[s1[right]]++;
            freq2[s2[right]]++;
        }

        // Verifica se a primeira janela já é uma permutação válida
        if (iguais(freq1, freq2)) return true;

        int left = 0;
        // Desloca a janela de tamanho fixo elemento por elemento ao longo de s2
        for (int right = s1.size(); right < s2.size(); right++)
        {
            freq2[s2[right]]++; // Inclui o novo caractere que entra pela direita
            freq2[s2[left]]--;  // Remove o caractere antigo que sai pela esquerda

            // Se o estado atual da janela bater com as frequências de s1, encontramos a permutação
            if (iguais(freq1, freq2)) return true;

            left++; // Avança a fronteira esquerda da janela
        }

        return false;
    }
};
