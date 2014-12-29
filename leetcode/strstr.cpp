#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if(haystack == NULL || needle == NULL || *needle == '\0'){
            return -1;
        }

        char *tt = needle;
        int lenn = 0;
        while(*tt != '\0'){
           lenn ++;
           tt ++;
        }

        int *kmp = new int[lenn + 1];
        calKmp(needle, kmp);

        int step = 0;
        int len = 0;
        char *tmp = needle;
        while(*haystack != '\0' && *needle != '\0'){
            if(*haystack != *needle){
                if(needle == tmp){
                    haystack ++;
                    len ++;
                    continue;
                }

                int l = step;
                step = kmp[step - 1];
                needle = needle - (l - step);
            }else{
                step ++;
                needle ++;
                haystack ++;
                len ++;
            }
        }

        delete [] kmp;

        if(*needle == '\0'){
            return len - step;
        }else{
            return -1;
        }
    }

    void calKmp(char *needle, int ret[]){
        if(needle == NULL){
            return;
        }

        int i = 1;
        int len = 1;
        ret[0] = 0;
        ret[-1] = 0;
        char *tmp = needle;
        needle ++;

        while(*needle != '\0'){
            i = len;
            while(i > 0){
                if(tmp[ret[i - 1]] == *needle){
                    ret[len] = ret[i - 1] + 1;
                    break;
                }else{
                    i = ret[i - 1];
                }
            }

            if(i == 0){
                ret[len] = 0;
            }

            len ++;
            needle ++;
        }
    }

};

int
main(int argc, char *argv[]){
    Solution st;
    string s = "";

    cout << st.strStr((char *)s.c_str(), "a") << endl;
}
