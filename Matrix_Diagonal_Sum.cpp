#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int diagonalSum(vector<vector<int>>& mat) {
    int sum_pri=0, sum_sec=0, size=mat.size(), idx=0;
    while(idx<size){
        sum_pri+=mat[idx][idx];
        sum_sec+=mat[idx][size-1-idx];
        ++idx;
    }
    int out=sum_pri+sum_sec;
    if(size%2!=0){
        out-=mat[(size-1)/2][(size-1)/2];
    }
    return out;
}

int main(){
    vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
    cout<<"Matrix diagonal sum: "<<diagonalSum(matrix)<<endl;
    return 0;
}