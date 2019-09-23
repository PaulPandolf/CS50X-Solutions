#include <cs50.h>
#include <stdio.h>

int main(void) {
    int n;
    do  {
        n = get_int("Height: \n");
    } while (n < 1 || n > 8);
   
    for (int i = 0; i < n; i++) { // Outer loop begins 
      for (int j = n - 1; j > i; j--) // Loop print n-1 spaces
      {
          printf(" ");
      } 
      for (int j = 0; j <= i; j++)    // Loop Print i hashes 
      {
          printf("#");
      }
          printf("  ");               // Print 2 spaces
      for (int j = 0; j <= i; j++)    // Loop print i hashes
      {
          printf("#");
      }
      printf("\n");                   // Print new line
    }
    
}
