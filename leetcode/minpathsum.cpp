#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.size() == 0){
            return 0;
        }

        vector<vector<int> > les(grid.size(), vector<int>(grid[0].size(), -1));
        return excute(grid, 0, 0, les);
    }

    int excute(vector<vector<int> > &grid, int x, int y, vector<vector<int> > &les){
        if(y >= grid.size() || x >= grid[0].size()) return 0;

        if(les[y][x] > 0){
            return les[y][x];
        }

        int ret = 0;
        if(y == grid.size() - 1){
            for(int i = x; i < grid[0].size(); i ++){
                ret += grid[y][i];
            }
        }else if(x == grid[0].size() - 1){
            for(int i = y; i < grid.size(); i ++){
                ret += grid[i][x];
            }
        }else{
            int right = excute(grid, x + 1, y, les);
            int below = excute(grid, x, y + 1, les);

            int min = right > below ? below : right;
            ret = grid[y][x] + min;
        }

        les[y][x] = ret;
        return ret;
    }
};

int
main(){
    vector<vector<int> > grid;
    int arr[] = {1, 2};
    vector<int> a(arr, arr + 2);
    grid.push_back(a);
    int brr[] = {1, 1};
    vector<int> b(brr, brr + 2);
    grid.push_back(b);
    Solution st;
    cout << st.minPathSum(grid) << endl;;
}
