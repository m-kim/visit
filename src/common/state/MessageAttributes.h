// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#ifndef MESSAGEATTRIBUTES_H
#define MESSAGEATTRIBUTES_H
#include <state_exports.h>
#include <string>
#include <AttributeSubject.h>


// ****************************************************************************
// Class: MessageAttributes
//
// Purpose:
//    This class contains attributes for sending messages.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class STATE_API MessageAttributes : public AttributeSubject
{
public:
    enum Severity
    {
        Error,
        Warning,
        Message,
        ErrorClear,
        Information
    };

    // These constructors are for objects of this class
    MessageAttributes();
    MessageAttributes(const MessageAttributes &obj);
protected:
    // These constructors are for objects derived from this class
    MessageAttributes(private_tmfs_t tmfs);
    MessageAttributes(const MessageAttributes &obj, private_tmfs_t tmfs);
public:
    virtual ~MessageAttributes();

    virtual MessageAttributes& operator = (const MessageAttributes &obj);
    virtual bool operator == (const MessageAttributes &obj) const;
    virtual bool operator != (const MessageAttributes &obj) const;
private:
    void Init();
    void Copy(const MessageAttributes &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectText();
    void SelectUnicode();

    // Property setting methods
    void SetText(const std::string &text_);
    void SetUnicode(const unsignedCharVector &unicode_);
    void SetHasUnicode(bool hasUnicode_);
    void SetSeverity(Severity severity_);

    // Property getting methods
    const std::string        &GetText() const;
          std::string        &GetText();
    const unsignedCharVector &GetUnicode() const;
          unsignedCharVector &GetUnicode();
    bool                     GetHasUnicode() const;
    Severity                 GetSeverity() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);

    // Enum conversion functions
    static std::string Severity_ToString(Severity);
    static bool Severity_FromString(const std::string &, Severity &);
protected:
    static std::string Severity_ToString(int);
public:

    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;


    // IDs that can be used to identify fields in case statements
    enum {
        ID_text = 0,
        ID_unicode,
        ID_hasUnicode,
        ID_severity,
        ID__LAST
    };

private:
    std::string        text;
    unsignedCharVector unicode;
    bool               hasUnicode;
    int                severity;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define MESSAGEATTRIBUTES_TMFS "su*bi"

#endif
