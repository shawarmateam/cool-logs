#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define COLOR_RED "\033[31m"
#define COLOR_BLUE "\033[34m"
#define COLOR_RESET "\033[0m"
#define COLOR_YELLOW "\033[33m"

char isColored = 0;

void logi(const char type, const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    switch (type) {
        case 'l': {
            printf(COLOR_BLUE "LOG: " COLOR_RESET);
            break;
        }
        case 'i': {
            printf(COLOR_BLUE "INF: "); isColored = 0xff;
            break;
        }
        case 'e': {
            printf(COLOR_RED "ERR: " COLOR_RESET);
            break;
        }
        case 'w': {
            printf(COLOR_YELLOW "WRN: " COLOR_RESET);
            break;
        }
        case 'f': {
            printf(COLOR_RED "FTL: "); isColored = 0xff;
            break;
        }


        case 'L': {
            printf(COLOR_BLUE "LOG:     " COLOR_RESET);
            break;
        }
        case 'I': {
            printf(COLOR_BLUE "INFO:    "); isColored = 0xff;
            break;
        }
        case 'E': {
            printf(COLOR_RED "ERROR:   " COLOR_RESET);
            break;
        }
        case 'W': {
            printf(COLOR_YELLOW "WARNING: " COLOR_RESET);
            break;
        }
        case 'F': {
            printf(COLOR_RED "FATAL:   "); isColored = 0xff;
            break;
        }
    }
    
    const char *p;
    for (p = format; *p != '\0'; p++) {
        if (*p == '%') {
            p++;
            switch (*p) {
                case 'd': {
                    int i = va_arg(args, int);
                    printf("%d", i);
                    break;
                }
                case 'f': {
                    double d = va_arg(args, double);
                    printf("%f", d);
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char *);
                    printf("{ %s }", s);
                    break;
                }
                default:
                    putchar('%');
                    putchar(*p);
                    break;
            }
        } else {
            putchar(*p);
        }
    }
    
    if (isColored != 0) { printf(COLOR_RESET); isColored = 0; }
    putchar('\n');
    
    va_end(args);
}

int main() {
    logi('I', "hw from logs! int: %d, str: %s", 231, "test");
    logi('i', "hw from logs! int: %d, str: %s", 231, "test");
    logi('W', "hw from logs! int: %d, str: %s", 231, "test");
    logi('F', "hw from logs! int: %d, str: %s", 231, "test");
}
