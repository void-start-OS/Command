#include "command_table.h"
#include <string.h>

#define MAX_COMMANDS 64

static command_info_t table[MAX_COMMANDS];
static int command_count = 0;

int command_table_add(const char* name,
                      command_func_t func,
                      const char* description)
{
    if (command_count >= MAX_COMMANDS)
        return -1;

    table[command_count].name = name;
    table[command_count].func = func;
    table[command_count].description = description;
    command_count++;

    return 0;
}

const command_info_t* command_table_find(const char* name)
{
    for (int i = 0; i < command_count; i++) {
        if (strcmp(table[i].name, name) == 0)
            return &table[i];
    }
    return 0;
}

void command_table_iterate(void (*callback)(const command_info_t* info))
{
    for (int i = 0; i < command_count; i++)
        callback(&table[i]);
}
