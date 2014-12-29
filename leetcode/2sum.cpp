#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
    public:
        vector<int> twoSumHash(vector<int> &numbers, int target) {
            vector<int> ret;
            if(numbers.size() == 0){
                return ret;
            }

            map<int, int> pre;
            int len = numbers.size();
            int tmp = 0;
            for(int i = 0; i < len; i ++){
                tmp = target - numbers[i];
                if(pre.count(tmp) > 0){
                    ret.push_back(pre[tmp] + 1);
                    ret.push_back(i + 1);

                    return ret;
                }

                pre[numbers[i]] = i;
            }

            return ret;
        }

        vector<int> twoSum(vector<int> &numbers, int target) {
            vector<int> ret;
            if(numbers.size() == 0){
                return ret;
            }

            map<int, vector<int> > maplist;
            for(int i = 0; i < numbers.size(); i ++){
                maplist[numbers[i]].push_back(i);
            }

            sort(numbers.begin(), numbers.end());
            int len = numbers.size();
            int front = 0;
            int last = len - 1;

            int tmp = 0;
            while(front < last && front >= 0 && last < len){
                tmp = numbers[front] + numbers[last];
                if(tmp == target){
                    vector<int> pre = maplist[numbers[front]];
                    vector<int> suf = maplist[numbers[last]];
                    for(int i = 0; i < pre.size(); i ++){
                        for(int j = 0; j < suf.size(); j ++){
                            if(pre[i] != suf[j]){
                                if(pre[i] < suf[j]){
                                    ret.push_back(pre[i] + 1);
                                    ret.push_back(suf[j] + 1);
                                }else{
                                    ret.push_back(suf[j] + 1);
                                    ret.push_back(pre[i] + 1);
                                }

                                return ret;
                            }
                        }
                    }
                }

                if(tmp > target){
                    last --;
                }else{
                    front ++;
                }
            }

            return ret;
        }

};

int
main(int argc, char *argv[]){
    int target = 6;
    int a[] = {3, 2, 4};
    vector<int> tt(a, a + 3);

    Solution st;
    vector<int> ret = st.twoSumHash(tt, target);
    for(int i = 0; i < ret.size(); i ++){
        cout << ret[i] << endl;
    }
}

