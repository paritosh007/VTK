/*=========================================================================

  Program:   Visualization Library
  Module:    CubeSrc.hh
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

This file is part of the Visualization Library. No part of this file or its 
contents may be copied, reproduced or altered in any way without the express
written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
//
// Created cube centered at origin
//
#ifndef __vlCubeSource_h
#define __vlCubeSource_h

#include "PolySrc.hh"

class vlCubeSource : public vlPolySource 
{
public:
  vlCubeSource(float xL=1.0, float yL=1.0, float zL=1.0);
  char *GetClassName() {return "vlCubeSource";};

  vlSetClampMacro(XLength,float,0.0,LARGE_FLOAT);
  vlGetMacro(XLength,float);

  vlSetClampMacro(YLength,float,0.0,LARGE_FLOAT);
  vlGetMacro(YLength,float);

  vlSetClampMacro(ZLength,float,0.0,LARGE_FLOAT);
  vlGetMacro(ZLength,float);

protected:
  void Execute();
  float XLength;
  float YLength;
  float ZLength;
};

#endif


