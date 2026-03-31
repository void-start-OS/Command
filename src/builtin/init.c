#include "command.h"

void help_cmd(int argc, const char** argv);
void mem_cmd(int argc, const char** argv);
void cls_cmd(int argc, const char** argv);
void reboot_cmd(int argc, const char** argv);

void register_builtin_commands(void)
{
    register_command("help",   help_cmd,   "Show command list");
    register_command("mem",    mem_cmd,    "Show memory info");
    register_command("cls",    cls_cmd,    "Clear screen");
    register_command("reboot", reboot_cmd, "Reboot system");
}
