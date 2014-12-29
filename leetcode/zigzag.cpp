#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string convert(string s, int nRows) {
            if(s.size() == 0 || nRows == 1){
                return s;
            }

            int len = s.size();
            string *ret = new string[nRows];
            int row = 0, step = 1;
            for(int i = 0; i < len; i ++){
                ret[row].push_back(s[i]);
                if(row == 0){
                    step = 1;
                }

                if(row == nRows - 1){
                    step = -1;
                }

                row += step;
            }

            string res;
            for(int i = 0; i < nRows; i ++){
                res.append(ret[i]);
            }

            delete [] ret;
            return res;
        }

        string convert_old(string s, int nRows) {
            if(s.size() == 0 || nRows == 1){
                return s;
            }

            int len = s.size();
            char *tmp = new char[len + 1];

            int line = 0, sep1 = 0, sep2 = 0, i = 0, j = 0, x = 0;
            sep1 = 2 * nRows - 2;
            while(i < len){
                tmp[i] = s[j];
                if(x % 2 == 1 && sep2 > 0 || sep1 == 0){
                    j += sep2;
                }else{
                    j += sep1;
                }

                if(j >= len){
                    line ++;
                    j = line;
                    x = 0;
                    sep1 -= 2;
                    sep2 += 2;
                }else{
                    x ++;
                }

                i ++;
            }

            tmp[i] = 0;
            s = tmp;
            delete [] tmp;
            return s;
        }

};

int
main(int argc, char *argv[]){
    Solution st;
    string s("PAYPALISHIRING");
    cout << "begin:" << st.convert(s, 3) << ":end" << endl;
}
