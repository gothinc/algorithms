#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int len = tokens.size();
        stack<int> tlist;
        for(int i = 0; i < len; i ++){
            int t = tokens[i][0] - '0';
            if((t >= 0 && t <= 9) || tokens[i].size() > 1){
                tlist.push(atoi(tokens[i].c_str()));
            }else{
                int b = tlist.top();
                tlist.pop();
                int a = tlist.top();
                tlist.pop();
                tlist.push(excute(tokens[i][0], a, b));
            }
        }

        return tlist.top();
    }

    int excute(char e, int a, int b){
        if(e == '+'){
           return a + b;
        }else if(e == '/'){
            return a / b;
        }else if(e == '-'){
            return a - b;
        }else if(e == '*'){
            return a * b;
        }
    }
};

int main(){
    vector<string> vec;
    vec.push_back("-1");
    vec.push_back("1");
    vec.push_back("*");
    vec.push_back("-1");
    vec.push_back("+");
    Solution st;
    cout  << st.evalRPN(vec) << endl;
}
