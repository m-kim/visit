// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <CloseDatabaseRPCExecutor.h>
#include <MDServerConnection.h>
#include <CloseDatabaseRPC.h>

// ****************************************************************************
// Method: CloseDatabaseRPCExecutor::CloseDatabaseRPCExecutor
//
// Purpose: 
//   Constructor for the CloseDatabaseRPCExecutor class.
//
// Arguments:
//   parent_ : A pointer to the object that created this RPC executor.
//   s       : A pointer to the rpc that invokes this executor.
//
// Programmer: Brad Whitlock
// Creation:   Tue Jul 30 11:07:28 PDT 2002
//
// Modifications:
//   
// ****************************************************************************

CloseDatabaseRPCExecutor::CloseDatabaseRPCExecutor(
    MDServerConnection *parent_, Subject *s) : Observer(s)
{
    parent = parent_;
}

// ****************************************************************************
// Method: CloseDatabaseRPCExecutor::~CloseDatabaseRPCExecutor
//
// Purpose: 
//   Destructor for the CloseDatabaseRPCExecutor class.
//
// Programmer: Brad Whitlock
// Creation:   Tue Jul 30 11:07:28 PDT 2002
//
// Modifications:
//   
// ****************************************************************************

CloseDatabaseRPCExecutor::~CloseDatabaseRPCExecutor()
{
}

// ****************************************************************************
// Method: CloseDatabaseRPCExecutor::Update
//
// Purpose: 
//   Performs the work of the RPC executor which, in this case, is to close
//   the open database.
//
// Arguments:
//   s : A pointer to the CloseDatabaseRPC that caused this method to
//       be called.
//
// Programmer: Brad Whitlock
// Creation:   Tue Jul 30 11:07:28 PDT 2002
//
// Modifications:
//   Brad Whitlock, Fri Feb 4 08:31:18 PDT 2005
//   I added a database argument.
//
// ****************************************************************************

void
CloseDatabaseRPCExecutor::Update(Subject *s)
{
    CloseDatabaseRPC *rpc = (CloseDatabaseRPC *)s;
    parent->CloseDatabase(rpc->GetDatabase());
    rpc->SendReply();
}
