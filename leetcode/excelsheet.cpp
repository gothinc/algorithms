#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        if(n <= 0){
            return "";
        }

        if(n < 27){
            return string(1, 'A' + (n - 1));
        }

        string s;
        double lg = log(n - 26) / log(26);
        int time = 0;
        if(lg < 2){
            time = 2;
        }else{
            time = (int)ceil(lg);
        }

        int tmp = n;
        while(time > 0){
            int t = (tmp - 1) / (int)pow(26, time - 1);
            char a = 'A' + t - 1;
            s.append(1, a);
            tmp = tmp - t * (int)pow(26, time - 1);
            time --;

            if(time == 1){
                a = 'A' + tmp - 1;
                s.append(1, a);
                break;
            }
        }

        return s;
    }
};

int
main(int argc, char *argv[]){
    Solution st;
    string s(argv[1]);
    cout << st.convertToTitle(atoi(s.c_str())) << endl;
}
