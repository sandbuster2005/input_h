#ifndef INPUT_H
#define INPUT_H

#define END ' '


#define c1 { '\x1b' , END}
#define c2 { '\x4' , '\x5B', END }
#define c3 { '\x31', '\x32', '\x33', '\x35', '\x36', END }
#define c4 { '\x30', '\x31', '\x32', '\x33', '\x34', '\x35', '\x37', '\x38', '\x39','\x3B' , END }
#define c5 { '\x30', '\x31', '\x32', '\x33', '\x34', '\x35', '\x37', '\x38', '\x39', '\x3B', END }

#define RIGHT "\x1B[C "
#define LEFT "\x1B[D "
#define UP "\x1B[A "
#define DOWN "\x1B[B "
#define ENTER "\x0A "


void input( char key[6] );

int check_in( char key[], char compared );

int is_key( char string[], char key[] );

void enable_raw(void);

void disable_raw(void);

#endif
