#include <getopt.h>
namespace my{
    struct option
    {
        const char *name;
     /* has_arg can't be an enum because some compilers complain about
      type mismatches in all the code that assumes it is an int.  */
        int has_arg;
        int *flag;
        int val;
    };
}
// 结构体数组
struct option arr[] =
{
    {"mem2reg",no_argument,0,4}
};