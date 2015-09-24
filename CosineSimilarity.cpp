/*
Cosine similarity is a measure of similarity between two vectors of an inner product space that measures the cosine of the angle between them. The cosine of 0° is 1, and it is less than 1 for any other angle.
See wiki: Cosine Similarity https://en.wikipedia.org/wiki/Cosine_similarity
Here is the formula: s = Sum(Ai * Bi) / (Sqrt(Sum(Ai*Ai)) * Sqrt(Sum(Bi*Bi)))   i = 1 .... n

Given two vectors A and B with the same size, calculate the cosine similarity.
Return 2.0000 if cosine similarity is invalid (for example A = [0] and B = [0]).

Have you met this question in a real interview? Yes

Example:
Given A = [1, 2, 3], B = [2, 3 ,4].
Return 0.9926.
Given A = [0], B = [0].
Return 2.0000
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        int N = A.size();
        long long sum_ab = 0;
        double sq_a = 0, sq_b = 0;
        
        for (int i = 0; i < N; i++) {
            sum_ab += (A[i] * B[i]);
            sq_a += (A[i] * A[i]);
            sq_b += (B[i] * B[i]);
        }
        
        if (!sq_a || !sq_b)
            return 2.0;
        
        return sum_ab / sqrt(sq_a) / sqrt(sq_b);
    }
};
