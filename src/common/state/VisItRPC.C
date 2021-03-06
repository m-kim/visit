// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <VisItRPC.h>
#include <Xfer.h>

#include <string>
using std::string;


VisItRPC::RPCReply::RPCReply(int s, AttributeSubject *d) 
    : AttributeSubject("issa"),
      status(s),
      message(""),
      type(""),
      data(d),
      rpcName("")
{
}

VisItRPC::RPCReply::~RPCReply() 
{
}

void
VisItRPC::RPCReply::SelectAll()
{
    Select(0,&status);
    Select(1,&message);
    Select(2,&type);
    if (data)
        Select(3,data);
}

void
VisItRPC::RPCReply::SetStatus(int s)
{
    status=s;
    Select(0,&status);
}

int
VisItRPC::RPCReply::GetStatus() const
{
    return status;
}

void
VisItRPC::RPCReply::SetMessage(const std::string &msg)
{
    message=msg;
    Select(1,&message);
}

const std::string &
VisItRPC::RPCReply::Message() const
{
    return message;
}

void
VisItRPC::RPCReply::SetExceptionType(const std::string &etype)
{
    type=etype;
    Select(2,&type);
}

const std::string &
VisItRPC::RPCReply::GetExceptionType() const
{
    return type;
}

void
VisItRPC::RPCReply::SetData(AttributeSubject *d)
{
    data=d;
    if (data)
        Select(3,data);
}

AttributeSubject *
VisItRPC::RPCReply::GetData()
{
    return data;
}

void
VisItRPC::RPCReply::SetRPCName(const std::string &name)
{
    rpcName = name;
}

const std::string
VisItRPC::RPCReply::TypeName() const
{
    std::string ret(data ? data->TypeName() : 
                    std::string("VisItRPC::RPCReply"));
    return ret + std::string(" (from ") + rpcName + std::string(")");
}

//-----------------------------------------------------------------------------

VisItRPC::VisItRPC(const char *fmt, int s, AttributeSubject *d) 
    : AttributeSubject(fmt),
      reply(s,d), 
      xfer(NULL)
{
}

VisItRPC::~VisItRPC()
{
}

int
VisItRPC::GetStatus() const
{
    return reply.GetStatus();
}

const std::string &
VisItRPC::Message() const
{
    return reply.Message();
}

const std::string &
VisItRPC::GetExceptionType() const
{
    return reply.GetExceptionType();
}


VisItRPC::RPCReply *
VisItRPC::GetReply()
{
    reply.SetRPCName(TypeName());

    return &reply;
}

void
VisItRPC::SetXfer(Xfer *x)
{
    xfer = x;
}

// ****************************************************************************
// Method: VisItRPC::RecvReply
//
// Purpose: 
//   Receives an RPC result back from the server.
//
// Programmer: Jeremy Meredith
// Creation:   Tue Aug 29 17:53:31 PST 2000
//
// Modifications:
//   Brad Whitlock, Tue Aug 29 17:54:10 PST 2000
//   I removed a cast from Connection to BufferConnection. The
//   Connection base class now understands the Append method.
//
//   Brad Whitlock, Thu Oct 19 12:31:11 PDT 2000
//   I enlarged the input buffer to 500.
//
//   Brad Whitlock, Tue Apr 24 11:23:19 PDT 2001
//   I added code to keep track of zero-length reads. If we get a bunch of
//   them in a row, throw an exception.
//
//   Brad Whitlock, Wed Mar 20 17:43:50 PST 2002
//   I abstracted the read code and removed the socket descriptor.
//
// ****************************************************************************

void
VisItRPC::RecvReply()
{
    if(xfer->GetInputConnection())
    {
        // Try and read more data from the server.
        int amountRead = xfer->GetInputConnection()->Fill();

        // Process the new information.
        if(amountRead > 0)
            xfer->Process();
    }
    else
        reply.SetStatus(complete);
}

void
VisItRPC::SendReply(int s, AttributeSubject *d)
{
    reply.SetStatus(s);
    reply.SetData(d);
    reply.Notify();
    reply.SetData(0);
}

void
VisItRPC::SendAbort()
{
    reply.SetStatus(abort);
    reply.SetData(0);
    reply.SetMessage("Operation aborted.");
    reply.Notify();
}

void
VisItRPC::SendError()
{
    reply.SetStatus(error);
    reply.SetData(0);
    reply.SetMessage("NoErrorMsgSet");
    reply.Notify();
}

void
VisItRPC::SendError(const std::string &msg)
{
    reply.SetStatus(error);
    reply.SetData(0);
    reply.SetMessage(msg);
    reply.Notify();
}

void
VisItRPC::SendError(const std::string &msg, const std::string &etype)
{
    reply.SetStatus(error);
    reply.SetMessage(msg);
    reply.SetData(0);
    reply.SetExceptionType(etype);
    reply.Notify();
}

void
VisItRPC::SendWarning(const std::string &msg)
{
    reply.SetStatus(warning);
    reply.SetMessage(msg);
    reply.SetData(0);
    reply.Notify();
}

//-----------------------------------------------------------------------------

NonBlockingRPC::NonBlockingRPC(const char *fmt, AttributeSubject *rd) 
    : VisItRPC(fmt, none, &completion)
{
    completion.SetReplyData(rd);
}

NonBlockingRPC::~NonBlockingRPC()
{
}

int
NonBlockingRPC::GetPercent() const
{
    return completion.GetPercent();
}

int
NonBlockingRPC::GetReplyLen() const
{
    return completion.GetReplyLen();
}

int
NonBlockingRPC::GetCurStageNum() const
{
    return completion.GetCurStageNum();
}

int
NonBlockingRPC::GetMaxStageNum() const
{
    return completion.GetMaxStageNum();
}

string
NonBlockingRPC::GetCurStageName() const
{
    return completion.GetCurStageName();
}

AttributeSubject *
NonBlockingRPC::GetReplyData() const
{
    return completion.GetReplyData();
}

//----
void
NonBlockingRPC::SendMaxStages(int n)
{
    completion.SetMaxStageNum(n);
    VisItRPC::SendReply(incomplete,&completion);
}

void
NonBlockingRPC::SendStage(int n, const string &s)
{
    completion.SetCurStageNum(n);
    completion.SetCurStageName(s);
    VisItRPC::SendReply(incomplete,&completion);
}

void
NonBlockingRPC::SendPercent(int p)
{
    completion.SetPercent(p);
    VisItRPC::SendReply(incomplete,&completion);
}

void
NonBlockingRPC::SendStatus(int percent, int curStage,
    const std::string &curStageName, int maxStages)
{
    completion.SetPercent(percent);
    completion.SetCurStageNum(curStage);
    completion.SetCurStageName(curStageName);
    completion.SetMaxStageNum(maxStages);
    VisItRPC::SendReply(incomplete,&completion);
}

void
NonBlockingRPC::SendReply(int l)
{
    completion.SetPercent(100);
    completion.SetReplyLen(l);
    VisItRPC::SendReply(complete,&completion);
}

void
NonBlockingRPC::SendReply(AttributeSubject *rd )
{
    completion.SetPercent(100);
    completion.SetReplyLen(0);
    completion.SetReplyData(rd);
    VisItRPC::SendReply(complete,&completion);
}

void
NonBlockingRPC::Execute()
{
    Notify();
    reply.SetStatus(incomplete);
    completion.SetCurStageNum(0);
    completion.SetMaxStageNum(0);
    completion.SetCurStageName("");
}

void
NonBlockingRPC::RecvReply()
{
    VisItRPC::RecvReply();
}

//-----------------------------------------------------------------------------

BlockingRPC::BlockingRPC(const char *fmt, AttributeSubject *d) 
    : VisItRPC(fmt,none,d)
{
}

BlockingRPC::~BlockingRPC()
{
}

void
BlockingRPC::SendReply(AttributeSubject *d)
{
    if (d)
        d->SelectAll();
    VisItRPC::SendReply(complete,d);
}

// ****************************************************************************
// Method: BlockingRPC::Execute
//
// Purpose: 
//   Executes the RPC and waits for the response.
//
// Programmer: Jeremy Meredith
// Creation:   Tue Aug 29 18:12:13 PST 2000
//
// Modifications:
//   Brad Whitlock, Tue Aug 29 18:12:44 PST 2000
//   I removed the throw since there was no pending exception. It was
//   acting like a call to abort. The invocation method should check
//   the error status of the reply and throw a descriptive exception.
//
//   Brad Whitlock, Mon Mar 25 09:42:15 PDT 2002
//   Removed the socket descriptor.
//
// ****************************************************************************

void
BlockingRPC::Execute()
{
    Notify();
    reply.SetStatus(incomplete);
    while (reply.GetStatus() == incomplete)
    {
        VisItRPC::RecvReply();
    }
}

