// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#ifndef VIEW2DATTRIBUTES_H
#define VIEW2DATTRIBUTES_H
#include <state_exports.h>
#include <string>
#include <AttributeSubject.h>

#include <float.h>

// ****************************************************************************
// Class: View2DAttributes
//
// Purpose:
//    This class contains the 2d view attributes.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class STATE_API View2DAttributes : public AttributeSubject
{
public:
    enum TriStateMode
    {
        On,
        Off,
        Auto
    };
    static const double DEFAULT_FULL_FRAME_AUTO_THRESHOLD;

    // These constructors are for objects of this class
    View2DAttributes();
    View2DAttributes(const View2DAttributes &obj);
protected:
    // These constructors are for objects derived from this class
    View2DAttributes(private_tmfs_t tmfs);
    View2DAttributes(const View2DAttributes &obj, private_tmfs_t tmfs);
public:
    virtual ~View2DAttributes();

    virtual View2DAttributes& operator = (const View2DAttributes &obj);
    virtual bool operator == (const View2DAttributes &obj) const;
    virtual bool operator != (const View2DAttributes &obj) const;
private:
    void Init();
    void Copy(const View2DAttributes &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectWindowCoords();
    void SelectViewportCoords();

    // Property setting methods
    void SetWindowCoords(const double *windowCoords_);
    void SetViewportCoords(const double *viewportCoords_);
    void SetFullFrameActivationMode(TriStateMode fullFrameActivationMode_);
    void SetFullFrameAutoThreshold(double fullFrameAutoThreshold_);
    void SetXScale(int xScale_);
    void SetYScale(int yScale_);
    void SetWindowValid(bool windowValid_);

    // Property getting methods
    const double *GetWindowCoords() const;
          double *GetWindowCoords();
    const double *GetViewportCoords() const;
          double *GetViewportCoords();
    TriStateMode GetFullFrameActivationMode() const;
    double       GetFullFrameAutoThreshold() const;
    int          GetXScale() const;
    int          GetYScale() const;
    bool         GetWindowValid() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);

    // Enum conversion functions
    static std::string TriStateMode_ToString(TriStateMode);
    static bool TriStateMode_FromString(const std::string &, TriStateMode &);
protected:
    static std::string TriStateMode_ToString(int);
public:

    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

    // User-defined methods
    bool GetUseFullFrame(const double *limits=0) const;
    void SetUseFullFrame(bool ff);
    void ResetView(const double *bbox);

    // IDs that can be used to identify fields in case statements
    enum {
        ID_windowCoords = 0,
        ID_viewportCoords,
        ID_fullFrameActivationMode,
        ID_fullFrameAutoThreshold,
        ID_xScale,
        ID_yScale,
        ID_windowValid,
        ID__LAST
    };

private:
    double windowCoords[4];
    double viewportCoords[4];
    int    fullFrameActivationMode;
    double fullFrameAutoThreshold;
    int    xScale;
    int    yScale;
    bool   windowValid;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define VIEW2DATTRIBUTES_TMFS "DDidiib"

#endif
