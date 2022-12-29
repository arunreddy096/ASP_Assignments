//reference taken from geeksforgeeks link : https://www.geeksforgeeks.org/making-linux-shell-c/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void CommandsExecute(char** commands)
{
    // Fork
    pid_t f = fork();
    if (f == 0) { //child
        if (execvp(commands[0], commands) < 0) {
            printf("\n invalid command provided..");
            exit(0);
        }
    } else {
        // waiting for child to terminate
        wait(NULL);
        return;
    }
}

void StringFormatter(char* str, char** commandString)
{
    int i =0;
   // printf("string %s", str);
    commandString[i] = strsep(&str, " ");
    while( commandString[i] != NULL){
        i++;
        commandString[i] = strsep(&str, " ");
        //printf("command: %s", commandString[i] );
    }
    commandString[i] = NULL;
    //printf("string %s", CommandString[1]);
}

int main()
{
    char String_Input[1000], *Args[100];
    printf("\n\t** Arun Reddy's MINI BASH **\n");
    char* uname = getenv("USER");
    printf("\nUSER : @%s\n", uname);
    while (1) {
        // print tag shell line
        printf("\nminibash>");
        // take input in the char array pointer
        fgets(String_Input,100,stdin);
        // replacing next line char with '\0'
        String_Input[strlen(String_Input) -1 ] = '\0';
        //printf("input string %s \n", inputString);
        //printf("input string\n");
        StringFormatter(String_Input, Args);
        CommandsExecute(Args);
    }
    return 0;

}
