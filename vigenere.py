"""
Program Name: vigenere.py
Author: Tyler S. Budd
Completion Date: 9/12/2019
Description: A modified version of the classic Vigenere Cypher. Instead of using just letters that are confined to uppercase or lowercase,
                i've allowed it to accept all ASCII characters from 32 [space] to 126 [~]. This gives the message much more security and
                much harder to crack with human eyes.
Additional Material: ASCII matrix used available on the file vigenereCypherMatrix.txt
"""
import time

#------------------------------------------------------- ENCRYPTION/DECRYPTION METHODS --------------------------------------

def encrypt(message, key):
    retString = "" # init encrypted string
    j = 0 #index key

    #goes through all the chars in the message, and encodes them to fit within the 32-126 ASCII values
    for char in range(len(message)):
        if j == len(key): #resets the key index if key is much shorter than original message
            j = 0 
        
        #converting chars to ascii numerical values, setting the bottom of the range to 0 instead of 32
        plainNum = ord(message[char])-32
        keyNum = ord(key[j])-32

        encryptChar = (plainNum + keyNum) % 94 #vigenere encryption formula

        retString = retString + chr(encryptChar+32)

        #increments the key index
        j += 1

    print("\nEncrypted Message:\t%s" % retString)

def decrypt(message, key):
    retString = "" #init decrypted string
    j = 0 #index key

    #goes through all the chars in the message, and decodes them to return original message
    for char in range(len(message)):
        if j == len(key): #resetting key index
            j = 0

        #converting chars to ASCII numerical values, setting the bottom of the range to 0 instead of 32
        plainNum = ord(message[char])-32
        keyNum = ord(key[j])-32

        encryptChar = (plainNum - keyNum + 94) % 94 # vigenere decryption formula
        retString = retString + chr(encryptChar+32)
        
        #increments key index
        j += 1
        
    print("\nDecrypted Message:\t%s" % retString)


#-------------------------------------------------------- BEGIN MAIN CODE ----------------------------------------------


def iteration():
    mode = 0 #if 0, then program set to decryption mode, else if 1 it'll set to encryption
    print("To ENCRYPT a message, type 'encrypt' and press ENTER\nTo DECRYPT a message, type 'decrypt' and press ENTER\n")
    while mode == 0:
        selection = input("Selection:\t")
        if selection == "encrypt":
            mode = 1
            break

        elif selection == "decrypt":
            mode = 0
            break

        #ERROR CASE
        else:
            print("\nYou did not type 'encrypt' or 'decrypt'. Try again.\n")
        

    if mode == 0:
        #getting encrypted message
        message = input("\nCOPY/PASTE or TYPE encrypted message here and press ENTER:\t")
        
        #getting key
        key = input("\nType in the key phrase to decrypt and press ENTER:\t")

        decrypt(message, key)

    else:
        #getting encrypted message
        message = input("\nCOPY/PASTE or TYPE plaintext message here and press ENTER:\t")

        #getting key
        key = input("\nType in the key phrase to encrypt and press ENTER:\t")

        encrypt(message, key)

    restart = input("\nWould you like to restart encoding/decoding process? (Y/N):\t")
    while True:
        if restart == "y" or restart == "Y":
            print()
            iteration()
        elif restart == "n" or restart == "N":
            print("\nGoodbye")
            time.sleep(3)
            exit()
        else:
            restart = input("\nIncorrect format: press (Y/N):\t")


print("Welcome to the Vigenere Cypher Program!\nCreated by: TYLER S. BUDD\nCreation date: September 12th, 2021")
print("NOTE: This encryption program only encrypts/decrypts letters, numbers, and basic punctuation.\n\t Any symbol/letter not found on a US keyboard will result in failure.\n")
iteration()