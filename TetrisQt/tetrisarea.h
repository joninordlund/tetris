#ifndef TETRISAREA_H
#define TETRISAREA_H

#include <QtGui>
#include <QWidget>
#include <QTimer>
#include "tetrisboard.h"


class TetrisArea : public QWidget
{
    Q_OBJECT
public:
    explicit TetrisArea(QWidget *parent = 0);
    void keyPress(QKeyEvent *event);

    void restart();

protected:
    void paintEvent(QPaintEvent *event);
    void togglePause();
private:
    QTimer* timer;
    QTimer* speedTimer;
    TetrisBoard* inst;
    bool paused;
    int speed;
signals:
    void scoreUpdate(int sc);
    
public slots:
    void updateArea();
    void updateSpeed();
};

#endif // TETRISAREA_H
