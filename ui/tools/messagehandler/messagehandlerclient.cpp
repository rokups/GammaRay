/*
  messagehandlerclient.cpp

  This file is part of GammaRay, the Qt application inspection and manipulation tool.

  SPDX-FileCopyrightText: 2013-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Milian Wolff <milian.wolff@kdab.com>

  SPDX-License-Identifier: GPL-2.0-or-later

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

#include "messagehandlerclient.h"

#include <common/endpoint.h>

using namespace GammaRay;

MessageHandlerClient::MessageHandlerClient(QObject *parent)
    : MessageHandlerInterface(parent)
{
}

void MessageHandlerClient::generateFullTrace()
{
    Endpoint::instance()->invokeObject(objectName(), "generateFullTrace");
}
