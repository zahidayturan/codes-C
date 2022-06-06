#include <stdio.h>

#define MAXITEM 100 /* maximum depth of stack */

static int sp;                /* next free stack position */
static double stack[MAXITEM]; /* stack (of double number values) */

/* push: push f onto value stack */
void push(double f)
{
        if (sp < MAXITEM)
                stack[sp++] = f;
        else
                printf("Error: Stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
        if (sp > 0)
                return stack[--sp];
        else {
                printf("Error: Stack empty\n");
                return 0.0;
        }
}

/* dump: print stack items */
void dump(void)
{
        if (sp > 0) {
                int i = sp;

                while (i-- > 0)
                        printf("%d: %f\n", i, stack[i]);
        } else {
                printf("Stack empty!\n");
                return;
        }
}

/* flush: reset stack while printing all the items */
void flush(void)
{
        while (--sp >= 0)
                printf("%d: %f\n", sp, stack[sp]);
}