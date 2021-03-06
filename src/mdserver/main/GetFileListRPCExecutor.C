// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <DebugStream.h>
#include <GetFileListRPCExecutor.h>
#include <GetFileListRPC.h>
#include <MDServerConnection.h>
#include <TimingsManager.h>

// ****************************************************************************
// Method: GetFileListRPCExecutor::GetFileListRPCExecutor
//
// Purpose: 
//   Constructor for the GetFileListRPCExecutor class.
//
// Arguments:
//   parent : A pointer to the object that created this executor.
//   s      : A pointer to the RPC that will call this RPC executor.
//
// Returns:    
//
// Note:       
//
// Programmer: Jeremy Meredith
// Creation:   August 29, 2000
//
// Modifications:
//   
// ****************************************************************************

GetFileListRPCExecutor::GetFileListRPCExecutor(MDServerConnection *parent_,
    Subject *s) : Observer(s)
{
    parent = parent_;
}

// ****************************************************************************
// Method: GetFileListRPCExecutor::~GetFileListRPCExecutor
//
// Purpose: 
//   Destructor for the GetFileListRPCExecutor class.
//
// Programmer: Jeremy Meredith
// Creation:   August 29, 2000
//
// Modifications:
//   
// ****************************************************************************

GetFileListRPCExecutor::~GetFileListRPCExecutor()
{
}

// ****************************************************************************
// Method: GetFileListRPCExecutor::Update
//
// Purpose: 
//   Gets the current file list.
//
// Arguments:
//   s : A pointer to the GetFileListRPC that called this method.
//
// Programmer: Jeremy Meredith
// Creation:   August 29, 2000
//
// Modifications:
//   Brad Whitlock, Tue Mar 25 11:00:46 PDT 2003
//   I added support for automatic file grouping.
//
//   Brad Whitlock, Thu Jul 29 12:20:50 PDT 2004
//   I added support for extra smart file grouping.
//
//   Brad Whitlock, Fri Feb 4 15:17:39 PST 2005
//   I changed how the file grouping settings are passed to the connection.
//
//   Brad Whitlock, Thu Dec 15 10:23:46 PDT 2005
//   I added a timer.
//
//   Hank Childs, Thu Sep  4 16:50:48 PDT 2008
//   Print out the file list correctly for the non-automatic grouping case.
//
// ****************************************************************************

void
GetFileListRPCExecutor::Update(Subject *s)
{
    int total = visitTimer->StartTimer();
    GetFileListRPC *rpc = (GetFileListRPC *)s;

    debug2 << "GetFileListRPCExecutor::Update\n" << std::flush;

    // Either send a successful reply or send an error.
    if(parent->GetReadFileListReturnValue() == 0)
    {
        if(rpc->GetAutomaticFileGrouping())
        {
            // Get the filtered file list.
            GetFileListRPC::FileList files;
            parent->SetFileGroupingOptions(rpc->GetFilter(),
                rpc->GetSmartFileGrouping());
            parent->GetFilteredFileList(files);

            debug4 << "FILELIST=" << files << endl << std::flush;
            rpc->SendReply(&files);
        }
        else
        {
            GetFileListRPC::FileList *files = parent->GetCurrentFileList();
            if (files == NULL)
                debug4 << "FILELIST is NULL!" << endl;
            else
                debug4 << "FILELIST=" << *files << endl << std::flush;

            rpc->SendReply(files);
        }
    }
    else
        rpc->SendError();

    visitTimer->StopTimer(total, "GetFileListRPC");
}

