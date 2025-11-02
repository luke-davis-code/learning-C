#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        switch (*argv[i])
        {
        case 'm':
            puts("this␣is␣a␣magpie");
            // break;
        case 'r':
            puts("this␣is␣a␣raven");
            break;
        case 'j':
            puts("this␣is␣a␣jay");
            break;
        case 'c':
            puts("this␣is␣a␣chough");
            break;
        default:
            puts("this␣is␣an␣unknown␣corvid");
        }
    }
}
