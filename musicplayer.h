#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QWidget>

namespace Ui {
class musicPlayer;
}

class musicPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit musicPlayer(QWidget *parent = 0);
    ~musicPlayer();

private:
    Ui::musicPlayer *ui;
};

#endif // MUSICPLAYER_H
