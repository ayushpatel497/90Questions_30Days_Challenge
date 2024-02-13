//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int rep,miss;
        vector<int>v(n+1,0);
        for(int i=0;i<n;i++)
            v[arr[i]]++;
        for(int i=1;i<=n;i++)
        {
            if(v[i]==0)
                miss = i;
            else if(v[i]==2)
                rep = i;
        }
        return {rep,miss};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends