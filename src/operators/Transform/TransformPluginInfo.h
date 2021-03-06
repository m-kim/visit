// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//  File: TransformPluginInfo.h
// ************************************************************************* //

#ifndef TRANSFORM_PLUGIN_INFO_H
#define TRANSFORM_PLUGIN_INFO_H
#include <OperatorPluginInfo.h>
#include <operator_plugin_exports.h>

class TransformAttributes;

// ****************************************************************************
//  Class: TransformPluginInfo
//
//  Purpose:
//    Five classes that provide all the information about an Transform operator
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
//  Modifications:
//
// ****************************************************************************

class TransformGeneralPluginInfo : public virtual GeneralOperatorPluginInfo
{
  public:
    virtual const char *GetName() const;
    virtual const char *GetVersion() const;
    virtual const char *GetID() const;
    virtual bool  EnabledByDefault() const;
    virtual const char *GetCategoryName() const;
};

class TransformCommonPluginInfo : public virtual CommonOperatorPluginInfo, public virtual TransformGeneralPluginInfo
{
  public:
    virtual AttributeSubject *AllocAttributes();
    virtual void CopyAttributes(AttributeSubject *to, AttributeSubject *from);
};

class TransformGUIPluginInfo : public virtual GUIOperatorPluginInfo, public virtual TransformCommonPluginInfo
{
  public:
    virtual QString *GetMenuName() const;
    virtual QvisPostableWindowObserver *CreatePluginWindow(int type,
        AttributeSubject *attr, const QString &caption, const QString &shortName,
        QvisNotepadArea *notepad);
    virtual const char **XPMIconData() const;
};

class TransformViewerEnginePluginInfo : public virtual ViewerEngineOperatorPluginInfo, public virtual TransformCommonPluginInfo
{
  public:
    virtual AttributeSubject *GetClientAtts();
    virtual AttributeSubject *GetDefaultAtts();
    virtual void SetClientAtts(AttributeSubject *atts);
    virtual void GetClientAtts(AttributeSubject *atts);

    virtual void InitializeOperatorAtts(AttributeSubject *atts,
                                        const avtPlotMetaData &plot,
                                        const bool fromDefault);
    virtual void UpdateOperatorAtts(AttributeSubject *atts,
                                    const avtPlotMetaData &plot);
    virtual const char *GetMenuName() const;

    static void InitializeGlobalObjects();
  private:
    static TransformAttributes *defaultAtts;
    static TransformAttributes *clientAtts;
};

class TransformViewerPluginInfo : public virtual ViewerOperatorPluginInfo, public virtual TransformViewerEnginePluginInfo
{
  public:
    virtual const char **XPMIconData() const;
};

class TransformEnginePluginInfo : public virtual EngineOperatorPluginInfo, public virtual TransformViewerEnginePluginInfo
{
  public:
    virtual avtPluginFilter *AllocAvtPluginFilter();
};

class TransformScriptingPluginInfo : public virtual ScriptingOperatorPluginInfo, public virtual TransformCommonPluginInfo
{
  public:
    virtual void InitializePlugin(AttributeSubject *subj, void *data);
    virtual void *GetMethodTable(int *nMethods);
    virtual bool TypesMatch(void *pyobject);
    virtual char *GetLogString();
    virtual void SetDefaults(const AttributeSubject *atts);
};

#endif
