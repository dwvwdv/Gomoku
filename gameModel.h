#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <vector>

enum GameType{
    MAN,
    AI
};

enum GameStatus{
    PLAYING,
    WIN,
    DEAD
};

//棋盤大小
const int BOARD_GRAD_SIZE = 15;


const int MARGIN = 30;
const int CHESS_RADIUS = 15;
const int MARK_SIZE = 6;
const int BLOCK_SIZE = 40;
const int POS_OFFSET = BLOCK_SIZE * 0.4;

const int AI_THINK_TIME = 700;

class gameModel{
public:
    gameModel(){};

    //當前場面狀況，黑1白-1，空位為0
    std::vector<std::vector<int>> gameMapVec;

    //AI評分
    std::vector<std::vector<int>> scoreMapVec;

    //當前回合玩家
    bool playerFlag;

    GameType gameType;
    GameStatus gameStatus;

    void startGame(GameType type);
    void calculateScore();
    void actionByPerson(int x,int y);
    void actionByAnotherPerson(int x,int y);
    void updateGameMap(int x,int y);

    bool isWin(int x,int y);
    bool isDead();
};


#endif // GAMEMODEL_H
