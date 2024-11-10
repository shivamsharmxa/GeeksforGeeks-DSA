//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> firstAndLast(int x, vector<int> &arr) {
        // Code here
        
    int start = 0, end = arr.size() - 1;
    int first = -1, last = -1, mid;

    // Find the first occurrence of x
    while (start <= end) {
        mid = start + (end - start) / 2;

        if (arr[mid] == x) {
            first = mid;
            end = mid - 1; // Move left to find the first occurrence
        }
        else if (arr[mid] < x) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    // Reset start and end to find the last occurrence of x
    start = 0, end = arr.size() - 1;
    while (start <= end) {
        mid = start + (end - start) / 2;

        if (arr[mid] == x) {
            last = mid;
            start = mid + 1; // Move right to find the last occurrence
        }
        else if (arr[mid] < x) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    // If x is not found, return [-1]
    if (first == -1 && last == -1) return {-1};

    // Return the first and last positions
    return {first, last};
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> ans = obj.firstAndLast(x, arr);
        for (int i : ans) {
            cout << i << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends