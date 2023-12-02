#include "common.h"

#include <fstream>
#include <sstream>
#include <iostream>

std::string readFile(const std::string& filePath)
{
    std::ifstream file;
    // ensure ifstream objects can throw exceptions:
    file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try 
    {
        // open files
        file.open(filePath);
        std::stringstream fileStream;
        // read file's buffer contents into streams
        fileStream << file.rdbuf();	
        // close file handlers
        file.close();
        // convert stream into string
        return fileStream.str();	
    }
    catch (std::ifstream::failure& e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
    }

    return "";
}
