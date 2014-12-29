#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
    public:
        vector<vector<int> > fourSum(vector<int> &num, int target) {
            vector<vector<int> > ret;
            int len = num.size();
            if(len == 0){
                return ret;
            }

            sort(num.begin(), num.end());
            int tmp = 0;
            int two_target = 0;
            map<int, int> pre;

            for(int i = 0; i < len - 3; i ++){
                if(i > 0 && num[i] == num[i - 1]){
                    continue;
                }

                for(int x = i + 1; x < len - 2; x ++){
                    if(x != i + 1 && num[x] == num[x - 1]){
                        continue;
                    }

                    pre.clear();
                    two_target = target - num[i] - num[x];
                    for(int j = x + 1; j < len; j ++){
                        if(j > x + 1 && num[j] == num[j - 1]){
                            continue;
                        }

                        tmp = two_target - num[j];
                        if(pre.count(tmp) > 0){
                            int in[] = {num[i], num[x], tmp, num[j]};
                            ret.push_back(vector<int>(in, in + 4));
                            continue;
                        }

                        pre[num[j]] = j;
                    }
                }
            }

            return ret;
        }
};


int
main(int argc, char *argv[]){
    Solution st;
    //int target = -1864;
    //int a[] = {-500,-495,-489,-472,-466,-449,-439,-435,-435,-413,-406,-381,-369,-353,-335,-311,-306,-260,-258,-231,-205,-189,-180,-165,-165,-164,-146,-141,-126,-121,-116,-100,-83,-23,-17,18,53,65,91,124,139,140,164,168,200,202,211,216,221,224,249,251,280,282,300,314,323,348,355,373,401,416,428,443,443,445,462,491,497};

    int target = 0;
    int a[] = {1, 0, -1, 0, -2, 2};
    int len = sizeof(a) / sizeof(int);
    vector<int> num(a, a + len);

    vector<vector<int> > vt = st.fourSum(num, target);
    for(int i = 0; i < vt.size(); i ++){
        for(int j = 0; j < vt[i].size(); j ++){
            cout << vt[i][j] << ",";
        }

        cout << endl;
    }

    cout << vt.size() << endl;
    return 0;
}
