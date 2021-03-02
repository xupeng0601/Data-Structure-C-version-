//
// Created by xupeng on 2021/3/2.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    for (int i = 0; i < 100; ++i) {
        if (i == 20) {
            return false;
        }
        printf("%d\n",i);
    }

}