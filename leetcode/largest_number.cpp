#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &num) {
        int len = num.size();
        sort(num, 0, len - 1);

        string ret;
        char nu[16] = {0};
        for(int i = 0; i < len; i ++){
            snprintf(nu, 16, "%d", num[i]);
            ret.append(nu);
        }

        int del = 0;
        for(int i = 0; i < ret.size(); i ++){
            if(ret[i] != '0') break;
            del ++;
        }

        if(del > 0){
            ret = ret.erase(0, del);
        }

        return ret.size() > 0 ? ret : "0";
    }

    void sort(vector<int> &num, int a, int b){
        if(a >= b){
            return;
        }

        int mid = findmid(num, a, b);
        for(int i = 0; i < num.size(); i ++){
            cout << num[i] << endl;
        }
        sort(num, a, mid - 1);
        sort(num, mid + 1, b);
    }

    int findmid(vector<int> &num, int a, int b){
        int t = a;

        while(a < b){
            while(pai(num[b], num[t]) <= 0 && a < b) b --;
            while(pai(num[a], num[t]) >= 0 && a < b) a ++;
            swap(num, a, b);
        }

        swap(num, t, a);
        return a;
    }

    int pai(int a, int b){
        char x[32] = {0};
        char y[32] = {0};
        snprintf(x, 32, "%d%d", a, b);
        snprintf(y, 32, "%d%d", b, a);

        int i =0, j = 0;
        while(i < 32 && j < 32){
            if(x[i] == 0 && y[j] == 0) return 0;
            if(x[i] > y[j]){
                return 1;
            }else if(x[i] < y[j]){
                return -1;
            }

            i ++;
            j ++;
        }
    }

    void swap(vector<int> &num, int a, int b){
        int t = num[a];
        num[a] = num[b];
        num[b] = t;
    }
};

int
main(){
    Solution st;
    int a[] = {1, 0};
    vector<int> vec(a, a + 2);
    cout << st.largestNumber(vec) << endl;
}
