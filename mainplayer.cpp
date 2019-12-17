#include "mainplayer.h"
#include "ui_mainplayer.h"

MainPlayer::MainPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainPlayer)
{
    ui->setupUi(this);
    ui->showError->setVisible(false);
    ui->audioFileList->setVisible(false);
    ui->stopButton->setEnabled(false);
    ui->playList->setSelectionMode(QAbstractItemView::SingleSelection);
    myPlayer = new QMediaPlayer(this);

    folderName = QString("C:/SkyLife/AudioFiles/");
    loadAudioFiles();
    ui->playList->item(0)->setSelected(true);
}

MainPlayer::~MainPlayer()
{
    delete ui;
}


void MainPlayer::on_playButton_clicked()
{
    if(ui->playList->selectedItems().size() > 0)
    {
        ui->stopButton->setEnabled(true);
        ui->playButton->setVisible(false);
        QUrl message = QUrl::fromLocalFile(folderName + ui->audioFileList->currentText());
        QUrl message1 = QUrl::fromLocalFile(folderName + ui->playList->selectedItems().first()->text());
        myPlayer->setMedia(message1);

        connect(myPlayer, SIGNAL(error(QMediaPlayer::Error)), this, SLOT(showError(QMediaPlayer::Error)));
        myPlayer->play();
    }
}

void MainPlayer::showError(QMediaPlayer::Error er)
{
    ui->showError->setVisible(true);
}

void MainPlayer::on_stopButton_clicked()
{
    ui->showError->setVisible(false);
    if(ui->playList->selectedItems().size() > 0)

    {
        ui->stopButton->setEnabled(false);
        ui->playButton->setVisible(true);
        myPlayer->stop();
    }
}

void MainPlayer::loadAudioFiles()
{
    audioFiles = new QDir(folderName);
    audioFiles->setNameFilters( QStringList() << "*.wav" << "*.mp3" << "*.ogg" << "*.wma" << "*.aiff" << "*.aac");

//    audioFiles = new QDir(":/");

    for(int i = 0; i < audioFiles->entryList().size(); i++)
    {
        ui->audioFileList->addItem(audioFiles->entryList().at(i));
        ui->playList->addItem(audioFiles->entryList().at(i));
    }
}

