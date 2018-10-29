#include <stdlib.h>
#include <time.h>
#include <stdio.h>

    time_t t;

void main(void)
{
    
    srand((unsigned)time(&t));

    for(int i =0; i < 10; ++i)
    {
        printf("rand x: %u\n", rand()%160);
        printf("rand y: %u\n", rand()%140);
    }
}
