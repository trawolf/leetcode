#include<iostream>
#include<vector>
#include<set>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::set;

struct Point{
    int row, col;
    Point(const int &i, const int &j):row(i),col(j){};
};

bool compare(const Point &pt1, const Point &pt2){
    return (pt1.row<pt2.row)?true:((pt1.row==pt2.row&&pt1.col<pt2.col)?true:false);
}

bool if_out_of_range(const Point &pt, const int rows, const int cols){
    if(pt.row>=0&&pt.row<rows&&pt.col>=0&&pt.col<cols){
        return false;
    }
    return true;
}

void move(const int &count, Point &pt){
    switch (count%4)
    {
    case 0:
        ++pt.col;
        break;
    case 1:
        ++pt.row;
        break;
    case 2:
        --pt.col;
        break;
    case 3:
        --pt.row;
        break;
    default:
        break;
    }
}

void print(const set<Point,decltype(compare)*> &set){
    for(const auto &it:set){
        cout<<"["<<it.row<<","<<it.col<<"] ";
    }
}

Point next(const int &count, Point pt){
    auto temp=pt;
    move(count,temp);
    return temp;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    set<Point,decltype(compare)*> visited(compare);
    vector<int> out;
    int count=0, size=matrix.size()*matrix[0].size(), idx=0;
    Point pt(0,0);
    while(idx<size){
        auto add=visited.emplace(pt);
        // cout<<"["<<size_t(pt.row)<<","<<size_t(pt.col)<<"]: ";
        out.push_back(matrix[size_t(pt.row)][size_t(pt.col)]);
        // cout<<out[idx]<<endl;
        if(if_out_of_range(next(count, pt),matrix.size(),matrix[0].size())||visited.find(next(count, pt))!=visited.end()){
            // cout<<"out of range or have been visited"<<endl;
            ++count;
        }
        move(count,pt);
        ++idx;
    }
    // print(visited);
    return out;
}

int main(){
    vector<vector<int>> nums{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    //cout<<nums.size()*nums[0].size()<<endl;
    auto out=spiralOrder(nums);
    for(auto const &num:out){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}