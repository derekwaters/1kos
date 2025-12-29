#include "user.h"

void main(void) {
    // Test printf
    printf(">>> Hello World from userspace shell! <<<\n\n");
    while (1) {
prompt:
        printf("> ");
        char cmdline[128];
        for (int i = 0;; i++) {
            char ch = getchar();
            putchar(ch);
            if (i == sizeof(cmdline) - 1) {
                printf("\n\n:: command line too long\n\n");
                goto prompt;
            } else if (ch == '\r') {
                printf("\n");
                cmdline[i] = '\0';
                break;
            } else {
                cmdline[i] = ch;
            }
        }

        if (strcmp(cmdline, "hello") == 0)
            printf("Hello world fro shell!\n");
        else if (strcmp(cmdline, "exit") == 0)
            exit(1);
        else if (strcmp(cmdline, "readfile") == 0) {
            char buf[128];
            int len = readfile("hello.txt", buf, sizeof(buf));
            buf[len] = '\0';
            printf("%s\n", buf);
        }
        else if (strcmp(cmdline, "writefile") == 0) {
            writefile("hello.txt", "Hello from shell!\n", 19);
        }
        else
            printf("unknown command: %s\n", cmdline);
    }
}