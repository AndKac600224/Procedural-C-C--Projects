
#include <iostream>
#include <stdio.h>
#include <memory.h>



void mixedSort( int* pTab, int nSize )
{
	int k = nSize;
	int l = 1;
	int p = nSize - 1;

	do {
		for( int j = p; j >= l; j-- )
		{
			if( pTab[j] < pTab[j - 1] )
			{
				int temp = pTab[j-1];
				pTab[j-1] = pTab[j];
				pTab[j] = temp;
				k = j;
			}
		}
		l = k + 1;
		for( int j = l; j <= p; j++ )
		{
			if( pTab[j] < pTab[j - 1] )
			{
				int temp = pTab[j-1];
				pTab[j-1] = pTab[j];
				pTab[j] = temp;
				k = j;
			}
		}
		p = k - 1;

	} while( l <= p );
}

int main()
{
		int tab[] = { 8, 555, 23, 61, 2 };
		int n = sizeof(tab) / sizeof(tab[0]);

		mixedSort( tab, n );
		printf( "Posortowana tablica: \n" );
		for( int i = 0; i < n; i++ ) {
			printf( "%d ", tab[i] );
		}
		return 0;
}
	