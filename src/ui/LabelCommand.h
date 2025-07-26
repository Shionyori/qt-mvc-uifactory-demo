#pragma once

#include "AbstractCommand.hpp"
#include "../model/ConfigModel.h"

class LabelCommand : public AbstractCommand {
    Q_OBJECT
public:
    explicit LabelCommand(ConfigModel* model, QObject *parent = nullptr);

    void execute() override;

    QString displayText() const;

private slots:
    void onCounterChanged(int value) {
        m_value = value;
    }
private:
    ConfigModel* m_model;
    int m_value = 0;
};