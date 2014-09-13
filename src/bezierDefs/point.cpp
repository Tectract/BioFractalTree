/*
-----BEGIN PGP SIGNED MESSAGE-----
Hash: SHA1


 * File:   point.cpp
 *   a point object in 3D real-space, with a global index
 *
 *
 * Author: Ryan Molecke, Ph.D.
 *
 * Created on September 6, 2014, 6:50 AM
 * MPL_license.txt file (Mozilla Public License 2.0)
 * MUST accompany this or any derivative software
 *
 * Bio-Fractal Tree Generator builds branching tube structures
 * in recursive fractal fashion, with these properties:
 *  - it is non-self-overlapping.
 *  - multiple root/branch structures (bio-networks) can be
 *    generated in the same space and will not overlap with
 *    each other.
 *  - trees / bio-networks can be generated inside pre-defined
 *    (non-manifold geometric model) boundaries in a space-filling way
 *  - multi-threaded "compete" model for sub-branch generation
 *  - nearest-neighbor mapping for space-filling collision detection
 *
 *   V0 Revision0 - build testing
 *
*/

#include "point.hpp"

point::point(vector<double> &pointSet, int64_t ind) {
  coord = new std::vector<double>;
  *coord = pointSet;
  gIndex = ind; // set the globalID of the point at instantiation
}

int point::setCoord(vector<double> &pointSet) {
  // copy three doubles into
  *coord = pointSet;
}

void point::getCoord(vector<double> &pointSet) {
  // copy three doubles into
  pointSet = *coord;
}