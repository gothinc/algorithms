#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            vector<vector<int> > ret;
            int len = num.size();
            if(len == 0){
                return ret;
            }

            sort(num.begin(), num.end());
            int tmp = 0;
            int target = 0;
            map<int, int> pre;

            for(int i = 0; i < len - 3; i ++){
                if(i > 0 && num[i] == num[i - 1]){
                    continue;
                }

                pre.clear();
                target = 0 - num[i];
                for(int j = i + 1; j < len; j ++){
                    tmp = target - num[j];
                    if(pre.count(tmp) > 0){
                        int in[] = {num[i], tmp, num[j]};
                        ret.push_back(vector<int>(in, in + 3));
                        continue;
                    }

                    if(pre.count(num[j]) == 0){
                        pre[num[j]] = j;
                    }
                }
            }

            vector<vector<int> >::iterator it = unique(ret.begin(), ret.end());
            ret.erase(it, ret.end());
            return ret;
        }
};


int
main(int argc, char *argv[]){
    Solution st;
    int target = 0;
    int a[] = {-10,-11,13,0,-11,9,1,-6,-1,-12,10,-9,0,-15,-13,4,-13,-1,-12,2,-11,-6,10,2,-6,6,-8,-12,11,-2,1,9,2,-1,-14,-1,-6,-6,0,0,-3,-4,-2,4,-12,-8,-7,-10,6,-11,-1,2,-2,-14,-10,7,7,-3,10,-4,3,-11,-10,12,3,13,-4,4,-8,4,-11,-4,-15,-6,-15,-12,1,-15,-15,14,-11,-8,2,-6,-7,-1,-14,-14,11,4,-3,-1,8,-6,-3,-12,-8,0,8,-1,11,4,2,11,14,2,6,-8,-6,-1,-8,-1,6};
    int len = sizeof(a) / sizeof(int);
    vector<int> num(a, a + len);

    vector<vector<int> > vt = st.threeSum(num);
    /*for(int i = 0; i < vt.size(); i ++){
        for(int j = 0; j < vt[i].size(); j ++){
            cout << vt[i][j] << ",";
        }

        cout << endl;
    }*/

    cout << vt.size() << endl;
    return 0;
}
