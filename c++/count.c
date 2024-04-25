#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Function to count cpp files recursively
int countCppFiles(const char *dir_path) {
    int count = 0;
    DIR *dir;
    struct dirent *entry;

    // Open directory
    dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Unable to open directory");
        exit(EXIT_FAILURE);
    }

    // Iterate through directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);

        // Check if entry is a directory
        DIR *subdir = opendir(path);
        if (subdir != NULL) {
            closedir(subdir);
            count += countCppFiles(path); // Recursive call for subdirectory
        } else {
            // Check if the file ends with ".cpp"
            if (strstr(entry->d_name, ".cpp") != NULL) {
                count++;
            }
        }
    }

    // Close directory
    closedir(dir);

    return count;
}

int main() {
    char *currentDir = ".";
    int cppCount = countCppFiles(currentDir);
    printf("Number of .cpp files in current directory and its subdirectories: %d\n", cppCount);
    return 0;
}
