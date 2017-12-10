#ifndef EX2_CONFIGURATIONFILEHANDLER_H
#define EX2_CONFIGURATIONFILEHANDLER_H

#include <string>
#include <stdlib.h>

using namespace std;

class ConfigurationFileHandler {
public:
    /**
     * This function reads the information from
     * the configuration file
     */
    void readConfigurationFile();

    /**
     * This function returns the server's IP
     *
     * @return the IP address
     */
    const char *getIPFromFile();

    /**
     * This function returns the server's Port
     *
     * @return the Port number
     */
    int getPortFromFile();

private:
    int port;
    string serverIP;
};


#endif //EX2_CONFIGURATIONFILEHANDLER_H
