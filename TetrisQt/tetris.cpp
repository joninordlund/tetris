#include "tetris.h"
#include "tetrisarea.h"
#include <QLabel>
#include <QPushButton>

Tetris::Tetris()
{
    setWindowTitle("Tetris");

    layout()->setSizeConstraint( QLayout::SetFixedSize );
    QWidget* centralWidget = new QWidget();
    QWidget* infoWidget = new QWidget();
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* infoLayout = new QHBoxLayout();

    sc = 0;
    score = new QLabel(QString("%1").arg(sc));
    area = new TetrisArea(this);

    mainLayout->addWidget(area);
    mainLayout->addWidget(infoWidget, 0, Qt::AlignTop);

    QLabel* text = new QLabel("Score:");

    QFont font( "Times New Roman", 18, QFont::Bold );
    text->setFont(font);
    text->setStyleSheet("QLabel { color : red; }");
    score->setFont(font);
    score->setStyleSheet("QLabel { color : black; }");

    restartButton = new QPushButton("Restart");
    restartButton->setFocusPolicy(Qt::NoFocus);

    infoLayout->addWidget(text, 0, Qt::AlignTop | Qt::AlignRight);
    infoLayout->addWidget(score, 0, Qt::AlignTop | Qt::AlignLeft);
    infoLayout->addWidget(restartButton, 0, Qt::AlignTop);

    keyPressed = false;

    connect(restartButton, SIGNAL(clicked()), this, SLOT(restart()));

    infoWidget->setLayout(infoLayout);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

void Tetris::keyPressEvent(QKeyEvent* event)
{
    if(event->isAutoRepeat()) return;
    if(!keyPressed){
        area->keyPress(event);
        keyPressed = true;
     }
}

void Tetris::keyReleaseEvent(QKeyEvent* event)
{
    if(event->isAutoRepeat()) return;
    keyPressed = false;
}

void Tetris::restart()
{
    area->restart();
}

void Tetris::paintEvent(QPaintEvent *event)
{
    score->setText(QString("%1").arg(sc));
    score->update();
}

