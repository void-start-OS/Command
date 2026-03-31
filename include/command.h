#pragma once
#include "command_types.h"

void command_system_init(void);

int register_command(const char* name,
                     command_func_t func,
                     const char* description);

void execute_command(const char* input);
