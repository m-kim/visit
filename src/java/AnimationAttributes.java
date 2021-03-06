// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

package llnl.visit;


// ****************************************************************************
// Class: AnimationAttributes
//
// Purpose:
//    This class contains the animation attributes.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class AnimationAttributes extends AttributeSubject
{
    private static int AnimationAttributes_numAdditionalAtts = 5;

    // Enum values
    public final static int ANIMATIONMODE_REVERSEPLAYMODE = 0;
    public final static int ANIMATIONMODE_STOPMODE = 1;
    public final static int ANIMATIONMODE_PLAYMODE = 2;

    public final static int PLAYBACKMODE_LOOPING = 0;
    public final static int PLAYBACKMODE_PLAYONCE = 1;
    public final static int PLAYBACKMODE_SWING = 2;


    public AnimationAttributes()
    {
        super(AnimationAttributes_numAdditionalAtts);

        animationMode = ANIMATIONMODE_STOPMODE;
        pipelineCachingMode = false;
        frameIncrement = 1;
        timeout = 1;
        playbackMode = PLAYBACKMODE_PLAYONCE;
    }

    public AnimationAttributes(int nMoreFields)
    {
        super(AnimationAttributes_numAdditionalAtts + nMoreFields);

        animationMode = ANIMATIONMODE_STOPMODE;
        pipelineCachingMode = false;
        frameIncrement = 1;
        timeout = 1;
        playbackMode = PLAYBACKMODE_PLAYONCE;
    }

    public AnimationAttributes(AnimationAttributes obj)
    {
        super(obj);

        animationMode = obj.animationMode;
        pipelineCachingMode = obj.pipelineCachingMode;
        frameIncrement = obj.frameIncrement;
        timeout = obj.timeout;
        playbackMode = obj.playbackMode;

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return AnimationAttributes_numAdditionalAtts;
    }

    public boolean equals(AnimationAttributes obj)
    {
        // Create the return value
        return ((animationMode == obj.animationMode) &&
                (pipelineCachingMode == obj.pipelineCachingMode) &&
                (frameIncrement == obj.frameIncrement) &&
                (timeout == obj.timeout) &&
                (playbackMode == obj.playbackMode));
    }

    // Property setting methods
    public void SetAnimationMode(int animationMode_)
    {
        animationMode = animationMode_;
        Select(0);
    }

    public void SetPipelineCachingMode(boolean pipelineCachingMode_)
    {
        pipelineCachingMode = pipelineCachingMode_;
        Select(1);
    }

    public void SetFrameIncrement(int frameIncrement_)
    {
        frameIncrement = frameIncrement_;
        Select(2);
    }

    public void SetTimeout(int timeout_)
    {
        timeout = timeout_;
        Select(3);
    }

    public void SetPlaybackMode(int playbackMode_)
    {
        playbackMode = playbackMode_;
        Select(4);
    }

    // Property getting methods
    public int     GetAnimationMode() { return animationMode; }
    public boolean GetPipelineCachingMode() { return pipelineCachingMode; }
    public int     GetFrameIncrement() { return frameIncrement; }
    public int     GetTimeout() { return timeout; }
    public int     GetPlaybackMode() { return playbackMode; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteInt(animationMode);
        if(WriteSelect(1, buf))
            buf.WriteBool(pipelineCachingMode);
        if(WriteSelect(2, buf))
            buf.WriteInt(frameIncrement);
        if(WriteSelect(3, buf))
            buf.WriteInt(timeout);
        if(WriteSelect(4, buf))
            buf.WriteInt(playbackMode);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            SetAnimationMode(buf.ReadInt());
            break;
        case 1:
            SetPipelineCachingMode(buf.ReadBool());
            break;
        case 2:
            SetFrameIncrement(buf.ReadInt());
            break;
        case 3:
            SetTimeout(buf.ReadInt());
            break;
        case 4:
            SetPlaybackMode(buf.ReadInt());
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + indent + "animationMode = ";
        if(animationMode == ANIMATIONMODE_REVERSEPLAYMODE)
            str = str + "ANIMATIONMODE_REVERSEPLAYMODE";
        if(animationMode == ANIMATIONMODE_STOPMODE)
            str = str + "ANIMATIONMODE_STOPMODE";
        if(animationMode == ANIMATIONMODE_PLAYMODE)
            str = str + "ANIMATIONMODE_PLAYMODE";
        str = str + "\n";
        str = str + boolToString("pipelineCachingMode", pipelineCachingMode, indent) + "\n";
        str = str + intToString("frameIncrement", frameIncrement, indent) + "\n";
        str = str + intToString("timeout", timeout, indent) + "\n";
        str = str + indent + "playbackMode = ";
        if(playbackMode == PLAYBACKMODE_LOOPING)
            str = str + "PLAYBACKMODE_LOOPING";
        if(playbackMode == PLAYBACKMODE_PLAYONCE)
            str = str + "PLAYBACKMODE_PLAYONCE";
        if(playbackMode == PLAYBACKMODE_SWING)
            str = str + "PLAYBACKMODE_SWING";
        str = str + "\n";
        return str;
    }


    // Attributes
    private int     animationMode;
    private boolean pipelineCachingMode;
    private int     frameIncrement;
    private int     timeout;
    private int     playbackMode;
}

