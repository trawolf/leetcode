// A sequence of numbers is called an arithmetic progression 
// if the difference between any two consecutive elements is the same.

// Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. 
// Otherwise, return false.

#include<iostream>
#include<vector>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

bool canMakeArithmeticProgression(vector<int>& arr) {
    vector<int> vec=arr;
    sort(vec.begin(),vec.end());
    auto iter=vec.begin()+1;
    while(iter!=vec.end()-1){
        if(*iter-*(iter-1)!=*(iter+1)-*iter){
            return false;
        }
        ++iter;
    }
    return true;
}

int main(){
    vector<int> arr{1,2,4};
    if(canMakeArithmeticProgression(arr)){
        cout<<"true!"<<endl;
    }else cout<<"false!"<<endl;
    return 0;
}