/*
 * File:   bBasis.cpp
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

#include "bBasis.hpp"
using namespace std;
#include <iostream>

bBasis::bBasis(int resolution) {
  double uinc = 1.0 / resolution;
  double u = uinc; // step counter
  // note this is for the bicubic basis set (order 4)
  basis = new vector<vector<double> >;
  basis->resize(4);
  // calculates and stores the Bernstein basis set
  // for a given resolution

  // set up the first row without calculation
  basis->at(0).push_back(1); // (1-u)^3   @ u = 0
  basis->at(1).push_back(0); // 3u(1-u)^2 @ u = 0
  basis->at(2).push_back(0); // 3u^2(1-u) @ u = 0
  basis->at(3).push_back(0); // u^3   @ u = 0

  for (int i = 1; i < resolution; i++) {
    double usqr = u * u;                    // u^2
    double tmp = 1 - u;                     // 1-u
    double tmpsqr = tmp * tmp;              // (1-u)^2
    basis->at(0).push_back(tmp * tmpsqr);   // (1-u)^3
    basis->at(1).push_back(3 * u * tmpsqr); // 3u(1-u)^2
    basis->at(2).push_back(3 * usqr * tmp); // 3u^2(1-u)
    basis->at(3).push_back(u * usqr);       // u^3
    // cout<< " u : " << u << "\n";
    u += uinc;
  }

  // set up the last row without calculation
  basis->at(0).push_back(0); // (1-u)^3   @ u = 1
  basis->at(1).push_back(0); // 3u(1-u)^2 @ u = 1
  basis->at(2).push_back(0); // 3u^2(1-u) @ u = 1
  basis->at(3).push_back(1); // u^3   @ u = 1
  // this prevents rounding errors on the corner points
}

void bBasis::getBasis(vector<vector<double> > &returnPoints) {
  returnPoints = *basis;
}
