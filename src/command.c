#include "command.h"
#include "command_table.h"
#include "parser.c"   // or include header if separated

#include <string.h>

#define MAX_ARGS 8

int register_command(const char* name,
                     command_func_t func,
                     const char* description)
{
    return command_table_add(name, func, description);
}

void execute_command(const char* input)
{
    const char* argv[MAX_ARGS];
    char buffer[256];

    strncpy(buffer, input, sizeof(buffer));
    buffer[sizeof(buffer)-1] = '\0';

    int argc = parse_command(buffer, argv, MAX_ARGS);
    if (argc == 0)
        return;

    const command_info_t* info = command_table_find(argv[0]);
    if (!info) {
        // print error
        // (ここは VGA/Serial の print 関数に置き換える)
        puts("Unknown command");
        return;
    }

    info->func(argc, argv);
}

extern void register_builtin_commands(void);

void command_system_init(void)
{
    register_builtin_commands();
}
