#include <stdio.h>

int
main(int argc, char *argv[]){
    if(argc < 2){
        printf("argv required\n");
        return 1;
    }

    int ret = 0;
    char *s = argv[1];

    while(*s != 0){
        if(*s < 48 || *s > 57) break;
        ret = ret * 10 + (*s - 48);    
        s ++;
    }

    printf("%d\n", ret);
    return 0;
}
