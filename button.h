#ifndef BUTTON_H
#define BUTTON_H

#include <QToolButton>

class Button : public QToolButton
{
    Q_OBJECT
public:
    explicit Button(const QString &text, QWidget *parent = 0);

//signals:
//public slots:

};

#endif // BUTTON_H
