// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                        ConnCompReduceScriptingPluginInfo.C
// ************************************************************************* //
#include <PyConnCompReduceAttributes.h>
#include <ConnCompReducePluginInfo.h>

VISIT_OPERATOR_PLUGIN_ENTRY(ConnCompReduce,Scripting)

// ****************************************************************************
// Method: ConnCompReduceScriptingPluginInfo::InitializePlugin
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
ConnCompReduceScriptingPluginInfo::InitializePlugin(AttributeSubject *subj,
    void *data)
{
    PyConnCompReduceAttributes_StartUp((ConnCompReduceAttributes *)subj, data);
}

// ****************************************************************************
// Method: ConnCompReduceScriptingPluginInfo::GetMethodTable
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
ConnCompReduceScriptingPluginInfo::GetMethodTable(int *nMethods)
{
    return PyConnCompReduceAttributes_GetMethodTable(nMethods);
}

// ****************************************************************************
// Method: ConnCompReduceScriptingPluginInfo::TypesMatch
//
// Purpose: 
//   Returns whether or not the input PyObject is ConnCompReduce plot attributes.
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
ConnCompReduceScriptingPluginInfo::TypesMatch(void *pyobject)
{
    return PyConnCompReduceAttributes_Check((PyObject *)pyobject);
}

// ****************************************************************************
// Method: ConnCompReduceScriptingPluginInfo::GetLogString
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
ConnCompReduceScriptingPluginInfo::GetLogString()
{
    std::string s(PyConnCompReduceAttributes_GetLogString());
    char *v = new char[s.size() + 1];
    strcpy(v, s.c_str());
    return v;
}

// ****************************************************************************
// Method: ConnCompReduceScriptingPluginInfo::SetDefaults
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
ConnCompReduceScriptingPluginInfo::SetDefaults(const AttributeSubject *atts)
{
    PyConnCompReduceAttributes_SetDefaults((const ConnCompReduceAttributes *)atts);
}
