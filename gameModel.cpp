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

bool gameModel::isWin(int row,int col){

    for (int i = 0; i < 5; i++)
        {
            if (col - i > 0 &&
                col - i + 4 < BOARD_GRAD_SIZE &&
                gameMapVec[row][col - i] == gameMapVec[row][col - i + 1] &&
                gameMapVec[row][col - i] == gameMapVec[row][col - i + 2] &&
                gameMapVec[row][col - i] == gameMapVec[row][col - i + 3] &&
                gameMapVec[row][col - i] == gameMapVec[row][col - i + 4])
                return true;
        }

        for (int i = 0; i < 5; i++)
        {
            if (row - i > 0 &&
                row - i + 4 < BOARD_GRAD_SIZE &&
                gameMapVec[row - i][col] == gameMapVec[row - i + 1][col] &&
                gameMapVec[row - i][col] == gameMapVec[row - i + 2][col] &&
                gameMapVec[row - i][col] == gameMapVec[row - i + 3][col] &&
                gameMapVec[row - i][col] == gameMapVec[row - i + 4][col])
                return true;
        }

        for (int i = 0; i < 5; i++)
        {
            if (row + i < BOARD_GRAD_SIZE &&
                row + i - 4 > 0 &&
                col - i > 0 &&
                col - i + 4 < BOARD_GRAD_SIZE &&
                gameMapVec[row + i][col - i] == gameMapVec[row + i - 1][col - i + 1] &&
                gameMapVec[row + i][col - i] == gameMapVec[row + i - 2][col - i + 2] &&
                gameMapVec[row + i][col - i] == gameMapVec[row + i - 3][col - i + 3] &&
                gameMapVec[row + i][col - i] == gameMapVec[row + i - 4][col - i + 4])
                return true;
        }

        for (int i = 0; i < 5; i++)
        {
            if (row - i > 0 &&
                row - i + 4 < BOARD_GRAD_SIZE &&
                col - i > 0 &&
                col - i + 4 < BOARD_GRAD_SIZE &&
                gameMapVec[row - i][col - i] == gameMapVec[row - i + 1][col - i + 1] &&
                gameMapVec[row - i][col - i] == gameMapVec[row - i + 2][col - i + 2] &&
                gameMapVec[row - i][col - i] == gameMapVec[row - i + 3][col - i + 3] &&
                gameMapVec[row - i][col - i] == gameMapVec[row - i + 4][col - i + 4])
                return true;
        }
    return false;
}
