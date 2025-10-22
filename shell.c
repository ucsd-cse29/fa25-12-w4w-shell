#include <string.h>
#include <stdio.h>

const int CMD_LENGTH = 1000;

// Fill in result with char* (string) elements that are the space-separated parts of cmd
int parse_args(char* cmd, char** result) {
  // Put return values from strtok into result
  char* current = strtok(cmd, " ");
  int i = 0;
  while(current != NULL) {
    result[i] = current;
    current = strtok(NULL, " ");
    i += 1;
  }
  return i;
}

int main() {
  char cmd[CMD_LENGTH];
  char* args[CMD_LENGTH]; // is this the right type?
  
  while(1) {
    printf("» ");                   // Maybe print current dir before »
    fgets(cmd, CMD_LENGTH, stdin);

    cmd[strcspn(cmd, "\n")] = '\0'; // replaces newline if present with null terminator

    // “parse” the command line into an array of strings

    // What is the type of an array of strings in C? Talk about it!
    // Our _result_ ought to be a char**
    int argc = parse_args(cmd, args);

    // This is where we run the program! execvp() and fork()
    printf("The command is: %s\n", args[0]);
    printf("The args are: ");
    for(int i = 0; i < argc; i += 1) {
      printf("%s, ", args[i]);
    }
    printf("\n");
  }
  return 0;
}
