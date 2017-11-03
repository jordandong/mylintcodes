/*
Given two numbers n and k. We need to find out if n can be written as sum of k prime numbers.

 Notice

n <= 10 ^ 9

Goldbach's conjecture

Have you met this question in a real interview? Yes
Example
Given n = 10, k = 2
Return true   // 10 = 5 + 5

Given n = 2, k = 2
Return false
Tags 
Mathematics
*/

/*
The idea is to use Goldbach’s conjecture,
which says that every even integer (greater than 2) can be expressed as sum of two primes.

If the N = 2K and K = 1 : 
  The answer will be Yes iff N is a prime number
If N >= 2K and K = 2 :
  If N is an even number answer will be Yes(Goldbach’s conjecture)
  If N is odd answer will be No if N-2 is not a prime number and Yes if N-2 is a prime number.
  This is because we know odd + odd = even and even + odd = odd.
  So when N is odd, and K = 2 one number must be 2 as it is the only even prime number.
  So now the answer depends whether N-2 is odd or not.
If N >= 2K and K >= 3 : 
  Answer will always be Yes.
  When N is even N – 2*(K-2) is also even so N – 2*(K – 2) can be written as sum of two prime numbers p, q.
  N can be written as 2, 2 …..K – 2 times, p, q.
  When N is odd N – 3 -2*(K – 3) is even so it can be written as sum of two prime numbers p, q.
  N can be witten as 2, 2 …..K-3 times, 3, p, q
*/

class Solution {
public:
    /*
     * @param : an int
     * @param : an int
     * @return: if N can be expressed in the form of sum of K primes, return true; otherwise, return false.
     */
    bool isSumOfKPrimes(int n, int k) {
        // write your code here
        // N < 2K directly return false
        if (n < k * 2)
            return false;
            
        // If k = 1 return value depends on primality of N
        if (k == 1)
            return isPrime(n);
 
        if (k == 2) {
            // if N is even directly return true;
            if (n % 2 == 0)
                return true;
 
            // If N is odd, then one prime must be 2.
            //All other primes are odd and cannot have a pair sum as even.
            return isPrime(n - 2);
        }
        // If k >= 3 return true;
        return true;
    }

private:    
    // Checking if a number is prime or not
    bool isPrime(int x) {
        // check for numbers from 2 to sqrt(x)
        // if it is divisble return false
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0)
                return false;
        return true;
    }
};
