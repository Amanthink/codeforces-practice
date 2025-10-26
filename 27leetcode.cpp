#include<bits/stdc++.h>
using namespace std;
long long solve (vector<int>nums){
  long long ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = nums[i], b = nums[j];

                int minDiff = min(abs(a - b), abs(a + b));
                int minVal = min(abs(a), abs(b));

                int maxDiff = max(abs(a - b), abs(a + b));
                int maxVal = max(abs(a), abs(b));

                if (minDiff <= minVal && maxDiff >= maxVal) {
                    ans++;
                }
            }
        }
        return ans;
}
int main(){
    vector<int>nums;
    for(int i=0;i<nums.size();i++)cin>>nums[i];
  cout<<solve(nums);
}