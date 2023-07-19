// Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

// Note that elements beyond the length of the original array are not written. 
// Do the above modifications to the input array in place and do not return anything.

#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

void displayVector(vector<int> arr){
    for(const auto elem:arr){
        cout<<elem<<" ";
    }
    cout<<endl;
}

void duplicateZeros(vector<int>& arr) {
    auto iter=arr.begin();
    int size=arr.size();
    vector<int>::size_type add=0;
    while(iter!=arr.end()){
        if(*iter==0){
            arr.insert(iter++,0);
            add+=2;
        }else add++;
        iter=arr.begin()+add;
        if(add>=size){
            break;
        }
        displayVector(arr);
    }
    // cout<<add<<endl;
    arr.erase(arr.begin()+size,arr.end());
}

int main(){
    vector<int> arr={0,0,0,0,0,0,0};
    duplicateZeros(arr);
    cout<<endl;
    displayVector(arr);
    return 0;
}