#include "command_table.h"
#include <vso/console.h>
#include <string.h>

static void print_info(const command_info_t* info)
{
    // コマンド名を黄色に
    vso_console_set_color(VSO_COLOR_YELLOW, VSO_COLOR_BLACK);
    vso_console_write(info->name);

    // 説明は白
    vso_console_set_color(VSO_COLOR_WHITE, VSO_COLOR_BLACK);
    vso_console_write(" - ");
    vso_console_write(info->description);
    vso_console_write("\n");
}

void help_cmd(int argc, const char** argv)
{
    if (argc == 2) {
        // help <command> の場合
        const command_info_t* info = command_table_find(argv[1]);
        if (!info) {
            vso_console_write("Command not found.\n");
            return;
        }

        vso_console_set_color(VSO_COLOR_YELLOW, VSO_COLOR_BLACK);
        vso_console_write(info->name);
        vso_console_write("\n");

        vso_console_set_color(VSO_COLOR_WHITE, VSO_COLOR_BLACK);
        vso_console_write(info->description);
        vso_console_write("\n");
        return;
    }

    // 通常の help（一覧）
    command_table_iterate(print_info);
}
