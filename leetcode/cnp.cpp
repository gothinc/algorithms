#include <iostream>
#include <string>

using namespace std;
static const char* origin = "kobe8tracy";

void nextval(const char *input, char *next, int next_len){
    next[0] = -1;
    int i = 1;
    int k = 0;
    k = next[i - 1];
    while(i < next_len){
        if(k == -1 || input[k] == input[i - 1]){
            next[i] = k + 1;
            i ++;
            k ++;
        }else{
            k = next[k];
        }
    }
}

int match_str(string input){
    int max = strlen(origin);
    int len = input.size();
    if(len == 0 || len > max){
        cout << "input invalid" << endl;
        return -1;
    }

    const char* cur = input.c_str();
    char *next = new char[len];
    memset(next, 0 , len);
    nextval(cur, next, len);

    int i, j;
    i = 0;
    j = 0;
    bool found = false;

    while(j < len && j >= 0 && i >= 0 && i < max){
        if(origin[i] == input[j]){
            i ++;
            j ++;
        }else{
            j = next[j];
            if(j == -1){
                j = 0;
                i ++;
            }
        }
    }

    if(j == len){
        found = true;
    }

    if(next != NULL){
        delete []next;
        next = NULL;
    }

    return found ? 1 : 0;
}

int
main(int argc, char *argv[]){
    string input;
    int ret = -1;
    cout << "please enter str" << endl;
    while(1){
        cin >> input;
        ret = match_str(input);
        if(ret == 1){
            cout << "match succ" << endl;
        }else{
            cout << "match fail" << endl;
        }
    }
}
