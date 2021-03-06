#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

// obviously we don't need this low level class in .h file.
// normaly I would hide it in .c file or as pimpl.
// unfortunately Qt wants all QObject classes in .h file
class Downloader : public QObject
{
    Q_OBJECT
public:
    Downloader(QObject* parent);
    ~Downloader();

    void download(const QUrl& url);
signals:
    // if someone interested in a progress
    void progress( qint64 bytesReceived, qint64 bytesTotal );
    void done(const QByteArray& data );
    void error();

private slots:
    void finishedLoad(QNetworkReply* reply);

private:
    QNetworkAccessManager* accessMgr_ = nullptr;
};

#endif // DOWNLOADER_H
