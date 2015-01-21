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
        int maxPoints(vector<Point> &points) {
            int len = points.size();
            if(len == 0 || len == 1) return len;

            int max_len = 0;
            map<string, int> ret;
            for(int i = 0; i < len; i ++){
                int tmp = 0;
                int same = 1;
                for(int j = 0; j < len; j ++){
                    if(j == i) continue;
                    if(points[i].x == points[j].x && points[i].y == points[j].y){
                        same ++;
                        continue;
                    }

                    string s = calrate(points[i], points[j]);
                    if(ret.count(s) > 0){
                        ret[s] ++;
                    }else{
                        ret[s] = 1;
                    }

                    if(ret[s] > tmp){
                        tmp = ret[s];
                    }
                }

                tmp += same;
                if(tmp > max_len){
                    max_len = tmp;
                }

                ret.clear();
            }

            return max_len;
        }

        string calrate(Point a, Point b){
            if(a.x == b.x){
               return "0/1";
            }else if(a.y == b.y){
                return "0/0";
            }

            return calkey(a.y - b.y, a.x - b.x);
        }

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

        int maxPointsOld2(vector<Point> &points) {
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

            return retlen;
        }

        string calkey(int a, int b){
            /*if(x == 0){
                return string("-0");
            }else if(y == 0){
                return string("0");
            }*/

            int x = abs(a);
            int y = abs(b);

            char check = a * b < 0 ? '-' : '+';

            if(x % y == 0){
                int a = x / y;
                char t[32] = {0};
                snprintf(t, 32, "%c%d", check, a);
                return string(t);
            }

            int gy = calgy(x, y);
            int p = x / gy;
            int l = y / gy;

            char t[128] = {0};
            snprintf(t, 128, "%c%d/%d", check, p, l);
            return string(t);
        }

        int calgy(int x, int y){
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
    vec.push_back(Point(0, 0));
    vec.push_back(Point(0, 0));
    vec.push_back(Point(2, 2));
    vec.push_back(Point(2, 2));
    cout << st.maxPoints(vec) << endl;
}
