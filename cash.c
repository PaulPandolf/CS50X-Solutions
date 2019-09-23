#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    float f;
    int sum = 0;
    do {
        f = get_float("Change: ");  // Amount in dollars
        printf("%f\n", f);
    } while (f < 0);
        int cents = round(f * 100); // Conversion to cents
    while (cents >= 25) {           
        sum = sum + 1;              // When quarters can be used increase sum
        cents = cents - 25;         // Subtract 25 cents
    } 
    while (cents >= 10) {
        sum = sum + 1;              // When dimes can be used increase sum
        cents = cents - 10;         // Subtract 10 cents
    } 
    while (cents >= 5) {
        sum = sum + 1;              // When nickels can be used increase sum
        cents = cents - 5;          // Subtract 5 cents
    } 
    while (cents >= 1) {
        sum = sum + 1;              // When pennies can be used increase sum
        cents = cents - 1;          // Subtract 1 cent
    } 
    printf("Total coins used: %i\n", sum); // Print total coins used (sum)
}
