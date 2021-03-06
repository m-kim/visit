// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//  File: MultiresControlCommonPluginInfo.C
// ************************************************************************* //

#include <MultiresControlPluginInfo.h>
#include <MultiresControlAttributes.h>

// ****************************************************************************
//  Method: MultiresControlCommonPluginInfo::AllocAttributes
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
MultiresControlCommonPluginInfo::AllocAttributes()
{
    return new MultiresControlAttributes;
}

// ****************************************************************************
//  Method: MultiresControlCommonPluginInfo::CopyAttributes
//
//  Purpose:
//    Copy a MultiresControl attribute subject.
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
MultiresControlCommonPluginInfo::CopyAttributes(AttributeSubject *to,
    AttributeSubject *from)
{
    *((MultiresControlAttributes *) to) = *((MultiresControlAttributes *) from);
}
