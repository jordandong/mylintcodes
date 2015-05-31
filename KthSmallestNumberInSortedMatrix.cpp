/*
Find the kth smallest number in at row and column sorted matrix.
Have you met this question in a real interview? Yes

Example
Given k = 4 and a matrix:
[
  [1 ,5 ,7],
  [3 ,7 ,8],
  [4 ,8 ,9],
]
return 5

Challenge
O(k log n), n is the maximal number in width and height.

Tags Expand 
Heap Matrix
*/

//T:O(klog(min(min(M, N), k))) S:O(log(min(min(M, N), k)))
struct min_heap {
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        return a.first > b.first;
    }
};

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        // write your code here
        int M = matrix.size();
        if (M == 0)
            return -1;
        int N = matrix[0].size();
        if (N == 0 || k > M*N)
            return -1;
            
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int> > >,  min_heap> mh;
        //could use balanced BST as well
        
        if (M <= N) {
            for (int i = 0; i < min(M, k); i++)
                mh.push(pair<int, pair<int, int> >{matrix[i][0], {i, 0} });
            
            while (0 < k-- && mh.size()) {
                if (k == 0)
                    return mh.top().first;
                int i = mh.top().second.first;
                int j = mh.top().second.second;
                mh.pop();
                if(j + 1 < N)
                    mh.push(pair<int, pair<int, int> >{matrix[i][j + 1], {i, j + 1} });
            }
        } else {
            for (int j = 0; j < min(N, k); j++)
                mh.push(pair<int, pair<int, int> >{matrix[0][j], {0, j} });
            
            while (0 < k-- && mh.size()) {
                if (k == 0)
                    return mh.top().first;
                int i = mh.top().second.first;
                int j = mh.top().second.second;
                mh.pop();
                if(i + 1 < M)
                    mh.push(pair<int, pair<int, int> >{matrix[i + 1][j], {i + 1, j} });
            }
        }
    }
};
