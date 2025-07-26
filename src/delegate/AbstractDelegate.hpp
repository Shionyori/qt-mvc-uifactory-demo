#pragma once

#include <QObject>
#include <QTimer>
#include "../ui/AbstractCommand.hpp"

class AbstractDelegate : public QObject {
    Q_OBJECT
public:
     AbstractDelegate(AbstractCommand* cmd, QWidget* widget, QObject* parent = nullptr)
        : QObject(parent), m_command(cmd), m_widget(widget)
    {
        // 创建轮询更新
        QTimer* timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &AbstractDelegate::refreshWidget);
        timer->start(100); // 100ms刷新周期
    }

protected slots:
    virtual void refreshWidget() = 0;

protected:
    AbstractCommand* m_command;
    QWidget* m_widget;
};