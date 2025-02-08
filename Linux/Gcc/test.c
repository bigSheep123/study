#include <stdio.h>

// #define V1 2
// #define V2 2
// #define V3 2

int main()
{
#ifdef V1
    printf("功能1\n");

#elif V2
    printf("功能1\n");
    printf("功能2\n");
    printf("功能3\n");
#else
    printf("功能1\n");
    printf("功能2\n");
    printf("功能3\n");
    printf("功能4\n");
    printf("功能5\n");
    printf("功能6\n");
#endif

    return 0;
}
