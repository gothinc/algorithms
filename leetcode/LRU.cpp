#include <iostream>
#include <map>

using namespace std;

class LRUCache{
    typedef struct val{
        int v;
        int u;
        val():v(0), u(0){}
    };

    private:
        int cap;
        int used;
        map<int, val> mat;
        map<int, int> minlist;

    public:
        LRUCache(int capacity){
            cap = capacity;
            used = 0;
        }

        void bianli(){
            for(map<int, val>::iterator it = mat.begin(); it != mat.end(); it ++){
                cout << it->first << endl;
            }
        }

        int get(int key) {
            if(mat.count(key) > 0){
                minlist.erase(mat[key].u);
                mat[key].u = used;
                minlist[used] = key;
                used ++;
                return mat[key].v;
            }

            return -1;
        }

        void set(int key, int value) {
            if(cap == 0){
                return;
            }

            if(mat.size() >= cap && mat.count(key) == 0){
                mat.erase(minlist.begin()->second);
                minlist.erase(minlist.begin());
            }

            if(mat.count(key) > 0){
                minlist.erase(mat[key].u);
            }

            mat[key].v = value;
            mat[key].u = used;
            minlist[used] = key;
            used ++;
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
