#include<stdio.h>
#include<setjmp.h>
jmp_buf buf;
void func()
{
    printf("Welcome to the invoke example\n");
  
    // Jump to the point setup by setjmp
    longjmp(buf, 1);
  
    printf("Invoke 1\n");
}
  
int main()
{
    // Setup jump position using buf and return 0
    if (setjmp(buf))
        printf("Invoke 2\n");
    else
    {
        printf("Invoke 3\n");
        func();
    }
    return 0;
}
