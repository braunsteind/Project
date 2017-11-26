#include "Player.h"

Player::Player(int color, Board &board, Rules *rules, Display *display) : color(color), board(board), rules(rules),
                                                                          display(display) {}

int Player::getColor() const {
    return color;
}

int Player::canPlay() const {
    std::vector<int> moves;
    //check where the player can put.
    rules->whereCanPut(board, color, moves);
    //if can't play.
    if (moves.size() <= 0) {
        return 0;
    }
    return 1;
}