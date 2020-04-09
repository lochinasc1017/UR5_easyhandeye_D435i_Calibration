/****************************************************************************
 *
 * $Id: vpQuaternionVector.h 3506 2011-11-29 19:29:31Z fspindle $
 *
 * This file is part of the ViSP software.
 * Copyright (C) 2005 - 2011 by INRIA. All rights reserved.
 * 
 * This software is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * ("GPL") version 2 as published by the Free Software Foundation.
 * See the file LICENSE.txt at the root directory of this source
 * distribution for additional information about the GNU GPL.
 *
 * For using ViSP with software that can not be combined with the GNU
 * GPL, please contact INRIA about acquiring a ViSP Professional 
 * Edition License.
 *
 * See http://www.irisa.fr/lagadic/visp/visp.html for more information.
 * 
 * This software was developed at:
 * INRIA Rennes - Bretagne Atlantique
 * Campus Universitaire de Beaulieu
 * 35042 Rennes Cedex
 * France
 * http://www.irisa.fr/lagadic
 *
 * If you have questions regarding the use of this file, please contact
 * INRIA at visp@inria.fr
 * 
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 * Description:
 * Quaternion definition.
 *
 * Authors:
 * Filip Novotny
 *
 *****************************************************************************/



#ifndef __QUATERNIONVECTOR_H__
#define __QUATERNIONVECTOR_H__

/*!
  \file vpQuaternionVector.h

  \brief Class that consider the case of a quaternion and basic
   operations on it.

*/

#include <visp/vpConfig.h>

#if VISP_VERSION_INT <= (2<<16 | 6<<8 | 1)

#include <visp/vpRotationMatrix.h>
#include <visp/vpColVector.h>


/*!
  \class vpQuaternionVector

  \ingroup RotTransformation
  
  \brief Defines a quaternion and its basic operations.

  This class allows to compute a quaternion from a rotation matrix
  using either vpQuaternionVector(const vpRotationMatrix &) contructor
  or buildFrom() method.

  It also defines common operations on a quaternion such as:
	- multiplication (scalar and quaternion)
	- addition
	- substraction.

  */
class VISP_EXPORT vpQuaternionVector : public vpColVector
{
private:        
  static const double minimum;
  double r[4];
public:

  vpQuaternionVector() ;    
  vpQuaternionVector(const double x, const double y, const double z,const double w) ;    
  vpQuaternionVector(const vpQuaternionVector &q);
  vpQuaternionVector(const vpRotationMatrix &R);

  void buildFrom(const vpRotationMatrix& R);

  void set(const double x, const double y, const double z,const double w) ;
  unsigned int size(){return 4;}
  //! returns x-component of the quaternion
  inline double x() const {return r[0];}
  //! returns y-component of the quaternion
  inline double y() const {return r[1];}
  //! returns z-component of the quaternion
  inline double z() const {return r[2];}
  //! returns w-component of the quaternion
  inline double w() const {return r[3];}

  vpQuaternionVector operator+( vpQuaternionVector &q)  ;
  vpQuaternionVector operator-( vpQuaternionVector &q)  ;
  vpQuaternionVector operator-()  ;
  vpQuaternionVector operator*(const double l) ;
  vpQuaternionVector operator* ( vpQuaternionVector &rq) ;
  vpQuaternionVector &operator=( vpQuaternionVector &q);
  
    
} ;

#endif
#endif

/*
 * Local variables:
 * c-basic-offset: 4
 * End:
 */
