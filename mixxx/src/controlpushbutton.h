/***************************************************************************
                          controlpushbutton.h  -  description
                             -------------------
    begin                : Wed Feb 20 2002
    copyright            : (C) 2002 by Tue and Ken Haste Andersen
    email                : 
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef CONTROLPUSHBUTTON_H
#define CONTROLPUSHBUTTON_H

#include "controlobject.h"
#include "defs.h"
#include "wbulb.h"

/**
  *@author Tue and Ken Haste Andersen
  */

class ControlPushButton : public ControlObject
{
    Q_OBJECT
public:
    ControlPushButton(ConfigKey key, WBulb *led = 0);
    ~ControlPushButton();
    char *print();
    char *printValue();
    int getPosition();
    void setValue(int);
    void setWidget(QWidget *_widget);
public slots:
    void slotSetPosition(int);
private slots:
    void slotClicked();
signals:
    void valueChanged(int);
protected:
    void forceGUIUpdate();
//    char *name;            // The name of the button
//    buttonType kind;       // Determine whether the button is latching or not.
    WBulb *led;
};

#endif
