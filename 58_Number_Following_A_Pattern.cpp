//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        int i = 1;
        stack<int> st;
        string result = "";
        for (char c: S) {
            st.push(i);
            i += 1;
            if (c == 'I') {
                while (!st.empty()) {
                    int el = st.top();
                    st.pop();
                    result.append(to_string(el));
                }
            }
        }
        st.push(i);
        while (!st.empty()) {
            int el = st.top();
            st.pop();
            result.append(to_string(el));
        }
        return result;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends