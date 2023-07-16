// Minimum Difference Between Highest and Lowest of K Scores

// You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. You are also given an integer k.
// Pick the scores of any k students from the array so that the difference between the highest and the lowest of the k scores is minimized.
// Return the minimum possible difference.

#include<iostream>
#include<vector>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

int minimumDifference(vector<int>& nums, int k) {
	auto temp=nums;
	sort(temp.begin(),temp.end());
	int min_diff=temp[k-1]-temp[0];
	for(int i=1;i<temp.size()-k+1;i++){
		min_diff=(min_diff<temp[i+k-1]-temp[i])?min_diff:temp[i+k-1]-temp[i];
	}
	return min_diff;
}

int main(){
	vector<int> nums(1,3,2,4,6,5);
	int k=2;
	cout<<minimumDifference(nums,k)<<endl;
	return 0;
}