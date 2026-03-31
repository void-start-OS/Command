void reboot_cmd(int argc, const char** argv)
{
    // 実機なら CPU リセット命令
    // outb(0x64, 0xFE);
}
