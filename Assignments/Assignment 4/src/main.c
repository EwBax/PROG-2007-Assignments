#include <stdio.h>

#include "../inc/crypt.h"

int main()
{

    // holding user choice between encryption and decryption
    enum encryptOrDecrypt operationType;

    // Array to hold encrypted message, and bitmask for encryption
    unsigned int    encrypted[ARRAY_LENGTH],
                    mask = 0xa5;

                    // Array to hold unencrypted message
    char            alphaText[ARRAY_LENGTH],

                    // Array for start position of sub cipher
                    start[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C',
                               'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                               'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '!', '@', '#',
                               '$', '%', '&', '(', ')', ':', ';', '?', '.', ',', '/'},
                    // Array for substitution cipher
                    sub[] = {':', ';', '?', '.', ',', '/', '0', '1', '2', '3', '4', '5', '6',
                             '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                             'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
                             'X', 'Y', 'Z', '!', '@', '#', '$', '%', '&', '(', ')'};


    // Prompting user to choose between encryption and decryption
    printf("What operation would you like to perform (1 - Encrypt, 2- Decrypt)?\n");
    scanf("%i", &operationType);

    // Switch to choose which operation to perform
    switch (operationType) {

        case ENCRYPT:

            // Message for user
            printf("So, you want to encrypt the message!\n");

            // Calling function to encrypt, and storing length of message
            encryption(alphaText, start, sub, encrypted, mask);

            printf("\nThe encrypted message is:\n");

            // Printing the result. encrypted[i] will have the same length as alphaText,
            // so looping until end of alphaText
            for (int i = 0; alphaText[i] != '\0'; i++) {
                printf("%i ", encrypted[i]);
            }

            printf("\n");

            break;

        case DECRYPT:

            // Message for user
            printf("So, you want to decrypt the message!\n");

            // Calling function to decrypt message
            decryption(alphaText, start, sub, encrypted, mask);

            // Printing the result
            printf("\nThe decrypted message is:\n%s\n", alphaText);

            break;

        default:

            // If user enters improper input
            printf("So, you do not know what you want!");

            return 1;

    }

    return 0;
}
