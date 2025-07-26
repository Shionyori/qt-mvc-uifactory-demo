#include "CoreController.h"

CoreController& CoreController::instance() {
    static CoreController controller;
    return controller;
}

void CoreController::registerHandler(const QString& commandId, std::function<void(QVariant)> handler) {
    m_handlers.insert(commandId, handler);
}

void CoreController::dispatch(QString commandId, QVariant context) {
    if (m_handlers.contains(commandId)) {
        m_handlers.value(commandId)(context);
    }
}
