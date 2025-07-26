#pragma once

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include "../controller/CoreController.h"
#include "../ui/ButtonCommand.h"
#include "../ui/LabelCommand.h"
#include "../ui/UIFactory.hpp"
#include "../model/ConfigModel.h"
#include "../delegate/ButtonDelegate.h"
#include "../delegate/LabelDelegate.h"
#include "../ui/ButtonCommand.h"
#include "../ui/LabelCommand.h"

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);

private:
    ConfigModel configModel;
    ButtonCommand btnCmd;
    LabelCommand lblCmd;
};