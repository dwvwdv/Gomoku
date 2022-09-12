#include <cmath>

#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(MARGIN * 2 + BLOCK_SIZE * BOARD_GRAD_SIZE,
                       MARGIN * 2 + BLOCK_SIZE * BOARD_GRAD_SIZE);
    this->setMouseTracking(true);
    initGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    for(int i=0;i<=BOARD_GRAD_SIZE;++i){
        painter.drawLine(MARGIN + BLOCK_SIZE * i , MARGIN,
                         MARGIN + BLOCK_SIZE * i , size().height() - MARGIN);
        painter.drawLine(MARGIN , MARGIN + BLOCK_SIZE * i,
                         size().height() - MARGIN , MARGIN + BLOCK_SIZE * i);

    }

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    if(clickPosRow > 0 && clickPosRow < BOARD_GRAD_SIZE &&
            clickPosCol > 0 && clickPosCol < BOARD_GRAD_SIZE &&
            game->gameMapVec[clickPosRow][clickPosCol] == 0){
        if(game->playerFlag){
            brush.setColor(Qt::black);
        }
        else
            brush.setColor(Qt::white);
        painter.setBrush(brush);
        painter.drawRect(MARGIN + BLOCK_SIZE * clickPosCol - MARK_SIZE / 2,MARGIN + BLOCK_SIZE * clickPosRow - MARK_SIZE / 2,MARK_SIZE,MARK_SIZE);
    }
}


void MainWindow::initGame(){
    game = new gameModel;
    initAIGame();
}

void MainWindow::initAIGame(){
    game_type = AI;
    game->gameStatus = PLAYING;

    game->startGame(game_type);
    this->update();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    int x = event->x();
    int y = event->y();

    //棋盤邊緣不能落子
    if(x >= MARGIN + BLOCK_SIZE / 2 &&
            x < size().width() - MARGIN - BLOCK_SIZE / 2 &&
            y >= MARGIN + BLOCK_SIZE / 2 &&
            x < size().height() - MARGIN - BLOCK_SIZE / 2){
        int col = (x - MARGIN) / BLOCK_SIZE;
        int row = (y - MARGIN) / BLOCK_SIZE;

        int leftTopPosX = MARGIN + BLOCK_SIZE * col;
        int leftTopPosY = MARGIN + BLOCK_SIZE * row;

        clickPosCol = clickPosRow = -1;

        selectPos = false;
        int len = -1;

        //左上角：
        len = sqrt((x - leftTopPosX) * (x - leftTopPosX) + (y - leftTopPosY) * (y - leftTopPosY));
        if(len < POS_OFFSET){
            clickPosCol = col;
            clickPosRow = row;

            if(game->gameMapVec[clickPosRow][clickPosCol] == 0){
                selectPos = true;
            }
        }
        //右上角：
        len = sqrt((x - leftTopPosX - BLOCK_SIZE) * (x - leftTopPosX - BLOCK_SIZE) + (y - leftTopPosY) * (y - leftTopPosY));
        if(len < POS_OFFSET){
            clickPosCol = col + 1;
            clickPosRow = row;

            if(game->gameMapVec[clickPosRow][clickPosCol] == 0){
                selectPos = true;
            }
        }
        //左下角：
        len = sqrt((x - leftTopPosX) * (x - leftTopPosX) + (y - leftTopPosY - BLOCK_SIZE) * (y - leftTopPosY - BLOCK_SIZE));
        if(len < POS_OFFSET){
            clickPosCol = col;
            clickPosRow = row + 1;

            if(game->gameMapVec[clickPosRow][clickPosCol] == 0){
                selectPos = true;
            }
        }
        //右下角：
        len = sqrt((x - leftTopPosX - BLOCK_SIZE) * (x - leftTopPosX - BLOCK_SIZE) + (y - leftTopPosY - BLOCK_SIZE) * (y - leftTopPosY - BLOCK_SIZE));
        if(len < POS_OFFSET){
            clickPosCol = col + 1;
            clickPosRow = row + 1;

            if(game->gameMapVec[clickPosRow][clickPosCol] == 0){
                selectPos = true;
            }
        }


    }
//        QPainter p(this);

    update();
}
