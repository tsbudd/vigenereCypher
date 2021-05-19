/** FILE NAME : vigenere.c
 * @author Tyler S. Budd
 * @date 5/18/2021
 * DESCRIPTION : A vigenere cypher program that uses a modified encryption matrix to encode/decode messages
 * CIPHER INFO LINK : https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher
 * TYLER'S GITHUB LINK : https://github.com/tsbudd
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * This is the original vigenere encryption/decryption matrix. It may replace the matrix in the main method.
 * If it does replace the modified matrix, the rest of the program needs to be modified to ignore punctuation and spaces during encryption/decryption
 */
void altMatrix(){
    //ascii start @ 65 end at 90
    char matrix[27][27];

    //k is index value, i is column, j is row
    int k;
    char c;
    for (int i = 65; i < 91; i++){
        k = i;
        for (int j = 65; j < 91; j++){
            if (k == 91){
                k = 65;
            }
            int column = i-65;
            int row = j-35;
            c = k; //converting int value to char
            matrix[column][row] = c;
            printf("%c ", c);

            k++;
        }
        printf("\n");
    }
}


// TODO: create encryption
void encrypt(char* input, char* key, int matrix[95][95]){
    int inStrLength = strlen(input);
    int keyStrLength = strlen(key);

    int asciiCol, asciiRow;
    char decryptChar;
    int j = 0;
    for (i = 0; i < inStrLength; i++){
        if (i >= keyStrLength){
            j = 0
        }else{
            j++;
        }

        asciiCol = input[i]; //gets the ascii value of character in input string [aka: column(i)]
        asciiRow = key[j]; //gets the ascii value of character in key string [aka: row(i)]

        decryptChar = matrix[asciiCol][asciiRow];

        printf("%c", decryptChar);

        j++;
    }

}

// TODO: create decryption
void decrypt(char* input, char* key, char matrix[95][95]){
    //go through each letter in the row used by the key, if the letter at the index of the row is the same as the letter of the index
    //in the input, then print the column index as a char

}

int main(){
    //---------------------------------CREATING MODIFIED ENCRYPTION MATRIX --------------------------

    //ascii start at 32 ( VALUE = [SPACE] ) end at 126 ( VALUE = ~ )
    int matrix[95][95];

    //k is index value (int), c is index value (char) i is column, j is row
    int k;
    for (int i = 32; i < 127; i++){
        //start each row with next ascii character
        k = i;

        for (int j = 32; j < 127; j++){
            if (k == 127){
                k = 32; //reset back to 32 to avoid going out of bounds
            }
            
            //getting matrix coordinates
            int column = i-32;
            int row = j-32;

            //setting matrix value
            matrix[column][row] = k;

            k++;
        }
    }
    
    // UNCOMMENT NEXT LINES TO PRINT MATRIX
    // char index;
    // for (int i = 0; i < 95; i++){
    //     for (int j = 0; j < 95; j++){
    //         index = matrix[i][j];
    //         printf ("%c", index);
    //     }
    //     printf("\n");
    // }

    
    //--------------------------------------WELCOME TEXT & SETTING ENCRYPTION/DECRYPTION--------------
    //welcome text/instructions
    printf("\nWelcome to the Vigenere Cypher Program!\nCreated by: TYLER S. BUDD\nCreation date: May 5th, 2021\n");
    printf("NOTE: This encryption program only encrypts/decrypts letters and basic punctuation. Any symbol/letter not found on a US keyboard will result in failure.\n\n");

    //encrypt or decrypt
    char selection[7];
    bool mode = false; //if false, then program set to decryption mode, else set to encryption
    printf("To ENCRYPT a message, type 'encrypt' and press ENTER\nTo DECRYPT a message, type 'decrypt' and press ENTER\n");
    while (true){
        printf("Selection: ");
        scanf("%s", selection);
        if (strcmp(selection, "encrypt") == 0){
            mode = true;
            break;

        }else if (strcmp(selection, "decrypt") == 0){
            mode = false;
            break;

        }else{
            printf("\nYou did not type 'encrypt' or 'decrypt'. Try again.\n");
        }

    }

    //-----------------------------------ENCRYPTION/DECRYPTION--------------------------------------
    
    if (!mode){
        char* message;
        printf("\nCopy/Paste encrypted message here and press ENTER: \n");
        scanf("%s", &message);

        char* key;
        printf("\nType in the key phrase to decrypt and press ENTER: ");
        scanf("%s", &key);

        //TODO decode
        decrypt(message, key, matrix);

    }else{
        char* message;
        printf("\nCopy/Paste original message here and press ENTER: \n");
        scanf("%s", &message);

        char* key;
        printf("\nType in the key phrase to encrypt and press ENTER: ");
        scanf("%s", &key);

        //TODO encode
        encrypt(message, key, matrix);
    }
    


    
    return 0;
}