/*
  libraryinfomodel.h

  This file is part of GammaRay, the Qt application inspection and manipulation tool.

  SPDX-FileCopyrightText: 2018-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Volker Krause <volker.krause@kdab.com>

  SPDX-License-Identifier: GPL-2.0-or-later

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

#ifndef GAMMARAY_LIBRARYINFOMODEL_H
#define GAMMARAY_LIBRARYINFOMODEL_H

#include <QAbstractTableModel>

namespace GammaRay {

class LibraryInfoModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit LibraryInfoModel(QObject *parent = nullptr);

    int columnCount(const QModelIndex &parent) const override;
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};

}

#endif // GAMMARAY_LIBRARYINFOMODEL_H
