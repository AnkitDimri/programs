#include <iostream>
#include <vector>
#include <utility>

#define print(x) std::cout << #x

 std::vector<int> p(4,0);
 std::vector<std::vector<int> > maze(4,p), path(4,p);

 // recursive function to traverse into new block inside maze
 int newBlock(std::pair<int,int>);

 int newBlock(std::pair<int,int> curr){
     int r = 0;
     if(curr.first == 3 && curr.second == 3){
         path[curr.first][curr.second] = 1;
         return 1;
     }
     if(curr.first < 3 && maze[curr.first+1][curr.second]){
         path[curr.first][curr.second] = 1;
         curr.first += 1;
         r = newBlock(curr);
     }
     if(curr.second < 3 && maze[curr.first][curr.second+1] && !r){
         path[curr.first][curr.second] = 1;
         curr.second += 1;
         r = newBlock(curr);
     }
     else if(!r){
         path[curr.first][curr.second] = 0;
         return 0;
     }
     return 1;
 }

 int main(){
     std::pair<int,int> current(0,0);
     maze[0][0] = 1;
     maze[1][0] = 1;
     maze[1][1] = 1;
     maze[1][3] = 1;
     maze[2][1] = 1;
     maze[3][0] = 1;
     maze[3][1] = 1;
     maze[3][2] = 1;
     maze[3][3] = 1;
     newBlock(current);
     print(\n\t Maze :\n);
     for(int i=0; i<4; i++){
         for(int j=0; j<4; j++){
             std::cout << maze[i][j] << "\t";
         }
         print(\n);
     }
     print(\n\n\t Path :\n);
     for(int i=0; i<4; i++){
         for(int j=0; j<4; j++){
             std::cout << path[i][j] << "\t";
         }
         print(\n);
     }
     return 0;

 }
