/*
Count the number of k's between 0 and n. k can be 0 - 9.

Example:
if n=12, in [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12], we have FIVE 1's (1, 10, 11, 12)
*/

/*    
e.g.
n = 123, k = 1;
base = 1,   a=12  (<120, 1's at pos 1),     digit=3 b=1(>=120, 1's at pos 1)
base = 10,  a=1*10(<100, 1's at pos 10),    digit=2 b=10(>=100, 1's at pos 10);
base = 100, a=0*100(<x000, 1's at pos 100), digit=1 b=23+1(>=x000, 1's at pos 100);
if k = 0, we ignore the start with 0 case, so minus 1
*/

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        int res = 0;
        int base = 1;
        while (base <= n){
            // caculate how many k's <(n/(base*10))*(base*10) at pos base
            int a = n/(base*10);
            if (base>1 && k==0 && a>0)
                a--;
            a*=base;

            //caculate how many k's >=(n/(base*10))*(base*10) at pos base
            int digit = (n/base)%10;
            int b = 0;
            if (k<digit)
                b = base;
            else if (k==digit)
                b = n%base + 1;
            if (k==0 && n<base*10)
                b = 0;

            res+=(a+b);
            base*=10;
        }
        return res;    
    }
};
