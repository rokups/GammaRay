/*
  clienttoolmodel.h

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2016-2021 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Volker Krause <volker.krause@kdab.com>

  Licensees holding valid commercial KDAB GammaRay licenses may use this file in
  accordance with GammaRay Commercial License Agreement provided with the Software.

  Contact info@kdab.com if any conditions of this licensing are not clear to you.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GAMMARAY_CLIENTTOOLMODEL_H
#define GAMMARAY_CLIENTTOOLMODEL_H

#include <QAbstractListModel>
#include <QItemSelectionModel>

namespace GammaRay {

class ClientToolManager;

/*! Model of all selectable client tools. */
class ClientToolModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ClientToolModel(ClientToolManager *manager);
    ~ClientToolModel() override;

    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

private slots:
    void startReset();
    void finishReset();
    void toolEnabled(int toolIndex);

private:
    ClientToolManager *m_toolManager;
};

/*! Selection model that automatically syncs ClientToolModel with ClientToolManager. */
class ClientToolSelectionModel : public QItemSelectionModel
{
    Q_OBJECT
public:
    explicit ClientToolSelectionModel(ClientToolManager *manager);
    ~ClientToolSelectionModel() override;

private slots:
    void selectTool(int index);
    void selectDefaultTool();

private:
    ClientToolManager *m_toolManager;
};

}

#endif // GAMMARAY_CLIENTTOOLMODEL_H
