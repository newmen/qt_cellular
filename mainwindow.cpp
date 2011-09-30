#include <QtGui>
#include "mainwindow.h"

MainWindow::MainWindow() {
   renderArea = new RenderArea(this);
   nextButton = new Button(tr("Next"), this);
   playButton = new PlayButton(tr("Play"), tr("Stop"), this);

   connect(nextButton, SIGNAL(clicked()), renderArea, SLOT(next()));
   connect(playButton, SIGNAL(timerStart()), renderArea, SLOT(play()));
   connect(playButton, SIGNAL(timerStop()), renderArea, SLOT(stop()));

   QVBoxLayout *mainLayout = new QVBoxLayout(this);
   mainLayout->addWidget(renderArea);
   mainLayout->addWidget(nextButton, 0, Qt::AlignCenter);
   mainLayout->addWidget(playButton, 0, Qt::AlignCenter);
}

MainWindow::~MainWindow() {
	delete renderArea;
	delete nextButton;
	delete playButton;
}

