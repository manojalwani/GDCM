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
#ifndef GDCMAPPLICATIONCONTEXT_H
#define GDCMAPPLICATIONCONTEXT_H

#include "gdcmTypes.h"

namespace gdcm
{

namespace network
{

/**
 Table 9-12
APPLICATION CONTEXT ITEM FIELDS
 */
class ApplicationContext
{
public:
static const uint8_t ItemType = 0x10;
static const uint8_t Reserved2 = 0x00;
uint16_t ItemLength; // len of application context name
std::string /*ApplicationContext*/ Name; // UID
private:
};

} // end namespace network

} // end namespace gdcm

#endif //GDCMAPPLICATIONCONTEXT_H