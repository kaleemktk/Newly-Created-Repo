#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main( int argc , char *argv[]){
        int i=0;
        char *newstr;
        struct stat statbuf;
        stat(argv[2], &statbuf);
        char buf_read[50]="";
        int bytesread=0, fd_read=0, fd_write=0, byteswritten=0;

        if(S_ISDIR(statbuf.st_mode)){
                	printf( " destination is directory \n");
               	asprintf(&newstr,"%s%s",argv[2],argv[1]);
               	fd_write = open(newstr , (O_WRONLY|O_CREAT));
                	fd_read = open(argv[1] , O_RDONLY);
                	while(1){
                	        bytesread=read(fd_read, &buf_read[i],1);
                	        if(bytesread==0) break;
                	        byteswritten=write(fd_write,&buf_read[i],1);
                	        if(buf_read[i] == '\n'){
                		                i=-1;
                		                memset(&(buf_read[0]),0,50);
	      	 	  }
                	        i++;
                	}
                	if(remove(argv[1])== -1)
                	        printf("not deleted ");
        	}//end if

        else{// second argument is not directory
                fd_write = open(argv[2] , (O_WRONLY|O_CREAT));
                fd_read = open(argv[1] , O_RDONLY);

                printf("Renaming file\n");
                while(1){
                        bytesread=read(fd_read, &buf_read[i],1);
                        if(bytesread==0) break;
                        byteswritten=write(fd_write,&buf_read[i],1);
                        if(buf_read[i] == '\n'){
                                i=-1;
                                memset(&(buf_read[0]),0,50);
                        }
                        i++;
                }
                if(remove(argv[1])== -1)
                        printf("not deleted ");
        }
return 0;}
