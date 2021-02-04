#include "sandpile.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * defined constants
 */
#define SIDE_LENGTH 23
#define HEIGHT 8 //height at which it spills over
#define CENTER 11

//int sandPile[SIDE_LENGTH][SIDE_LENGTH];

void printPiles(int piles[SIDE_LENGTH][SIDE_LENGTH]);
void spill(int pile[SIDE_LENGTH][SIDE_LENGTH], int row, int col);

int main(int argc, char** argv) {
    //variable declared
    int sandPile[SIDE_LENGTH][SIDE_LENGTH];
    int j, i, z, c, row, col, value;


    //setting up a grid with all 0s
    for (j = 0; j < SIDE_LENGTH; j++) {
        for (i = 0; i < SIDE_LENGTH; i++) {
            sandPile[j][i] = 0;
        }
    }

    for (z = 1; z < argc; z++) {
        row = atoi(argv[z]);
        col = atoi(argv[z+1]);
        value = atoi(argv[z+2]);
        if(row == CENTER && col == CENTER && value ==-1){
            printf("Sorry that is invalid! The center cannot be a sink. Please try again\n");
            return 0;
        }
        sandPile[row][col] = value;
        z = z+2;
    }


    //infinite loop to continue updating the grid
    while(1){
        sandPile[CENTER][CENTER]++;
        printPiles(sandPile);
        printf("\n");
        if(sandPile[CENTER][CENTER]>=HEIGHT){
            spill(sandPile, CENTER, CENTER);
        }

        usleep(1000000);
    }

    return 0;
}


void printPiles(int pile[SIDE_LENGTH][SIDE_LENGTH]) {
    int i, j;
    for (j = 0; j < SIDE_LENGTH; j++) {
        for (i = 0; i < SIDE_LENGTH; i++) {
            if(pile[j][i] != -1) {
                printf("%3d ", pile[j][i]); //field width so all of them have the same width
            }
            else{
                printf("  # ");
            }
        }
        printf("\n");
    }
}

void spill(int pile[SIDE_LENGTH][SIDE_LENGTH], int row, int col){
    pile[row][col] = pile[row][col]-8;

    //bottom row
    if(row+1<23){
        if(col+1< 23) {
            if(pile[row+1][col+1]>=0 && pile[row+1][col+1]<HEIGHT) {
                pile[row+1][col+1]++;
            }
            else if(pile[row+1][col+1]>=HEIGHT){
                spill(pile, row+1, col+1);
            }
        }
        if(col-1 >= 0) { //changed
            if(pile[row+1][col-1]>=0 && pile[row+1][col-1]<HEIGHT) {
                pile[row+1][col-1]++;
            }
            else if(pile[row+1][col-1]>=HEIGHT){
                spill(pile, row+1, col-1);
            }
        }
        if(pile[row+1][col]>=0 && pile[row+1][col]<HEIGHT) {
            pile[row+1][col]++;
        }
        else if(pile[row+1][col]>=HEIGHT){
            spill(pile, row+1, col);
        }
    }
    //top row
    if(row-1>0) {
        if(col+1< 23) {
            if(pile[row-1][col+1]>=0 && pile[row-1][col+1]<8) {
                pile[row-1][col+1]++;
            }
            else if(pile[row-1][col+1]>=HEIGHT){
                spill(pile, row-1, col+1);
            }
        }
        if(col-1 >= 0) {
            if(pile[row-1][col-1]>=0 && pile[row-1][col-1]<HEIGHT) {
                pile[row-1][col-1]++;
            }
            else if(pile[row-1][col-1]>=HEIGHT){
                spill(pile, row-1, col-1);
            }
        }
        if(pile[row-1][col]>=0 && pile[row-1][col]<HEIGHT) {
            pile[row-1][col]++;
        }
        else if(pile[row-1][col]>=HEIGHT){
            spill(pile, row-1, col);
        }
    }
    //right and left middle
    if(col+1< 23) {
        if(pile[row][col+1]>=0 && pile[row][col+1]<HEIGHT) {
            pile[row][col+1]++;
        }
        else if(pile[row][col+1]>=HEIGHT){
            spill(pile, row, col+1);
        }
    }

    if(col-1 >= 0) {
        if(pile[row][col-1]>=0 && pile[row][col-1]<HEIGHT) {
            pile[row][col-1]++;
        }
        else if(pile[row][col-1]>=HEIGHT){
            spill(pile, row, col-1);
        }
    }
    if(pile[row][col]>=0 && pile[row][col]<HEIGHT) {
        pile[row][col]++;
    }
    else if(pile[row][col]>=HEIGHT){
        spill(pile, row, col);
    }
}


