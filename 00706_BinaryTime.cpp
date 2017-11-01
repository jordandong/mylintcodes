/*
Given a watch with a binary display time and a non-negative integer n which represents the number of 1s on a given timetable, return all possible time.

 Notice

The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

Example
Given n = 1
Return ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
*/

class Solution {
public:
    /*
     * @param : the number of "1"s on a given timetable
     * @return: all possible time
     */
    vector<string> binaryTime(int num) {
        // Write your code here
        vector<string> res;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (bit_count(h) + bit_count(m) == num) {
                    const auto hour = to_string(h);
                    const auto minute = m < 10 ? "0" + to_string(m) : to_string(m);
                    res.push_back(hour + ":" + minute);
                }
            }
        }
        return res;
    }

private:
    int bit_count(int bits) {
        int count = 0;
        while (bits) {
            bits &= bits - 1;
            ++count;
        }
        return count;
    }
};
