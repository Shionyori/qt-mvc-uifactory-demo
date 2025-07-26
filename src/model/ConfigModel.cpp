#include "ConfigModel.h"

int ConfigModel::counter() const {
    return m_counter;
}

void ConfigModel::incrementCounter() {
    m_counter++;
    emit counterChanged(m_counter);
}