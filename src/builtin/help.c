#include "command_table.h"
#include <stdio.h>

static void print_info(const command_info_t* info)
{
    printf("%s - %s\n", info->name, info->description);
}

void help_cmd(int argc, const char** argv)
{
    command_table_iterate(print_info);
}
