#include <stdio.h>
#include <string.h>

void procesar(char *s) {
    int e = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '\n' || s[i] == '\r') continue;
        
        if (e == 0) {
            if (s[i] == '+') e = 1;
            else if (s[i] >= 'A' && s[i] <= 'Z') e = 3;
            else { e = -1; break; }
        } else if (e == 1) {
            if (s[i] == '+') e = 2;
            else { e = -1; break; }
        } else if (e == 2) {
            e = -1; break;
        } else if (e == 3) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) e = 3;
            else { e = -1; break; }
        }
    }

    if (e == 1) printf("SUMA\n");
    else if (e == 2) printf("INCR\n");
    else if (e == 3) printf("ID\n");
    else printf("NO ACEPTA\n");
}

int main() {
    FILE *f = fopen("entrada.txt", "r");
    if (!f) return 1;
    char buf[100];
    while (fscanf(f, "%s", buf) != EOF) {
        procesar(buf);
    }
    fclose(f);
    return 0;
}