// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                        FluxScriptingPluginInfo.C
// ************************************************************************* //
#include <PyFluxAttributes.h>
#include <FluxPluginInfo.h>

VISIT_OPERATOR_PLUGIN_ENTRY(Flux,Scripting)

// ****************************************************************************
// Method: FluxScriptingPluginInfo::InitializePlugin
//
// Purpose: 
//   Calls the initialization function for the plugin.
//
// Arguments:
//   subj    : A pointer to the plugin's state object.
//   data    : A pointer to data to be used by the observer function.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void
FluxScriptingPluginInfo::InitializePlugin(AttributeSubject *subj,
    void *data)
{
    PyFluxAttributes_StartUp((FluxAttributes *)subj, data);
}

// ****************************************************************************
// Method: FluxScriptingPluginInfo::GetMethodTable
//
// Purpose: 
//   Returns a pointer to the plugin's Python method table. These methods are
//   added to the top-level visit module's methods.
//
// Arguments:
//   nMethods : Returns the number of methods in the method table.
//
// Returns:    A pointer to the method table.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void *
FluxScriptingPluginInfo::GetMethodTable(int *nMethods)
{
    return PyFluxAttributes_GetMethodTable(nMethods);
}

// ****************************************************************************
// Method: FluxScriptingPluginInfo::TypesMatch
//
// Purpose: 
//   Returns whether or not the input PyObject is Flux plot attributes.
//
// Arguments:
//   pyobject : A PyObject cast to void*.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

bool
FluxScriptingPluginInfo::TypesMatch(void *pyobject)
{
    return PyFluxAttributes_Check((PyObject *)pyobject);
}

// ****************************************************************************
// Method: FluxScriptingPluginInfo::GetLogString
//
// Purpose: 
//   Gets a string representation of the current attributes.
//
// Arguments:
//   val : Whether or not to log state information.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

char *
FluxScriptingPluginInfo::GetLogString()
{
    std::string s(PyFluxAttributes_GetLogString());
    char *v = new char[s.size() + 1];
    strcpy(v, s.c_str());
    return v;
}

// ****************************************************************************
// Method: FluxScriptingPluginInfo::SetDefaults
//
// Purpose: 
//   Used to set the default values for a plugin's state object.
//
// Arguments:
//   atts : The new state.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void
FluxScriptingPluginInfo::SetDefaults(const AttributeSubject *atts)
{
    PyFluxAttributes_SetDefaults((const FluxAttributes *)atts);
}
