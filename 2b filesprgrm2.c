// lseek 
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
  
void func(char arr[], int n)
{

    int f_write = open("info1.txt", O_RDONLY);
  
    int f_read = open("end.txt", O_CREAT | O_WRONLY);
  
    int count = 0;
    while (read(f_write, arr, 1))
    {
            lseek(f_write, n, SEEK_CUR);
            write(f_read, arr, 1);       
    }
    close(f_write);
    close(f_read);
}
  
int main()
{
    char arr[100];
    int n;
    n = 2;
  
    func(arr, n);
    return 0;
}
