#include <stdio.h>
#include <string.h>
int main() {
    char username[200] = {0};
    for (int i = 0; i < 100; i++) {
        scanf("%c", &username[i]);
        if (username[i] == '\n') {
            username[i] = 0;
            break;
        }
    }
    printf("%ld\n\"%.20s\"", strlen(username), username);
    return 0;
}
