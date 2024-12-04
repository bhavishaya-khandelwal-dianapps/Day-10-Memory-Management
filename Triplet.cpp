#include<bits/stdc++.h>
using namespace std;


//* Brute Force Approach 
bool solve(int n, vector<int> &nums) {
    if(nums.size() < 3) return false;
    for(int i = 0 ; i < nums.size() - 2 ; i++) {
        for(int j = i + 1 ; j < nums.size() - 1 ; j++) {
            for(int k = j + 1 ; k < nums.size() ; k++) {
                if((nums[i] * nums[i]) + (nums[j] * nums[j]) == (nums[k] * nums[k])) return true;
                else if((nums[i] * nums[i]) + (nums[k] * nums[k]) == (nums[j] * nums[j])) return true;
                else if((nums[j] * nums[j]) + (nums[k] * nums[k]) == (nums[i] * nums[i])) return true;
            }
        }
    }
    return false;
}


//* Better Approach -> 
bool isTripletExist(int n, vector<int> &nums) {
    for(int i = 0 ; i < nums.size() ; i++) {
        nums[i] = nums[i] * nums[i];
    }
    sort(nums.begin(), nums.end());
    for(int i = nums.size() - 1 ; i > 1 ; i--) {
        int l = 0, r = i - 1;
        while(l < r) {
            if(nums[l] + nums[r] == nums[i]) return true;
            else if(nums[l] + nums[r] < nums[i]) {
                l++;
            }
            else if(nums[l] + nums[r] > nums[i]) {
                r--;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> V(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> V[i];
    }
    cout << solve(n, V) << endl;
    cout << isTripletExist(n, V) << endl;
}