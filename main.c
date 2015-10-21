#include <stdio.h>
#include <stdlib.h>
#include "includes/myio.h"

int main(int argc, char* argv[])
{
    FILE* rom = 0;

    unsigned char* romContents;

    long romSize;

    int smcHeader = 0;

    rom = fopen("smas.smc", "rb");

    if(rom == 0)
    {
        printfn("Could not open selected rom file.");
        return EXIT_FAILURE;
    }

    fseek(rom, 0L, SEEK_END);
    romSize = ftell(rom);
    fseek(rom, 0L, SEEK_SET);

    smcHeader = romSize % 1024;

    fseek(rom, smcHeader, SEEK_SET);

    romSize -= smcHeader;

    romContents = malloc(romSize);

    fread(romContents, romSize, 1, rom);

    fclose(rom);

    return 0;
}
