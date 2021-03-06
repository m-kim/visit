// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//  File: LabelCommonPluginInfo.C
// ************************************************************************* //

#include <LabelPluginInfo.h>
#include <LabelAttributes.h>

// ****************************************************************************
//  Method: LabelCommonPluginInfo::AllocAttributes
//
//  Purpose:
//    Return a pointer to a newly allocated attribute subject.
//
//  Returns:    A pointer to the newly allocated attribute subject.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

AttributeSubject *
LabelCommonPluginInfo::AllocAttributes()
{
    return new LabelAttributes;
}

// ****************************************************************************
//  Method: LabelCommonPluginInfo::CopyAttributes
//
//  Purpose:
//    Copy a Label attribute subject.
//
//  Arguments:
//    to        The destination attribute subject.
//    from      The source attribute subject.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

void 
LabelCommonPluginInfo::CopyAttributes(AttributeSubject *to,
    AttributeSubject *from)
{
    *((LabelAttributes *) to) = *((LabelAttributes *) from);
}
// ****************************************************************************
// Method: LabelCommonPluginInfo::GetVariableTypes
//
// Purpose: 
//   Returns a flag indicating the types of variables that can be put in the
//   plot's variable list.
//
// Returns:    A flag indicating the types of variables that can be put in
//             the plot's variable list.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

int
LabelCommonPluginInfo::GetVariableTypes() const
{
    return VAR_CATEGORY_MESH | VAR_CATEGORY_SCALAR | VAR_CATEGORY_VECTOR | VAR_CATEGORY_MATERIAL | VAR_CATEGORY_SUBSET | VAR_CATEGORY_TENSOR | VAR_CATEGORY_SYMMETRIC_TENSOR | VAR_CATEGORY_LABEL | VAR_CATEGORY_ARRAY;
}

