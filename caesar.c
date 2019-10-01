#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2)                                            // if input is 2 then continue if not return 1;
    {                                          
        
        for (int j = 0, n = strlen(argv[1]); j < n; j++)      // iterate over each character of 2nd argument
        {
            if (isdigit(argv[1][j]))                          // if each character is a decimal digit continue
            {                                           
            } 
            else 
            {                                          
                printf("Usage: ./caesar key\n");              // if not return 1 and printf error message
                return 1;                            
            }
        }
        
        printf("\n");                                         
        int k = atoi(argv[1]);                                // k = charater argv as integer
        string s = get_string("plaintext: ");
        printf("cyphertext: ");
        for (int i = 0; i < strlen(s); i++)                   // iterate over length of input string
        {
            if (isalpha(s[i]) && isupper(s[i])) {             // if string at location "i" is alphabetical and uppercase do this 
                int alpha = s[i] - 65;                            // convert from ASCII to alphabetcal
                alpha = (alpha + k) % 26;                         // add key 
                char cyphertext = alpha + 65;                     // convert back to ASCII from alphabetical
                printf("%c", cyphertext);                         // print cyphertext
            } else if (isalpha(s[i]) && islower(s[i])) {      // if string at location "i" is alphabetical and lowercase do this
                int alpha = s[i] - 97;                            // convert from ASCII to alphabetcal
                alpha = (alpha + k) % 26;                         // add key 
                char cyphertext = alpha + 97;                     // convert back to ASCII from alphabetical
                printf("%c", cyphertext);                         // print cyphertext  
            } else {                                          // if string a location "i" is not alphabetical
                printf("%c", s[i]);                               // print char unchanged 
            }
        }
        printf("\n");                                         // print new line
    } 
    else 
    {
        printf("Usage: ./caesar key\n");                      // if argv[1] is not a number print error text and stop the program
        return 1;
    }
}
