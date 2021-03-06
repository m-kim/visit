// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//  File: MeshGUIPluginInfo.C
// ************************************************************************* //

#include <MeshPluginInfo.h>
#include <MeshAttributes.h>
#include <QApplication>
#include <QvisMeshPlotWindow.h>

VISIT_PLOT_PLUGIN_ENTRY(Mesh,GUI)

// ****************************************************************************
//  Method: MeshGUIPluginInfo::GetMenuName
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
MeshGUIPluginInfo::GetMenuName() const
{
    return new QString(qApp->translate("PlotNames", "Mesh"));
}


// ****************************************************************************
//  Method: MeshGUIPluginInfo::CreatePluginWindow
//
//  Purpose:
//    Return a pointer to an plot's attribute window.
//
//  Arguments:
//    type      The type of the plot.
//    attr      The attribute subject for the plot.
//    notepad   The notepad to use for posting the window.
//
//  Returns:    A pointer to the plot's attribute window.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

QvisPostableWindowObserver *
MeshGUIPluginInfo::CreatePluginWindow(int type, AttributeSubject *attr,
    const QString &caption, const QString &shortName, QvisNotepadArea *notepad)
{
    return new QvisMeshPlotWindow(type, (MeshAttributes *)attr,
        caption, shortName, notepad);
}

// ****************************************************************************
//  Method: MeshGUIPluginInfo::XPMIconData
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

#include <Mesh.xpm>
const char **
MeshGUIPluginInfo::XPMIconData() const
{
    return Mesh_xpm;
}

