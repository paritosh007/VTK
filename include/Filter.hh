/*=========================================================================

  Program:   Visualization Library
  Module:    Filter.hh
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

This file is part of the Visualization Library. No part of this file or its 
contents may be copied, reproduced or altered in any way without the express
written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
//
// Abstract class for specifying filter behaviour
//
#ifndef __vlFilter_h
#define __vlFilter_h

#include "Object.hh"
#include "DataSet.hh"

class vlFilter : virtual public vlObject 
{
public:
  vlFilter() : StartMethod(0), EndMethod(0), Updating(0) {};
  ~vlFilter() {};
  char *GetClassName() {return "vlFilter";};
  virtual void Update() = 0;
  void SetStartMethod(void (*f)());
  void SetEndMethod(void (*f)());

protected:
  virtual void Execute() = 0;
  char Updating;
  void (*StartMethod)();
  void (*EndMethod)();
  vlTimeStamp ExecuteTime;

};

#endif


