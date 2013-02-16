/*
 * Copyright (c) 2013 Damien Grauser (Damien.Grauser@pev-geneve.ch)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _GC_GcSideBarItem_h
#define _GC_GcSideBarItem_h 1

#include <QtGui>
#include <QList>
#include <QAction>

class GcSideBarItem;

class GcSideBarTitle : public QWidget
{
    Q_OBJECT

public:

    GcSideBarTitle(QString title,GcSideBarItem *parent);
    ~GcSideBarTitle();

    void addAction(QAction *action);

public slots:
    void paintEvent (QPaintEvent *event);

    void showHideClicked();

    void setExpanded(bool expanded);

signals:
    void showSideBar(bool);

    void addChart();

private:
    void paintBackground(QPaintEvent *);

    GcSideBarItem *parent;

    QHBoxLayout *titleLayout;
    QLabel *titleLabel;
    QToolBar *titleToolbar;
    QPushButton *showHide;

    int fullHeight;
};

class GcSideBarItem : public QWidget
{
    Q_OBJECT

public:

    GcSideBarItem(QString title, QWidget *parent);
    ~GcSideBarItem();

    void addAction(QAction *action);

    QWidget *content;

    bool state;

public slots:

    void addWidget(QWidget*);

private:
    QVBoxLayout *layout;

    GcSideBarTitle *titleBar;

};

#endif
