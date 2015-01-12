#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *sortList(ListNode *head){
            if(head == NULL){
                return NULL;
            }

            ListNode *tmp = head->next;
            ListNode *pre = head;
            while(tmp != NULL){
                if(tmp->val < pre->val){
                    pre->next = tmp->next;

                    if(head->val > tmp->val){
                        tmp->next = head;
                        head = tmp;
                    }else{
                        ListNode *t = head;
                        while(t->next != NULL){
                            if(t->next->val >= tmp->val){
                                tmp->next = t->next;
                                t->next = tmp;
                                break;
                            }

                            t = t->next;
                        }
                    }

                    tmp = pre->next;
                }else{
                    pre = pre->next;
                    tmp = tmp->next;
                }
            }

            return head;
        }
};

int
main(int argc, char *argv[]){
    int len = 10240;
    int *x = new int[len];
    for(int i = 0; i < len; i ++){
        x[i] = i % 3 + 1;
    }

    ListNode *l = new ListNode(0);
    ListNode *e = l;
    for(int i = 0; i < len; i ++){
        ListNode *t = new ListNode(x[i]);
        e->next = t;
        e = e->next;
    }

    Solution st;
    ListNode *ret = st.sortList(l);

    while(ret != NULL){
        cout << ret->val << endl;
        ret = ret->next;
    }
}

