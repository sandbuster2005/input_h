#include <stdio.h>
#include "input.h"
#include <termios.h>
#include <unistd.h>
#include <string.h>

char C1[] = c1;
char C2[] = c2;
char C3[] = c3;
char C4[] = c4;
char C5[] = c5;

static struct termios old;

void enable_raw(void) {
    struct termios raw;
    tcgetattr(STDIN_FILENO, &old);
    raw = old;
    raw.c_lflag &= ~(ICANON | ECHO);
    raw.c_cc[VMIN] = 1;
    raw.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

void disable_raw(void) {
    tcsetattr(STDIN_FILENO, TCSANOW, &old);
}



void input( char key[6] ){
    for(int i = 0 ; i < 6 ; i++){key[i] = ' '; }


    key[0] = fgetc(stdin);

    if ( !check_in(C1 , key[0 ]) ){
        return ;
    }

    key[1] = fgetc(stdin);

    if ( !check_in(C2 , key[1]) ){
        return ;
    }

    key[2] = fgetc(stdin);

    if ( !check_in(C3 , key[2]) ){
        return ;
    }

    key[3] = fgetc(stdin);

    if ( !check_in(C4 , key[3]) ){
        return ;
    }

    key[4] = fgetc(stdin);

    if ( !check_in(C5 , key[4 ]) ){
        return ;
    }

    key[5] = fgetc(stdin);
    return ;

}


int is_key(char string[], char key[] ){

    char complete_key[6] = {' ',' ',' ',' ',' ',' '};
    int i = 0;

    while( key[i] != END){
        complete_key[i] = key[i];
        i++;
    }

    return !strcmp( string, complete_key);
}




int check_in( char key[], char compared ){
    int i = 0;

    while (key[i] != END ){
        if ( key[i] == compared  ){
            return 1;
            }
        i++;
        }

    return 0;
    }


//int main(){
//    char table[6] ;
//    enable_raw();
//    input( table );
//    for( int i = 0; i < 6; i++){printf("%d\n", (int) table[i] );}
//
//}
