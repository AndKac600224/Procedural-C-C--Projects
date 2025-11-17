// HalfInsertion.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <iostream>


void halfInsertion( int* pTab, int nSize )
{
	for( int i = 1; i < nSize; i++ )
	{
		int temp = pTab[i];
		int p = nSize - 1;
		int l = 0;
		while( l <= p )
		{
			int m = ( l + p ) / 2;
			if( temp < pTab[m] ) p = m - 1;
			else l = m + 1;
		}

		for( int j = i - 1; j >= l; j-- )
		{
			pTab[j + 1] = pTab[j];
		}
		pTab[l] = temp;
	}

}

int main()
{
		int tab[] = { 12, 11, 13, 5, 6 };
		int n = sizeof( tab ) / sizeof( tab[0] );

		halfInsertion(tab, n);
		printf( "Posortowana tablica: \n" );
		for( int i = 0; i < n; i++ ) {
			printf( " %d ", tab[i] );
		}
		return 0;
}
