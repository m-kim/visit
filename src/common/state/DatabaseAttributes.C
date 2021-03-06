// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <DatabaseAttributes.h>
#include <DataNode.h>

// ****************************************************************************
// Method: DatabaseAttributes::DatabaseAttributes
//
// Purpose: 
//   Init utility for the DatabaseAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void DatabaseAttributes::Init()
{
    state = 0;

    DatabaseAttributes::SelectAll();
}

// ****************************************************************************
// Method: DatabaseAttributes::DatabaseAttributes
//
// Purpose: 
//   Copy utility for the DatabaseAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void DatabaseAttributes::Copy(const DatabaseAttributes &obj)
{
    state = obj.state;

    DatabaseAttributes::SelectAll();
}

// Type map format string
const char *DatabaseAttributes::TypeMapFormatString = DATABASEATTRIBUTES_TMFS;
const AttributeGroup::private_tmfs_t DatabaseAttributes::TmfsStruct = {DATABASEATTRIBUTES_TMFS};


// ****************************************************************************
// Method: DatabaseAttributes::DatabaseAttributes
//
// Purpose: 
//   Default constructor for the DatabaseAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

DatabaseAttributes::DatabaseAttributes() : 
    AttributeSubject(DatabaseAttributes::TypeMapFormatString)
{
    DatabaseAttributes::Init();
}

// ****************************************************************************
// Method: DatabaseAttributes::DatabaseAttributes
//
// Purpose: 
//   Constructor for the derived classes of DatabaseAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

DatabaseAttributes::DatabaseAttributes(private_tmfs_t tmfs) : 
    AttributeSubject(tmfs.tmfs)
{
    DatabaseAttributes::Init();
}

// ****************************************************************************
// Method: DatabaseAttributes::DatabaseAttributes
//
// Purpose: 
//   Copy constructor for the DatabaseAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

DatabaseAttributes::DatabaseAttributes(const DatabaseAttributes &obj) : 
    AttributeSubject(DatabaseAttributes::TypeMapFormatString)
{
    DatabaseAttributes::Copy(obj);
}

// ****************************************************************************
// Method: DatabaseAttributes::DatabaseAttributes
//
// Purpose: 
//   Copy constructor for derived classes of the DatabaseAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

DatabaseAttributes::DatabaseAttributes(const DatabaseAttributes &obj, private_tmfs_t tmfs) : 
    AttributeSubject(tmfs.tmfs)
{
    DatabaseAttributes::Copy(obj);
}

// ****************************************************************************
// Method: DatabaseAttributes::~DatabaseAttributes
//
// Purpose: 
//   Destructor for the DatabaseAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

DatabaseAttributes::~DatabaseAttributes()
{
    // nothing here
}

// ****************************************************************************
// Method: DatabaseAttributes::operator = 
//
// Purpose: 
//   Assignment operator for the DatabaseAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

DatabaseAttributes& 
DatabaseAttributes::operator = (const DatabaseAttributes &obj)
{
    if (this == &obj) return *this;

    DatabaseAttributes::Copy(obj);

    return *this;
}

// ****************************************************************************
// Method: DatabaseAttributes::operator == 
//
// Purpose: 
//   Comparison operator == for the DatabaseAttributes class.
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
DatabaseAttributes::operator == (const DatabaseAttributes &obj) const
{
    // Create the return value
    return ((state == obj.state));
}

// ****************************************************************************
// Method: DatabaseAttributes::operator != 
//
// Purpose: 
//   Comparison operator != for the DatabaseAttributes class.
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
DatabaseAttributes::operator != (const DatabaseAttributes &obj) const
{
    return !(this->operator == (obj));
}

// ****************************************************************************
// Method: DatabaseAttributes::TypeName
//
// Purpose: 
//   Type name method for the DatabaseAttributes class.
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
DatabaseAttributes::TypeName() const
{
    return "DatabaseAttributes";
}

// ****************************************************************************
// Method: DatabaseAttributes::CopyAttributes
//
// Purpose: 
//   CopyAttributes method for the DatabaseAttributes class.
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
DatabaseAttributes::CopyAttributes(const AttributeGroup *atts)
{
    if(TypeName() != atts->TypeName())
        return false;

    // Call assignment operator.
    const DatabaseAttributes *tmp = (const DatabaseAttributes *)atts;
    *this = *tmp;

    return true;
}

// ****************************************************************************
// Method: DatabaseAttributes::CreateCompatible
//
// Purpose: 
//   CreateCompatible method for the DatabaseAttributes class.
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
DatabaseAttributes::CreateCompatible(const std::string &tname) const
{
    AttributeSubject *retval = 0;
    if(TypeName() == tname)
        retval = new DatabaseAttributes(*this);
    // Other cases could go here too. 

    return retval;
}

// ****************************************************************************
// Method: DatabaseAttributes::NewInstance
//
// Purpose: 
//   NewInstance method for the DatabaseAttributes class.
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
DatabaseAttributes::NewInstance(bool copy) const
{
    AttributeSubject *retval = 0;
    if(copy)
        retval = new DatabaseAttributes(*this);
    else
        retval = new DatabaseAttributes;

    return retval;
}

// ****************************************************************************
// Method: DatabaseAttributes::SelectAll
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
DatabaseAttributes::SelectAll()
{
    Select(ID_state, (void *)&state);
}

///////////////////////////////////////////////////////////////////////////////
// Persistence methods
///////////////////////////////////////////////////////////////////////////////

// ****************************************************************************
// Method: DatabaseAttributes::CreateNode
//
// Purpose: 
//   This method creates a DataNode representation of the object so it can be saved to a config file.
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
DatabaseAttributes::CreateNode(DataNode *parentNode, bool completeSave, bool forceAdd)
{
    if(parentNode == 0)
        return false;

    DatabaseAttributes defaultObject;
    bool addToParent = false;
    // Create a node for DatabaseAttributes.
    DataNode *node = new DataNode("DatabaseAttributes");

    if(completeSave || !FieldsEqual(ID_state, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("state", state));
    }


    // Add the node to the parent node.
    if(addToParent || forceAdd)
        parentNode->AddNode(node);
    else
        delete node;

    return (addToParent || forceAdd);
}

// ****************************************************************************
// Method: DatabaseAttributes::SetFromNode
//
// Purpose: 
//   This method sets attributes in this object from values in a DataNode representation of the object.
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
DatabaseAttributes::SetFromNode(DataNode *parentNode)
{
    if(parentNode == 0)
        return;

    DataNode *searchNode = parentNode->GetNode("DatabaseAttributes");
    if(searchNode == 0)
        return;

    DataNode *node;
    if((node = searchNode->GetNode("state")) != 0)
        SetState(node->AsInt());
}

///////////////////////////////////////////////////////////////////////////////
// Set property methods
///////////////////////////////////////////////////////////////////////////////

void
DatabaseAttributes::SetState(int state_)
{
    state = state_;
    Select(ID_state, (void *)&state);
}

///////////////////////////////////////////////////////////////////////////////
// Get property methods
///////////////////////////////////////////////////////////////////////////////

int
DatabaseAttributes::GetState() const
{
    return state;
}

///////////////////////////////////////////////////////////////////////////////
// Keyframing methods
///////////////////////////////////////////////////////////////////////////////

// ****************************************************************************
// Method: DatabaseAttributes::GetFieldName
//
// Purpose: 
//   This method returns the name of a field given its index.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

std::string
DatabaseAttributes::GetFieldName(int index) const
{
    switch (index)
    {
    case ID_state: return "state";
    default:  return "invalid index";
    }
}

// ****************************************************************************
// Method: DatabaseAttributes::GetFieldType
//
// Purpose: 
//   This method returns the type of a field given its index.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

AttributeGroup::FieldType
DatabaseAttributes::GetFieldType(int index) const
{
    switch (index)
    {
    case ID_state: return FieldType_int;
    default:  return FieldType_unknown;
    }
}

// ****************************************************************************
// Method: DatabaseAttributes::GetFieldTypeName
//
// Purpose: 
//   This method returns the name of a field type given its index.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

std::string
DatabaseAttributes::GetFieldTypeName(int index) const
{
    switch (index)
    {
    case ID_state: return "int";
    default:  return "invalid index";
    }
}

// ****************************************************************************
// Method: DatabaseAttributes::FieldsEqual
//
// Purpose: 
//   This method compares two fields and return true if they are equal.
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
DatabaseAttributes::FieldsEqual(int index_, const AttributeGroup *rhs) const
{
    const DatabaseAttributes &obj = *((const DatabaseAttributes*)rhs);
    bool retval = false;
    switch (index_)
    {
    case ID_state:
        {  // new scope
        retval = (state == obj.state);
        }
        break;
    default: retval = false;
    }

    return retval;
}

///////////////////////////////////////////////////////////////////////////////
// User-defined methods.
///////////////////////////////////////////////////////////////////////////////

