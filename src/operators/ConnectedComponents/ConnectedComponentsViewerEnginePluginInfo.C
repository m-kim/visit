// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//  File: ConnectedComponentsViewerEnginePluginInfo.C
// ************************************************************************* //

#include <ConnectedComponentsPluginInfo.h>
#include <ConnectedComponentsAttributes.h>

//
// Storage for static data elements.
//
ConnectedComponentsAttributes *ConnectedComponentsViewerEnginePluginInfo::clientAtts = NULL;
ConnectedComponentsAttributes *ConnectedComponentsViewerEnginePluginInfo::defaultAtts = NULL;

// ****************************************************************************
//  Method:  ConnectedComponentsViewerEnginePluginInfo::InitializeGlobalObjects
//
//  Purpose:
//    Initialize the operator atts.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************
void
ConnectedComponentsViewerEnginePluginInfo::InitializeGlobalObjects()
{
    ConnectedComponentsViewerEnginePluginInfo::clientAtts  = new ConnectedComponentsAttributes;
    ConnectedComponentsViewerEnginePluginInfo::defaultAtts = new ConnectedComponentsAttributes;
}

// ****************************************************************************
//  Method: ConnectedComponentsViewerEnginePluginInfo::GetClientAtts
//
//  Purpose:
//    Return a pointer to the viewer client attributes.
//
//  Returns:    A pointer to the viewer client attributes.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

AttributeSubject *
ConnectedComponentsViewerEnginePluginInfo::GetClientAtts()
{
    return clientAtts;
}

// ****************************************************************************
//  Method: ConnectedComponentsViewerEnginePluginInfo::GetDefaultAtts
//
//  Purpose:
//    Return a pointer to the viewer default attributes.
//
//  Returns:    A pointer to the viewer default attributes.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

AttributeSubject *
ConnectedComponentsViewerEnginePluginInfo::GetDefaultAtts()
{
    return defaultAtts;
}

// ****************************************************************************
//  Method: ConnectedComponentsViewerEnginePluginInfo::SetClientAtts
//
//  Purpose:
//    Set the viewer client attributes.
//
//  Arguments:
//    atts      A pointer to the new client attributes.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

void
ConnectedComponentsViewerEnginePluginInfo::SetClientAtts(AttributeSubject *atts)
{
    *clientAtts = *(ConnectedComponentsAttributes *)atts;
    clientAtts->Notify();
}

// ****************************************************************************
//  Method: ConnectedComponentsViewerEnginePluginInfo::GetClientAtts
//
//  Purpose:
//    Get the viewer client attributes.
//
//  Arguments:
//    atts      A pointer to return the client default attributes in.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

void
ConnectedComponentsViewerEnginePluginInfo::GetClientAtts(AttributeSubject *atts)
{
    *(ConnectedComponentsAttributes *)atts = *clientAtts;
}

// ****************************************************************************
//  Method: ConnectedComponentsViewerEnginePluginInfo::InitializeOperatorAtts
//
//  Purpose:
//    Initialize the operator attributes to the default attributes.
//
//  Arguments:
//    atts        The attribute subject to initialize.
//    plot        The viewer plot that owns the operator.
//    fromDefault True to initialize the attributes from the defaults. False
//                to initialize from the current attributes.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

void
ConnectedComponentsViewerEnginePluginInfo::InitializeOperatorAtts(AttributeSubject *atts,
                                              const avtPlotMetaData &plot,
                                              const bool fromDefault)
{
    if (fromDefault)
        *(ConnectedComponentsAttributes*)atts = *defaultAtts;
    else
        *(ConnectedComponentsAttributes*)atts = *clientAtts;

    UpdateOperatorAtts(atts, plot);
}

// ****************************************************************************
//  Method: ConnectedComponentsViewerEnginePluginInfo::UpdateOperatorAtts
//
//  Purpose:
//    Update the operator attributes when using operator expressions.
//
//  Arguments:
//    atts        The attribute subject to update.
//    plot        The viewer plot that owns the operator.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

void
ConnectedComponentsViewerEnginePluginInfo::UpdateOperatorAtts(AttributeSubject *atts, const avtPlotMetaData &plot)
{
}

// ****************************************************************************
//  Method: ConnectedComponentsViewerEnginePluginInfo::GetMenuName
//
//  Purpose:
//    Return a pointer to the name to use in the viewer menus.
//
//  Returns:    A pointer to the name to use in the viewer menus.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

const char *
ConnectedComponentsViewerEnginePluginInfo::GetMenuName() const
{
    return "ConnectedComponents";
}

