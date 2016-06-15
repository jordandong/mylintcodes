/*
Given two arrays of length m and n with digits 0-9 representing two numbers.
Create the maximum number of length k <= m + n from digits of the two.
The relative order of the digits from the same array must be preserved.
Return an array of the k digits. You should try to optimize your time and space complexity.

Example,
Given nums1 = [3, 4, 6, 5], nums2 = [9, 1, 2, 5, 8, 3], k = 5
return [9, 8, 6, 5, 3]

Given nums1 = [6, 7], nums2 = [6, 0, 4], k = 5
return [6, 7, 6, 0, 4]

Given nums1 = [3, 9], nums2 = [8, 9], k = 3
return [9, 8, 9]

Tags 
Greedy Dynamic Programming Google
*/

// Time:  O(m + n + k^2) ~ O(m + n + k^3)
// Space: O(k^2)
// DP + Greedy solution.
class Solution {
public:
    /**
     * @param nums1 an integer array of length m with digits 0-9
     * @param nums2 an integer array of length n with digits 0-9
     * @param k an integer and k <= m + n
     * @return an integer array
     */
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        const int m = nums1.size(), n = nums2.size();
        vector<vector<int>> max_numbers1(k + 1), max_numbers2(k + 1);
        maxNumberDP(nums1, max(0, k - n), min(k, m), max_numbers1); //O(m)
        maxNumberDP(nums2, max(0, k - m), min(k, n), max_numbers2); //O(n)

        vector<int> res(k);
        for (int i = max(0, k - n); i <= min(k, m); ++i) { //O(k)
            vector<int> tmp(k);
            merge(max_numbers1[i], max_numbers2[k - i], &tmp);
            if (tmp > res) { //O(k)
                res = move(tmp);
            }
        }
        return res;
    }

private:
    void maxNumberDP(vector<int> nums, int start, int end, vector<vector<int>> &max_numbers) {
        max_numbers[end] = maxNumber(nums, end); //O(m), O(n)
        for (int i = end - 1; i >= start; --i)
            max_numbers[i] = deleteNumber(max_numbers[i + 1]);//O(k)
    }

    vector<int> maxNumber(const vector<int>& nums, int k) { //O(m), O(n)
        vector<int> res;
        int drop = nums.size() - k;
        for (const auto& num : nums) {
            while (drop > 0 && !res.empty() && res.back() < num) {
                res.pop_back();
                --drop;
            }
            res.push_back(num);
        }
        res.resize(k);
        return res;
    }

    vector<int> deleteNumber(const vector<int> &nums) {
        vector<int> res(nums);
        for (int i = 0; i < res.size(); ++i) {
            if (i == res.size() - 1 || res[i] < res[i + 1]) {
                res.erase(res.begin() + i);
                break;
            }
        }
        return res;
    }

    void merge(const vector<int> &vec1, const vector<int> &vec2, vector<int> *res) {
        auto first1 = vec1.begin(), last1 = vec1.end(),
             first2 = vec2.begin(), last2 = vec2.end();
        auto result = res->begin();
        while (first1 != last1 || first2 != last2) {//O(k)
            if (greater(first1, last1, first2, last2)) {//O(k)
                *result++ = *first1++;
            } else {
                *result++ = *first2++;
            }
        }
    }

    template<typename IT>
    bool greater(IT first1, IT last1, IT first2, IT last2) {
        while (first1 != last1 && first2 != last2 && *first1 == *first2) {
            ++first1;
            ++first2;
        }
        return (first2 == last2) || (first1 != last1 && *first1 > *first2);
    }
};

class Solution {
public:
    /**
     * @param nums1 an integer array of length m with digits 0-9
     * @param nums2 an integer array of length n with digits 0-9
     * @param k an integer and k <= m + n
     * @return an integer array
     */

    //T : O(K*(m + n)^2) S : O(m + n)
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        // Write your code here
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> res;
        for (int k1 = max(k - n2, 0); k1 <= min(k, n1); ++k1) { //O(k)
            vector<int> res1 = maxNumberHelper1(nums1, k1); //O(n)
            vector<int> res2 = maxNumberHelper1(nums2, k - k1); //O(m)
            res = max(res, maxNumberHelper2(res1, res2)); //O((m + n)^2)
        }
        return res;
    }

    vector<int> maxNumberHelper1(vector<int> &nums, int k) {
        int drop = nums.size() - k;
        vector<int> res;
        for (int num : nums) {
            while (drop && res.size() && res.back() < num) {
                res.pop_back();
                drop--;
            }
            res.push_back(num);
        }
        res.resize(k);
        return res;
    }

    //O ((m+n)^2)
    vector<int> maxNumberHelper2(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        auto i1 = nums1.begin(), end1 = nums1.end();
        auto i2 = nums2.begin(), end2 = nums2.end();
        while (i1 != end1 || i2 != end2) {
            res.push_back(vector<int>(i1, end1) > vector<int>(i2, end2) ? *i1++ : *i2++);
        }
        return res;
    }
};
