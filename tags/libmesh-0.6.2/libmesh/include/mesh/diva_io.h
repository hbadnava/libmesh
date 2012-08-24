// $Id: diva_io.h,v 1.7 2007-10-21 20:48:42 benkirk Exp $

// The libMesh Finite Element Library.
// Copyright (C) 2002-2007  Benjamin S. Kirk, John W. Peterson
  
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


#ifndef __diva_io_h__
#define __diva_io_h__

// Local includes
#include "libmesh_common.h"
#include "mesh_output.h"

// Forward declarations
class UnstructuredMesh;



/**
 * This class implements writing meshes in the Diva format.
 * This is a scientific visualization program created by Kelly Gaither.
 * More information on Diva can be found here:
 * http://www.erc.msstate.edu/simcenter/docs/diva/
 *
 * @author John W. Peterson, 2004
 */

// ------------------------------------------------------------
// DivaIO class definition
class DivaIO : public MeshOutput<UnstructuredMesh>
{
public:
  /**
   * Note that only writing diva files is supported since Diva is
   * not a mesh generator.
   */
  //TODO:[JWP] figure out how to implement a const write method!
  DivaIO (const UnstructuredMesh&);

  /**
   * This method implements writing a mesh to a specified file.
   */
  virtual void write (const std::string& );

private:
  
  /**
   * The actual implementation of writing the diva file.  This
   * file is called by the public interface file after it
   * constructs an ofstream.
   */
  virtual void write_stream(std::ostream& out);
};




// ------------------------------------------------------------
// DivaIO inline members
inline
DivaIO::DivaIO (const UnstructuredMesh& mesh) :
  MeshOutput<UnstructuredMesh>  (mesh)
{}


#endif // #define __diva_io_h__