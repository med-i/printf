#include "main.h"

long int resize_u(unsigned long int num, int length)
{
    if (length == 'l')
        return (num);
    else if (length == 'h')
        return ((unsigned short)num);
    
    return ((unsigned int)num);
}