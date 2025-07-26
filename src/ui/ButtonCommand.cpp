#include "ButtonCommand.h"

ButtonCommand::ButtonCommand(ConfigModel* model, QObject *parent)
    : AbstractCommand(parent), m_model(model) {}

void ButtonCommand::execute() {
    m_model->incrementCounter();
    emit executed(m_commandId, QVariant());
}