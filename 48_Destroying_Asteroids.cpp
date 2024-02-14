class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long newMass = mass;
        stack<int> st;

        for (int val : asteroids) {
            st.push(val);
            while (!st.empty() && st.top() <= newMass) {
                newMass += st.top();
                st.pop();
            }
        }
        return st.empty();
    }
};