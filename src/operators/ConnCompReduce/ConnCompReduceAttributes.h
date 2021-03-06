// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#ifndef CONNCOMPREDUCEATTRIBUTES_H
#define CONNCOMPREDUCEATTRIBUTES_H
#include <AttributeSubject.h>


// ****************************************************************************
// Class: ConnCompReduceAttributes
//
// Purpose:
//    This class contains attributes for the reduce connected components operator.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class ConnCompReduceAttributes : public AttributeSubject
{
public:
    // These constructors are for objects of this class
    ConnCompReduceAttributes();
    ConnCompReduceAttributes(const ConnCompReduceAttributes &obj);
protected:
    // These constructors are for objects derived from this class
    ConnCompReduceAttributes(private_tmfs_t tmfs);
    ConnCompReduceAttributes(const ConnCompReduceAttributes &obj, private_tmfs_t tmfs);
public:
    virtual ~ConnCompReduceAttributes();

    virtual ConnCompReduceAttributes& operator = (const ConnCompReduceAttributes &obj);
    virtual bool operator == (const ConnCompReduceAttributes &obj) const;
    virtual bool operator != (const ConnCompReduceAttributes &obj) const;
private:
    void Init();
    void Copy(const ConnCompReduceAttributes &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();

    // Property setting methods
    void SetTarget(double target_);

    // Property getting methods
    double GetTarget() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;


    // IDs that can be used to identify fields in case statements
    enum {
        ID_target = 0,
        ID__LAST
    };

private:
    double target;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define CONNCOMPREDUCEATTRIBUTES_TMFS "d"

#endif
