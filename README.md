# Vigenere Cypher
Program File Name: vigenere.py

**Author**: Tyler S. Budd

**Completion Date**: 9/12/2019

## Description:
A modified version of the classic Vigenere Cypher. Instead of using just letters that are confined to uppercase or lowercase,
I've allowed it to accept all ASCII characters from 32 [space] to 126 [~]. This gives the message much more security and
much harder to crack with human eyes.

## Mathematical Approach: 
At first, I was going to approach the problem by creating the matrix and using the analog "search and find" method, like what we would use in the image                             below. Instead, I found a better approach to use only mathematics. 

For example, if we were to encrypt a message with only the original 26x26 matrix, I would use the formula: 
- Encryption(i) = (Plaintext(i) + Key(i)) mod 26 
  - i = index of the string

To decode, I use the formula: 
- Decryption(i) = (Encryption(i) - Key(i) + 26) mod 26 
  - i = index of the string

Because I used 94 ASCII characters as my matrix, I modified the formulas.

## Additional Material: 
94x94 ASCII matrix used available on the file [vigenereCypherMatrix.txt](https://github.com/tsbudd/vigenereCypher/blob/main/vigenereCypherMatrix.txt)

Original 26x26 Matrix and encoding example: ![image](https://user-images.githubusercontent.com/72171224/133002328-8d6755b4-a4fb-4463-abc0-386113344050.png)
