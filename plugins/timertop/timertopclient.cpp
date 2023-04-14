/*
  timertopclient.cpp

  This file is part of GammaRay, the Qt application inspection and manipulation tool.

  SPDX-FileCopyrightText: 2014-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Filipe Azevedo <filipe.azevedo@kdab.com>

  SPDX-License-Identifier: GPL-2.0-or-later

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

#include "timertopclient.h"

#include <common/endpoint.h>

using namespace GammaRay;

TimerTopClient::TimerTopClient(QObject *parent)
    : TimerTopInterface(parent)
{
}

TimerTopClient::~TimerTopClient() = default;

void TimerTopClient::clearHistory()
{
    Endpoint::instance()->invokeObject(objectName(), "clearHistory");
}
