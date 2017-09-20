/*
Given a list of integers and find the smallest prime number that doesn't appear in this list.

Example
Given a list [2,3,5,7,11,13,17,23,29]
return 19

Tags 
Enumeration
*/

//looks the question assume all elements are prime and sorted
class Solution {
public:
    /*
     * @param : an array of integer
     * @return: the first missing prime number
     */
    int firstMissingPrime(vector<int> nums) {
        // write your code here
        int N = nums.size();
        if (N == 0)
            return 2;
        int m = 2 * nums.back() + 1;
        vector<bool> prime (m , true);
        int limit = sqrt(m);
        //find all prime numbers under m + 1
        for(int i = 2; i <= limit; i++) {
            if(prime[i]){
              for(int j = i * i; j <= m; j += i)
                  prime[j] = false;
            }
        }
        
        for (auto e : nums)
            prime[e] = false;
        
        for (int i = 2; i < m; i++)
            if (prime[i])
                return i;
        return m;
    }
};
