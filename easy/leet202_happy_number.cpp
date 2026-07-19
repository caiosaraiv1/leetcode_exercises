/**
 * Problema: LeetCode 202 - Happy Number
 * Link: https://leetcode.com/problems/happy-number/
 * * Complexidade de Tempo: O(log N) - O custo de processar os dígitos de um número
 * é proporcional ao número de dígitos dele, que é O(log N). O número de passos na
 * sequência antes de cair no ciclo ou chegar a 1 é provado matematicamente como sendo muito pequeno.
 * * Complexidade de Espaço: O(1) - Memória estritamente constante. Ao usar a técnica de dois
 * ponteiros (slow e fast) para detectar o ciclo, você elimina a necessidade de armazenar o histórico em um hash set.
 */

class Solution {
public:
    // Função auxiliar para calcular a soma dos quadrados dos dígitos
    int get_next(int n) {
        int soma_total = 0;

        while (n > 0)
        {
            int digito = n % 10;
            soma_total += digito * digito;
            n /= 10;
        }

        return soma_total;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        // O ponteiro rápido avança duas interações à frente.
        // O loop quebra se o fast (ou o próximo passo dele) encontrar o número 1 (número feliz).
        while (fast != 1 && get_next(fast) != 1)
        {
            slow = get_next(slow);            // Anda 1 passo na sequência
            fast = get_next(get_next(fast));  // Anda 2 passos na sequência

            // Se o ponteiro rápido e o lento se encontrarem, entramos em um ciclo infinito.
            // Logo, o número não é feliz.
            if (slow == fast) return false;
        }

        return true;
    }
};
