#include <stdio.h>
#include "color.h"
#include "tests.h"

void print_result(char *test_name, int result)
{
    printf("%s%s - %s%s\n",
        result ? ANSI_COLOR_GREEN : ANSI_COLOR_RED,
        test_name,
        result ? "OK" : "FAILURE",
        ANSI_COLOR_RESET);
}

int main()
{
    
    return 0;
}