#pragma once

#include <QObject>
#include <QVariant>
#include <QMap>
#include <functional>

class CoreController : public QObject {
    Q_OBJECT
public:
    static CoreController& instance();

    void registerHandler(const QString& commandId, std::function<void(QVariant)> handler);

public slots:
    void dispatch(QString commandId, QVariant context);
private:
    QMap<QString, std::function<void(QVariant)>> m_handlers;
};