#include <stdio.h>  /* BUFSIZ, getchar */
#include <stdlib.h> /* atof */

char line[BUFSIZ];

/* getnum: convert line to a double */
double getnum(void)
{
        int c, i;
        i = 0;
        int lim = BUFSIZ;

        while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
                line[i++] = c;
        if (c == '\n')
                line[i++] = c;

        line[i] = '\0';

        return atof(line);
}