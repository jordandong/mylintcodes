/*
Given an array of integers, how many three numbers can be found in the array, so that we can build an triangle whose three edges length is the three numbers that we find?

Example
Given array S = [3,4,6,7], return 3. They are:
[3,4,6]
[3,6,7]
[4,6,7]

Given array S = [4,4,4,4], return 4. They are:
[4(1),4(2),4(3)]
[4(1),4(2),4(4)]
[4(1),4(3),4(4)]
[4(2),4(3),4(4)]

Tags Expand 
Two Pointers LintCode Copyright
*/

class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        int N = S.size();
        if (N == 0)
            return 0;
        int res = 0;
        sort(S.begin(), S.end());
        for (int k = N - 1; k >= 0; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                    if (S[i] + S[j] <= S[k]) {
                        i++;
                    } else {
                        res += j - i;
                        j--;
                    }
            }
        }
        return res;
    }
};

class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        int N = S.size();
        if (N == 0)
            return 0;
        int res = 0;
        sort(S.begin(), S.end());
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int twosum = S[i] + S[j];
                for (int k = N - 1; k > j; k--) {
                    if (twosum > S[k]) {
                        res += k - j;
                        break;
                    }
                }
            }
        }
        return res;
    }
};
