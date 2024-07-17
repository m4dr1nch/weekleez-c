#include <stdio.h>
#include <stdbool.h>

#include "utils.h" 

void banner()
{
    puts("  _      __        __    __"); 
    puts(" | | /| / /__ ___ / /__ / /__ ___ ___");
    puts(" | |/ |/ / -_) -_)  '_// / -_) -_)_ /");
    puts(" |__/|__/\\__/\\__/_/\\_\\/_/\\__/\\__//__/");
}

void options()
{
    puts("");
    puts("Options:");
    puts("[1] List tasks");
    puts("[2] Create task");
    puts("[3] Remove task");
    puts("[4] Mark task as completed");
    puts("[5] Mark task as not completed");
    puts("[q] Exit & save");
    puts("");
}

void clear_stdin()
{
    char c;
    while (true)
    {
        c = getc(stdin);
        if (c == EOF || c == '\n')
            break;
    }
}
