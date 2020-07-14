#include<bits/stdc++.h>
using namespace std;

int findCrossOver(vector<int> &arr, int l, int r, int x) {
    while(l <= r) {
        int mid = (l + r)/2;
        if(arr[mid] <= x && arr[mid+1] > x) {
            return mid;
        }
        if(arr[mid] < x) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    return 0;
}

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n = arr.size();
    if(x <= arr[0]) {
        return vector<int>(arr.begin(), arr.begin()+k);
    } else if(x >= arr[arr.size()-1]) {
        return vector<int>(arr.end()-k, arr.end());
    } else {
        int l = findCrossOver(arr, 0, n-1, x), r = l+1, count = 0;
        if(arr[l] == x) {
            l--;
            count++;
        }
        while(l >= 0 && r < n && count < k) {
            if(x - arr[l] <= arr[r] - x) {
                l--;
            } else {
                r++;
            }
            count++;
        }
        while(count < k && l >= 0) {
            l--;
            count++;
        }
        while(count < k && r < n) {
            r++;
            count++;
        }
        vector<int> ans(k);
        for(int i = l+1; i<r; i++) {
            ans[i-l-1] = arr[i];
        }
        return ans;
    }
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    int k = 4, x = 4;
    vector<int> ans = findClosestElements(v, k, x);
    for(auto e: ans) {
        cout<<e<<" ";
    }
    cout<<endl;
}
