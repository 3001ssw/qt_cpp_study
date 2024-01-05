#ifndef TV_H
#define TV_H

#include <QObject>

class Tv : public QObject
{
    Q_OBJECT
public:
    explicit Tv(QObject *parent = nullptr);

public slots:
    void slot_TvOn();
};

#endif // TV_H
