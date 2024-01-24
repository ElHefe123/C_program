#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void appendToFile(const std::string& filename, const std::string& data) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << data;
        file.close();
        std::cout << "Data appended to " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void reverseFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream input(inputFile);
    std::ofstream output(outputFile);

    if (input.is_open() && output.is_open()) {
        std::string content((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
        std::reverse(content.begin(), content.end());
        output << content;

        std::cout << "Reversed data written to " << outputFile << std::endl;

        input.close();
        output.close();
    } else {
        std::cerr << "Unable to open files: " << inputFile << " or " << outputFile << std::endl;
    }
}

int main() {
    std::string userInput;

    // Get input from the user
    std::cout << "Enter data to append to CSC450_CT5_mod5.txt (Press Enter to finish):\n";
    std::getline(std::cin, userInput);

    // Append user input to the file
    appendToFile("CSC450_CT5_mod5.txt", userInput);

    // Reverse the content of the file
    reverseFile("CSC450_CT5_mod5.txt", "CSC450-mod5-reverse.txt");

    return 0;
}
