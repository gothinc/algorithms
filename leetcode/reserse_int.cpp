#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Solution {
    public:
        int reverse(int a){
            long ret = 0;
            int x = abs(a);

            while(x > 0){
                ret = ret * 10 + x  % 10;
                x = x / 10;
            }


            if(ret > (pow(2, 31) - 1)){
                return 0;
            }

            return  a > 0 ? ret : -ret;
        }

        int reverse_old(int x) {
            if(x == 0){
                return 0;
            }

            char tmp[16] = {0};
            snprintf(tmp, 16, "%d", x);

            int base = (int)(pow(2, 31) - 1);
            long long ret = 0;
            int pos = x > 0 ? 1 : -1;
            for(int i = strlen(tmp) - 1; i >=0; i --){
                if(tmp[i] == '-'){
                    break;
                }

                ret = ret * 10 + (tmp[i] - 48);
                if(ret > base){
                    return 0;
                }
            }

            return (int)ret * pos;
        }
};

int
main(int argc, char *argv[]){
    Solution st;
    int a = st.reverse(1534236469);

    cout << a << endl;
}
