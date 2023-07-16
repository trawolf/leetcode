// Given an integer array nums and an integer k, 
// return the k most frequent elements. You may return the answer in any order.

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::map;
using std::pair;

vector<int> topKFrequent(vector<int>& nums, int k) {
    // auto vec=nums;
    // sort(vec.begin(),vec.end());
    map<int,int> num_count;
    for(const auto &it:nums){
        if(num_count.find(it)!=num_count.end()){
            ++num_count.at(it);
        }else{
            num_count.emplace(it,1);
        }
    }
    sort(num_count.begin(),num_count.end(),
        [](const pair<int,int> &pair_1,const pair<int,int> &pair_2)
        {return pair_1.second<pair_2.second;});
    // vector<int> vec(num_count.size());
    // for(const auto &it:num_count){
    //     vec.push_back(it.second);
    // }
    // sort(vec.begin(),vec.end());
    // vec.erase(vec.begin(),vec.end()-k);
    // vector<int> out(k);
    
    return vec;
}

int main(){
    int in,k;
    cout<<"most frequent parameter: ";
    cin>>k;
    vector<int> nums;
    cout<<"input the numbers: ";
    while(cin>>in){
        nums.push_back(in);
    }
    vector<int> out(topKFrequent(nums,k));
    for(const auto &it:out){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}