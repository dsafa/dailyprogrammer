#[`[easy`] challenge #232](https://www.reddit.com/r/dailyprogrammer/comments/3kx6oh/20150914_challenge_232_easy_palindromes/)

##Description

A palindrome is a word or sentence that is spelled the same backwards and forwards. A simple of example of this is Swedish pop sensation ABBA, which, when written backwards, is also ABBA. Their hit song (and winner of the 1974 Eurovision Song Contest!) "Waterloo" is not a palindrome, because "Waterloo" backwards is "Oolretaw".
Palindromes can be longer than one word as well. "Solo gigolos" (the saddest of all gigolos) is a palindrome, because if you write it backwards it becomes "Sologig olos", and if you move the space three places back (which you are allowed to do), that becomes "Solo gigolos".
Today, you are going to write a program that detects whether or not a particular input is a valid palindrome.

##Formal inputs & outputs
###Inputs

On the first line of the input, you will receive a number specifying how many lines of input to read. After that, the input consists of some number of lines of text that you will read and determine whether or not it is a palindrome or not.
The only important factor in validating palindromes is whether or not a sequence of letters is the same backwards and forwards. All other types of characters (spaces, punctuation, newlines, etc.) should be ignored, and whether a character is lower-case or upper-case is irrelevant.

###Outputs

Output "Palindrome" if the input is a palindrome, "Not a palindrome" if it's not.
