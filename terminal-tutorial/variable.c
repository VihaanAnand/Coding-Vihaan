#include <stdio.h>
int main() {
        char output[1024];
        FILE * pipe = popen("pwd", "r");
        fgets(output, sizeof(output), pipe);
        pclose(pipe);
        printf("%s", output);
}
