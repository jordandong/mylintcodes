/*
Given a (decimal - e g  3.72) number that is passed in as a string,return the binary representation that is passed in as a string.
If the number can not be represented accurately in binary, print “ERROR”

Example:
n = 3.72, return ERROR
n = 3.5, return 11.1
*/

/*
Cannot understand this test case. It cannot be accurately represented.
Wrong Answer

Total Runtime: 15 ms
12 / 15 test cases passed.
Input
0.6418459415435791
Output
ERROR
Expected
0.1010010001010000000001
*/


class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        // wirte your code here
        string n1="", b1="",n2="", b2="";
        size_t npos = -1;
        size_t ret = n.find('.');
        string mod = "0";
        string ones = "0";
        if(ret == npos){
            n1 = n;
        }else{
            n1 = n.substr(0, ret);
            n2 = n.substr(ret);
            n2[0] = '0';
        }
        
        while(n1.size()){
            str_divide_mod(n1, mod);
            b1 = mod + b1;
        }

        if(ret == npos)
            return b1;
        
        int n2_sz = n2.size() - 1;
        int count = 0;
        while((n2.size() > 1)){
            if(count >= n2_sz)
                return "ERROR";
            str_multiple_getones(n2, ones);
            b2+=ones;
            count++;
        }
        while(b2[b2.length() - 1] == '0')
            b2.erase(b2.length() - 1);
        return b2.size()?b1+"."+b2:b1;
    }
    
    void str_divide_mod(string &n1, string &mod){
        int len = n1.length();
        mod = "0";
        for(int i = len-1; i>=0; i--){
            int num = n1[i] - '0';
            n1[i] = num/2 + '0';
            if(num%2 == 1){
                if(i < len - 1)
                    n1[i+1] +=  5;
                else
                    mod = "1";
            }
        }
        if(n1[0] == '0')
            n1.erase(0, 1);
    }
    
    void str_multiple_getones(string &n2, string &ones){
        int len = n2.length();
        int carry = 0;
        ones = "0";
        for(int i = len-1; i>=0; i--){
            int num = n2[i] - '0';
            num*=2;
            num+=carry;
            n2[i] = num + '0';
            carry = num/10;
        }
        if(n2[0] == '1'){
            ones = "1";
            n2[0] = '0';
        }
        if(n2[len - 1] == '0')
            n2.erase(len - 1);
    }
};
