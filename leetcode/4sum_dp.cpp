#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
    public:
        vector<vector<int> > fourSum(vector<int> &num, int target){
            vector<vector<int> > ret;
            if(num.size() < 4){
                return ret;
            }

            sort(num.begin(), num.end(), greater<int>());

            map<string, vector<vector<int> > > dp;
            vector<vector<int> > tmplist;
            excute(num, target, 0, 4, tmplist, dp);

            vector<vector<int> >::iterator it = unique(tmplist.begin(), tmplist.end());
            tmplist.erase(it, tmplist.end());

            return tmplist;
        }

        int excute(vector<int> &num, int target, int begin, int need, vector<vector<int> > &tmplist, map<string, vector<vector<int> > > &dp){
            int len = num.size();
            if(begin >= len || len - begin < need || need <= 0){
                return -1;
            }

            stringstream ss;
            ss << begin << need << target;
            string key = ss.str();
            if(dp.count(key) > 0){
                int dplen = dp[key].size();
                for(int i = 0; i < dplen; i ++){
                    tmplist.push_back(dp[key][i]);
                }

                return 0;
            }

            int ret = 0;
            vector<int> tmp;
            if(len - begin == need){
                for(int i = len - 1; i >= begin; i --){
                    ret += num[i];
                    tmp.push_back(num[i]);
                }

                if(ret == target){
                    tmplist.push_back(tmp);
                }

                tmp.clear();
                return 0;
            }

            if(need == 1){
                tmp.push_back(target);
                for(int i = begin; i < len; i ++){
                    if(num[i] == target){
                        tmplist.push_back(tmp);
                        break;
                    }
                }
            }else{
                vector<vector<int> > store;
                excute(num, target - num[begin], begin + 1, need - 1, store, dp);
                for(int i = 0; i < store.size(); i ++){
                    store[i].push_back(num[begin]);
                    tmplist.push_back(store[i]);
                }

                store.clear();
                excute(num, target, begin + 1,  need, store, dp);
                for(int i = 0; i < store.size(); i ++){
                    tmplist.push_back(store[i]);
                }
            }

            dp[key] = tmplist;
            return 0;
        }

};

int
main(int argc, char *argv[]){
    Solution st;
    int target = -158;
    int a[] = {-489,-487,-471,-464,-451,-421,-414,-405,-396,-355,-354,-350,-336,-335,-334,-307,-298,-296,-295,-287,-267,-256,-247,-231,-170,-130,-120,-109,-96,-80,-78,-71,-63,-56,-44,-43,-13,2,9,18,31,36,39,43,49,49,50,61,68,73,99,107,112,113,120,121,173,180,185,190,203,210,233,246,258,296,319,340,345,370,371,378,395,418,436,444,447,451,460,485};
    int len = sizeof(a) / sizeof(int);
    /*int target = 0;
    int a[] = {1, 0, -1, 0, 2, -2};
    int len = sizeof(a) / sizeof(int);*/
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
