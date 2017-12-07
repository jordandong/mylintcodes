/*
Given a boolean expression with following symbols.

Symbols
    'T' ---> true 
    'F' ---> false 
And following operators filled between symbols

Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR 
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Let the input be in form of two arrays one contains the symbols (T and F) in order and other contains operators (&, | and ^}

Example
Given symbol = ['T', 'F', 'T'], operator = ['^', '&']
return 2
The given expression is "T ^ F & T", it evaluates true, in two ways "((T ^ F) & T)" and "(T ^ (F & T))"

given symbol = ['T', 'F', 'F'], operator = ['^', '|']
return 2
The given expression is "T ^ F | F", it evaluates true, in two ways "( (T ^ F) | F )" and "( T ^ (F | F) )".
Tags 
Dynamic Programming Google
*/

class Solution {
public:
    /*
     * @param symb: the array of symbols
     * @param oper: the array of operators
     * @return: the number of ways
     */
    int countParenth(string &symb, string &oper) {
        // write your code here
        int n = symb.length();
        int F[n][n], T[n][n];
        
        // Fill diaginal entries first
        // All diagonal entries in T[i][i] are 1 if symbol[i] is T (true).
        // Similarly, all F[i][i] entries are 1 if symbol[i] is F (False)
        for (int i = 0; i < n; i++) {
            F[i][i] = (symb[i] == 'F') ? 1: 0;
            T[i][i] = (symb[i] == 'T') ? 1: 0;
        }
        
        // Now fill T[i][i+1], T[i][i+2], T[i][i+3]... in order
        // And F[i][i+1], F[i][i+2], F[i][i+3]... in order
        for (int gap = 1; gap < n; ++gap) {
            for (int i = 0, j = gap; j < n; ++i, ++j) {
                T[i][j] = F[i][j] = 0;
                for (int g = 0; g < gap; g++) {
                    // Find place of parenthesization using current value of gap
                    int k = i + g;
                    // Store Total[i][k] and Total[k+1][j]
                    int tik = T[i][k] + F[i][k];
                    int tkj = T[k + 1][j] + F[k + 1][j];
 
                    // Follow the recursive formulas according to the current
                    // operator
                    if (oper[k] == '&') {
                        T[i][j] += T[i][k] * T[k + 1][j];
                        F[i][j] += (tik * tkj - T[i][k] * T[k + 1][j]);
                    }
                    if (oper[k] == '|') {
                        F[i][j] += F[i][k] * F[k + 1][j];
                        T[i][j] += (tik * tkj - F[i][k] * F[k + 1][j]);
                    }
                    if (oper[k] == '^') {
                        T[i][j] += F[i][k] * T[k + 1][j] + T[i][k] * F[k + 1][j];
                        F[i][j] += T[i][k] * T[k + 1][j] + F[i][k] * F[k + 1][j];
                    }
                }
            }
        }
        return T[0][n-1];
    }
};
