/*==================
BACKTRACKING  - algorytm z nawrotami
-------------
ogólny algorytm wyszukiwania wszystkich (lub kilku) rozwiązań 
niektórych problemów obliczeniowych, który stopniowo generuje 
kandydatów na rozwiązanie jednak, gdy stwierdzi, że znaleziony 
kandydat x nie może być poprawnym rozwiązaniem, nawraca (ang. "backtracks") 
do punktu, gdzie może podjąć inną decyzje związaną z jego budową
==============================*/

#include "ChessHorse.h"




int main( int argc, char* argv[] )
{
    if( argc != 3 ) 
    {
        printf( "Usage: %s firstX firstY\n", argv[0] );
        return 1;
    }

    int firstX = atoi( argv[1] );       //przekazujemy argumenty
    int firstY = atoi( argv[2] );

    if( firstX < 0 || firstX >= CHESSBOARD_SIZE || firstY < 0 || firstY >= CHESSBOARD_SIZE ) 
    {
        printf( "Wrong starting position (beyond chessboard).\n" ); //poza szachwnica - trzeba wybrac inny punkt początk.
        return 1;
    }

    int** pChessBoard = createChessboard( CHESSBOARD_SIZE ); //tworzy tablice 2D jako szachownica o danych rozmiarach

    Point HorseMove[ HORSE_MOVES ] = {   {-2, 1},           //wszystkie mozliwe ruchy (wspolczynniki na macierzy)
                                         {-1, 2}, 
                                         {1, 2}, 
                                         {2, 1}, 
                                         {2, -1},  
                                         {1, -2},  
                                         {-1, -2}, 
                                         {-2, -1}     };

    if( !root( pChessBoard, CHESSBOARD_SIZE, firstX, firstY, HorseMove ) ) 
    {
        printf( "There is no option to visit one chessplace at once.\n\n" ); //niemozliwe wykonanie takiej operacji
    } 
    else
    {
        printChessBoard( pChessBoard, CHESSBOARD_SIZE ); //printuje szachownice
    }

    

    freeChessboard( &pChessBoard ); //zwalnia pamiec komorek szachownicy (Tab2D)

    return 0;
}

/*

Kwadratowa szachownica (n x n) 
Liczba możliwych ścieżek konika szachowego 
1x1    1     
2x2    0   // nie ma ruchu  
3x3    0   // sa pozycje blokujace  
4x4    0   // sa pozycje blokujace  
5x5    1728    
6x6    6’637’928     
7x7    165’575’218’320 
*/