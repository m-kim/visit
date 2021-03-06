// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <AugDecompPluginInfo.h>
#include <avtAugDecompFileFormat.h>
#include <avtMTMDFileFormatInterface.h>
#include <avtGenericDatabase.h>

// ****************************************************************************
//  Method:  AugDecompCommonPluginInfo::GetDatabaseType
//
//  Purpose:
//    Returns the type of a AugDecomp database.
//
//  Programmer:  generated by xml2info
//  Creation:    omitted
//
// ****************************************************************************
DatabaseType
AugDecompCommonPluginInfo::GetDatabaseType()
{
    return DB_TYPE_MTMD;
}

// ****************************************************************************
//  Method: AugDecompCommonPluginInfo::SetupDatabase
//
//  Purpose:
//      Sets up a AugDecomp database.
//
//  Arguments:
//      list    A list of file names.
//      nList   The number of timesteps in list.
//      nBlocks The number of blocks in the list.
//
//  Returns:    A AugDecomp database from list.
//
//  Programmer: childs -- generated by xml2info
//  Creation:   Wed Feb 13 08:58:39 PDT 2008
//
//  Modifications:
//    Brad Whitlock, Tue Jun 24 16:34:12 PDT 2008
//    Pass the common info to the file format constructor since we're using
//    the common info to pass the pointer to the plugin manager.
//
//    Jeremy Meredith, Thu Jan 28 15:49:05 EST 2010
//    MTMD files can now be grouped into longer sequences.
//
// ****************************************************************************
avtDatabase *
AugDecompCommonPluginInfo::SetupDatabase(const char *const *list,
                                   int nList, int nBlock)
{
    // ignore any nBlocks past 1
    int nTimestepGroups = nList / nBlock;
    avtMTMDFileFormat **ffl = new avtMTMDFileFormat*[nTimestepGroups];
    for (int i = 0 ; i < nTimestepGroups ; i++)
    {
        ffl[i] = new avtAugDecompFileFormat(list[i*nBlock], this);
    }
    avtMTMDFileFormatInterface *inter 
           = new avtMTMDFileFormatInterface(ffl, nTimestepGroups);
    return new avtGenericDatabase(inter);
}

