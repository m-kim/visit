// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//  File: LineSurfacePluginInfo.C
// ************************************************************************* //

#include <LineSurfacePluginInfo.h>
#include <LineSurfaceAttributes.h>

#include <visit-config.h>
VISIT_PLUGIN_VERSION(LineSurface,OP_EXPORT)

VISIT_OPERATOR_PLUGIN_ENTRY(LineSurface,General)

// ****************************************************************************
//  Method: LineSurfaceGeneralPluginInfo::GetName
//
//  Purpose:
//    Return the name of the operator plugin.
//
//  Returns:    A pointer to the name of the operator plugin.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

const char *
LineSurfaceGeneralPluginInfo::GetName() const
{
    return "LineSurface";
}

// ****************************************************************************
//  Method: LineSurfaceGeneralPluginInfo::GetVersion
//
//  Purpose:
//    Return the version of the operator plugin.
//
//  Returns:    A pointer to the version of the operator plugin.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

const char *
LineSurfaceGeneralPluginInfo::GetVersion() const
{
    return "1.0";
}

// ****************************************************************************
//  Method: LineSurfaceGeneralPluginInfo::GetID
//
//  Purpose:
//    Return the id of the operator plugin.
//
//  Returns:    A pointer to the id of the operator plugin.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

const char *
LineSurfaceGeneralPluginInfo::GetID() const
{
    return "LineSurface_1.0";
}
// ****************************************************************************
//  Method: LineSurfaceGeneralPluginInfo::EnabledByDefault
//
//  Purpose:
//    Return true if this plugin should be enabled by default; false otherwise.
//
//  Returns:    true/false
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

bool
LineSurfaceGeneralPluginInfo::EnabledByDefault() const
{
    return false;
}

// ****************************************************************************
//  Method: LineSurfaceGeneralPluginInfo::GetCategoryName
//
//  Purpose:
//    Return the category name to which the operator belongs.
//
//  Returns:    Return the category name to which the operator belongs.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

const char *
LineSurfaceGeneralPluginInfo::GetCategoryName() const
{
    return "Analysis";
}
