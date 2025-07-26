#pragma once

#include "AbstractDelegate.hpp"
#include "../ui/ButtonCommand.h"
#include <QPushButton>

class ButtonDelegate : public AbstractDelegate {
public:
    ButtonDelegate(ButtonCommand* cmd, QPushButton* btn, QObject* parent = nullptr);

protected:
    void refreshWidget() override;

private:
    QPushButton* m_button;
    ButtonCommand* m_buttonCmd;
};