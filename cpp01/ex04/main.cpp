/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <student.1337.ma>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:17:51 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/29 15:19:01 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void findAndReplaceAll(std::string &str, std::string toReplace, std::string replaceWith)
{
    size_t pos = str.find(toReplace);
    while (pos != std::string::npos)
    {
        str.erase(pos, toReplace.length());
        str.insert(pos, replaceWith);
        pos = str.find(toReplace);
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: ./sed file_name s1 s2" << std::endl;
        return (1);
    }
    std::string fileName = argv[1];
    std::string toReplace = argv[2];
    std::string toReplaceWith = argv[3];

    std::string outFileName = fileName + ".replace";

    std::ifstream inputFile (fileName.c_str());   
    if (!inputFile) 
    {
        std::cout << "could not open file: " << fileName << std::endl;
        return 1;   
    }
    std::ofstream outFile (outFileName.c_str());
    if (!outFile.is_open()) 
    {
        std::cout << "could not open file: " << outFileName << std::endl;
        inputFile.close();
        return 1;   
    }
    std::string str;
    while (getline(inputFile, str))
    {
        findAndReplaceAll(str, toReplace, toReplaceWith);
        outFile << str << "\n";
    }
    outFile.close();
    inputFile.close();
    return 0;
}