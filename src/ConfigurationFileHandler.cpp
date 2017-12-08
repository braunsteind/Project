
#include "ConfigurationFileHandler.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ConfigurationFileHandler::readConfigurationFile() {
    string ipLine;
    string portLine;
    string tempPort;
    int i, endOfSubString, startIndex = 0;

    //opening file
    ifstream inFile;
    inFile.open ("../exe/Configuration");

    //reading the IP and Port lines.
    getline(inFile,ipLine);
    getline(inFile,portLine);
    //done reading from file
    inFile.close();

    //extracting the IP address from first line
    for (i = 0; i < ipLine.size(); i++) {
        if (ipLine[i] == ':') {
            //fixing the starting location
            startIndex = i + 1;
        }
    }

    this->serverIP  = ipLine.substr(startIndex, ipLine.size() - 1);

    //extracting the port from the second line
    for (i = 0; i < portLine.size(); i++) {
        if (portLine[i] == ':') {
            //fixing the starting location
            startIndex = i + 1;
        }
    }
    //cutting the string to Port only
    tempPort = portLine.substr(startIndex, portLine.size() - 1);

    this->port = atoi(tempPort.c_str());
}

int ConfigurationFileHandler::getPortFromFile() {
    return port;
}

const char* ConfigurationFileHandler::getIPFromFile() {
    return serverIP.c_str();
}