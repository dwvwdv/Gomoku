#include "gameModel.h"

void gameModel::startGame(GameType type){
    gameType = type;

    gameMapVec.clear();
    for(int i=0;i<BOARD_GRAD_SIZE;++i){
        std::vector<int> lineboard;
        for(int j=0;j<BOARD_GRAD_SIZE;++j){
            lineboard.push_back(0);
        }
        gameMapVec.push_back(lineboard);
    }

    if(gameType == AI){
        scoreMapVec.clear();
        for(int i=0;i<BOARD_GRAD_SIZE;++i){
            std::vector<int> linescores;
            for(int j=0;j<BOARD_GRAD_SIZE;++j){
                linescores.push_back(0);
            }
            scoreMapVec.push_back(linescores);
        }
    }

    playerFlag = true;
}


void gameModel::actionByPerson(int row,int col){
    updateGameMap(row,col);
}

void gameModel::updateGameMap(int row,int col){
    if(playerFlag)
        gameMapVec[row][col] = 1;
    else
        gameMapVec[row][col] = -1;
    playerFlag = !playerFlag;
}
