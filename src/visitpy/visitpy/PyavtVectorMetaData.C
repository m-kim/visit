// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <PyavtVectorMetaData.h>
#include <ObserverToCallback.h>
#include <stdio.h>

// ****************************************************************************
// Module: PyavtVectorMetaData
//
// Purpose: 
//   Contains vector metadata attributes
//
// Note:       Autogenerated by xml2python. Do not modify by hand!
//
// Programmer: xml2python
// Creation:   omitted
//
// ****************************************************************************

//
// This struct contains the Python type information and a avtVectorMetaData.
//
struct avtVectorMetaDataObject
{
    PyObject_HEAD
    avtVectorMetaData *data;
    bool        owns;
    PyObject   *parent;
};

//
// Internal prototypes
//
static PyObject *NewavtVectorMetaData(int);

std::string
PyavtVectorMetaData_ToString(const avtVectorMetaData *atts, const char *prefix)
{
    std::string str;
    char tmpStr[1000];

    str = PyavtVarMetaData_ToString(atts, prefix);

    snprintf(tmpStr, 1000, "%svarDim = %d\n", prefix, atts->varDim);
    str += tmpStr;
    return str;
}

static PyObject *
avtVectorMetaData_Notify(PyObject *self, PyObject *args)
{
    avtVectorMetaDataObject *obj = (avtVectorMetaDataObject *)self;
    obj->data->Notify();
    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
avtVectorMetaData_SetVarDim(PyObject *self, PyObject *args)
{
    avtVectorMetaDataObject *obj = (avtVectorMetaDataObject *)self;

    int ival;
    if(!PyArg_ParseTuple(args, "i", &ival))
        return NULL;

    // Set the varDim in the object.
    obj->data->varDim = (int)ival;

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
avtVectorMetaData_GetVarDim(PyObject *self, PyObject *args)
{
    avtVectorMetaDataObject *obj = (avtVectorMetaDataObject *)self;
    PyObject *retval = PyInt_FromLong(long(obj->data->varDim));
    return retval;
}



PyMethodDef PyavtVectorMetaData_methods[AVTVECTORMETADATA_NMETH] = {
    {"Notify", avtVectorMetaData_Notify, METH_VARARGS},
    {"SetVarDim", avtVectorMetaData_SetVarDim, METH_VARARGS},
    {"GetVarDim", avtVectorMetaData_GetVarDim, METH_VARARGS},
    {NULL, NULL}
};

static void PyavtVectorMetaData_ExtendSetGetMethodTable()
{
    static bool extended = false;
    if (extended) return;
    extended = true;

    int i = 0;
    while (PyavtVectorMetaData_methods[i].ml_name)
        i++;
    int n = i;
    while (PyavtVarMetaData_methods[i-n+1].ml_name)
    {
        PyavtVectorMetaData_methods[i] = PyavtVarMetaData_methods[i-n+1];
        i++;
    }

    PyMethodDef nullMethod = {NULL, NULL};
    PyavtVectorMetaData_methods[i] = nullMethod;
}

//
// Type functions
//

static void
avtVectorMetaData_dealloc(PyObject *v)
{
   avtVectorMetaDataObject *obj = (avtVectorMetaDataObject *)v;
   if(obj->parent != 0)
       Py_DECREF(obj->parent);
   if(obj->owns)
       delete obj->data;
}

static int
avtVectorMetaData_compare(PyObject *v, PyObject *w)
{
    avtVectorMetaData *a = ((avtVectorMetaDataObject *)v)->data;
    avtVectorMetaData *b = ((avtVectorMetaDataObject *)w)->data;
    return (*a == *b) ? 0 : -1;
}

PyObject *
PyavtVectorMetaData_getattr(PyObject *self, char *name)
{
    if(strcmp(name, "varDim") == 0)
        return avtVectorMetaData_GetVarDim(self, NULL);

    if(strcmp(name, "__methods__") != 0)
    {
        PyObject *retval = PyavtVarMetaData_getattr(self, name);
        if (retval) return retval;
    }

    PyavtVectorMetaData_ExtendSetGetMethodTable();

    return Py_FindMethod(PyavtVectorMetaData_methods, self, name);
}

int
PyavtVectorMetaData_setattr(PyObject *self, char *name, PyObject *args)
{
    if (PyavtVarMetaData_setattr(self, name, args) != -1)
        return 0;
    else
        PyErr_Clear();

    // Create a tuple to contain the arguments since all of the Set
    // functions expect a tuple.
    PyObject *tuple = PyTuple_New(1);
    PyTuple_SET_ITEM(tuple, 0, args);
    Py_INCREF(args);
    PyObject *obj = NULL;

    if(strcmp(name, "varDim") == 0)
        obj = avtVectorMetaData_SetVarDim(self, tuple);

    if(obj != NULL)
        Py_DECREF(obj);

    Py_DECREF(tuple);
    if( obj == NULL)
        PyErr_Format(PyExc_RuntimeError, "Unable to set unknown attribute: '%s'", name);
    return (obj != NULL) ? 0 : -1;
}

static int
avtVectorMetaData_print(PyObject *v, FILE *fp, int flags)
{
    avtVectorMetaDataObject *obj = (avtVectorMetaDataObject *)v;
    fprintf(fp, "%s", PyavtVectorMetaData_ToString(obj->data, "").c_str());
    return 0;
}

PyObject *
avtVectorMetaData_str(PyObject *v)
{
    avtVectorMetaDataObject *obj = (avtVectorMetaDataObject *)v;
    return PyString_FromString(PyavtVectorMetaData_ToString(obj->data,"").c_str());
}

//
// The doc string for the class.
//
#if PY_MAJOR_VERSION > 2 || (PY_MAJOR_VERSION == 2 && PY_MINOR_VERSION >= 5)
static const char *avtVectorMetaData_Purpose = "Contains vector metadata attributes";
#else
static char *avtVectorMetaData_Purpose = "Contains vector metadata attributes";
#endif

//
// The type description structure
//
static PyTypeObject avtVectorMetaDataType =
{
    //
    // Type header
    //
    PyObject_HEAD_INIT(&PyType_Type)
    0,                                   // ob_size
    "avtVectorMetaData",                    // tp_name
    sizeof(avtVectorMetaDataObject),        // tp_basicsize
    0,                                   // tp_itemsize
    //
    // Standard methods
    //
    (destructor)avtVectorMetaData_dealloc,  // tp_dealloc
    (printfunc)avtVectorMetaData_print,     // tp_print
    (getattrfunc)PyavtVectorMetaData_getattr, // tp_getattr
    (setattrfunc)PyavtVectorMetaData_setattr, // tp_setattr
    (cmpfunc)avtVectorMetaData_compare,     // tp_compare
    (reprfunc)0,                         // tp_repr
    //
    // Type categories
    //
    0,                                   // tp_as_number
    0,                                   // tp_as_sequence
    0,                                   // tp_as_mapping
    //
    // More methods
    //
    0,                                   // tp_hash
    0,                                   // tp_call
    (reprfunc)avtVectorMetaData_str,        // tp_str
    0,                                   // tp_getattro
    0,                                   // tp_setattro
    0,                                   // tp_as_buffer
    Py_TPFLAGS_CHECKTYPES,               // tp_flags
    avtVectorMetaData_Purpose,              // tp_doc
    0,                                   // tp_traverse
    0,                                   // tp_clear
    0,                                   // tp_richcompare
    0                                    // tp_weaklistoffset
};

//
// Helper functions for object allocation.
//

static avtVectorMetaData *defaultAtts = 0;
static avtVectorMetaData *currentAtts = 0;

static PyObject *
NewavtVectorMetaData(int useCurrent)
{
    avtVectorMetaDataObject *newObject;
    newObject = PyObject_NEW(avtVectorMetaDataObject, &avtVectorMetaDataType);
    if(newObject == NULL)
        return NULL;
    if(useCurrent && currentAtts != 0)
        newObject->data = new avtVectorMetaData(*currentAtts);
    else if(defaultAtts != 0)
        newObject->data = new avtVectorMetaData(*defaultAtts);
    else
        newObject->data = new avtVectorMetaData;
    newObject->owns = true;
    newObject->parent = 0;
    return (PyObject *)newObject;
}

static PyObject *
WrapavtVectorMetaData(const avtVectorMetaData *attr)
{
    avtVectorMetaDataObject *newObject;
    newObject = PyObject_NEW(avtVectorMetaDataObject, &avtVectorMetaDataType);
    if(newObject == NULL)
        return NULL;
    newObject->data = (avtVectorMetaData *)attr;
    newObject->owns = false;
    newObject->parent = 0;
    return (PyObject *)newObject;
}

///////////////////////////////////////////////////////////////////////////////
//
// Interface that is exposed to the VisIt module.
//
///////////////////////////////////////////////////////////////////////////////

PyObject *
avtVectorMetaData_new(PyObject *self, PyObject *args)
{
    int useCurrent = 0;
    if (!PyArg_ParseTuple(args, "i", &useCurrent))
    {
        if (!PyArg_ParseTuple(args, ""))
            return NULL;
        else
            PyErr_Clear();
    }

    return (PyObject *)NewavtVectorMetaData(useCurrent);
}

//
// Plugin method table. These methods are added to the visitmodule's methods.
//
static PyMethodDef avtVectorMetaDataMethods[] = {
    {"avtVectorMetaData", avtVectorMetaData_new, METH_VARARGS},
    {NULL,      NULL}        /* Sentinel */
};

static Observer *avtVectorMetaDataObserver = 0;

std::string
PyavtVectorMetaData_GetLogString()
{
    std::string s("avtVectorMetaData = avtVectorMetaData()\n");
    if(currentAtts != 0)
        s += PyavtVectorMetaData_ToString(currentAtts, "avtVectorMetaData.");
    return s;
}

static void
PyavtVectorMetaData_CallLogRoutine(Subject *subj, void *data)
{
    typedef void (*logCallback)(const std::string &);
    logCallback cb = (logCallback)data;

    if(cb != 0)
    {
        std::string s("avtVectorMetaData = avtVectorMetaData()\n");
        s += PyavtVectorMetaData_ToString(currentAtts, "avtVectorMetaData.");
        cb(s);
    }
}

void
PyavtVectorMetaData_StartUp(avtVectorMetaData *subj, void *data)
{
    if(subj == 0)
        return;

    currentAtts = subj;
    PyavtVectorMetaData_SetDefaults(subj);

    //
    // Create the observer that will be notified when the attributes change.
    //
    if(avtVectorMetaDataObserver == 0)
    {
        avtVectorMetaDataObserver = new ObserverToCallback(subj,
            PyavtVectorMetaData_CallLogRoutine, (void *)data);
    }

}

void
PyavtVectorMetaData_CloseDown()
{
    delete defaultAtts;
    defaultAtts = 0;
    delete avtVectorMetaDataObserver;
    avtVectorMetaDataObserver = 0;
}

PyMethodDef *
PyavtVectorMetaData_GetMethodTable(int *nMethods)
{
    *nMethods = 1;
    return avtVectorMetaDataMethods;
}

bool
PyavtVectorMetaData_Check(PyObject *obj)
{
    return (obj->ob_type == &avtVectorMetaDataType);
}

avtVectorMetaData *
PyavtVectorMetaData_FromPyObject(PyObject *obj)
{
    avtVectorMetaDataObject *obj2 = (avtVectorMetaDataObject *)obj;
    return obj2->data;
}

PyObject *
PyavtVectorMetaData_New()
{
    return NewavtVectorMetaData(0);
}

PyObject *
PyavtVectorMetaData_Wrap(const avtVectorMetaData *attr)
{
    return WrapavtVectorMetaData(attr);
}

void
PyavtVectorMetaData_SetParent(PyObject *obj, PyObject *parent)
{
    avtVectorMetaDataObject *obj2 = (avtVectorMetaDataObject *)obj;
    obj2->parent = parent;
}

void
PyavtVectorMetaData_SetDefaults(const avtVectorMetaData *atts)
{
    if(defaultAtts)
        delete defaultAtts;

    defaultAtts = new avtVectorMetaData(*atts);
}

