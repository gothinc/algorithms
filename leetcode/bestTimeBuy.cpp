#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
    public:
        int maxProfitTwice(vector<int> &prices){
            if(prices.size() == 0){
                return 0;
            }

            int len = prices.size();
            int *opt = new int[len];
            int min = prices[0];
            int ret = 0;

            for(int i = 0; i < len; i ++){
                if(prices[i] - min > ret){
                    ret = prices[i] - min;
                }

                if(prices[i] < min){
                    min = prices[i];
                }

                opt[i] = ret;
            }

            int *reverse = new int[len];
            int max = prices[len - 1];
            ret = 0;
            for(int i = len - 1; i >= 0; i --){
                if(max - prices[i] > ret){
                    ret = max - prices[i];
                }

                if(prices[i] > max){
                    max = prices[i];
                }

                reverse[i] = ret;
            }


            ret = 0;
            for(int i = 0; i < len; i ++){
                if(opt[i] + reverse[i] > ret){
                    ret = opt[i] + reverse[i];
                }
            }

            delete [] opt;
            delete [] reverse;
            return ret;
        }

        int excuteTwice(vector<int> &prices, int begin, int end){
            if(begin >= end)
                return 0;
            }

            int min = prices[begin];
            int ret = 0;

            for(int i = begin; i < end; i ++){
                if(prices[i] - min > ret){
                    ret = prices[i] - min;
                }

                if(prices[i] < min){
                    min = prices[i];
                }
            }

            return ret;
        }

        int maxProfitMulti(vector<int> &prices){
            if(prices.size() == 0){
                return 0;
            }

            int min = prices[0];
            int ret = 0;
            int len = prices.size();

            for(int i = 1; i < len; i ++){
                if(prices[i] > min){
                    ret += prices[i] - min;
                }

                min = prices[i];
            }

            return ret;
        }

        int maxProfit(vector<int> &prices){
            if(prices.size() == 0){
                return 0;
            }

            int min = prices[0];
            int ret = 0;
            int len = prices.size();

            for(int i = 1; i < len; i ++){
                if(prices[i] - min > ret){
                    ret = prices[i] - min;
                }

                if(prices[i] < min){
                    min = prices[i];
                }
            }

            return ret;
        }
};
