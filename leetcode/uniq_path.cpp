#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int **pai;

public:
    Solution(): pai(NULL){
        pai = new int*[100];
        for(int i = 0; i < 100; i ++){
            pai[i] = new int[100];
            memset(pai[i], 0, 100 * sizeof(int));
        }
    }

    ~Solution(){
        for(int i = 0; i < 100; i ++){
            delete [] pai[i];
        }

        delete [] pai;
    }

    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0) return 0;
        if(m == 1 || n == 1) return 1;

        if(pai[m - 1][n - 1] > 0){
            return pai[m - 1][n - 1];
        }

        int tmp = 0;
        tmp += uniquePaths(m - 1, n);
        tmp += uniquePaths(m, n - 1);

        pai[m - 1][n - 1] = tmp;

        return tmp;
    }

};

int
main(){
    Solution st;
    cout << st.uniquePaths(2, 2) << endl;
}
