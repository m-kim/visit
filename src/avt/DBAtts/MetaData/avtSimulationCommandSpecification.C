// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <avtSimulationCommandSpecification.h>
#include <DataNode.h>

//
// Enum conversion methods for avtSimulationCommandSpecification::RunMode
//

static const char *RunMode_strings[] = {
"Unknown", "Running", "Stopped"
};

std::string
avtSimulationCommandSpecification::RunMode_ToString(avtSimulationCommandSpecification::RunMode t)
{
    int index = int(t);
    if(index < 0 || index >= 3) index = 0;
    return RunMode_strings[index];
}

std::string
avtSimulationCommandSpecification::RunMode_ToString(int t)
{
    int index = (t < 0 || t >= 3) ? 0 : t;
    return RunMode_strings[index];
}

bool
avtSimulationCommandSpecification::RunMode_FromString(const std::string &s, avtSimulationCommandSpecification::RunMode &val)
{
    val = avtSimulationCommandSpecification::Unknown;
    for(int i = 0; i < 3; ++i)
    {
        if(s == RunMode_strings[i])
        {
            val = (RunMode)i;
            return true;
        }
    }
    return false;
}

//
// Enum conversion methods for avtSimulationCommandSpecification::CommandArgumentType
//

static const char *CommandArgumentType_strings[] = {
"CmdArgNone", "CmdArgInt", "CmdArgFloat", 
"CmdArgString"};

std::string
avtSimulationCommandSpecification::CommandArgumentType_ToString(avtSimulationCommandSpecification::CommandArgumentType t)
{
    int index = int(t);
    if(index < 0 || index >= 4) index = 0;
    return CommandArgumentType_strings[index];
}

std::string
avtSimulationCommandSpecification::CommandArgumentType_ToString(int t)
{
    int index = (t < 0 || t >= 4) ? 0 : t;
    return CommandArgumentType_strings[index];
}

bool
avtSimulationCommandSpecification::CommandArgumentType_FromString(const std::string &s, avtSimulationCommandSpecification::CommandArgumentType &val)
{
    val = avtSimulationCommandSpecification::CmdArgNone;
    for(int i = 0; i < 4; ++i)
    {
        if(s == CommandArgumentType_strings[i])
        {
            val = (CommandArgumentType)i;
            return true;
        }
    }
    return false;
}

// ****************************************************************************
// Method: avtSimulationCommandSpecification::avtSimulationCommandSpecification
//
// Purpose: 
//   Init utility for the avtSimulationCommandSpecification class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void avtSimulationCommandSpecification::Init()
{
    argumentType = CmdArgNone;
    enabled = true;
    isOn = true;

    avtSimulationCommandSpecification::SelectAll();
}

// ****************************************************************************
// Method: avtSimulationCommandSpecification::avtSimulationCommandSpecification
//
// Purpose: 
//   Copy utility for the avtSimulationCommandSpecification class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void avtSimulationCommandSpecification::Copy(const avtSimulationCommandSpecification &obj)
{
    name = obj.name;
    argumentType = obj.argumentType;
    className = obj.className;
    enabled = obj.enabled;
    parent = obj.parent;
    isOn = obj.isOn;
    signal = obj.signal;
    text = obj.text;
    uiType = obj.uiType;
    value = obj.value;

    avtSimulationCommandSpecification::SelectAll();
}

// Type map format string
const char *avtSimulationCommandSpecification::TypeMapFormatString = AVTSIMULATIONCOMMANDSPECIFICATION_TMFS;
const AttributeGroup::private_tmfs_t avtSimulationCommandSpecification::TmfsStruct = {AVTSIMULATIONCOMMANDSPECIFICATION_TMFS};


// ****************************************************************************
// Method: avtSimulationCommandSpecification::avtSimulationCommandSpecification
//
// Purpose: 
//   Default constructor for the avtSimulationCommandSpecification class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

avtSimulationCommandSpecification::avtSimulationCommandSpecification() : 
    AttributeSubject(avtSimulationCommandSpecification::TypeMapFormatString)
{
    avtSimulationCommandSpecification::Init();
}

// ****************************************************************************
// Method: avtSimulationCommandSpecification::avtSimulationCommandSpecification
//
// Purpose: 
//   Constructor for the derived classes of avtSimulationCommandSpecification class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

avtSimulationCommandSpecification::avtSimulationCommandSpecification(private_tmfs_t tmfs) : 
    AttributeSubject(tmfs.tmfs)
{
    avtSimulationCommandSpecification::Init();
}

// ****************************************************************************
// Method: avtSimulationCommandSpecification::avtSimulationCommandSpecification
//
// Purpose: 
//   Copy constructor for the avtSimulationCommandSpecification class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

avtSimulationCommandSpecification::avtSimulationCommandSpecification(const avtSimulationCommandSpecification &obj) : 
    AttributeSubject(avtSimulationCommandSpecification::TypeMapFormatString)
{
    avtSimulationCommandSpecification::Copy(obj);
}

// ****************************************************************************
// Method: avtSimulationCommandSpecification::avtSimulationCommandSpecification
//
// Purpose: 
//   Copy constructor for derived classes of the avtSimulationCommandSpecification class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

avtSimulationCommandSpecification::avtSimulationCommandSpecification(const avtSimulationCommandSpecification &obj, private_tmfs_t tmfs) : 
    AttributeSubject(tmfs.tmfs)
{
    avtSimulationCommandSpecification::Copy(obj);
}

// ****************************************************************************
// Method: avtSimulationCommandSpecification::~avtSimulationCommandSpecification
//
// Purpose: 
//   Destructor for the avtSimulationCommandSpecification class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

avtSimulationCommandSpecification::~avtSimulationCommandSpecification()
{
    // nothing here
}

// ****************************************************************************
// Method: avtSimulationCommandSpecification::operator = 
//
// Purpose: 
//   Assignment operator for the avtSimulationCommandSpecification class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

avtSimulationCommandSpecification& 
avtSimulationCommandSpecification::operator = (const avtSimulationCommandSpecification &obj)
{
    if (this == &obj) return *this;

    avtSimulationCommandSpecification::Copy(obj);

    return *this;
}

// ****************************************************************************
// Method: avtSimulationCommandSpecification::operator == 
//
// Purpose: 
//   Comparison operator == for the avtSimulationCommandSpecification class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

bool
avtSimulationCommandSpecification::operator == (const avtSimulationCommandSpecification &obj) const
{
    // Create the return value
    return ((name == obj.name) &&
            (argumentType == obj.argumentType) &&
            (className == obj.className) &&
            (enabled == obj.enabled) &&
            (parent == obj.parent) &&
            (isOn == obj.isOn) &&
            (signal == obj.signal) &&
            (text == obj.text) &&
            (uiType == obj.uiType) &&
            (value == obj.value));
}

// ****************************************************************************
// Method: avtSimulationCommandSpecification::operator != 
//
// Purpose: 
//   Comparison operator != for the avtSimulationCommandSpecification class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

bool
avtSimulationCommandSpecification::operator != (const avtSimulationCommandSpecification &obj) const
{
    return !(this->operator == (obj));
}

// ****************************************************************************
// Method: avtSimulationCommandSpecification::TypeName
//
// Purpose: 
//   Type name method for the avtSimulationCommandSpecification class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

const std::string
avtSimulationCommandSpecification::TypeName() const
{
    return "avtSimulationCommandSpecification";
}

// ****************************************************************************
// Method: avtSimulationCommandSpecification::CopyAttributes
//
// Purpose: 
//   CopyAttributes method for the avtSimulationCommandSpecification class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

bool
avtSimulationCommandSpecification::CopyAttributes(const AttributeGroup *atts)
{
    if(TypeName() != atts->TypeName())
        return false;

    // Call assignment operator.
    const avtSimulationCommandSpecification *tmp = (const avtSimulationCommandSpecification *)atts;
    *this = *tmp;

    return true;
}

// ****************************************************************************
// Method: avtSimulationCommandSpecification::CreateCompatible
//
// Purpose: 
//   CreateCompatible method for the avtSimulationCommandSpecification class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

AttributeSubject *
avtSimulationCommandSpecification::CreateCompatible(const std::string &tname) const
{
    AttributeSubject *retval = 0;
    if(TypeName() == tname)
        retval = new avtSimulationCommandSpecification(*this);
    // Other cases could go here too. 

    return retval;
}

// ****************************************************************************
// Method: avtSimulationCommandSpecification::NewInstance
//
// Purpose: 
//   NewInstance method for the avtSimulationCommandSpecification class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

AttributeSubject *
avtSimulationCommandSpecification::NewInstance(bool copy) const
{
    AttributeSubject *retval = 0;
    if(copy)
        retval = new avtSimulationCommandSpecification(*this);
    else
        retval = new avtSimulationCommandSpecification;

    return retval;
}

// ****************************************************************************
// Method: avtSimulationCommandSpecification::SelectAll
//
// Purpose: 
//   Selects all attributes.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void
avtSimulationCommandSpecification::SelectAll()
{
    Select(ID_name,         (void *)&name);
    Select(ID_argumentType, (void *)&argumentType);
    Select(ID_className,    (void *)&className);
    Select(ID_enabled,      (void *)&enabled);
    Select(ID_parent,       (void *)&parent);
    Select(ID_isOn,         (void *)&isOn);
    Select(ID_signal,       (void *)&signal);
    Select(ID_text,         (void *)&text);
    Select(ID_uiType,       (void *)&uiType);
    Select(ID_value,        (void *)&value);
}

///////////////////////////////////////////////////////////////////////////////
// Set property methods
///////////////////////////////////////////////////////////////////////////////

void
avtSimulationCommandSpecification::SetName(const std::string &name_)
{
    name = name_;
    Select(ID_name, (void *)&name);
}

void
avtSimulationCommandSpecification::SetArgumentType(avtSimulationCommandSpecification::CommandArgumentType argumentType_)
{
    argumentType = argumentType_;
    Select(ID_argumentType, (void *)&argumentType);
}

void
avtSimulationCommandSpecification::SetClassName(const std::string &className_)
{
    className = className_;
    Select(ID_className, (void *)&className);
}

void
avtSimulationCommandSpecification::SetEnabled(bool enabled_)
{
    enabled = enabled_;
    Select(ID_enabled, (void *)&enabled);
}

void
avtSimulationCommandSpecification::SetParent(const std::string &parent_)
{
    parent = parent_;
    Select(ID_parent, (void *)&parent);
}

void
avtSimulationCommandSpecification::SetIsOn(bool isOn_)
{
    isOn = isOn_;
    Select(ID_isOn, (void *)&isOn);
}

void
avtSimulationCommandSpecification::SetSignal(const std::string &signal_)
{
    signal = signal_;
    Select(ID_signal, (void *)&signal);
}

void
avtSimulationCommandSpecification::SetText(const std::string &text_)
{
    text = text_;
    Select(ID_text, (void *)&text);
}

void
avtSimulationCommandSpecification::SetUiType(const std::string &uiType_)
{
    uiType = uiType_;
    Select(ID_uiType, (void *)&uiType);
}

void
avtSimulationCommandSpecification::SetValue(const std::string &value_)
{
    value = value_;
    Select(ID_value, (void *)&value);
}

///////////////////////////////////////////////////////////////////////////////
// Get property methods
///////////////////////////////////////////////////////////////////////////////

const std::string &
avtSimulationCommandSpecification::GetName() const
{
    return name;
}

std::string &
avtSimulationCommandSpecification::GetName()
{
    return name;
}

avtSimulationCommandSpecification::CommandArgumentType
avtSimulationCommandSpecification::GetArgumentType() const
{
    return CommandArgumentType(argumentType);
}

const std::string &
avtSimulationCommandSpecification::GetClassName() const
{
    return className;
}

std::string &
avtSimulationCommandSpecification::GetClassName()
{
    return className;
}

bool
avtSimulationCommandSpecification::GetEnabled() const
{
    return enabled;
}

const std::string &
avtSimulationCommandSpecification::GetParent() const
{
    return parent;
}

std::string &
avtSimulationCommandSpecification::GetParent()
{
    return parent;
}

bool
avtSimulationCommandSpecification::GetIsOn() const
{
    return isOn;
}

const std::string &
avtSimulationCommandSpecification::GetSignal() const
{
    return signal;
}

std::string &
avtSimulationCommandSpecification::GetSignal()
{
    return signal;
}

const std::string &
avtSimulationCommandSpecification::GetText() const
{
    return text;
}

std::string &
avtSimulationCommandSpecification::GetText()
{
    return text;
}

const std::string &
avtSimulationCommandSpecification::GetUiType() const
{
    return uiType;
}

std::string &
avtSimulationCommandSpecification::GetUiType()
{
    return uiType;
}

const std::string &
avtSimulationCommandSpecification::GetValue() const
{
    return value;
}

std::string &
avtSimulationCommandSpecification::GetValue()
{
    return value;
}

///////////////////////////////////////////////////////////////////////////////
// Select property methods
///////////////////////////////////////////////////////////////////////////////

void
avtSimulationCommandSpecification::SelectName()
{
    Select(ID_name, (void *)&name);
}

void
avtSimulationCommandSpecification::SelectClassName()
{
    Select(ID_className, (void *)&className);
}

void
avtSimulationCommandSpecification::SelectParent()
{
    Select(ID_parent, (void *)&parent);
}

void
avtSimulationCommandSpecification::SelectSignal()
{
    Select(ID_signal, (void *)&signal);
}

void
avtSimulationCommandSpecification::SelectText()
{
    Select(ID_text, (void *)&text);
}

void
avtSimulationCommandSpecification::SelectUiType()
{
    Select(ID_uiType, (void *)&uiType);
}

void
avtSimulationCommandSpecification::SelectValue()
{
    Select(ID_value, (void *)&value);
}

///////////////////////////////////////////////////////////////////////////////
// User-defined methods.
///////////////////////////////////////////////////////////////////////////////

