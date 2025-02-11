#include <iostream>
#include <sys/stat.h>
#include <ctime>

int main() {
    const char* filename = "file.txt"; // Replace with the name of the file to check
    struct stat file_stat;
    if (stat(filename, &file_stat) == -1) {
        perror("Failed to get file status");
        return 1;
    }
    std::cout << "Last modification time of file '" << filename << "' is " << std::asctime(std::localtime(&file_stat.st_mtime));
    return 0;
}
