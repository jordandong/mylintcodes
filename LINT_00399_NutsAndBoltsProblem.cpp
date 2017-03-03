/*
Given a set of n nuts of different sizes and n bolts of different sizes. There is a one-one mapping between nuts and bolts. Comparison of a nut to another nut or a bolt to another bolt is not allowed. It means nut can only be compared with bolt and bolt can only be compared with nut to see which one is bigger/smaller.
We will give you a compare function to compare nut with bolt.

Have you met this question in a real interview? Yes

Example
Given nuts = ['ab','bc','dd','gg'], bolts = ['AB','GG', 'DD', 'BC'].
Your code should find the matching bolts and nuts.
one of the possible return:
nuts = ['ab','bc','dd','gg'], bolts = ['AB','BC','DD','GG'].

we will tell you the match compare function. If we give you another compare function.
the possible return is the following:
nuts = ['ab','bc','dd','gg'], bolts = ['BC','AA','DD','GG'].
So you must use the compare function that we give to do the sorting.
The order of the nuts or bolts does not matter. You just need to find the matching bolt for each nut.

Tags Expand 
Quick Sort Sort
*/

/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    enum { 
        SMALLER = -1,
        EQUAL = 0,
        BIGGER = 1,
        INVALID = 2
    };

    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        int M = nuts.size();
        int N = bolts.size();
        if (M == 0 || N == 0 || M != N)
            return;
        quickSort(nuts, bolts, 0, M - 1, compare);
    }

    void quickSort(vector<string> &nuts, vector<string> &bolts, int l, int r, Comparator &compare) {
        if (r < l)
            return;
        int pivot = partition(nuts, l, r, bolts[r], compare); //take the last as pivot
        partition(bolts, l, r, nuts[pivot], compare); //using returned pivot in last step
        
        quickSort(nuts, bolts, l, pivot - 1, compare);
        quickSort(nuts, bolts, pivot + 1, r, compare);
    }

    int partition(vector<string> &data, int l, int r, string &pivot, Comparator &compare) {
        int i = l;
        while (i < r) {
            if (compare.cmp(data[i], pivot) == SMALLER || (compare.cmp(data[i], pivot) == INVALID && compare.cmp(pivot, data[i]) == BIGGER)) { //smaller
                swap(data[i++], data[l++]);
            } else if (compare.cmp(data[i], pivot) == BIGGER || (compare.cmp(data[i], pivot) == INVALID && compare.cmp(pivot, data[i]) == SMALLER)) { //bigger
                i++;
            } else {
                if (data[i] == data[r])
                    i++;
                else
                    swap(data[i], data[r]);//set the last as the equal case
            }
        }
        swap(data[l], data[r]); //make pivot at l index the ending of left part
        return l;
    }
};
