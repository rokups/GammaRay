/*
  qmlcontexttab.cpp

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2016 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
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

#include "qmlcontexttab.h"
#include "ui_qmlcontexttab.h"

#include <ui/contextmenuextension.h>
#include <ui/deferredresizemodesetter.h>
#include <ui/propertyeditor/propertyeditordelegate.h>

#include <common/objectbroker.h>
#include <common/propertymodel.h>
#include <common/probecontrollerinterface.h>

#include <QMenu>

using namespace GammaRay;

QmlContextTab::QmlContextTab(PropertyWidget *parent) :
    QWidget(parent),
    ui(new Ui::QmlContextTab)
{
    ui->setupUi(this);

    auto contextModel = ObjectBroker::model(parent->objectBaseName() + QStringLiteral(".qmlContextModel"));
    ui->contextView->setModel(contextModel);
    ui->contextView->setSelectionModel(ObjectBroker::selectionModel(contextModel));

    ui->contextPropertyView->setModel(ObjectBroker::model(parent->objectBaseName() + QStringLiteral(".qmlContextPropertyModel")));
    new DeferredResizeModeSetter(ui->contextPropertyView->header(), 0, QHeaderView::ResizeToContents);
    ui->contextPropertyView->setItemDelegate(new PropertyEditorDelegate(this));
    connect(ui->contextPropertyView, &QWidget::customContextMenuRequested, this, &QmlContextTab::propertiesContextMenu);
}

QmlContextTab::~QmlContextTab()
{
}

void QmlContextTab::propertiesContextMenu(QPoint pos)
{
    const auto idx = ui->contextPropertyView->indexAt(pos);
    if (!idx.isValid())
        return;

    const auto actions = idx.data(PropertyModel::ActionRole).toInt();
    if (actions != PropertyModel::NavigateTo)
        return;

    const auto objectId = idx.data(PropertyModel::ObjectIdRole).value<ObjectId>();
    if (objectId.isNull())
        return;

    QMenu contextMenu;
    ContextMenuExtension ext(objectId);
    ext.populateMenu(&contextMenu);
    contextMenu.exec(ui->contextPropertyView->viewport()->mapToGlobal(pos));
}
