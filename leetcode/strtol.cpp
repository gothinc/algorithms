#include <iostream>
#include <math.h>

using namespace std;

class Solution {
    public:
        int sot(const char *str) {
            if(NULL == str || strlen(str) == 0){
                return 0;
            }

            int len = strlen(str);
            long long ret = 0;
            int pos = 1;
            int i = 0;

            while(i < len){
                if(str[i] == ' '){
                    i ++;
                }else{
                    break;
                }
            }

            if(str[i] == '-'){
                pos = -1;
                i ++;
            }else if(str[i] == '+'){
                i ++;
            }

            while(i < len){
                if(str[i] == '0'){
                    i ++;
                }else{
                    break;
                }
            }

            long long max = (long long)pow(2, 31);
            for(; i < len; i ++){
                if(str[i] < 48 || str[i] > 57){
                    break;
                }

                ret = ret * 10 + str[i] - 48;
                if(ret > max){
                    break;
                }
            }

            if(ret >= max){
                if(pos == 1){
                    return max - 1;
                }else{
                    return -max;
                }
            }

            return (int)ret * pos;
        }
};

int
main(int argc, char *argv[]){
    Solution st;
    cout << st.sot("-1") << endl;

    return 0;
}
