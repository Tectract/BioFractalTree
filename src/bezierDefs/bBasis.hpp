/*
 * File:   bBasis.hpp
 *    builds Berstein basis functions for a given
 *    resolution, of the 4th-order (quadratic)
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

#include <vector>
using namespace std;

class bBasis {
private:
  double uSquare;
  double tmpSquare;
  vector<vector<double> > *basis;

public:
  bBasis(int resolution);
  void getBasis(vector<vector<double> > &returnPoints); // get basis points
  ~bBasis() {};
};