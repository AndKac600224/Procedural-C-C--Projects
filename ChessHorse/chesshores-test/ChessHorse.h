#ifndef CHESSHORSE_H

#define CHESSHORSE_H
#include <stdio.h>
#include <stdlib.h>
//#include <string.h> //for memset

#define CHESSBOARD_SIZE 5 //5 | 6 | 7
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


int** createChessboard( int nDim );
void freeChessboard( int*** pChessBoard );
void printChessBoard( int** pChessBoard, int nDim );
int move( int** pChessBoard, int nDim, int move, int x, int y, int* px, int* py, Point* pHorseMoves );
int root( int** pChessBoard, int nDim, int x, int y, Point* pHorseMoves );

#endif