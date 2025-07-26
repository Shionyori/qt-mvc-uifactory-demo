#include "ButtonDelegate.h"

ButtonDelegate::ButtonDelegate(ButtonCommand* cmd, QPushButton* btn, QObject* parent)
    : AbstractDelegate(cmd, btn), m_button(btn), m_buttonCmd(cmd)
{
    connect(m_button, &QPushButton::clicked, this, [this]() {
        m_command->execute();
    });
    m_button->setText("Click to Increment");
}

void ButtonDelegate::refreshWidget() {} // 按钮不需要定期更新