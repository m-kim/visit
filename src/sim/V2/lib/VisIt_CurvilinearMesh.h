/*****************************************************************************
*
* Copyright (c) 2000 - 2010, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-400124
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

#ifndef VISIT_CURVILINEAR_MESH_H
#define VISIT_CURVILINEAR_MESH_H

#ifdef __cplusplus
extern "C"
{
#endif

int VisIt_CurvilinearMesh_alloc(visit_handle *obj);
int VisIt_CurvilinearMesh_free(visit_handle obj);
int VisIt_CurvilinearMesh_setCoordsXY(visit_handle obj, int dims[2], visit_handle x, visit_handle y);
int VisIt_CurvilinearMesh_setCoordsXYZ(visit_handle obj, int dims[3], visit_handle x, visit_handle y, visit_handle z);
int VisIt_CurvilinearMesh_setCoords2(visit_handle obj, int dims[2], visit_handle c);
int VisIt_CurvilinearMesh_setCoords3(visit_handle obj, int dims[3], visit_handle c);
int VisIt_CurvilinearMesh_setRealIndices(visit_handle obj, int min[3], int max[3]);
int VisIt_CurvilinearMesh_setBaseIndex(visit_handle obj, int base_index[3]);

int VisIt_CurvilinearMesh_getCoords(visit_handle h, int *ndims, int dims[3],
                                    int *coordMode, 
                                    visit_handle *x,
                                    visit_handle *y,
                                    visit_handle *z,
                                    visit_handle *c);
int VisIt_CurvilinearMesh_getRealIndices(visit_handle h, int min[3], int max[3]);
int VisIt_CurvilinearMesh_getBaseIndex(visit_handle h, int base_index[3]);

#ifdef __cplusplus
}
#endif

#endif
