#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "sorting.h"

void forheap( int* tab, int l, int p );
void forquick( int* tab, int l, int p );

//---------------------------------------------------
void InsertionSort( int* tab, int n ) 
{
	for( int i = 1; i < n; i++ ) {
		int temp = tab[ i ];
		int j = i - 1;
		while( j >= 0 && tab[ j ] > temp ) tab[ j + 1 ] = tab[ j-- ];
		tab[ j + 1 ] = temp;
	}
}

//---------------------------------------------------
void SelectionSort( int* tab, int n ) 
{
	for( int i = 0; i < n - 1; i++ ) 
	{
		int temp2 = i;
		int min = tab[ i ];
		for( int j = i + 1; j < n; j++ ) 
		{
			if( tab[ j ] < min ) 
			{
				min = tab[ j ];
				temp2 = j;
			}
		}
		tab[ temp2 ] = tab[ i ];
		tab[ i ] = min;
	}
}

//---------------------------------------------------
void BubbleSort( int* tab, int n ) 
{
	for( int i = 0; i < n - 1; i++ ) 
	{
		for( int j = n - 1; j > i; j-- ) 
		{
			if( tab[ j ] > tab[ j - 1 ] ) 
			{
				int temp = tab[ j ];
				tab[ j ] = tab[ j - 1 ];
				tab[ j - 1 ] = temp;
			}
		}
	}
}

//---------------------------------------------------
void MixSort( int* tab, int n ) 
{
	int k = n;
	int l = 1;
	int p = n - 1;
	do 
	{
		for( int j = p; j >= l; j-- ) 
		{
			if( tab[ j - 1 ] > tab[ j ] ) 
			{
				int temp = tab[ j - 1 ];
				tab[ j - 1 ] = tab[ j ];
				tab[ j ] = temp;
				k = j;
			}
		}
		l = k + 1;
		for( int j = l; j <= p; j++ ) 
		{
			if( tab[ j - 1 ] > tab[ j ] ) 
			{
				int temp = tab[ j - 1 ];
				tab[ j - 1 ] = tab[ j ];
				tab[ j ] = temp;
				k = j;
			}
		}
		p = k - 1;
	} while( l <= p );
}


//---------------------------------------------------
void HeapSort( int* tab, int n ) 
{
	int p = n - 1; 
	for( int i = n / 2; i >= 0; i-- ) forheap( tab, i, p );
	for( p ; p > 0; p-- ) {
		int temp = tab[ 0 ];
		tab[ 0 ] = tab[ p ];
		tab[ p ] = temp;
		forheap( tab, 0, p - 1 );
	}
}

void forheap( int* tab, int l, int p ) {
	if( l >= p ) return;
	int i = l;
	int j = 2 * i + 1;
	int temp = tab[i];
	while( j <= p ) {
		if( ( j < p ) && ( tab[j] > tab[j + 1] ) ) j++;
		if( temp <= tab[j] ) break;
		tab[i] = tab[j];
		i = j;
		j = 2 * i + 1;
	}
	tab[i] = temp;
}


//---------------------------------------------------
void HalfSort( int* tab, int n ) 
{
	for( int i = 1; i < n - 1; i++ ) 
	{
		int temp = tab[i];
		int p = i - 1;
		int j = 0;
		while( j <= p ) 
		{
			int m = ( j + p ) / 2;
			if( temp < tab[m] ) p = m - 1;
			else j = m + 1;
		}

		for( int k = i - 1; k >= j; k-- ) {
			tab[k + 1] = tab[k];
		}
		tab[j] = temp;
	}
}



//---------------------------------------------------
void QuickSort( int* tab, int n )
{
	forquick( tab, 0, n - 1 );
}

void forquick( int* tab, int l, int p ) {
	int i = l;
	int j = p;
	int temp = tab[ (l + p) / 2 ];
	do 
	{
		while( tab[ i ] < temp ) i++;
		while( tab[ j ] > temp ) j--;
		if( i <= j )
		{
			int w = tab[ i ];
			tab[ i ] = tab[ j ];
			tab[ j ] = w;
			i++;
			j--;
		}
	} while( i <= j );

	if( j > l ) forquick( tab, l, j );
	if( i < p ) forquick( tab, i, p );
}