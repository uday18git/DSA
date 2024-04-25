#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

// Function to count cpp files recursively
int countCppFiles(const fs::path& directory) {
    int count = 0;
    for (const auto& entry : fs::recursive_directory_iterator(directory)) {
        if (fs::is_regular_file(entry) && entry.path().extension() == ".cpp") {
            count++;
        }
    }
    return count;
}

int main() {
    fs::path currentDir = fs::current_path();
    int cppCount = countCppFiles(currentDir);
    std::cout << "Number of .cpp files in current directory and its subdirectories: " << cppCount << std::endl;
    return 0;
}
