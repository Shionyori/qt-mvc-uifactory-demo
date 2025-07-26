#include "LabelCommand.h"

LabelCommand::LabelCommand(ConfigModel* model, QObject *parent)
    : AbstractCommand(parent), m_model(model) {
    connect(m_model, &ConfigModel::counterChanged, 
            this, &LabelCommand::onCounterChanged);
}

void LabelCommand::execute() {} // 标签无执行操作

QString LabelCommand::displayText() const {
    return QString("Counter Value: %1").arg(m_value);
}