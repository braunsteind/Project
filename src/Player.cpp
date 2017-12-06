#include "Player.h"

Player::Player(Color color, Board &board, Rules *rules, Display *display) : color(color), board(board), rules(rules),
                                                                            display(display) {}

Color Player::getColor() const {
    return color;
}

void Player::setColor(Color newColor) {
    color = newColor;
}

bool Player::canPlay() const {
    vector<Point> moves;
    //check where the player can put.
    moves = rules->whereCanPut(board, color);
    //if can't play.
    if (moves.empty()) {
        return false;
    }
    return true;
}