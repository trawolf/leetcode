// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
// Return the sum of the three integers.
// You may assume that each input would have exactly one solution.

#include<iostream>
#include<vector>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
// using std::sort;

int threeSumClosest(vector<int>& nums, int target) {
    std::sort(nums.begin(),nums.end());
    for(const auto &num:nums){
        cout<<num<<" ";
    }
    cout<<endl;
    int sum=nums[0]+nums[1]+nums[2];
    for(size_t i=0;i<nums.size()-3;++i){
        cout<<abs(sum-target)<<" "<<abs(sum-nums[i]+nums[i+3]-target)<<" ";
        if(abs(sum-target)<abs(sum-nums[i]+nums[i+3]-target)){
            cout<<sum<<endl;
            break;
        }else{
            sum=sum-nums[i]+nums[i+3];
            cout<<sum<<endl;
        }
    }
    return sum;
}

int main(){
    vector<int> nums{4,0,5,-5,3,3,0,-4,-5};
    int target=-2;
    cout<<"The closest sum of three: "<<endl<<threeSumClosest(nums,target)<<endl;
    return 0;
}