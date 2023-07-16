#include<iostream>
#include<vector>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int max(const vector<int> &vec){
    int max=0;
    for(auto &it : vec){
        max=(max>it)?max:it;
    }
    return max;
}

int min(const vector<int> &vec){
    int min=vec[0];
    for(auto &it : vec){
        min=(min<it)?min:it;
    }
    return min;
}

void print(const vector<int> &vec){
    cout<<"[ ";
    for(const auto &it:vec){
        cout<<it<<" ";
    }
    cout<<"]";
}

int numSubseq(const vector<int>& nums, const int target) {
    int count=0;
    for(auto iter1=nums.begin();iter1!=nums.end();++iter1){
        for(auto iter2=iter1+1;iter2<=nums.end();++iter2){
            vector<int> sub(iter2-iter1);
            std::copy(iter1, iter2, sub.begin());
            // print(sub);
            if(min(sub)*2>target){
                continue;
            }else if(min(sub)+max(sub)<=target){
                // print(sub);
                ++count;
            }
        }
    }
    return count;
}

int main(){
    const vector<int> nums{3,5,6,7};
    const int target=9;
    cout<<"Number of Subsequences That Satisfy the Given Sum Condition: "<<numSubseq(nums, target)<<endl;
    return 0;
}