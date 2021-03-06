// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//  File: CoordSwapGUIPluginInfo.C
// ************************************************************************* //

#include <CoordSwapPluginInfo.h>
#include <CoordSwapAttributes.h>
#include <QApplication>
#include <QvisCoordSwapWindow.h>

VISIT_OPERATOR_PLUGIN_ENTRY(CoordSwap,GUI)

// ****************************************************************************
//  Method: CoordSwapGUIPluginInfo::GetMenuName
//
//  Purpose:
//    Return a pointer to the name to use in the GUI menu.
//
//  Returns:    A pointer to the name to use in the GUI menu.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

QString *
CoordSwapGUIPluginInfo::GetMenuName() const
{
    return new QString(qApp->translate("OperatorNames", "CoordSwap"));
}


// ****************************************************************************
//  Method: CoordSwapGUIPluginInfo::CreatePluginWindow
//
//  Purpose:
//    Return a pointer to an operator's attribute window.
//
//  Arguments:
//    type      The type of the operator.
//    attr      The attribute subject for the operator.
//    notepad   The notepad to use for posting the window.
//
//  Returns:    A pointer to the operator's attribute window.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

QvisPostableWindowObserver *
CoordSwapGUIPluginInfo::CreatePluginWindow(int type, AttributeSubject *attr,
    const QString &caption, const QString &shortName, QvisNotepadArea *notepad)
{
    return new QvisCoordSwapWindow(type, (CoordSwapAttributes *)attr,
        caption, shortName, notepad);
}

// ****************************************************************************
//  Method: CoordSwapGUIPluginInfo::XPMIconData
//
//  Purpose:
//    Return a pointer to the icon data.
//
//  Returns:    A pointer to the icon data.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

#include <CoordSwap.xpm>
const char **
CoordSwapGUIPluginInfo::XPMIconData() const
{
    return CoordSwap_xpm;
}

