/*
Given a list of non negative integers, arrange them such that they form the largest number.

Note
 The result may be very large, so you need to return a string instead of an integer.

Example
Given [1, 20, 23, 4, 8], the largest formed number is 8423201.

Tags Expand 
Sort
*/

bool str_cmp (string a, string b) {
    return (a+b < b+a);
}

class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        // write your code here
        vector<string> num_copy;
        string res;
        for(int e : num)
            num_copy.push_back(num2str(e));
            
        sort(num_copy.begin(), num_copy.end(), str_cmp);
        for(int i = num_copy.size() - 1; i >= 0 ; i--)
            res+=num_copy[i];
        if(res.size() > 1 && res[0] == '0')
            return "0";
        else
            return res;
    }

    string num2str(int a){
        string s;
        do{
            s.push_back((a%10) + '0');
            a/=10;
        }while(a);
        reverse(s.begin(), s.end());
        return s;
    }
};
