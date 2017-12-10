#include <gtest/gtest.h>
#include "../src/ConfigurationFileHandler.h"

TEST(ConfigurationFileHandler, getIPFromFile) {
    ConfigurationFileHandler handler;
    handler.readConfigurationFile();
    const char *ip = handler.getIPFromFile();
    const char answer[] = "127.0.0.1";
    EXPECT_EQ(strcmp(ip, answer), 0);
}

TEST(ConfigurationFileHandler, getPortFromFile) {
    ConfigurationFileHandler handler;
    handler.readConfigurationFile();
    int port = handler.getPortFromFile();
    int answer = 8000;
    EXPECT_EQ(port, answer);
}