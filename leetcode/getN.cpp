#include <iostream>
#include <math.h>

using namespace std;

int
main(int argc, char argv[]){
    int a = -31255315;
    int n;

    int ret = 0;
    int pos = a > 0 ? 1 : -1;
    while(1){
        cin >> n;
        if(n <=0){
            cout << "enter positive number" << endl;
            continue;
        }

        ret = (a % (int)(pow(10, n)) - a % (int)(pow(10, n - 1))) / (int)pow(10, n - 1);
        cout << "ret:" << ret * pos << endl;
    }
}
