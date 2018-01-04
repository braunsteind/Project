#ifndef EX2_DISPLAY_H
#define EX2_DISPLAY_H

#include <string>
#include <vector>
#include "Board.h"
#include "Point.h"

using namespace std;
enum Mode {
    Human = 1, Computer, Remote
};

class Display {
public:
    /**
     * Announce the winner.
     * @param winner The winning player.
     */
    virtual void announceWinner(Color winner) const = 0;

    /**
     * Show the board.
     * @param board The game board.
     */
    virtual void showBoard(Board &board) const = 0;

    /**
     * Announce that there is no possible moves.
     * @param color The player color.
     */
    virtual void noMoves(Color color) const = 0;

    /**
     * Show the player possible moves.
     * @param player The player.
     * @param moves The player possible moves.
     */
    virtual void showMoves(Color player, vector<Point> &moves) const = 0;

    /**
     * Announce the input is invalid.
     */
    virtual void invalidInput() const = 0;

    /**
     * Announce the move.
     * @param player The player.
     * @param row The row that played.
     * @param column The column that played.
     */
    virtual void announceMove(Color player, int row, int column) const = 0;

    /**
     * Announce the player has no moves.
     * @param player The player.
     */
    virtual void announceNoMove(Color player) const = 0;

    /**
     * Running the menu.
     * @return The type of player we play against.
     */
    virtual Mode runMenu() const = 0;

    /**
     * Show connected to server message.
     */
    virtual void connectedToServer() const = 0;

    /**
     * Wait for other player to connect.
     */
    virtual void waitingForOtherPlayer() const = 0;

    /**
     * Wait for other player.
     */
    virtual void waitingForOtherPlayerMove() const = 0;

    /**
     * Show the possible commands.
     */
    virtual void showCommands() const = 0;

    /**
     * show list of games.
     * @param gamesList List of games.
     */
    virtual void showGamesList(vector<std::string> gamesList) const = 0;

    /**
     * End the server.
     */
    virtual void serverEnded() const = 0;

    /**
     * The room exist.
     */
    virtual void roomExist() const = 0;

    /**
     * No such room.
     */
    virtual void noSuchRoom() const = 0;

    /**
     * No such command.
     */
    virtual void invalidCommand() const = 0;
};

#endif //EX2_DISPLAY_H