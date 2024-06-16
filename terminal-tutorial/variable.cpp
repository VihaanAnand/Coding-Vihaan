#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
        char output[1024];
        FILE * pipe = popen("pwd", "r");
        fgets(output, sizeof(output), pipe);
        pclose(pipe);
        cout << output << "\n";
}