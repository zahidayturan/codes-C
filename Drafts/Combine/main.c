#include <stdio.h>

#include "getnum.h"
#include "stack.h"

int main(void)
{
        double num = 0.0;

        while (1) {
                printf("Number [ENTER to stop]? ");

                if ((num = getnum()) == 0.0)
                        break;

                push(num);
        }

        dump();
        flush();
        dump();

        return 0;
}