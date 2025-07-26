#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include "controller/CoreController.h"
#include "ui/ButtonCommand.h"
#include "ui/LabelCommand.h"
#include "ui/UIFactory.hpp"
#include "model/ConfigModel.h"
#include "delegate/ButtonDelegate.h"
#include "delegate/LabelDelegate.h"
#include "ui/ButtonCommand.h"
#include "ui/LabelCommand.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    // 初始化模型
    ConfigModel configModel;
    
    // 创建命令
    ButtonCommand btnCmd(&configModel);
    btnCmd.setCommandId("INCREMENT_CMD");
    
    LabelCommand lblCmd(&configModel);
    lblCmd.setCommandId("DISPLAY_CMD");
    
    // 注册控制器处理
    CoreController::instance().registerHandler("INCREMENT_CMD", [&](QVariant) {
        // 实际业务逻辑
        qDebug() << "Handling increment command";
    });
    
    // 连接命令信号到控制器
    QObject::connect(&btnCmd, &AbstractCommand::executed,
                     &CoreController::instance(), &CoreController::dispatch);
    
    // 创建UI
    QWidget window;
    QVBoxLayout* layout = new QVBoxLayout;
    
    layout->addWidget(UIFactory::createLabel(&lblCmd));
    layout->addWidget(UIFactory::createButton(&btnCmd));
    
    window.setLayout(layout);
    window.show();
    
    return app.exec();
}