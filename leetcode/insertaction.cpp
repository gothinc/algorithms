#include <iostream>

using namespace std;

class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            if(headA == NULL || headB == NULL){
                return NULL;
            }

            ListNode *a = headA, *b = headB;
            while(a != NULL && b != NULL){
                if(a == b){
                    return a;
                }

                if(a->next == NULL){
                    a = headB;
                    continue;
                }

                if(b->next == NULL){
                    b = headA;
                    continue;
                }

                a = a->next;
                b = b->next;
            }

            return NULL;
        }

};
