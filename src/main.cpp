#include "GameLauncher.h"
#include "GameRunner.h"

int main() {
    //Launch the game.
    GameLauncher gameLauncher;
    //create game runner.
    GameRunner game(*gameLauncher.getBoard(), gameLauncher.getPlayer1(), gameLauncher.getPlayer2(),
                    gameLauncher.getRules(), gameLauncher.getDisplay());
    //run the game.
    game.run();
    return 0;
}