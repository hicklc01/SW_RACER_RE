#include "sithMulti.h"

#include "globals.h"

// 0x00404760
void sithMulti_InitializeConnection(int connectionIndex)
{
    int res;

    res = stdComm_InitializeConnection(connectionIndex);
    if (res == -0x7788ff06)
    {
        stdlib__sprintf(unknownError_buffer, "Not_available.\n%s", std_output_buffer);
        return;
    }
    if (res != 0)
    {
        stdlib__sprintf(unknownError_buffer, "Did_not_connect.\n_%s", std_output_buffer);
    }
}

// 0x0041c570
void sithMulti_CloseGame(void)
{
    HANG("TODO");
}
