#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
    public:
        int maxPointsOld(vector<Point> &points) {
            int len = points.size();
            if(len == 0){
                return 0;
            }

            map<string, int> ret;
            int check00 = 0;
            for(int i = 0; i < len; i ++){
                if(points[i].x == 0 && points[i].y == 0){
                    check00 = 1;
                    continue;
                }

                string s = calkey(abs(points[i].x), abs(points[i].y));
                if(points[i].x * points[i].y < 0){
                    s.insert(s.begin(), 1, '-');
                }

                if(ret.count(s) > 0){
                    ret[s] ++;
                }else{
                    ret[s] = 1;
                }
            }

            map<string, int>::iterator it;
            int retlen = 0;
            for(it = ret.begin(); it != ret.end(); it ++){
                if(it->second > retlen){
                    retlen = it->second;
                }
            }

            return check00 == 1 ? retlen + 1 : retlen;
        }

        int maxPoints(vector<Point> &points) {
            int len = points.size();
            if(len == 0) return 0;
            if(len == 1) return 1;

            map<string, int> ret;
            for(int i = 0; i < len; i ++){
                string key;
                char t[32];
                snprintf(t, 32, "%d/0", points[i].x);
                if(ret.count(t) == 0){
                    ret[t] = 1;
                }
                snprintf(t, 32, "0/%d", points[i].y);
                if(ret.count(t) == 0){
                    ret[t] = 1;
                }

                for(int j = i + 1; j < len; j ++){

                }

                string s = calkey(abs(points[i].x), abs(points[i].y));
                if(points[i].x * points[i].y < 0){
                    s.insert(s.begin(), 1, '-');
                }

                if(ret.count(s) > 0){
                    ret[s] ++;
                }else{
                    ret[s] = 1;
                }
            }

            map<string, int>::iterator it;
            int retlen = 0;
            for(it = ret.begin(); it != ret.end(); it ++){
                if(it->second > retlen){
                    retlen = it->second;
                }
            }

            return check00 == 1 ? retlen + 1 : retlen;
        }

        string calkey(int x, int y){
            if(x == 0){
                return string("-0");
            }else if(y == 0){
                return string("0");
            }

            if(x % y == 0){
                int a = x / y;
                char t[32] = {0};
                snprintf(t, 32, "%d", a);
                return string(t);
            }

            int gy = calgy(x, y);
            int p = x / gy;
            int l = y / gy;

            char t[128] = {0};
            snprintf(t, 128, "%d/%d", p, l);
            return string(t);
        }

        int calgy(int x, int y){
            cout << "x:" << x << ",y:" << y << endl;
            int b, l;
            if(x > y){
                b = x;
                l = y;
            }else{
                b = y;
                l = x;
            }

            int yu = b % l;
            if(yu == 0){
                return l;
            }

            return calgy(yu, l);
        }
};

int
main(){
    Solution st;
    vector<Point> vec;
    vec.push_back(Point(2, 3));
    vec.push_back(Point(4, 6));
    vec.push_back(Point(-6, -6));
    cout << st.maxPoints(vec) << endl;
}
