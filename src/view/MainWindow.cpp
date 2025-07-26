#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent),
      configModel(),
      btnCmd(&configModel),
      lblCmd(&configModel)
{
    btnCmd.setCommandId("INCREMENT_CMD");
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
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(UIFactory::createLabel(&lblCmd));
    layout->addWidget(UIFactory::createButton(&btnCmd));
    setLayout(layout);

    this->resize(800, 600);
    this->setMinimumSize(400, 300);
}