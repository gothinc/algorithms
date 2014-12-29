#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
    public:
        //bool wordBreak(string s, unordered_set<string> &dict){
        bool wordBreak(string s, set<string> &dict){
            if(dict.size() == 0 || s.size() == 0){
                return false;
            }

            int len = s.size();
            map<int, vector<int> > tmp;
            int begin = 0;
            int end = 0;
            int ret = -1;
            //unordered_set<string>::iterator it;
            set<string>::iterator it;
            for(it = dict.begin(); it != dict.end(); it ++){
                begin = s.find(*it, 0);
                while(begin != string::npos){
                    end = begin + it->size();
                    if(tmp.count(begin) > 0){
                        tmp[begin].push_back(end);
                    }else{
                        vector<int> x(1, end);
                        tmp[begin] = x;
                    }
                    begin = s.find(*it, begin + 1);
                }
            }

            if(tmp.size() == 0 || tmp.count(0) == 0){
                return false;
            }

            int find = false;
            map<int, int> dp;
            for(int i = 0; i < tmp[0].size(); i ++){
                if(tmp[0][i] == len){
                    find = true;
                    break;
                }
                if(findMax(tmp, tmp[0][i], len, dp) == 0){
                    find = true;
                    break;
                }
            }

            return find;
        }

        int findMax(map<int, vector<int> > &ori, int key, int max, map<int, int> &dp){
            if(dp[key] == -1){
                return -1;
            }

            if(ori.count(key) == 0){
                dp[key] = -1;
                return -1;
            }

            int ret = -1;
            for(int i = 0; i < ori[key].size(); i ++){
                if(ori[key][i] == max){
                    return 0;
                }

                ret = findMax(ori, ori[key][i], max, dp);
                if(ret == 0){
                    return 0;
                }
            }

            dp[key] = -1;
            return -1;
        }
};


int
main(int argc, char *argv[]){
    Solution st;
    string s = "acaaaaabbbdbcccdcdaadcdccacbcccabbbbcdaaaaaadb";
    set<string> dict;
    dict.insert("a");
    dict.insert("b");
    dict.insert("c");
    dict.insert("d");
    bool ret = st.wordBreak(s, dict);
    cout << ret << endl;

    return 0;
}
