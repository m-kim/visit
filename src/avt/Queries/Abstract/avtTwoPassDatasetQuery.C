// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                           avtTwoPassDatasetQuery.C                        //
// ************************************************************************* //

#include <avtTwoPassDatasetQuery.h>

#include <vtkDataSet.h>


// ****************************************************************************
//  Constructor:  avtTwoPassDatasetQuery::avtTwoPassDatasetQuery
//
//  Programmer:  Jeremy Meredith
//  Creation:    April 16, 2003
//
// ****************************************************************************
avtTwoPassDatasetQuery::avtTwoPassDatasetQuery()
    : avtDatasetQuery()
{
}


// ****************************************************************************
//  Method: avtTwoPassDatasetQuery destructor
//
//  Purpose:
//      Defines the destructor.  Note: this should not be inlined in the header
//      because it causes problems for certain compilers.
//
//  Programmer: Hank Childs
//  Creation:   February 5, 2004
//
// ****************************************************************************

avtTwoPassDatasetQuery::~avtTwoPassDatasetQuery()
{
    ;
}


// ****************************************************************************
//  Method:  avtTwoPassDatasetQuery::Execute
//
//  Purpose:
//    The main execute method -- overrides base class virtual function.
//
//  Arguments:
//    inDT       the datatree
//
//  Programmer:  Jeremy Meredith
//  Creation:    April 16, 2003
//
// ****************************************************************************
void
avtTwoPassDatasetQuery::Execute(avtDataTree_p inDT)
{
    // Two passes -- the length of this stage is double
    totalNodes *= 2;

    // Execute one pass, then the other
    ExecuteNthPass(inDT,1);

    MidExecute();

    ExecuteNthPass(inDT,2);
}


// ****************************************************************************
//  Method: avtTwoPassDatasetQuery::Execute
//
//  Purpose:
//    Recursive method to traverse an avtDataTree, calling Execute on the leaf
//    nodes. 
//
//  Notes:  Started as a direct copy of Execute() method of
//          avtDatasetQuery, added extensions for two passes
//
//  Programmer: Jeremy Meredith
//  Creation:   April 16, 2003
//
//  Modifications:
//    Kathleen Bonnell, Wed May 17 15:22:06 PDT 2006
//    Remove call to SetSource(NULL) as it now removes information necessary
//    for the dataset.
//
// ****************************************************************************
void
avtTwoPassDatasetQuery::ExecuteNthPass(avtDataTree_p inDT, int pass)
{
    if (*inDT == NULL)
    {
        return;
    }
 
    int nc = inDT->GetNChildren();
 
    if (nc <= 0 && !inDT->HasData())
    {
        return;
    }
 
    if ( nc == 0 )
    {
        //
        // There is only one dataset to process.
        //
        vtkDataSet *in_ds = inDT->GetDataRepresentation().GetDataVTK();
        int dom = inDT->GetDataRepresentation().GetDomain();
 
        //
        // Setting the source to NULL for the input will break the
        // pipeline.
        //
        //in_ds->SetSource(NULL);

        if (pass==1)
            Execute1(in_ds, dom);
        if (pass==2)
            Execute2(in_ds, dom);

        currentNode++;
        UpdateProgress(currentNode, totalNodes);
    }
    else
    {
        //
        // There is more than one input dataset to process.
        // Recurse through the children.
        //
        for (int j = 0; j < nc; j++)
        {
            if (inDT->ChildIsPresent(j))
            {
                ExecuteNthPass(inDT->GetChild(j), pass);
            }
        }
    }
}

