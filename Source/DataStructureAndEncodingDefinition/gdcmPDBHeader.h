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
#ifndef __gdcmPDBHeader_h
#define __gdcmPDBHeader_h

#include "gdcmTypes.h"
#include "gdcmDataSet.h"
#include "gdcmPDBElement.h"

namespace gdcm
{

/*
 * Everything done in this code is for the sole purpose of writing interoperable 
 * software under Sect. 1201 (f) Reverse Engineering exception of the DMCA.
 * If you believe anything in this code violates any law or any of your rights, 
 * please contact us (gdcm-developers@lists.sourceforge.net) so that we can 
 * find a solution. 
 */
//-----------------------------------------------------------------------------

class DataElement;
class PrivateTag;
/**
 * \brief Class for PDBHeader
 *
 * GEMS MR Image have an Attribute (0025,1b,GEMS_SERS_01) which store the Acquisition
 * parameter of the MR Image. It is compressed and can therefore not be used as is.
 * This class de-encapsulated the Protocol Data Block and allow users to query
 * element by name.
 *
 * \warning:
 * Everything you do with this code is at your own risk, since decoding process
 * was not written from specification documents.
 *
 * \WARNING: the API of this class might change.
 *
 */
class GDCM_EXPORT PDBHeader
{
public :
  PDBHeader() {}
  ~PDBHeader() {}

  /// Load the PDB Header from a DataElement of a DataSet
  bool LoadFromDataElement(DataElement const &de);

  /// Print
  void Print(std::ostream &os) const;

  /// Return the Private Tag where the PDB header is stored within a DICOM DataSet
  static const PrivateTag & GetPDBInfoTag();

  /// Lookup in the PDB header if a PDB element match the name 'name':
  /// \warning Case Sensitive
  const PDBElement &GetPDBElementByName(const char *name);

  /// Return true if the PDB element matching name is found or not
  bool FindPDBElementByName(const char *name);

protected:
  const PDBElement& GetPDBEEnd() const;

private:
  int readprotocoldatablock(const char *input, size_t inputlen, bool verbose);
  std::vector<PDBElement> InternalPDBDataSet;
  static PDBElement PDBEEnd;
};
} // end namespace gdcm
//-----------------------------------------------------------------------------
#endif //__gdcmPDBHeader_h
