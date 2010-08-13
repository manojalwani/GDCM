/*=========================================================================

  Program: GDCM (Grassroots DICOM). A DICOM library
  Module:  $URL$

  Copyright (c) 2006-2010 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef GDCMAABORTPDU_H
#define GDCMAABORTPDU_H

#include "gdcmTypes.h"

namespace gdcm
{

// TODO: MM : does swig handle nested namespace
// I would like to avoid polluting gdcm namespace with such low level details the networ
// primitives:
namespace network
{

/**
 */
class AAbortPDU
{
public:
static const uint8_t ItemType = 0x7; // PDUType ?
static const uint8_t Reserved2 = 0x0;
uint32_t ItemLength; // PDU Length
static const uint8_t Reserved7 = 0x0;
static const uint8_t Reserved8 = 0x0;
uint8_t Source;
uint8_t Reason; // diag

private:
};

} // end namespace network

} // end namespace gdcm

#endif //GDCMAABORTPDU_H