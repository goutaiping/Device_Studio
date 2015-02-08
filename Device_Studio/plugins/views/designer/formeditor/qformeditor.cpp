#include "qformeditor.h"

#include "qformpanel.h"

#include "../../../../libs/kernel/host/qabstractwidgethost.h"

#include <QPainter>

QFormEditor::QFormEditor(QWidget* parent):
    QStackedWidget(parent)
{
    this->setAutoFillBackground(false);
}

void QFormEditor::setHostList(QList<QAbstractWidgetHost *> list)
{
    clear();

    foreach(QAbstractWidgetHost * host,list)
    {
        QFormPanel * panel = new QFormPanel(host);
        m_panelToHost.insert(panel,host);
        m_hostToPanel.insert(host,panel);
        addWidget(panel);
    }
}

void QFormEditor::clear()
{
    qDeleteAll(m_panelToHost.values());
    m_panelToHost.clear();
    m_hostToPanel.clear();
}

void QFormEditor::showHost(QAbstractWidgetHost *host)
{
    setCurrentWidget(m_hostToPanel.value(host));
}

void QFormEditor::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.fillRect(this->rect(),QColor(255,255,255));
}