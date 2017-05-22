/*
Suppose we abstract our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string
"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:
dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1.
subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system.
For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system.
If there is no file in the system, return 0.

Notice
1. The name of a file contains at least a . and an extension.
2. The name of a directory or sub-directory will not contain a ..
3. Time complexity required: O(n) where n is the size of the input string.
4. Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.

Example
Give input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" return 20

Tags 
Google
*/

class Solution {
public:
    /**
     * @param input an abstract file system
     * @return return the length of the longest absolute path to file
     */
    int lengthLongestPath(string& input) {
        // Write your code here
        if (input.length() == 0)
            return 0;
        input.push_back('\n');
        size_t max_len = 0;
        unordered_map<int, int> path_len;
        path_len[0] = 0;

        for (auto i = input.find("\n"), prev_i = 0ul;
             i != string::npos;
             prev_i = i + 1, i = input.find("\n", i + 1)) {

            const auto line = input.substr(prev_i, i - prev_i);
            const auto name = line.substr(line.find_first_not_of("\t"));
            const auto depth = line.length() - name.length();

            if (name.find('.') != string::npos) {
                max_len = max(max_len, path_len[depth] + name.length());
            } else {
                //update current depth length, must have dir first then file
                path_len[depth + 1] = path_len[depth] + name.length() + 1;
            }
        }
        return max_len;
    }
};
