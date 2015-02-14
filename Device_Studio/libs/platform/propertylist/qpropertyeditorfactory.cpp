#include "qpropertyeditorfactory.h"

#include "editor/qbasiceditor.h"

#include "editor/qboolpropertyeditor.h"
#include "editor/qbytearrayeditor.h"

QMap<QString,QMetaObject> QPropertyEditorFactory::m_metaObjects;

void QPropertyEditorFactory::registerEditor(const QString &className, const QMetaObject &metaObject)
{
    m_metaObjects.insert(className,metaObject);
}

QAbstractPropertyEditor* QPropertyEditorFactory::createEditor(const QString &className,
                                                              QAbstractProperty* property)
{

    QAbstractPropertyEditor *editor = NULL;

    if(m_metaObjects.keys().contains(className))
    {
        QMetaObject metaObject = m_metaObjects.value(className);
        editor = (QAbstractPropertyEditor*)metaObject.newInstance(Q_ARG(QAbstractProperty*,property));
    }

    if(editor == NULL)
    {
        editor = new QBasicEditor(property);
    }
    return editor;
}

void QPropertyEditorFactory::registerInnerEditor()
{
    registerEditor("QBoolProperty",QBoolPropertyEditor::staticMetaObject);
    registerEditor("QByteArrayProperty",QByteArrayEditor::staticMetaObject);
}