#include<iostream>
#include<vector>
#include<set>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::set;

void move(const int count, size_t &row, size_t &col){
    switch (count%4)
    {
    case 0:
        ++col;
        break;
    case 1:
        ++row;
        break;
    case 2:
        --col;
        break;
    case 3:
        --row;
        break;
    default:
        break;
    }
}

bool if_out_of_range(const int count, const int n, size_t row, size_t col){
    auto row_=row,col_=col;
    move(count,row_,col_);
    return !(row_>=0&&row_<n&&col_>=0&&col_<n);
}

bool visited(const int count, size_t row, size_t col, vector<vector<int>> nums, const set<int> set){
    auto row_=row,col_=col;
    move(count,row_,col_);
    auto temp=nums[row_][col_];
    return set.find(temp)!=set.end();
}

vector<vector<int>> generateMatrix(int n) {
    set<int> set;
    vector<vector<int>> nums(n,vector<int>(n));
    size_t row=0,col=0;
    int count=0;
    for(int i=1;i<=n*n;++i){
        set.emplace(i);
        nums[row][col]=i;
        if(if_out_of_range(count,n,row,col)||visited(count,row,col,nums,set)){
            ++count;
        }
        move(count,row,col);
    }
    return nums;
}

int main(){
    int n;
    cin>>n;
    auto out=generateMatrix(n);
    for(size_t i=0;i<n;++i){
        for(size_t j=0;j<n;++j){
            cout<<out[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

