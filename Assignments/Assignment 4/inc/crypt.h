#ifndef ASSIGN4_CRYPT_H
#define ASSIGN4_CRYPT_H

// Constant for array length
#define ARRAY_LENGTH 256

// Preprocessor Macros
#define ENCRYPT_DECRYPT(numericText, mask) ((numericText) ^ (mask))


// Enumeration for checking which operation user chooses at runtime
enum encryptOrDecrypt {
    ENCRYPT = 1,
    DECRYPT
};


// Prototype function declarations
void substitutionCipher(char * alphaText, char * start, char * sub);


// Function for converting char array to int array
void charToInt(char * alphaText, unsigned int * numericText);


// Function for converting int array to char array
void intToChar(char * alphaText, unsigned int * numericText, int messageLength);


// Function for encrypting
void encryption(char * alphaText,
               char * start,
               char * sub,
               unsigned int * encrypted,
               unsigned int mask);


// Function for decrypting
void decryption(char * alphaText,
                char * start,
                char * sub,
                unsigned int * encrypted,
                unsigned int mask);


// Function to get encrypted message as String then convert to unsigned int array
int inputEncryptedMessage(unsigned int * encrypted);


#endif //ASSIGN4_CRYPT_H
