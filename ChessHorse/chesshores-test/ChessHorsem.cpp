

#include <stdio.h>
#include <stdlib.h>
#include "ChessHorse.h"
//#include <string.h> //for memset
/*
#define CHESSBOARD_SIZE 6 //5 | 6 | 7
#define HORSE_MOVES 8

enum HMoves //ilosc ruchow skoczka - rodzai 
{
    FIRST,
    SECOND,
    THIRD,
    FOURTH,
    FIFTH,
    SIXTH,
    SEVENTH,
    EIGHT
};

struct Point
{
    int x;
    int y;
};
*/
int allMoves = 0; //zlicza ruchy (good and wrong)



int** createChessboard( int nDim )
{
    int** pChessBoard = NULL;
    pChessBoard = ( int** )calloc( nDim, sizeof( int* ) );
    if( pChessBoard == NULL ) 
    {
        return NULL; 
    }
    int* p = *pChessBoard = ( int* )calloc( nDim * nDim, sizeof( int ) );
    if( *pChessBoard == NULL ) 
    {
        return NULL; 
    }

    int** v = pChessBoard + 1; 

    for( int i = 1; i < nDim; i++ )     
    {
        p += nDim;
        *v++ = p;


    }
    return pChessBoard; 
}

void freeChessboard( int*** pChessBoard )
{
    free( **pChessBoard );
    /*if(*pChessBoard == NULL)
    {
    return; 
    }

    for( int i = 0; i < CHESSBOARD_SIZE; ++i )      
    {
    free( ( *pChessBoard )[ i ] ); //deallocation na i-ty elementy
    }*/
    free( *pChessBoard ); // deallocation na tab of pointers
    *pChessBoard = NULL; // gwarancja braku dostêpu do "zfreeowanego" elementu szachownicy
}


void printChessBoard( int** pChessBoard, int nDim ) //printuje szachownice 
{
    for( int i = 0; i < nDim; i++  ) 
    {                                           
        int *p = *pChessBoard++;
        for( int j = 0; j < nDim; j++ ) 
        {
            printf( "%d\t", *p++ );
        }
        printf( "\n\n\n" );
    }
}

int move( int** pChessBoard, int nDim, int move, int x, int y, int* px, int* py, Point* pHorseMoves )
{
    *px = x + pHorseMoves[ move ].x; //nowa wspolrzedne skoczka(skok o wspolrzedna x i nadpisanie x)
    *py = y + pHorseMoves[ move ].y; //nowa wspolrzedne skoczka(skok o wspolrzedna y i nadpisanie y

    if( *px >= 0 && *px < nDim && *py >= 0 && *py < nDim && pChessBoard[*px][*py] == 0 ) //...==0 -> czy pole jest puste
    {
        return 1;
    }
    return 0;   //...==1 -> blad jak jest w szachownicy ale trafil na pole ktore juz byl - wraca sie ale zalicza ruch do allMoves
}
//--------------------------------------------------------------------------


int root( int** pChessBoard, int nDim, int x, int y, Point* pHorseMoves )
{
    static int moveNo = 0; //zmienna statyczna - zmienna globalna o zasiêgu funkcji - zahcowuje wartosc z ostatniego dzia³ania
    pChessBoard[ x ][ y ] = moveNo; //nr ruchu (only good)
    allMoves++; // zwiêkszamy licznik ruchów za ka¿dym razem, gdy wywo³ujemy funkcjê root

    if( moveNo++ == nDim * nDim ) //jesli przejdzie przez wszystkie pola jednokrotnie to konczy - np 8x8 = 64 ruchy dobre
    {                           //moveNo!= allMoves bo zliczaja odpowiedno dobre oraz dobre&zle ruchyy - wtedy gdy moveNo zliczy pole szachownicy 
                                //to wyswietla wszystkie ruchy allMoves bo program sie skonczyl
        printf( "\nAll moves: %d\n", allMoves );
        return 1;
    }

    for( int i = FIRST ; i <= EIGHT; i++) 
    {
        int nextX;
        int nextY;
        if( move( pChessBoard, nDim, i, x, y, &nextX, &nextY, pHorseMoves ) ) 
        {
            if( root( pChessBoard, nDim, nextX, nextY, pHorseMoves) ) 
            {
                return 1; //dobre bo znazazl "legalny" ruch
            }
        }
    }

    moveNo--;

    pChessBoard[ x ][ y ] = 0;
    return 0; //wraca sie jak nie jest to "legalny" ruch
}