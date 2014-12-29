#include <iostream>
#include <map>

using namespace std;

class Solution {
    private:
        map<int, int> pai;
    public:
        int climbStairs(int n) {
            if(n <= 0){
                return 0;

            }

            if(n == 1){
                return 1;

            }

            if(n == 2){
                return 2;

            }

            if(pai.count(n) > 0){
                return pai[n];
            }

            pai[n] = climbStairs(n - 1) + climbStairs(n - 2);
            return pai[n];
        }

};

int
main(){
    Solution st;
    cout << st.climbStairs(44) << endl;
}
