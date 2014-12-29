#include <iostream>
#include <stdlib.h>

using namespace std;
class MinStack {
    private:
        int len;
        int *stack;
        int size;
        int min;
    public:
        MinStack():len(0), stack(NULL), size(0), min(0){
            size = 64;
            stack = new int[size];
        }

        ~MinStack(){
            if(stack != NULL){
                delete [] stack;
                stack = NULL;

            }

        }

        void push(int x) {
            if(len >= size){
                int *tmp = new int[size * 2];
                memcpy(tmp, stack, sizeof(int) * size);
                size *= 2;
                delete [] stack;
                stack = tmp;

            }

            if(len == 0 || x < min){
                min = x;

            }

            stack[len] = x;
            len ++;
        }

        void pop() {
            if(len > 0){
                len --;

            }
        }

        int top() {
            if(len > 0){
                return stack[len - 1];
            }

            return 0;
        }

        int getMin() {
            return min;
        }
};

int
main(){
    MinStack ms;
    for(int i = 0; i < 36; i ++){
        ms.push((int)rand() % 1000);
    }
    cout << ms.getMin() << endl;
}
