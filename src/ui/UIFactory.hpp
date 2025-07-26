#pragma once

#include <QPushButton>
#include <QLabel>
#include "ButtonCommand.h"
#include "LabelCommand.h"
#include "../delegate/ButtonDelegate.h"
#include "../delegate/LabelDelegate.h"

class UIFactory {
public:
    static QPushButton* createButton(ButtonCommand* cmd) {
        QPushButton* btn = new QPushButton();
        new ButtonDelegate(cmd, btn); // 自动建立绑定
        return btn;
    }

    static QLabel* createLabel(LabelCommand* cmd) {
        QLabel* label = new QLabel();
        new LabelDelegate(cmd, label); // 自动建立绑定
        return label;
    }
};
