/*
Given an array A of integer with size of n( means n books and number of pages of each book) and k people to copy the book. You must distribute the continuous id books to one people to copy. (You can give book A[1],A[2] to one people, but you cannot give book A[1], A[3] to one people, because book A[1] and A[3] is not continuous.) Each person have can copy one page per minute. Return the number of smallest minutes need to copy all the books.

Have you met this question in a real interview? Yes

Example
Given array A = [3,2,4], k = 2.
Return 5( First person spends 5 minutes to copy book 1 and book 2 and second person spends 4 minutes to copy book 3. )

Challenge
Could you do this in O(n*k) time ?
*/

//T: O(N * log(sum of pages)), S: O(1)
class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        int sum = 0;
        int min_res = -1, max_res = -1;
        
        if (k >= pages.size()) {
            for (auto& p : pages)
                min_res = max(min_res, p);
            return min_res;
        }

        for (auto& p : pages)
            sum += p;

        min_res = sum / k;
        max_res = sum;
        while (min_res <= max_res) {
            int mid_res = min_res + (max_res - min_res) / 2;
            if (is_solution(pages, k, mid_res)) {
                max_res = mid_res - 1;
            } else {
                min_res = mid_res + 1;
            }
        }
        return min_res;
    }

    bool is_solution(vector<int> &pages, int k, int mid_res) {
        int sum = 0;
        int count = 1;
        for (int i = 0; i < pages.size() && count <= k; i++) {
            if (sum + pages[i] > mid_res) {
                sum = 0;
                ++count;
            }
            sum += pages[i];
        }
        return  count <= k;
    }
};
