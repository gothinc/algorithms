#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSayOld(int n){
        if (0 == n) return "";
        if (1 == n) return "1";

        std::string res="1";
        std::string s;

        for (int i = 1; i < n; i++){    // run from starting to generate second string

            int len = res.size();

            //cheack all digits in the string
            char co[10] = {0};
            for (int j = 0; j < len; j++){

                int count=1; // we have at least 1 occourence of each digit

                // get the number of times same digit occurred (be carefull with the end of the string)
                while ((j + 1 < len) && (res[j] == res[j + 1])){
                    count++;
                    j++;        // we need to keep increasing the index inside of the string
                }

                // add to new string "count"+"digit itself"

                snprintf(co, 10, "%d", count);
                //s += co + res[j];
                s.append(co);
                s += res[j];
            }

            // save temporary result
            res = s;
            cout << res << endl;

            // clean our string-helper
            s.clear();

        }

        return res;
    }
    string countAndSay(int n){
        if(n == 0){
            return "0";
        }

        int time = 1, count = 1, len = 0;
        char co_str[16] = {0};
        string ret("1");
        string tmp;

        while(time ++ < n){
            count = 1;
            len = ret.size();
            for(int i = 0; i < len; i ++){
                if((i < len - 1) && ret[i + 1] == ret[i]){
                    count ++;
                    continue;
                }

                snprintf(co_str, 16, "%d", count);
                tmp.append(co_str);
                tmp.append(1, ret[i]);
                count = 1;
            }

            ret = tmp;
            tmp.clear();
        }

        return ret;
    }
};

int
main(){
    Solution st;
    string s = st.countAndSay(10);
    cout << s << endl;
}
