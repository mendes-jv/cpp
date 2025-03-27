#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>

int main(int argc, char **argv) {
    if (!argv || argc != 4 || !argv[0] || !argv[1] || !argv[2] || !argv[3]) {
        std::cerr << "Error: wrong number of arguments\nUsage: "
                "./replace <file_name> <string_to_search> <string_to_replace>"
                << std::endl;
        return (EXIT_FAILURE);
    }
    const std::string inputFilename = argv[1];
    std::ifstream inputFile(inputFilename.c_str(), std::ios::in);
    if (!inputFile) {
        std::cerr << "Error: could not open file \'" << inputFilename << "\'" << std::endl;
        return (EXIT_FAILURE);
    }
    const std::string outputFilename = inputFilename + ".replace";
    std::ofstream outputFile(outputFilename.c_str(), std::ios::out | std::ios::trunc);
    if (!outputFile) {
        std::cerr << "Error: \'" << outputFilename << "\' was not created or truncated" << std::endl;
        inputFile.close();
        return (EXIT_FAILURE);
    }
    std::string content;
    const std::string stringToSearch = argv[2];
    const std::string stringToReplace = argv[3];
    if (stringToSearch.empty() || stringToReplace.empty()) {
        std::cerr << "Error: string to search and/or string to replace is empty" << std::endl;
        inputFile.close();
        outputFile.close();
        return (EXIT_FAILURE);
    }
    while (std::getline(inputFile, content)) {
        size_t linePosition = 0;
        while ((linePosition = content.find(stringToSearch, linePosition)) != std::string::npos) {
            content.erase(linePosition, stringToSearch.length());
            content.insert(linePosition, stringToReplace);
            linePosition += stringToReplace.length();
        }
        outputFile << content << std::endl;
    }
    inputFile.close();
    outputFile.close();
    return (EXIT_SUCCESS);
}
