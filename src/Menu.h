//
// Created by shlomi on 11/25/17.
//

#ifndef REVERSI_MENU_H
#define REVERSI_MENU_H


class Menu {
public:
    /**
     * Class constructor
     * initializes members to be false
     */
    Menu();
    /**
     * Checks if a game with Human player was chosen
     * @return true for human, false otherwise
     */
    bool againstHuman();
    /**
     * Checks if a game with AI player was chosen
     * @return true for AI, false otherwise
     */
    bool againstAI();
    /**
     * This function runs the menu
     */
    void runMenu();

private:
    bool humanPlayer;
    bool aiPlayer;

};


#endif //REVERSI_MENU_H
