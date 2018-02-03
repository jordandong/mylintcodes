/*
Given the prime number n, output the number of prime numbers

 Notice
n <= 100000
The prime number is defined as a natural number greater than 1, and there are no other factors except 1 and it itself.
Have you met this question in a real interview? Yes
Example
Given n = 3, return 2.

explanation:
[2,3,5], 3 is the second prime number.
Given n = 11, return 5.

explanation:
[2,3,5,7,11], 11 is the fifth prime number.
*/

class Solution {
public:
    /**
     * @param n: the number
     * @return: the rank of the number
     */
    int kthPrime(int n) {
        // write your code here
        bool *prime = new bool[100001];
        memset(prime, true, 100001);
        int limit = sqrt(100001);
        int cnt = 0;
        for(int i = 2; i <= limit; i++) {
            if (prime[i]) {
                for(int j = i * i; j <= n; j += i)
                    prime[j] = false;
            }
        }
        for (int i = 2; i < 100001; i++) {
            if (prime[i])
                cnt++;
            if (i == n)
                return cnt;
        }
        delete prime;
        return cnt;
    }
};
