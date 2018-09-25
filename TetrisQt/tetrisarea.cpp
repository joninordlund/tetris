#include "tetrisarea.h"
#include "tetrisboard.h"
#include "tetris.h"

#include <array>

const Qt::GlobalColor cols[] = {Qt::green, Qt::red, Qt::cyan, Qt::blue, Qt::yellow};
const int portWidth = TetrisBoard::width * 14;
const int portHeight = TetrisBoard::height * 14;

TetrisArea::TetrisArea(QWidget *parent) :
    QWidget(parent)
{
    setMinimumSize(portWidth, portHeight);
    setFocusPolicy(Qt::StrongFocus);

    speed = 400;
    timer = new QTimer(this);
    speedTimer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(updateArea()));
    connect(speedTimer, SIGNAL(timeout()), this, SLOT(updateSpeed()));
    connect(this, SIGNAL(scoreUpdate(int)), parentWidget(), SLOT(setScore(int)));

    inst = new TetrisBoard();
    paused = true;
}

void TetrisArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen(Qt::black, 2, Qt::SolidLine);
    painter.setPen(pen);
    setFixedSize(portWidth + 4,portHeight + 4);

    painter.drawRect(0,0,portWidth + 4,portHeight + 4);
    TetrisBoard::Grid grid = inst->getGrid();

    emit scoreUpdate(inst->getScore());
    painter.translate(QPoint(2,2));

    for(int y = 0; y < TetrisBoard::height; ++y){
        for(int x = 0; x < TetrisBoard::width; ++x){
            if(grid[y][x] != 0){
               painter.fillRect(14*x, 14*y, 14, 14, cols[grid[y][x]-1]);
            }
        }
    }
    if(inst->isGameOver()){
        QFont font( "arial", 26, QFont::Bold );
        painter.setFont(font);
        painter.drawText(50, 100, QString("Game Over"));
    }
    if(paused)
    {
        QFont font( "arial", 12, QFont::Bold );
        painter.setFont(font);
        painter.drawText(28, 150, QString("Press space to start/continue"));
    }
}

void TetrisArea::keyPress(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
    {
        if(inst->isGameOver()) restart();
        togglePause();
        return;
    }
    if(paused) return;
    switch(event->key()){
        case Qt::Key_Down:
            inst->moveDown();
            break;
        case Qt::Key_Left:
            inst->moveLeft();
            break;
        case Qt::Key_Right:
            inst->moveRight();
            break;
        case Qt::Key_Up:
            inst->rotate();
            break;
        default:
            break;
    }
    update();
}

void TetrisArea::updateArea()
{
    if(paused) return;
    inst->moveDown();
    if(inst->isGameOver())
    {
        togglePause();
    }
    update();
}

void TetrisArea::updateSpeed()
{
    speed -= 15;
    if(speed < 150) speed = 150;
    timer->start(speed);
}

void TetrisArea::restart()
{
    delete inst;
    inst = new TetrisBoard();
    speed = 400;
    paused = true;
    update();
}

void TetrisArea::togglePause()
{
    if(!paused){
        timer->stop();
        speedTimer->stop();
        paused = true;
     }
    else{
        timer->start(speed);
        speedTimer->start(10000);
        paused = false;
    }
}
