//
//  main.c
//  number_guess
//
//  Created by Joshua Ernzen on 12/20/17.
//  Copyright © 2017 Joshua Ernzen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int nonIntDetector(char *input, unsigned long stringLength) {
    short int inputCounter, intCounter, nonIntDetect, intDetect;
    char Numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    nonIntDetect = 0;
    intDetect = 0;
    
    for(inputCounter = 0; inputCounter < stringLength; inputCounter++)
        for(intCounter = 0; intCounter < 10; intCounter++) {
            if(input[inputCounter] == Numbers[intCounter]) {
                intDetect++;
                break;
            }
            if(intDetect != inputCounter) {
                puts("Numbers only, please.");
                
                return 1;
            }
        }
    return nonIntDetect;
}


int main() {
    short int playAgain, loopChecker, randomNumber, intInput;
    char userInput[16], anotherGame[16];
    
    loopChecker = 1;
    
    puts("Random number guessing game.");
    
    do {
        randomNumber = arc4random_uniform(101);
        do {
            do {
                printf("Enter your guess: ");
                fgets(userInput, sizeof(userInput), stdin);
            }
            while(nonIntDetector(userInput, strlen(userInput)));
            
            intInput = atoi(userInput);
            
            if(intInput > randomNumber)
                puts("Too High.");
            
            else if(intInput < randomNumber)
                puts("Too low.");
        }
        while(intInput != randomNumber);
        
        puts("You win!");
        
        do {
            do {
                puts("Another game?");
                puts("1. Yes, 2. No");
                
                fgets(anotherGame, sizeof(anotherGame), stdin);
            }
            while(nonIntDetector(anotherGame, strlen(anotherGame)));
            
            playAgain = atoi(anotherGame);
            
            if(playAgain == 2) {
                playAgain = 0;
                loopChecker = 0;
                continue;
            }
            else if(playAgain == 1) {
                loopChecker = 0;
                continue;
            }
            else
                loopChecker = 1;
        }
        while(loopChecker && puts("Invalid option."));
    }
    while(playAgain == 1);
    
    return 0;
}
