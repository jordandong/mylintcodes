/*
Find top k frequent words with map reduce framework.

The mapper's key is the document id, value is the content of the document, words in a document are split by spaces.

For reducer, the output should be at most k key-value pairs, which are the top k words and their frequencies in this reducer.
The judge will take care about how to merge different reducers' results to get the global top k frequent words, so you don't need to care about that part.

The k is given in the constructor of TopK class.

Notice
For the words with same frequency, rank them with alphabet.

Example
Given document A =
lintcode is the best online judge
I love lintcode

and document B =
lintcode is an online judge for coding interview
you can test your code online at lintcode

The top 2 words and their frequencies should be
lintcode, 4
online, 3

Tags 
Map Reduce
*/

/**
 * Definition of Input:
 * template<class T>
 * class Input {
 * public:
 *     bool done(); 
 *         // Returns true if the iteration has elements or false.
 *     void next();
 *         // Move to the next element in the iteration
 *         // Runtime error if the iteration has no more elements
 *     T value();
 *        // Get the current element, Runtime error if
 *        // the iteration has no more elements
 * }
 * Definition of Document:
 * class Document {
 * public:
 *     int id; // document id
 *     string content; // document content
 * }
 */
class TopKFrequentWordsMapper: public Mapper {
public:
    void Map(Input<Document>* input) {
        // Write your code here
        // Please directly use func 'output' to output 
        // the results into output buffer.
        // void output(string &key, int value);
        while (!input->done()) {
            auto doc = input->value();
            string s = doc.content;
            int id = doc.id, start = 0;
            s += " ";
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == ' ') {
                    if (s[start] != ' ') {
                        string word = s.substr(start, i - start);
                        output(word, 1);
                    }
                    start = i + 1;
                }
            }
            input->next();
        }
    }
};

class cmp {
public:
    bool operator() (pair<int, string> &a, pair<int, string> &b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};

class TopKFrequentWordsReducer: public Reducer {
private:
    priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> q;
    int K;
public:
    void setUp(int k) {
        // initialize your data structure here
        K = k;
    }

    void Reduce(string &key, Input<int>* input) {
        // Write your code here
        int val = 0;
        while (!input->done()) {
            val += input->value();
            input->next();
        }
        q.push(make_pair(val, key));
    }

    void cleanUp() {
        // Please directly use func 'output' to output 
        // the top k pairs <word, times> into output buffer.
        // void output(string &key, int &value);
        while (!q.empty() && K--) {
            auto e = q.top();
            q.pop();
            output(e.second, e.first);
        }
    }
};
