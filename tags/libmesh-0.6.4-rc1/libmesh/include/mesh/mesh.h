// $Id$

// The libMesh Finite Element Library.
// Copyright (C) 2002-2008 Benjamin S. Kirk, John W. Peterson, Roy H. Stogner
  
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
  
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
  
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA


#ifndef __mesh_h__
#define __mesh_h__

#include "libmesh_config.h"

#ifdef LIBMESH_ENABLE_PARMESH
#include "parallel_mesh.h"
  typedef ParallelMesh DefaultMesh;
#else
#include "serial_mesh.h"
  typedef SerialMesh DefaultMesh;
#endif

// Forward declarations don't like typedefs...
// typedef SerialMesh Mesh;


/**
 * The \p Mesh class is a thin wrapper, around the \p SerialMesh class
 * by default.
*/

// ------------------------------------------------------------
// Mesh class definition
class Mesh : public DefaultMesh
{
 public:

  /**
   * Constructor.  Requires the dimension and optionally
   * a processor id.  Note that \p proc_id should always
   * be provided for multiprocessor applications.
   */
  Mesh (unsigned int d) : DefaultMesh(d) {}

  /**
   * Copy-constructor.  This should be able to take a
   * serial or parallel mesh.
   */
  Mesh (const UnstructuredMesh& other_mesh) : DefaultMesh(other_mesh) {}

  /**
   * Destructor.
   */
  ~Mesh() {}
};





#endif
