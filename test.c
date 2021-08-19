#include<stdio.h>
#include<errno.h>

int main()
{
    FILE* pwrite=fopen("text.txt","w");
    if(pwrite==NULL)
    {
        printf("%s\n",strerror(errno));
    }
    fputc('a',pwrite);
    fputc('p',pwrite);
    fputc('p',pwrite);
    fputc('l',pwrite);
    fputc('e',pwrite);
    fclose(pwrite);
    pwrite=NULL;
    return 0;
}