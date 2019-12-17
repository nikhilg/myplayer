#ifndef MAINPLAYER_H
#define MAINPLAYER_H

#include <QWidget>
#include <QDir>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainPlayer; }
QT_END_NAMESPACE

class MainPlayer : public QWidget
{
    Q_OBJECT

public:
    MainPlayer(QWidget *parent = nullptr);
    ~MainPlayer();

private slots:
    void on_playButton_clicked();
    void on_stopButton_clicked();
    void showError(QMediaPlayer::Error);

private:
    Ui::MainPlayer *ui;
    void loadAudioFiles();

    QDir *audioFiles;
    QMediaPlayer *myPlayer;
    QString folderName;
};
#endif // MAINPLAYER_H
