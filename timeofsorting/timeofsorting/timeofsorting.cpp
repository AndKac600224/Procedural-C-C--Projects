#include <stdio.h>
#include <memory.h>
#include <time.h>
#include <stdlib.h>
#include "sorting.h"

//#define DEBUG
#define MAXPRINT 10
#define MAX 50

int CreateTab( int** pTab, int nSize );
void PrintTab( int* pTab, int nSize );
void initTab( int* pTab, int nSize );

typedef void( *sortFun )( int*, int );

int main( int argc, char* argv[] ) 
{
    if( argc != 2 ) 
    {
        printf( "Usage %s <tab_size>\n", argv[0] );
        return -1;
    }

    int nSize = atoi( argv[1] );

    sortFun pSortTab[] = { InsertionSort, SelectionSort, BubbleSort, MixSort, HalfSort, HeapSort, QuickSort };    //sortowania (funkcje)
    const char* pNames[] = { "InsertSort", "SelectionSort", "BubbleSort", "MixSort", "HalfSort", "HeapSort", "QuickSort" };    //nazwy sortowań

    int* pTab = NULL;
    if( !CreateTab(&pTab, nSize) ) {
        perror( "Error in Creating Tab1" );
        return -2;
    }

    int* pSortTime = NULL;
    if( !CreateTab(&pSortTime, nSize) ) {
        perror( "Error in Creating Tab2" );
        return -3;
    }
    const int num = sizeof( pSortTab ) / sizeof( sortFun ); //-1 bo NULL

    initTab( pTab, nSize );

#ifdef DEBUG
    printf( "Tablica z losowymi elementami:\n" );
    PrintTab( pTab, ( nSize > MAX ) ? MAX : nSize );
#endif

    
    for (int i = 0; i < num; i++)
    {
        memcpy( pSortTime, pTab, nSize * sizeof(int) );
        clock_t start = clock(); //funckja clock!!
        pSortTab[i]( pSortTime, nSize );
        printf( "\nSortowanie za pomoca %s zajmie: \n%f\n", pNames[i], (double)(clock() - start) / CLOCKS_PER_SEC ); // policzenie czasu i wypisanie //iloraz wyniku i sekund

#ifdef DEBUG
        printf( "Posortowana tablica:\n" );
        PrintTab( pSortTime, ( nSize > MAX ) ? MAX : nSize );
#endif
    }
    free( pSortTime );
    free( pTab );    //zwolnienie pamięci
    return 0;
}

int CreateTab( int** pTab, int nSize ) //tworzenie tablicy
{
    *pTab = ( int* )malloc( sizeof(int) * nSize );
    if( !*pTab ) return 0;
    memset( *pTab, 0, sizeof(int) * nSize );
    return 1;
}

void PrintTab( int* pTab, int nSize ) //printowanie tablicy
{
    for( int i = 0; i < nSize; i++ ) 
    {
        printf( "%d ", pTab[i] );
        if( (i + 1) % MAXPRINT == 0 ) printf("\n");
    }
}

void initTab( int* pTab, int nSize ) //liczby pseudolsoowe do tablicy
{
    srand( (unsigned int)time(NULL) );
    for( int i = 0; i < nSize; i++ )
        pTab[i] = rand() % nSize;
}

