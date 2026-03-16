// Copyright (C) 2025 Hermes3 Technology, LLC
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "../mainwindow.h"

#include <QtTest>

class MainWindowSmokeTest : public QObject
{
    Q_OBJECT

private slots:
    void showsMainWindow();
};

void MainWindowSmokeTest::showsMainWindow()
{
    MainWindow window;

    window.show();

    QVERIFY(window.isVisible());
}

QTEST_MAIN(MainWindowSmokeTest)

#include "mainwindow_smoke_test.moc"
