// The Program read 2 different files and shows how many lines and Chars are different.
//Populate two files in the same Dir as file1.txt & file2.txt
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
int main(){

        int fd1,fd2,bytesread1,bytesread2,i=0,large=0,len1,len2;
        int line_count=0,chars_count=0,check=0;

        fd1 = open( "file1.txt",O_RDONLY);
        fd2 = open( "file2.txt",O_RDONLY);
        char line[100]={""};
        char line2[100]={""};

        if(fd1 == -1 ){
                perror("error");
        }
        else {
                do{
                        bytesread1 = read(fd1,&line[i],1);
                        bytesread2 = read(fd2,&line2[i],1);
                       if(line[i] == '\n'){

                                check= strcmp(line,line2);
                                if(check!=0) line_count++;
                                       printf("%s",line);
                                i=-1;
                                len1=strlen(line);
                                len2=strlen(line2);
                                if(len1>len2)large =len1;
                                else large = len2;
                                for(int j=0;j<large;j++){
                                        if(line[j]!=line2[j]);
                                        chars_count++;
                                }
                                memset(&(line[0]),0,100);

                        }
                        else{}
                        i++;
                }while(bytesread1!=0);
}

        printf("\n %d lines are different \n", line_count );
        printf("\n %d characters are different \n", chars_count );

    return 0;
}
