#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILE "demo.txt"
#define INPUT_LINE_SIZE 512

void logic(const char * filename)
{
    char buffer[512];
    size_t len = INPUT_LINE_SIZE;
    char * ptr;
    FILE * fp = fopen(filename,"r");
    while(fgets(buffer,len,fp)) {
        if(feof(fp))
            break;
        if (strncmp(buffer,"#include",8) == 0) {
            ptr = index(buffer,'>');
            ptr[0] = '\0';
            ptr = index(buffer,'<');
            ptr++;
            //printf("DEBUG: %s\n", ptr);
            logic(ptr);
        } else {
            printf("%s", buffer);
        }
    }
    fclose(fp);
}

int main(int argc,char ** argv)
{
   logic(INPUT_FILE);
   return EXIT_SUCCESS;
}

