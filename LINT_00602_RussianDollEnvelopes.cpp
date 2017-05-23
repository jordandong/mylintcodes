/*
You have a number of envelopes with widths and heights given as a pair of integers (w, h).
One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], 
the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Tags 
Binary Search Dynamic Programming Facebook
*/

//O(NlogN), O(N)
class Solution {
public:
    /**
     * @param envelopes a number of envelopes with widths and heights
     * @return the maximum number of envelopes
     */
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        // Write your code here
        int N = envelopes.size();
        vector<int> candidates;
        sort(envelopes.begin(), envelopes.end(),
            [](pair<int, int> i, pair<int, int> j) {
                if (i.first == j.first)
                    return i.second > j.second;
                return i.first < j.first;});
        for (int i = 0; i < N; i++) {
            int lo = 0, hi = candidates.size() - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo)/2;
                if (envelopes[i].second > envelopes[candidates[mid]].second)
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            if (lo == candidates.size())
                candidates.push_back(i);
            else
                candidates[lo] = i;
        }
        return candidates.size();
    }
};

//O(N^2), O(N), LTE
class Solution {
public:
    /**
     * @param envelopes a number of envelopes with widths and heights
     * @return the maximum number of envelopes
     */
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        // Write your code here
        sort(envelopes.begin(), envelopes.end(),
            [](pair<int, int> i, pair<int, int> j) {
                if (i.first == j.first)
                    return i.second < j.second;
                return i.first < j.first;});
        int N = envelopes.size();
        vector<int> dp(N, 1);
        int mx = (N == 0) ? 0 : 1;
        for (int i = 0; i < N; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    mx = max(dp[i], mx);
                }
            }
        }
        return mx;
    }
};
