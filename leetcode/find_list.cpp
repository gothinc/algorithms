#include <iostream>
#include <string>

using namespace std;

typedef struct _tnode{
    int val;
    struct _tnode *next;
}tnode;

typedef struct _tlist{
    tnode *head;
    int num;
}tlist;

tlist *createList();
int insertList(tlist *ls, tnode *tn);
void printList(tlist *ls);
int findList(tlist *ls, int index);

int
main(int argc, char *argv[]){
    if(argc < 2){
        cout << "index needed" << endl;
        return -1;
    }

    int index = atoi(argv[1]);
    tlist *ls = createList();
    cout << findList(ls, index) << endl;
}

int
findList(tlist *ls, int index){
    if(ls->num == 0 || index <= 0 || index > ls->num){
        return -1;
    }

    tnode *obj = NULL;
    tnode *tmp = ls->head->next;
    int pro = 1;
    while(pro < index){
        tmp = tmp->next;
        pro ++;
    }

    obj = ls->head->next;
    while(tmp->next != NULL){
        obj = obj->next;
        tmp = tmp->next;
    }

    return obj == NULL ?  -1 : obj->val;
}

void
printList(tlist *ls){
    tnode *tmp = ls->head;
    for(int i = 0; i < ls->num; i ++){
        cout << tmp->next->val << endl;
        tmp = tmp->next;
    }
}

tlist *
createList(){
    tlist *ls = (tlist *)malloc(sizeof(tlist));
    ls->num = 0;
    ls->head = (tnode *)malloc(sizeof(tnode));

    ls->head->val = 0;
    ls->head->next = NULL;

    for(int i = 0; i < 20; i ++){
        tnode *no = (tnode *)malloc(sizeof(tnode));
        no->val = i;
        no->next = NULL;
        insertList(ls, no);
        ls->num ++;
    }

    return ls;
}

int
insertList(tlist *ls, tnode *tn){
    tnode *tmp = ls->head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }

    tmp->next = tn;
    return 0;
}
