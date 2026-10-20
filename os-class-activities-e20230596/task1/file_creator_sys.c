#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    const char *text = "Hello from Operating Systems class!\n";
    const char *message = "File created successfully!\n";
    int file = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (file == -1) {
        perror("open");
        return 1;
    }
    write(file, text, strlen(text));
    close(file);
    write(STDOUT_FILENO, message, strlen(message));
    return 0;
}
