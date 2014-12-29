#include <iostream>

using namespace std;

class Solution {
    public:
        int compareVersion(string version1, string version2) {
            if(version1 == version2){
                return 0;
            }

            int alen = version1.size();
            int blen = version2.size();

            return version1 > version2 ? 1 : -1;
        }
};

int
main(int argc, char *argv[]){
    Solution st;
    string s1("3.15");
    string s2("3.15");
    int a = st.compareVersion(s1, s2);
    cout << a << endl;
    return 0;
}
