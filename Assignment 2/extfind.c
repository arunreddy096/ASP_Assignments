#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <stdlib.h>
#include <ftw.h>
#include <string.h>

int file_found=0;
char **fextension_args;
int arg;


static int extfind(const char *fpath, const struct stat *sb,
int typeflag, struct FTW *ftwbuf)
{
 char *bpath, *ext;
 int i = 1;
 if (typeflag == FTW_F) {
 bpath = strrchr(fpath, '/');
 //printf("%s\n", fpath);
    if (arg == 2){
        printf("%s\n", fpath);
    }
    while(fextension_args[++i] != NULL)
            {	
            	 ext = strchr(bpath,'.');
                 if( ext != NULL  && strcmp(ext + 1, fextension_args[i]) == 0) {
                 file_found=1;
                 printf("%s\n", fpath);
                 
                 }
   
            }
    }
    return 0;
}


int main(int argc, char *argv[])
{
    //printf("%d", argc);
  
 if (argc < 2) {
 	printf("please provide path!");}
 else if(argc >=12){
 printf("give  between 0-10 file extensions");
 }
 else {
 arg = argc;
 fextension_args = argv;
nftw(argv[1], extfind, 20, FTW_PHYS);
}
if(file_found==0)
  {
  printf("file with given extensions are not found \n");
  } 
}
