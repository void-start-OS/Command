#include <ctype.h>
#include <string.h>

int parse_command(const char* input, const char** argv, int max_args)
{
    int argc = 0;

    while (*input && argc < max_args) {
        while (*input == ' ')
            input++;

        if (*input == '\0')
            break;

        argv[argc++] = input;

        while (*input && *input != ' ')
            input++;

        if (*input == '\0')
            break;

        *((char*)input) = '\0';
        input++;
    }

    return argc;
}
