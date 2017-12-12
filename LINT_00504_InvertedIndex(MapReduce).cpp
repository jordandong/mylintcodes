/*
Use map reduce to build inverted index for given documents.
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
class InvertedIndexMapper: public Mapper {
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
                        output(word, id);
                    }
                    start = i + 1;
                }
            }
            input->next();
        }
    }
};

class InvertedIndexReducer: public Reducer {
public:
    void Reduce(string &key, Input<int>* input) {
        // Write your code here
        // Please directly use func 'output' to output 
        // the results into output buffer.
        // void output(string &key, vector<int> &value);
        vector<int> value;
        set<int> st;
        while (!input->done()) {
            int v = input->value();
            st.insert(v);
            input->next();
        }
        for (auto s: st)
            value.push_back(s);
        output(key, value);
    }
};
