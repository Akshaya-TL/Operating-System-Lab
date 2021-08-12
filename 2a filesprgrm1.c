// open, read, write, close, fcntl

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
  
int main (void) 
{ 
    int fd[2]; 
    char buf1[12] = "hello world"; 
    char buf2[12]; 
  
    fd[0] = open("info1.txt", O_RDWR | O_CREAT);         
    fd[1] = open("info1.txt", O_RDWR); 
      
    write(fd[0], buf1, strlen(buf1));          
    write(1, buf2, read(fd[1], buf2, 12)); 
  
    close(fd[0]); 
    close(fd[1]); 
      return 0; 
} 

