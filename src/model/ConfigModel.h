#pragma once
#include <QObject>

class ConfigModel : public QObject {
    Q_OBJECT
public:
    int counter() const;
    void incrementCounter();

signals:
    void counterChanged(int value);

private:
    int m_counter = 0;
};
