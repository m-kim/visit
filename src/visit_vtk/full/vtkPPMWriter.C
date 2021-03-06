// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include "vtkPPMWriter.h"
#include <vtkImageData.h>
#include <vtkPointData.h>
#include <vtkObjectFactory.h>


//------------------------------------------------------------------------------
// Modifications:
//   Kathleen Bonnell, Wed Mar  6 15:14:29 PST 2002 
//   Replace 'New' method with Macro to match VTK 4.0 API.
//------------------------------------------------------------------------------

vtkStandardNewMacro(vtkPPMWriter);


vtkPPMWriter::vtkPPMWriter()
{
  this->FileLowerLeft = 1;
}

void vtkPPMWriter::WriteFileHeader(ofstream *file, vtkImageData *cache, int wExt[6])
{
  int min0 = wExt[0], 
      max0 = wExt[1], 
      min1 = wExt[2], 
      max1 = wExt[3];
  int width, height;
  
  width = (max0 - min0 + 1);
  height = (max1 - min1 + 1);

  // Figure out the header and write it to the file.
  char header[100];
  sprintf(header, "P6\n%d %d\n255\n", width, height);
  for(char *cptr = header; *cptr != 0; ++cptr)
      file->put(*cptr);
}


void vtkPPMWriter::WriteFile(ofstream *file, vtkImageData *data,
                             int extent[6], int wExt[6])
{
  int idx1;
  int rowLength, i; // in bytes
  unsigned char *ptr;
  int bpp;
  unsigned long count = 0;
  unsigned long target;
  float progress = this->Progress;
  float area;
  
  bpp = data->GetNumberOfScalarComponents();
  
  // Make sure we actually have data.
  if ( !data->GetPointData()->GetScalars())
    {
    vtkErrorMacro(<< "Could not get data from input.");
    return;
    }

  // take into consideration the scalar type
  if (data->GetScalarType() != VTK_UNSIGNED_CHAR)
    {
    vtkErrorMacro("PPMWriter only accepts unsigned char scalars!");
    return; 
    }

  // Row length of x axis
  rowLength = extent[1] - extent[0] + 1;

  area = ((extent[5] - extent[4] + 1)*(extent[3] - extent[2] + 1)*
          (extent[1] - extent[0] + 1)) / 
    ((wExt[5] -wExt[4] + 1)*(wExt[3] -wExt[2] + 1)*
     (wExt[1] -wExt[0] + 1));
    
  target = (unsigned long)((extent[5]-extent[4]+1)*
                           (extent[3]-extent[2]+1)/(50.0*area));
  target++;

    for (idx1 = extent[3]; idx1 >= extent[2]; --idx1)
      {
      if (!(count%target))
        {
        this->UpdateProgress(progress + count/(50.0*target));
        }
      count++;
      ptr = (unsigned char *)data->GetScalarPointer(extent[0], idx1, 0);
      if (bpp == 1)
        {
        for (i = 0; i < rowLength; i++)
          {
          file->put(ptr[i]);
          file->put(ptr[i]);
          file->put(ptr[i]);
          }
        }
      else if (bpp == 2)
        {
        for (i = 0; i < rowLength; i++)
          {
          file->put(ptr[i*2]);
          file->put(ptr[i*2]);
          file->put(ptr[i*2]);
          }
        }
      else if (bpp == 3)
        {
        for (i = 0; i < rowLength; i++)
          {
          file->put(ptr[i*3]);
          file->put(ptr[i*3 + 1]);
          file->put(ptr[i*3 + 2]);
          }
        }
      else if (bpp == 4)
        {
        for (i = 0; i < rowLength; i++)
          {
          file->put(ptr[i*4]);
          file->put(ptr[i*4 + 1]);
          file->put(ptr[i*4 + 2]);
          }
        }
      }
}
