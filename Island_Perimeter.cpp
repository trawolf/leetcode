#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

int islandPerimeter(vector<vector<int>>& grid) {
    int height=grid.size(),width=grid[0].size();
    int items=0,remove=0;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(grid[i][j]==1){
                items++;
                if((i-1)>=0&&grid[i-1][j]==1){
                    remove++;
                }
                if((j+1)<width&&grid[i][j+1]==1){
                    remove++;
                }
                if((i+1)<height&&grid[i+1][j]==1){
                    remove++;
                }
                if((j-1)>=0&&grid[i][j-1]==1){
                    remove++;
                }
            }
        }
    }
    return items*4-remove;
}

int main(){
    vector<vector<int>> grid{{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    cout<<islandPerimeter(grid);
}