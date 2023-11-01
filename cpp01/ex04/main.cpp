/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:17:51 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/30 13:20:27 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int findAndReplaceAll(std::string &str, std::string toReplace, std::string replaceWith)
{
    size_t pos = str.find(toReplace);
    while (pos != std::string::npos)
    {
        str.erase(pos, toReplace.length());
        str.insert(pos, replaceWith);
        pos = str.find(toReplace, pos + replaceWith.length());
    }
    return (1);
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
    if (inputFile.peek() == EOF)
    {
        std::cout << fileName << " is empty" << std::endl;
        inputFile.close();
        return (1);
    }
    if (toReplace.empty())
        return (0);
    std::ofstream outFile (outFileName.c_str());
    if (!outFile) 
    {
        std::cout << "could not open file: " << outFileName << std::endl;
        inputFile.close();
        return 1;   
    }
    std::string str;
    while (getline(inputFile, str))
    {
        if(!findAndReplaceAll(str, toReplace, toReplaceWith))
            break;
        outFile << str;
        if (inputFile.peek() != EOF)
            outFile << "\n";
    }
    outFile.close();
    inputFile.close(); 
    return 0;
}