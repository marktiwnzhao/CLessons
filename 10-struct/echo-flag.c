//
// Created by 赵政杰 on 2021/12/13.
#include <stdio.h>

int main(int argc, char *argv[]) {
    int escaped = 0;

    char **args = argv;
    while (*++args != NULL) {
        if ((*args)[0] == '-') {
            char flag = (*args)[1];
            switch (flag) {
                case 'e': escaped = 1;
                    break;
                case 'E': escaped = 0;
                    break;
                default: printf("Error!\n");
                    return 0;
            }
        }
    }

    char *arg = NULL;
    while (--argc > 0) {
        arg = *++argv;
        if(arg[0] == '\\' && escaped) {
            if (arg[1] == 't') {
                printf("\t");
            }
            if (arg[1] == 'n') {
                printf("\n");
            }
        } else if (arg[0] != '-') {
            printf((argc > 1) ? "%s " : "%s", arg);
        }
    }
    return 0;
}
