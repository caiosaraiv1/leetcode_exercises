/**
 * Problema: LeetCode 20 - Valid Parentheses
 * Link: https://leetcode.com/problems/valid-parentheses/
 * * Complexidade de Tempo: O(N) - Onde N é o comprimento da string 's'.
 * Percorremos a string uma única vez, e as operações da pilha (push, pop, top)
 * possuem complexidade de tempo constante O(1).
 * * Complexidade de Espaço: O(N) - No pior caso (por exemplo, uma string composta apenas
 * por caracteres de abertura como "(((((("), empilharemos todos os N caracteres na pilha.
 */

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool eh_abertura(char c) { return c == '(' || c == '{' || c == '['; }

    bool eh_fechamento(char c) { return c == ')' || c == '}' || c == ']'; }

    bool eh_par(char a, char f)
    {
        if ((a == '(' && f == ')') ||
            (a == '{' && f == '}') ||
            (a == '[' && f == ']'))
            return true;
        else
            return false;
    }

    bool isValid(string s) {
        stack<char> pilha;

        for (const auto& c : s)
        {
            if (eh_abertura(c))
                pilha.push(c);

            if (eh_fechamento(c))
            {
                if (pilha.empty())
                    return false;
                else if (!eh_par(pilha.top(), c))
                    return false;
                else
                    pilha.pop();
            }
        }

        if (!pilha.empty()) return false;

        return true;
    }
};
