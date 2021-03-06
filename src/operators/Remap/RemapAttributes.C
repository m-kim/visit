// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <RemapAttributes.h>
#include <DataNode.h>

//
// Enum conversion methods for RemapAttributes::VariableTypes
//

static const char *VariableTypes_strings[] = {
"intrinsic", "extrinsic"};

std::string
RemapAttributes::VariableTypes_ToString(RemapAttributes::VariableTypes t)
{
    int index = int(t);
    if(index < 0 || index >= 2) index = 0;
    return VariableTypes_strings[index];
}

std::string
RemapAttributes::VariableTypes_ToString(int t)
{
    int index = (t < 0 || t >= 2) ? 0 : t;
    return VariableTypes_strings[index];
}

bool
RemapAttributes::VariableTypes_FromString(const std::string &s, RemapAttributes::VariableTypes &val)
{
    val = RemapAttributes::intrinsic;
    for(int i = 0; i < 2; ++i)
    {
        if(s == VariableTypes_strings[i])
        {
            val = (VariableTypes)i;
            return true;
        }
    }
    return false;
}

// ****************************************************************************
// Method: RemapAttributes::RemapAttributes
//
// Purpose: 
//   Init utility for the RemapAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void RemapAttributes::Init()
{
    useExtents = true;
    startX = 0;
    endX = 1;
    cellsX = 10;
    startY = 0;
    endY = 1;
    cellsY = 10;
    is3D = true;
    startZ = 0;
    endZ = 1;
    cellsZ = 10;
    variableType = intrinsic;

    RemapAttributes::SelectAll();
}

// ****************************************************************************
// Method: RemapAttributes::RemapAttributes
//
// Purpose: 
//   Copy utility for the RemapAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void RemapAttributes::Copy(const RemapAttributes &obj)
{
    useExtents = obj.useExtents;
    startX = obj.startX;
    endX = obj.endX;
    cellsX = obj.cellsX;
    startY = obj.startY;
    endY = obj.endY;
    cellsY = obj.cellsY;
    is3D = obj.is3D;
    startZ = obj.startZ;
    endZ = obj.endZ;
    cellsZ = obj.cellsZ;
    variableType = obj.variableType;

    RemapAttributes::SelectAll();
}

// Type map format string
const char *RemapAttributes::TypeMapFormatString = REMAPATTRIBUTES_TMFS;
const AttributeGroup::private_tmfs_t RemapAttributes::TmfsStruct = {REMAPATTRIBUTES_TMFS};


// ****************************************************************************
// Method: RemapAttributes::RemapAttributes
//
// Purpose: 
//   Default constructor for the RemapAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

RemapAttributes::RemapAttributes() : 
    AttributeSubject(RemapAttributes::TypeMapFormatString)
{
    RemapAttributes::Init();
}

// ****************************************************************************
// Method: RemapAttributes::RemapAttributes
//
// Purpose: 
//   Constructor for the derived classes of RemapAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

RemapAttributes::RemapAttributes(private_tmfs_t tmfs) : 
    AttributeSubject(tmfs.tmfs)
{
    RemapAttributes::Init();
}

// ****************************************************************************
// Method: RemapAttributes::RemapAttributes
//
// Purpose: 
//   Copy constructor for the RemapAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

RemapAttributes::RemapAttributes(const RemapAttributes &obj) : 
    AttributeSubject(RemapAttributes::TypeMapFormatString)
{
    RemapAttributes::Copy(obj);
}

// ****************************************************************************
// Method: RemapAttributes::RemapAttributes
//
// Purpose: 
//   Copy constructor for derived classes of the RemapAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

RemapAttributes::RemapAttributes(const RemapAttributes &obj, private_tmfs_t tmfs) : 
    AttributeSubject(tmfs.tmfs)
{
    RemapAttributes::Copy(obj);
}

// ****************************************************************************
// Method: RemapAttributes::~RemapAttributes
//
// Purpose: 
//   Destructor for the RemapAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

RemapAttributes::~RemapAttributes()
{
    // nothing here
}

// ****************************************************************************
// Method: RemapAttributes::operator = 
//
// Purpose: 
//   Assignment operator for the RemapAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

RemapAttributes& 
RemapAttributes::operator = (const RemapAttributes &obj)
{
    if (this == &obj) return *this;

    RemapAttributes::Copy(obj);

    return *this;
}

// ****************************************************************************
// Method: RemapAttributes::operator == 
//
// Purpose: 
//   Comparison operator == for the RemapAttributes class.
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
RemapAttributes::operator == (const RemapAttributes &obj) const
{
    // Create the return value
    return ((useExtents == obj.useExtents) &&
            (startX == obj.startX) &&
            (endX == obj.endX) &&
            (cellsX == obj.cellsX) &&
            (startY == obj.startY) &&
            (endY == obj.endY) &&
            (cellsY == obj.cellsY) &&
            (is3D == obj.is3D) &&
            (startZ == obj.startZ) &&
            (endZ == obj.endZ) &&
            (cellsZ == obj.cellsZ) &&
            (variableType == obj.variableType));
}

// ****************************************************************************
// Method: RemapAttributes::operator != 
//
// Purpose: 
//   Comparison operator != for the RemapAttributes class.
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
RemapAttributes::operator != (const RemapAttributes &obj) const
{
    return !(this->operator == (obj));
}

// ****************************************************************************
// Method: RemapAttributes::TypeName
//
// Purpose: 
//   Type name method for the RemapAttributes class.
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
RemapAttributes::TypeName() const
{
    return "RemapAttributes";
}

// ****************************************************************************
// Method: RemapAttributes::CopyAttributes
//
// Purpose: 
//   CopyAttributes method for the RemapAttributes class.
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
RemapAttributes::CopyAttributes(const AttributeGroup *atts)
{
    if(TypeName() != atts->TypeName())
        return false;

    // Call assignment operator.
    const RemapAttributes *tmp = (const RemapAttributes *)atts;
    *this = *tmp;

    return true;
}

// ****************************************************************************
// Method: RemapAttributes::CreateCompatible
//
// Purpose: 
//   CreateCompatible method for the RemapAttributes class.
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
RemapAttributes::CreateCompatible(const std::string &tname) const
{
    AttributeSubject *retval = 0;
    if(TypeName() == tname)
        retval = new RemapAttributes(*this);
    // Other cases could go here too. 

    return retval;
}

// ****************************************************************************
// Method: RemapAttributes::NewInstance
//
// Purpose: 
//   NewInstance method for the RemapAttributes class.
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
RemapAttributes::NewInstance(bool copy) const
{
    AttributeSubject *retval = 0;
    if(copy)
        retval = new RemapAttributes(*this);
    else
        retval = new RemapAttributes;

    return retval;
}

// ****************************************************************************
// Method: RemapAttributes::SelectAll
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
RemapAttributes::SelectAll()
{
    Select(ID_useExtents,   (void *)&useExtents);
    Select(ID_startX,       (void *)&startX);
    Select(ID_endX,         (void *)&endX);
    Select(ID_cellsX,       (void *)&cellsX);
    Select(ID_startY,       (void *)&startY);
    Select(ID_endY,         (void *)&endY);
    Select(ID_cellsY,       (void *)&cellsY);
    Select(ID_is3D,         (void *)&is3D);
    Select(ID_startZ,       (void *)&startZ);
    Select(ID_endZ,         (void *)&endZ);
    Select(ID_cellsZ,       (void *)&cellsZ);
    Select(ID_variableType, (void *)&variableType);
}

///////////////////////////////////////////////////////////////////////////////
// Persistence methods
///////////////////////////////////////////////////////////////////////////////

// ****************************************************************************
// Method: RemapAttributes::CreateNode
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
RemapAttributes::CreateNode(DataNode *parentNode, bool completeSave, bool forceAdd)
{
    if(parentNode == 0)
        return false;

    RemapAttributes defaultObject;
    bool addToParent = false;
    // Create a node for RemapAttributes.
    DataNode *node = new DataNode("RemapAttributes");

    if(completeSave || !FieldsEqual(ID_useExtents, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("useExtents", useExtents));
    }

    if(completeSave || !FieldsEqual(ID_startX, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("startX", startX));
    }

    if(completeSave || !FieldsEqual(ID_endX, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("endX", endX));
    }

    if(completeSave || !FieldsEqual(ID_cellsX, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("cellsX", cellsX));
    }

    if(completeSave || !FieldsEqual(ID_startY, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("startY", startY));
    }

    if(completeSave || !FieldsEqual(ID_endY, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("endY", endY));
    }

    if(completeSave || !FieldsEqual(ID_cellsY, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("cellsY", cellsY));
    }

    if(completeSave || !FieldsEqual(ID_is3D, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("is3D", is3D));
    }

    if(completeSave || !FieldsEqual(ID_startZ, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("startZ", startZ));
    }

    if(completeSave || !FieldsEqual(ID_endZ, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("endZ", endZ));
    }

    if(completeSave || !FieldsEqual(ID_cellsZ, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("cellsZ", cellsZ));
    }

    if(completeSave || !FieldsEqual(ID_variableType, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("variableType", VariableTypes_ToString(variableType)));
    }


    // Add the node to the parent node.
    if(addToParent || forceAdd)
        parentNode->AddNode(node);
    else
        delete node;

    return (addToParent || forceAdd);
}

// ****************************************************************************
// Method: RemapAttributes::SetFromNode
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
RemapAttributes::SetFromNode(DataNode *parentNode)
{
    if(parentNode == 0)
        return;

    DataNode *searchNode = parentNode->GetNode("RemapAttributes");
    if(searchNode == 0)
        return;

    DataNode *node;
    if((node = searchNode->GetNode("useExtents")) != 0)
        SetUseExtents(node->AsBool());
    if((node = searchNode->GetNode("startX")) != 0)
        SetStartX(node->AsDouble());
    if((node = searchNode->GetNode("endX")) != 0)
        SetEndX(node->AsDouble());
    if((node = searchNode->GetNode("cellsX")) != 0)
        SetCellsX(node->AsInt());
    if((node = searchNode->GetNode("startY")) != 0)
        SetStartY(node->AsDouble());
    if((node = searchNode->GetNode("endY")) != 0)
        SetEndY(node->AsDouble());
    if((node = searchNode->GetNode("cellsY")) != 0)
        SetCellsY(node->AsInt());
    if((node = searchNode->GetNode("is3D")) != 0)
        SetIs3D(node->AsBool());
    if((node = searchNode->GetNode("startZ")) != 0)
        SetStartZ(node->AsDouble());
    if((node = searchNode->GetNode("endZ")) != 0)
        SetEndZ(node->AsDouble());
    if((node = searchNode->GetNode("cellsZ")) != 0)
        SetCellsZ(node->AsInt());
    if((node = searchNode->GetNode("variableType")) != 0)
    {
        // Allow enums to be int or string in the config file
        if(node->GetNodeType() == INT_NODE)
        {
            int ival = node->AsInt();
            if(ival >= 0 && ival < 2)
                SetVariableType(VariableTypes(ival));
        }
        else if(node->GetNodeType() == STRING_NODE)
        {
            VariableTypes value;
            if(VariableTypes_FromString(node->AsString(), value))
                SetVariableType(value);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
// Set property methods
///////////////////////////////////////////////////////////////////////////////

void
RemapAttributes::SetUseExtents(bool useExtents_)
{
    useExtents = useExtents_;
    Select(ID_useExtents, (void *)&useExtents);
}

void
RemapAttributes::SetStartX(double startX_)
{
    startX = startX_;
    Select(ID_startX, (void *)&startX);
}

void
RemapAttributes::SetEndX(double endX_)
{
    endX = endX_;
    Select(ID_endX, (void *)&endX);
}

void
RemapAttributes::SetCellsX(int cellsX_)
{
    cellsX = cellsX_;
    Select(ID_cellsX, (void *)&cellsX);
}

void
RemapAttributes::SetStartY(double startY_)
{
    startY = startY_;
    Select(ID_startY, (void *)&startY);
}

void
RemapAttributes::SetEndY(double endY_)
{
    endY = endY_;
    Select(ID_endY, (void *)&endY);
}

void
RemapAttributes::SetCellsY(int cellsY_)
{
    cellsY = cellsY_;
    Select(ID_cellsY, (void *)&cellsY);
}

void
RemapAttributes::SetIs3D(bool is3D_)
{
    is3D = is3D_;
    Select(ID_is3D, (void *)&is3D);
}

void
RemapAttributes::SetStartZ(double startZ_)
{
    startZ = startZ_;
    Select(ID_startZ, (void *)&startZ);
}

void
RemapAttributes::SetEndZ(double endZ_)
{
    endZ = endZ_;
    Select(ID_endZ, (void *)&endZ);
}

void
RemapAttributes::SetCellsZ(int cellsZ_)
{
    cellsZ = cellsZ_;
    Select(ID_cellsZ, (void *)&cellsZ);
}

void
RemapAttributes::SetVariableType(RemapAttributes::VariableTypes variableType_)
{
    variableType = variableType_;
    Select(ID_variableType, (void *)&variableType);
}

///////////////////////////////////////////////////////////////////////////////
// Get property methods
///////////////////////////////////////////////////////////////////////////////

bool
RemapAttributes::GetUseExtents() const
{
    return useExtents;
}

double
RemapAttributes::GetStartX() const
{
    return startX;
}

double
RemapAttributes::GetEndX() const
{
    return endX;
}

int
RemapAttributes::GetCellsX() const
{
    return cellsX;
}

double
RemapAttributes::GetStartY() const
{
    return startY;
}

double
RemapAttributes::GetEndY() const
{
    return endY;
}

int
RemapAttributes::GetCellsY() const
{
    return cellsY;
}

bool
RemapAttributes::GetIs3D() const
{
    return is3D;
}

double
RemapAttributes::GetStartZ() const
{
    return startZ;
}

double
RemapAttributes::GetEndZ() const
{
    return endZ;
}

int
RemapAttributes::GetCellsZ() const
{
    return cellsZ;
}

RemapAttributes::VariableTypes
RemapAttributes::GetVariableType() const
{
    return VariableTypes(variableType);
}

///////////////////////////////////////////////////////////////////////////////
// Keyframing methods
///////////////////////////////////////////////////////////////////////////////

// ****************************************************************************
// Method: RemapAttributes::GetFieldName
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
RemapAttributes::GetFieldName(int index) const
{
    switch (index)
    {
    case ID_useExtents:   return "useExtents";
    case ID_startX:       return "startX";
    case ID_endX:         return "endX";
    case ID_cellsX:       return "cellsX";
    case ID_startY:       return "startY";
    case ID_endY:         return "endY";
    case ID_cellsY:       return "cellsY";
    case ID_is3D:         return "is3D";
    case ID_startZ:       return "startZ";
    case ID_endZ:         return "endZ";
    case ID_cellsZ:       return "cellsZ";
    case ID_variableType: return "variableType";
    default:  return "invalid index";
    }
}

// ****************************************************************************
// Method: RemapAttributes::GetFieldType
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
RemapAttributes::GetFieldType(int index) const
{
    switch (index)
    {
    case ID_useExtents:   return FieldType_bool;
    case ID_startX:       return FieldType_double;
    case ID_endX:         return FieldType_double;
    case ID_cellsX:       return FieldType_int;
    case ID_startY:       return FieldType_double;
    case ID_endY:         return FieldType_double;
    case ID_cellsY:       return FieldType_int;
    case ID_is3D:         return FieldType_bool;
    case ID_startZ:       return FieldType_double;
    case ID_endZ:         return FieldType_double;
    case ID_cellsZ:       return FieldType_int;
    case ID_variableType: return FieldType_enum;
    default:  return FieldType_unknown;
    }
}

// ****************************************************************************
// Method: RemapAttributes::GetFieldTypeName
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
RemapAttributes::GetFieldTypeName(int index) const
{
    switch (index)
    {
    case ID_useExtents:   return "bool";
    case ID_startX:       return "double";
    case ID_endX:         return "double";
    case ID_cellsX:       return "int";
    case ID_startY:       return "double";
    case ID_endY:         return "double";
    case ID_cellsY:       return "int";
    case ID_is3D:         return "bool";
    case ID_startZ:       return "double";
    case ID_endZ:         return "double";
    case ID_cellsZ:       return "int";
    case ID_variableType: return "enum";
    default:  return "invalid index";
    }
}

// ****************************************************************************
// Method: RemapAttributes::FieldsEqual
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
RemapAttributes::FieldsEqual(int index_, const AttributeGroup *rhs) const
{
    const RemapAttributes &obj = *((const RemapAttributes*)rhs);
    bool retval = false;
    switch (index_)
    {
    case ID_useExtents:
        {  // new scope
        retval = (useExtents == obj.useExtents);
        }
        break;
    case ID_startX:
        {  // new scope
        retval = (startX == obj.startX);
        }
        break;
    case ID_endX:
        {  // new scope
        retval = (endX == obj.endX);
        }
        break;
    case ID_cellsX:
        {  // new scope
        retval = (cellsX == obj.cellsX);
        }
        break;
    case ID_startY:
        {  // new scope
        retval = (startY == obj.startY);
        }
        break;
    case ID_endY:
        {  // new scope
        retval = (endY == obj.endY);
        }
        break;
    case ID_cellsY:
        {  // new scope
        retval = (cellsY == obj.cellsY);
        }
        break;
    case ID_is3D:
        {  // new scope
        retval = (is3D == obj.is3D);
        }
        break;
    case ID_startZ:
        {  // new scope
        retval = (startZ == obj.startZ);
        }
        break;
    case ID_endZ:
        {  // new scope
        retval = (endZ == obj.endZ);
        }
        break;
    case ID_cellsZ:
        {  // new scope
        retval = (cellsZ == obj.cellsZ);
        }
        break;
    case ID_variableType:
        {  // new scope
        retval = (variableType == obj.variableType);
        }
        break;
    default: retval = false;
    }

    return retval;
}

///////////////////////////////////////////////////////////////////////////////
// User-defined methods.
///////////////////////////////////////////////////////////////////////////////

