#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class Solution {
    public:
        int maxProduct(int A[], int n){
            if(n <= 0){
                return 0;
            }

            int max_pre = A[0];
            int max_sofar = A[0];
            int min_pre = A[0];
            int min_sofar = A[0];

            for(int i = 1; i < n; i ++){
                max_pre = getMax(max_pre * A[i], min_pre * A[i], A[i]);
                min_pre = getMin(max_pre * A[i], min_pre * A[i], A[i]);
                max_sofar = max_sofar > max_pre ? max_sofar : max_pre;
                min_sofar = min_sofar < min_pre ? min_sofar : min_pre;
                cout << min_sofar << endl;
            }

            return max_sofar;
        }

        int getMax(int a, int b, int c){
            int tmp;
            tmp = a > b ? a : b;
            return tmp > c ? tmp : c;
        }

        int getMin(int a, int b, int c){
            int tmp;
            tmp = a < b ? a : b;
            return tmp < c ? tmp : c;
        }
};

int main(int argc, char *argv[]){
    int test[] = {-4,-3,-2};
    Solution st;
    int len = sizeof(test) / sizeof(int);
    int x = st.maxProduct(test, len);
    printf("%d\n", x);
}
