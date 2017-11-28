#ifndef EX2_CONSOLEDISPLAY_H
#define EX2_CONSOLEDISPLAY_H

#include "Display.h"

class ConsoleDisplay : public Display {
public:
    virtual void announceWinner(int winner) const;

    virtual void showBoard(Board &board) const;

    virtual void noMoves(int color) const;

    virtual void showMoves(int player, std::vector<int> &moves) const;

    virtual void invalidInput() const;

    virtual void announceMove(int player, int row, int column) const;

    virtual int runMenu() const;
};

#endif //EX2_CONSOLEDISPLAY_H
