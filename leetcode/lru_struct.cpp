#include <iostream>
#include <map>
#include <list>
#include <pair>

using namespace std;

class LRUCache{
    private:
        typedef list<int> format;
        pair<int, format::iterator> val;

        int cap;
        map<int, val> mat;
        format minlist;

    public:
        LRUCache(int capacity){
            cap = capacity;
        }

        void bianli(){
            for(map<int, val>::iterator it = mat.begin(); it != mat.end(); it ++){
                cout << it->first << endl;
            }
        }

        int get(int key) {
            if(mat.count(key) > 0){
                minlist.erase(mat[key].second);
                minlist.push_front(key);
                return mat[key].first;
            }

            return -1;
        }

        void set(int key, int value) {
            if(cap == 0){
                return;
            }

            if(mat.size() >= cap && mat.count(key) == 0){
                mat.erase(minlist.back());
                minlist.pop_back();
            }else if(mat.count(key) > 0){
                minlist.erase(mat[key].second);
            }

            minlist.push_front(key);
            mat[key].first = value;
            mat[key].second = minlist.begin();
        }
};

int
main(int argc, char *argv[]){
    LRUCache st(3);
    st.set(1178, 3401);
    st.set(903,6060);
    st.set(333, 222);
    st.get(333);
    st.get(903);
    st.get(1178);
    st.set(444, 444);

    cout << "------------" << endl;
    st.bianli();
}
