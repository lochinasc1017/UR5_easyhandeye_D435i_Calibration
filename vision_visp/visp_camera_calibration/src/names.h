/****************************************************************************
 *
 * $Id: file.h 3496 2011-11-22 15:14:32Z fnovotny $
 *
 * This file is part of the ViSP software.
 * Copyright (C) 2005 - 2012 by INRIA. All rights reserved.
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
 * Contact visp@irisa.fr if any conditions of this licensing are
 * not clear to you.
 *
 * Description:
 * File containing names of topics or services used all accross the package
 *
 * Authors:
 * Filip Novotny
 *
 *
 *****************************************************************************/

/*!
  \file names.h
  \brief File containing names of topics or services used all accross the package
*/

#ifndef __visp_hand2eye_calibration_NAMES_H__
# define __visp_hand2eye_calibration_NAMES_H__
# include <string>

// define topic and service names for the visp_hand2eye_calibration package.
namespace visp_camera_calibration
{
  extern std::string camera_prefix;
  extern std::string raw_image_topic;
  extern std::string point_correspondence_topic;
  extern std::string calibrate_service;
  extern std::string set_camera_info_service;
  extern std::string set_camera_info_bis_service;
  extern std::string gray_level_precision_param;
  extern std::string size_precision_param;
  extern std::string pause_at_each_frame_param;
  extern std::string images_path_param;
  extern std::string calibration_path_param;

  extern std::string model_points_x_param;
  extern std::string model_points_y_param;
  extern std::string model_points_z_param;

  extern std::string selected_points_x_param;
  extern std::string selected_points_y_param;
  extern std::string selected_points_z_param;

  void remap();

}

#endif

