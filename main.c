/* 
 * File:   main.c
 * Author: Alvarez, Famat, Sotto
 *
 * Created on February 12, 2019, 7:48 AM
 */

/*We used another MP instead of the one we submitted a few weeks back.
 *The unit tests are in the newcunittest2.c file.
 */

#include <stdio.h>

int negativeOrZero(int input){
    if (input <= 0){
        return 1;
    } else return 0;
}

int fibonacci(int number){
    int seq1, seq2, sum, ctr, total = 0;
    seq1 = 1;
    seq2 = 1;
    sum = seq1 + seq2;
    ctr = 0;

    while (ctr < number) {
            printf("%i ", seq1);
            total += seq1;
            seq1 = seq2;
            seq2 = sum;
            sum = seq1 + seq2;
            ctr = ctr + 1;
                  
    }
    return total;
}

int main() {
	int n, seq1, seq2, sum, ctr;

	printf("\nEnter a positive number: ");
	scanf("%i", &n);
        
        if (negativeOrZero(n) == 1){
            return 0;
        }
        
        return fibonacci(n);
        
	return 0;
	
}

