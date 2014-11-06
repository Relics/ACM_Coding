#include <stdio.h>
#define MAX 10000

int array[MAX+1][2];

int main()
{
    int input;
    int coin = 1,total;
    int day = 0;
    
    while ( day < MAX )
    {
        int i = coin;
        while ( i-- )
        {
            array[++day][0] = coin;
            array[day][1] = array[day-1][1]+coin;
            if ( day == MAX )
            {
                break;
            }    
        }    
        ++coin;
    }
    
    while ( scanf( "%d", &input ), input != 0 )
    {
        printf( "%d %d\n", array[input][0], array[input][1] );
    }    
    
    system( "PAUSE" );
    return 0;
}   