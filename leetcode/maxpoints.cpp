#include <iostream>
#include <vector>
#include <map>
#include <float.h>

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
            map<double, int> ret;
            for(int i = 0; i < len; i ++){
                int tmp = 0;
                int same = 1;
                for(int j = i + 1; j < len; j ++){
                    if(points[i].x == points[j].x && points[i].y == points[j].y){
                        same ++;
                        continue;
                    }

                    double s = calrate(points[i], points[j]);
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

        double calrate(Point a, Point b){
            if(a.x == b.x){
                return DBL_MAX;
            }

            return double (a.y - b.y) / (a.x - b.x);
        }

        string calkey(int a, int b){
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
    vec.push_back(Point(84, 250));
    vec.push_back(Point(1, 0));
    vec.push_back(Point(0, 0));
    vec.push_back(Point(0, -70));
    vec.push_back(Point(0, -70));
    vec.push_back(Point(1, -1));
    vec.push_back(Point(21, 10));
    vec.push_back(Point(42, 90));
    vec.push_back(Point(-42, -230));
    cout << st.maxPoints(vec) << endl;
}
