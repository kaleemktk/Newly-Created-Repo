#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
int recursiveDelete(char* dirname){
        DIR *dp;
        struct dirent *ep;
        char abs_filename[FILENAME_MAX];
        dp = opendir (dirname);
        if (dp != NULL){
                while (ep = readdir (dp)){
                        struct stat stFileInfo;
                        stat(ep->d_name, &stFileInfo);
                        snprintf(abs_filename, FILENAME_MAX, "%s/%s", dirname, ep->d_name);
                        if(S_ISDIR(stFileInfo.st_mode)){
                                if(strcmp(ep->d_name, ".") && strcmp(ep->d_name, "..")){
                                        printf("%s  directory found\n",abs_filename);
                                        recursiveDelete(abs_filename);
                                }
                        }
                        else {
                                printf("%s file found\n",abs_filename);
                                remove(abs_filename);
                        }
                }
                (void) closedir (dp);
        }
        else
                perror ("Couldn't open the directory");
        remove(dirname);
  return 0;
}
int main(int argc, char *argv[]){
        if(argc<2){
                printf("NO enough arguments\n");
                return 1;
        }
                recursiveDelete(argv[1]);
        return 0;
}

