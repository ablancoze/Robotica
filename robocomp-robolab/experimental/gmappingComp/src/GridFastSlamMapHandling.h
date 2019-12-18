/**
* @file GridFastSlamMapHandling.h
* This file declares static functions for loading and saving and maps generated by GMapping.
* @author <a href="mailto:Tim.Laue@dfki.de">Tim Laue</a>
*/

#ifndef __GridFastSlamMapHandling_h_
#define __GridFastSlamMapHandling_h_

//#include "../Include/LibGFSLocalizer.h"
#include <values.h>
#include <gridfastslam/gridslamprocessor.h>

/** 
* @class GridFastSlamMapHandling
* Simple class just to encapsulate the static functions
*/
class GridFastSlamMapHandling
{
public:
  /** Save a map to a file
  * @param map The map data structure
  * @param mapName The file name
  */
  static void saveMap(const GMapping::ScanMatcherMap& map, const std::string& mapName);

  /** Load a map from a file
  * @param mapName The file name
  * @return A pointer to a new map object. The memory is allocated by this function
  * and needs to be freed by the user.
  */
  static GMapping::ScanMatcherMap* loadMap(const std::string& mapName);
};


#endif// __GridFastSlamMapHandling_h_
