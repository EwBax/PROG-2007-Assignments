<img width="150px" src="https://www.nscc.ca/img/aboutnscc/visual-identity-guidelines/artwork/nscc-jpeg.jpg" >

# PROG 2007 - Assignment 4
Operating with Bits, the PreProcessor and Enumerated Types  
PROG 2007: Programming II  
**Due as posted in Brightspace**

## Task
Write a C program that conforms to the requirements listed below.

### Requirements:
- You are building a magic decoder ring; a program capable of reading in lines of text and encrypting it; or reversing the process by reading an encrypted code string and decrypting it

- Encryption and decryption require you to follow a specific set of steps to encrypt, or a reverse set of steps to decrypt

- For this program we will combine the use of **bit masks** and **bitwise Exclusive Or** operations to produce the results.

- User Interface: Prompt the user for an operation – either Encrypt or Decrypt, and then for a text string, capture the input, and then do the requested action. See encryption, below.

- Set up an array of printable characters to use in a substitution cipher as one step of the encryption:
  <img width="800px" src="https://prog2007.netlify.app/assign4-substitution.png" alt="Assign 4 Substitution Cypher">
  - Note the table uses capitals. Perform a **toupper** function for each element of the input character array.

- Set up an **enumerated type** with values of ENCRYPTING and DECRYPTING to control the direction of the process based on the user’s choice.

- Set up an **encryption bitmask**, called mask with this value: *unsigned int mask = 0xa5;*

- Set up **two unsigned int arrays and a character array**, each of size 256. **HINT**: It would be awfully nice if 256 was not used as a “magic number”. These arrays will hold the character or numeric sequences

- Set up **two pre-processor macros**, ENCRYPT_DECRYPT and DECRYPT to perform the bitwise Exclusive Or. Each should **take two parameters**, the input character sequence of each line converted to an integer and the aforementioned mask. You would then use the macro with something similar to (Where x[] is an array holding the result):
  - **x[idx] = ENCRYPT_DECRYPT(numeric_text[idx], mask);** for each character in the encrypted text.

#### Encryption:

- Perform the letter offset substitution cipher from the table on all characters (non-blank entries) in the input text

- Convert each character in the substituted text to type integer. The easiest way to do this is to create a corresponding integer array and use a cast to perform the conversion of type and copy and convert each character to an entry in this integer array, including spaces

- Encrypt the integer representation of the characters in the integer array using the ENCRYPT_DECRYPT macro. This includes all of the space characters as well

- **Print out the encrypted result using decimal format so you can see the numeric value of each encoded character. Cypher groups will look something like:**
  - 334 312 545 345 323 147 312 and so on
  - Each space delimits a new character (because space characters are now encrypted as their own number sequence)

#### Decryption:

- Reverse the encryption sequence on the encrypted text to decrypt it. Remember to capture the decrypted entries in decimal (using the space delimiters for each “character”) and store them in an integer array to convert back to text

- **NOTE: It will be important to make sure that you do not have newlines in the middle of your coded messages** when copying them in as you may stop processing at the first newline, so make sure to copy cipher strings in as just one line.

- Print out the decrypted text to the console. Confirm it matches the original text from the first (plaintext) input file – it is acceptable if the decrypted message is capitalized even if the original was not (see the examples below).

#### General Procedure:

- Run a message through the encryption and copy the encrypted output.

- Run the encrypted output (AS ONE LINE) through decryption to ensure it works.

- Trade messages with your friends as a further test. Although keep the messages PG-13 as we would not want to offend anyone, even in code.

#### General requirements:

- You will need to put your functions perform ecryption and decryption routines in their **own source file called crypt.c**
- Have your pre-processor macro functions, enumeration, & function prototype declarations in a **header file called crypt.h**
- All your source files (i.e. main.c and crypt.c) should be in a **folder called “src”**
- Your header file (i.e. crypt.h) should be in a **folder called “inc”**
- Include clear comments
- Maintain a standard layout/format for the code. Be consistent with spacing or tabbing, use the layout to make nested operation visually clear.
- Provide clear visual feedback to the user

### Sample Outputs:
Encrypting a message:  
<img width="800px" src="https://prog2007.netlify.app/assign4-encrypt.png" alt="Assign 4 Encryption">

Decrypting the previously encrypted message:  
<img width="800px" src="https://prog2007.netlify.app/assign4-decrypt.png" alt="Assign 4 Decryption">

**NOTE:** In the above example the output numeric code from the previous encryption example was entered in its entirety **on one line without newlines**, but was cut off in the screenshot.

Sample of bad input:  
<img width="800px" src="https://prog2007.netlify.app/assign4-bad-input.png" alt="Assign 4 Bad Input">

## Submission Instructions
### Video Recording Submission:

You will demonstrate the completion of this project via a **video screen-capture recording** of you using CLion, GitBash, and viewing your code to show completion of the **Video Submission Checklist**, which is posted on Brightspace. You will post **either your video file or a link to it** (e.g. a Microsoft Stream recording, make sure to give the instructor permissions to watch it), to the Brightspace Assignment 4 Dropbox prior to the deadline. If you are not sure of how best to capture such a video, seek advice from the instructor prior to the deadline.

NOTE: MAKE SURE TO SHOW EVERYTHING IN THE VIDEO SUBMISSION CHECKLIST STEP-BY-STEP. YOU WILL NEED AUDIO IN THE VIDEO FOR AT LEAST THE CODE REVIEW PORTION OF THE CHECKLIST

> Written with [StackEdit](https://stackedit.io/).