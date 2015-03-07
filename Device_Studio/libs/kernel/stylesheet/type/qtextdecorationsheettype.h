#ifndef QTEXTDECORATIONSHEETTYPE_H
#define QTEXTDECORATIONSHEETTYPE_H

#include "qabstractenumsheettype.h"

class QTextDecorationSheetType : public QAbstractEnumSheetType
{
    Q_OBJECT
public:
    Q_INVOKABLE QTextDecorationSheetType(QAbstractSheetType * parent = NULL);
    ~QTextDecorationSheetType();

    QStringList getValueList();
};

#endif // QTEXTDECORATIONSHEETTYPE_H
