#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "gameModel.h"

#include <QPainter>
#include <QMouseEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    gameModel *game;
    GameType game_type;

    void initGame();
    void initAIGame();

    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);


    int clickPosCol,clickPosRow;
    bool selectPos = false;
};
#endif // MAINWINDOW_H
