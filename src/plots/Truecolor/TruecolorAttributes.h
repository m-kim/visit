// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#ifndef TRUECOLORATTRIBUTES_H
#define TRUECOLORATTRIBUTES_H
#include <AttributeSubject.h>


// ****************************************************************************
// Class: TruecolorAttributes
//
// Purpose:
//    Truecolor plot
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class TruecolorAttributes : public AttributeSubject
{
public:
    // These constructors are for objects of this class
    TruecolorAttributes();
    TruecolorAttributes(const TruecolorAttributes &obj);
protected:
    // These constructors are for objects derived from this class
    TruecolorAttributes(private_tmfs_t tmfs);
    TruecolorAttributes(const TruecolorAttributes &obj, private_tmfs_t tmfs);
public:
    virtual ~TruecolorAttributes();

    virtual TruecolorAttributes& operator = (const TruecolorAttributes &obj);
    virtual bool operator == (const TruecolorAttributes &obj) const;
    virtual bool operator != (const TruecolorAttributes &obj) const;
private:
    void Init();
    void Copy(const TruecolorAttributes &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();

    // Property setting methods
    void SetOpacity(double opacity_);
    void SetLightingFlag(bool lightingFlag_);

    // Property getting methods
    double GetOpacity() const;
    bool   GetLightingFlag() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

    // User-defined methods
    bool ChangesRequireRecalculation(const TruecolorAttributes &obj);

    // IDs that can be used to identify fields in case statements
    enum {
        ID_opacity = 0,
        ID_lightingFlag,
        ID__LAST
    };

private:
    double opacity;
    bool   lightingFlag;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define TRUECOLORATTRIBUTES_TMFS "db"

#endif
