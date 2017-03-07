/*
Merge two given sorted integer array A and B into a new sorted integer array.

Have you met this question in a real interview? Yes
Example
A=[1,2,3,4]
B=[2,4,5,6]
return [1,2,2,3,4,4,5,6]

Challenge 
How can you optimize your algorithm if one array is very large and the other is very small?

Tags 
Sorted Array Array
*/

class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        int mx_sz = A.size()>=B.size()?A.size():B.size();
        int mi_sz = A.size()<B.size()?A.size():B.size();
        vector<int> &MX = A.size()>=B.size()?A:B;
        vector<int> &MI = A.size()<B.size()?A:B;
        vector<int> res(mx_sz + mi_sz);
        int i = mx_sz-1, j = mi_sz -1, k = mx_sz + mi_sz - 1;
        copy(MX.begin(), MX.end(), res.begin());
        while(i>=0 && j>=0){
            if(res[i]>MI[j]){
                res[k] = res[i];
                i--;
                k--;
            }else{
                res[k] = MI[j];
                j--;
                k--;
            }
        }
        
        while(j>=0){
            res[k] = MI[j];
            j--;
            k--;
        }
        
        return res;
    }
};
