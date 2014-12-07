/*
Binary search is a famous question in algorithm.

For a given sorted array (ascending order) and a target number, find the first index of this number in O(log n) time complexity.

If the target number does not exist in the array, return -1.

Example
If the array is [1, 2, 3, 3, 4, 5, 10], for given target 3, return 2.

Challenge Expand 
If the count of numbers is bigger than MAXINT, can your code work properly?

Tags Expand 
Binary Search
*/

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int lo = 0;
        int hi = array.size()-1;
        
        while(lo<=hi){
            int mid = lo + (hi - lo)/2;
            if(array[mid] == target){
                if(lo == hi)
                    return lo;
                hi = mid;
                continue;
            }
            if(array[mid] > target){
                hi = mid -1;
                continue;
            }
            if(array[mid] < target){
                lo = mid +1;
                continue;
            }
        }
        
        return -1;
    }
};
