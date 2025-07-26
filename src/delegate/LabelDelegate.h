#pragma once

#include "AbstractDelegate.hpp"
#include "../ui/LabelCommand.h"
#include <QLabel>

class LabelDelegate : public AbstractDelegate {
public:
    LabelDelegate(LabelCommand* cmd, QLabel* label);

protected:
    void refreshWidget() override;

private:
    QLabel* m_label;
    LabelCommand* m_labelCmd;
};