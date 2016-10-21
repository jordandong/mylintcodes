/*
Implement an assignment operator overloading method.

Make sure that:

The new data can be copied correctly
The old data can be deleted / free correctly.
We can assign like A = B = C
Example
If we assign like A = B, the data in A should be deleted, and A can have a copy of data from B. If we assign like A = B = C, both A and B should have a copy of data from C.

Challenge
Consider about the safety issue if you can and make sure you released the old data.

Clarification
This problem is for C++ only as Java and Python don't have overloading for assignment operator.

Tags Expand 
OO Design
*/

class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        if(this != &object) {
            free(this->m_pData);
            this->m_pData = NULL;
            if(object.m_pData != NULL) {
                int sz = strlen(object.m_pData);
                this->m_pData = new char[sz + 1];
                memcpy(this->m_pData, object.m_pData, sz + 1);
            }
        }
    }
};
