//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int i = 0;
        int j = 0;
        
        int sum = 0;
        int Maxvalue = INT_MIN;
        
        while(j < n){
            sum = sum + arr[j];
            
            if(j - i + 1 < k){
                j++;
            }
            else if(j - i + 1 == k){
                Maxvalue = std::max(Maxvalue,sum);
                sum = sum - arr[i];
                i++;
                j++;
            }
        }
        return Maxvalue;
        
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        int ans = ob.maximumSumSubarray(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends