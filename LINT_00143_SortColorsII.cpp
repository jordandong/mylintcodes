/*
Given an array of n objects with k different colors (numbered from 1 to k), sort them so that objects of the same color are adjacent, with the colors in the order 1, 2, ... k.

Note
You are not suppose to use the library's sort function for this problem.

Example:
GIven colors=[3, 2, 2, 1, 4], k=4, your code should sort colors in-place to [1, 2, 2, 3, 4]. 

Challenge:
A rather straight forward solution is a two-pass algorithm using counting sort. That will cost O(k) extra memory.

Can you do it without using extra memory?
*/

class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        //T: O(nlogn) S : O(1)
        //sort(colors.begin(), colors.end());
        
        
        // write your code here
        //T : O(n), S : O(1)
        //Cannot pass two cases :
        //handle k > colors.size(). 
        //Also, assume each color must present at least once. Otherwise overwriting may happen.
        //These two cases cannot do it in place for this case
        int sz = colors.size();
        int i = 0;
        while(i < sz){
            int c = colors[i]-1;
            if(c>=0){
                if(colors[c]<=0){
                    colors[c]--;
                    colors[i++]=0;
                }else{
                    colors[i] = colors[c];
                    colors[c] = -1;
                }
            }else{
                i++;
            }
        }
        
        i = sz - 1;
        for(int j = sz-1; j>=0; j--){
            int num = colors[j];
            while(num<0){
                colors[i--] = j + 1;
                num++;
            }
        }
    }
};
