// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#ifndef AXISATTRIBUTES_H
#define AXISATTRIBUTES_H
#include <state_exports.h>
#include <AttributeSubject.h>

#include <AxisTitles.h>
#include <AxisLabels.h>
#include <AxisTickMarks.h>

// ****************************************************************************
// Class: AxisAttributes
//
// Purpose:
//    Contains the properties for one axis.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class STATE_API AxisAttributes : public AttributeSubject
{
public:
    // These constructors are for objects of this class
    AxisAttributes();
    AxisAttributes(const AxisAttributes &obj);
protected:
    // These constructors are for objects derived from this class
    AxisAttributes(private_tmfs_t tmfs);
    AxisAttributes(const AxisAttributes &obj, private_tmfs_t tmfs);
public:
    virtual ~AxisAttributes();

    virtual AxisAttributes& operator = (const AxisAttributes &obj);
    virtual bool operator == (const AxisAttributes &obj) const;
    virtual bool operator != (const AxisAttributes &obj) const;
private:
    void Init();
    void Copy(const AxisAttributes &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectTitle();
    void SelectLabel();
    void SelectTickMarks();

    // Property setting methods
    void SetTitle(const AxisTitles &title_);
    void SetLabel(const AxisLabels &label_);
    void SetTickMarks(const AxisTickMarks &tickMarks_);
    void SetGrid(bool grid_);

    // Property getting methods
    const AxisTitles    &GetTitle() const;
          AxisTitles    &GetTitle();
    const AxisLabels    &GetLabel() const;
          AxisLabels    &GetLabel();
    const AxisTickMarks &GetTickMarks() const;
          AxisTickMarks &GetTickMarks();
    bool                GetGrid() const;

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
        ID_title = 0,
        ID_label,
        ID_tickMarks,
        ID_grid,
        ID__LAST
    };

private:
    AxisTitles    title;
    AxisLabels    label;
    AxisTickMarks tickMarks;
    bool          grid;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define AXISATTRIBUTES_TMFS "aaab"

#endif
