/*=========================================================================

  Program: GDCM (Grassroots DICOM). A DICOM library
  Module:  $URL$

  Copyright (c) 2006-2009 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "gdcmExplicitDataElement.h"
#include "gdcmSequenceOfItems.h"
#include "gdcmSequenceOfFragments.h"

namespace gdcm
{

//-----------------------------------------------------------------------------

VL ExplicitDataElement::GetLength() const
{
  if( ValueLengthField.IsUndefined() )
    {
    assert( ValueField->GetLength().IsUndefined() );
    Value *p = ValueField;
    // If this is a SQ we need to compute it's proper length
    SequenceOfItems *sq = dynamic_cast<SequenceOfItems*>(p);
    // TODO can factor the code:
    if( sq )
      {
      return TagField.GetLength() + VRField.GetLength() + 
        ValueLengthField.GetLength() + sq->ComputeLength<ExplicitDataElement>();
      }
    SequenceOfFragments *sf = dynamic_cast<SequenceOfFragments*>(p);
    if( sf )
      {
      assert( VRField & VR::OB_OW ); // VR::INVALID is not possible AFAIK...
      return TagField.GetLength() + VRField.GetLength() 
        + ValueLengthField.GetLength() + sf->ComputeLength();
      }
    abort();
    }
  else
    {
    // Each time VR::GetLength() is 2 then Value Length is coded in 2
    //                              4 then Value Length is coded in 4
    assert( !ValueField || ValueField->GetLength() == ValueLengthField );
    return TagField.GetLength() + 2*VRField.GetLength() + ValueLengthField;
    }
}


} // end namespace gdcm
