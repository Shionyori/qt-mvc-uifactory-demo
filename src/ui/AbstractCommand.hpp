#pragma once

#include <QObject>
#include <QString>
#include <QVariant>

class AbstractCommand : public QObject {
    Q_OBJECT
public:
    explicit AbstractCommand(QObject *parent = nullptr) : QObject(parent) {}
    virtual void execute() = 0;

    QString commandId() const { return m_commandId; }
    void setCommandId(const QString& id) { m_commandId = id; }

signals:
    void executed(QString commandId, QVariant context);

protected:
    QString m_commandId;
};
