#pragma once

typedef void (*command_func_t)(int argc, const char** argv);

typedef struct {
    const char* name;
    command_func_t func;
    const char* description;
} command_info_t;
