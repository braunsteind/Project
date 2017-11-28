#include "Player.h"

Player::Player(Color color, Board &board, Rules *rules, Display *display) : color(color), board(board), rules(rules),
                                                                          display(display) {}

int Player::getColor() const {
    return color;
}

int Player::canPlay() const {
    const int noMoves = 0;
    const int hasMoves = 1;
    std::vector<int> moves;
    //check where the player can put.
    rules->whereCanPut(board, color, moves);
    //if can't play.
    if (moves.size() <= noMoves) {
        return noMoves;
    }
    return hasMoves;
}