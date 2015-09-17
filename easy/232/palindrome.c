#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool getTextFromFile(char filePath[], char** string);
void freeStringArray(char** arr, int size);
void removeNonAlpha(char* string);
bool isPalindrome(char* string);

int main(int argc, char *argv[])
{
  //no arguments
  if (argc == 1){
    fputs("No Arguments. Usage: palindrome.exe <filepath>.., ", stderr);
    exit(0);
  }

  //get text from text file
  char* string = NULL;
  if (getTextFromFile(argv[1], &string)){
    printf("Input:\n%s", string);
    removeNonAlpha(string);

    char* result = isPalindrome(string) ? "Palindrome" : "Not a Palindrome";
    printf("\n------------------\nResult: %s", result);

    free(string);
  } else {
    exit(0);
  }

  return 0;
}

bool getTextFromFile(char filePath[], char** string)
{
  FILE *file;
  file = fopen(filePath, "r");

  if (file == NULL){
    fprintf(stderr, "Error opening file %s", filePath);
    return false;
  }

  //check for number of lines given
  const int BUFF_SIZE = 1000;
  char buffer[1000];
  int lineCount;

  //check the first line and store it into buffer
  if (fgets(buffer, BUFF_SIZE, file) == NULL){
    return false;
  }

  //get linecount. line count of 0 means error or actaul 0 which will not be a palindrome
  lineCount = atoi(buffer);
  if (lineCount <= 0) {
    fprintf(stderr, "Error: Line count is invalid");
    return false;
  }

  //create array to hold all the lines
  char** lines = malloc(sizeof(char*) * lineCount);

  int totalCharacterCount = 0;
  for (int i = 0; i < lineCount; i++){
    if (fgets(buffer, BUFF_SIZE, file) != NULL) {
      int stringLength = strlen(buffer);
      totalCharacterCount += stringLength;

      lines[i] = malloc((sizeof(char) * stringLength) + 1);
      strcpy(lines[i], buffer);
    } else {
      fprintf(stderr, "Error: Invalid lines in file");
      freeStringArray(lines, i);
      return false;
    }
  }

  //concatnate all lines
  *string = malloc((sizeof(char) * totalCharacterCount) + totalCharacterCount);
  (*string)[0] = '\0';
  for(int i = 0; i < lineCount; i++){
    strcat(*string, lines[i]);
  }

  freeStringArray(lines, lineCount);
  fclose(file);
  return true;
}

void freeStringArray(char** arr, int size)
{
    for (int i = 0; i < size; i++){
      free(arr[i]);
      arr[i] = NULL;
    }
    free(arr);
    arr = NULL;
}

void removeNonAlpha(char* string)
{
  int index = 0;

  //if non alpha, move all characters in front back one index
  while(string[index] != '\0') {
    int testChar = (int)string[index];
    if (isalpha(testChar)){
      index++;
    }else{
      memmove(string + index, string + index + 1, strlen(string));
    }
  }

}

bool isPalindrome(char* string)
{
  //convert all characters to lower case
  for (int i = 0; i < strlen(string); i++) {
    string[i] = tolower(string[i]);
  }

  for (int i = 0, j = strlen(string) - 1; i <= j; i++, j--){
    if (string[i] != string[j]){
      return false;
    }
  }

  return true;
}
