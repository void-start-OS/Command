#pragma once
#include "command_types.h"

int command_table_add(const char* name,
                      command_func_t func,
                      const char* description);

const command_info_t* command_table_find(const char* name);

void command_table_iterate(void (*callback)(const command_info_t* info));
