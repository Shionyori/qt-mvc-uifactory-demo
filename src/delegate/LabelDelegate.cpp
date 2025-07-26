#include "LabelDelegate.h"

LabelDelegate::LabelDelegate(LabelCommand* cmd, QLabel* label)
    : AbstractDelegate(cmd, label), m_label(label), m_labelCmd(cmd)
{
    refreshWidget();
}

void LabelDelegate::refreshWidget() {
    m_label->setText(m_labelCmd->displayText());
}