/*=========================================================================

  Program:   Visualization Library
  Module:    Scalars.cc
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

This file is part of the Visualization Library. No part of this file or its 
contents may be copied, reproduced or altered in any way without the express
written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
//
//  Scalars, abstract representation
//
#include "Scalars.hh"
#include "FScalars.hh"
#include "IdList.hh"

vlScalars::vlScalars()
{
  this->Range[0] = 0.0;
  this->Range[1] = 1.0;
}

void vlScalars::GetScalars(vlIdList& ptId, vlFloatScalars& fp)
{
  for (int i=0; i<ptId.NumIds(); i++)
    {
    fp.InsertScalar(i,this->GetScalar(ptId[i]));
    }
}
void vlScalars::ComputeRange()
{
  int i;
  float s;

  if ( this->GetMtime() > this->ComputeTime )
    {
    this->Range[0] =  LARGE_FLOAT;
    this->Range[1] =  -LARGE_FLOAT;
    for (i=0; i<this->NumScalars(); i++)
      {
      s = this->GetScalar(i);
      if ( s < this->Range[0] ) this->Range[0] = s;
      if ( s > this->Range[1] ) this->Range[1] = s;
      }

    this->ComputeTime.Modified();
    }
}

float *vlScalars::GetRange()
{
  this->ComputeRange();
  return this->Range;
}

void vlScalars::PrintSelf(ostream& os, vlIndent indent)
{
  float *range;

  vlObject::PrintSelf(os,indent);

  os << indent << "Number Scalars: " << this->NumScalars() << "\n";
  range = this->GetRange();
  os << indent << "Range: (" << range[0] << ", " << range[1] << ")\n";
}
