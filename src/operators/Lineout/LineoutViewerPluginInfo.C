// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//  File: LineoutViewerPluginInfo.C
// ************************************************************************* //

#include <LineoutPluginInfo.h>
#include <LineoutAttributes.h>

VISIT_OPERATOR_PLUGIN_ENTRY_EV(Lineout,Viewer)


// ****************************************************************************
//  Method: LineoutViewerPluginInfo::XPMIconData
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

#include <Lineout.xpm>
const char **
LineoutViewerPluginInfo::XPMIconData() const
{
    return Lineout_xpm;
}

