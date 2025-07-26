#pragma once

#include "AbstractCommand.hpp"
#include "../model/ConfigModel.h"

class ButtonCommand : public AbstractCommand {
    Q_OBJECT
public:
    explicit ButtonCommand(ConfigModel* model, QObject *parent = nullptr);
    void execute() override;

private:
    ConfigModel* m_model;
};