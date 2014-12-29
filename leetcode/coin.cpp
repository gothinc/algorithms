#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct coin_t{
    int coin_size;
    int coin_val;
};

class Coin{
    public:
        Coin();
        ~Coin();

    public:
        int cal();

    private:
        void init_coin();
        int excute(int num, int tj);

    private:
        vector<coin_t> coins;
        const static int max_coin_num;
        const static int max_tj;
};

const int Coin::max_coin_num = 3;
const int Coin::max_tj = 10;

Coin::Coin(){}
Coin::~Coin(){}
void Coin::init_coin(){
    for(int i = 0; i < max_coin_num; i ++){
        coin_t ct;
        ct.coin_size = i + 2;
        ct.coin_val = i + 1;
        coins.push_back(ct);
    }
}

int Coin::cal(){
    this->init_coin();
    int ret = this->excute(max_coin_num, max_tj);
    cout << ret << endl;
}

int Coin::excute(int num, int tj){
    if(num <= 0 || tj <= 0){
        return 0;
    }

    int a = coins[num - 1].coin_val + excute(num - 1, tj - coins[num - 1].coin_size);
    int b = excute(num - 1, tj);

    return a > b ? a : b;
}

int main(int argc, char *argv[]){
    Coin test;
    test.cal();
}
