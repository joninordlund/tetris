#ifndef TETRIS_H
#define TETRIS_H

#include <QMainWindow>
#include <QPushButton>
#include "tetrisarea.h"

class Tetris : public QMainWindow
{
	Q_OBJECT
	
public:
	Tetris(); 

    QLabel* score;

protected:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void paintEvent(QPaintEvent *event);
private:
    TetrisArea* area;
    QPushButton* restartButton;

    bool keyPressed;
    int sc;
private slots:
    void restart();
    void setScore(int sc){this->sc = sc; update();}
};

#endif // TETRIS_H
