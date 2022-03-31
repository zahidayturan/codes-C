#include <stdio.h>
// ./getchar <text.txt
int main(void) 
{
    int c, i=0, nwhites, nother;
    int ndigit[10];

    nwhites = nother = 0;
    for (i=0; i < 10; i++)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhites;
        else
            ++nother;

        for (i=0; i < 10; i++)
            printf(" %d %s%d\n",i,"Number of: ",ndigit[i]);
            printf(" White space = %d, Other = %d\n",
            nwhites, nother);
        return 0;
}