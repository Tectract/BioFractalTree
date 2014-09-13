/*
-----BEGIN PGP SIGNED MESSAGE-----
Hash: SHA1


 * File:   BioFractalTree.cpp
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
-----BEGIN PGP SIGNATURE-----

iQIcBAEBAgAGBQJUC898AAoJEIRVa2JtJura8FkP/Rr/HceYZYbhZkkDrSs+1QwU
SkQ5U3N2lQmpRf06wY54naPa0dGTsxU8JjzIKwA0Veb0Nyw9xcNXVWwpNCunpdKc
otoqWcjKxBhdZvoUTf4ahhsfwm1WLL9vu0wNEKdxCWK3ZTrSEK0fzTvYjv6vOFhQ
6IfwhO5DuF05It0V+ehRBu8dY3oF+N1hseEbaXGRKjlvmfZOCDUfoESCSQlmIMl/
qZ02WnC99CbWLrOpw6v3vGV5+9fPBl1w5a5g+KnfGkrewxDYJsYPzTmkdOOI/76Y
YdsyJ6tKGzuAJaD/GJld1upkDQXKiHugCbjCKIFVJI8BIHymmF1YauFgH/P/VhTC
+34S3My8sepKtxWQyJlDU5Sl1j1PD92Ygyb+jb62UVqEGpxxd6mecXWY72WKjbVJ
1Rba0rNdOGR7Ztjesb8BODX1aERnoSQhl01mGBfs7bLxwBoNwA8QzS3I8L6NeG4j
gaNmdk4oLoEcvrlsTSXUUiY3gpqRX60s8JKOn1QjcOCnHKx3CrG/ASKQemglmG6w
485NJdcmSvx7n+R7dsJD+e8oSS7wfDqOSfdpmgRalFZhIn3y3zUPLmX2YF+BPGv+
iMHx9JqCis3BqU+Jq//HiFfIf2uIbgH+V76I2qwaYddVA1pnCVWiHavEtsG2XIPy
xCQf3zTRzg/vjT44EWb3
=ZDTL
-----END PGP SIGNATURE-----
 */

#include <memory>
#include <iostream>
#include "BioFractalTree.hpp"

int main(int argc, char **argv) {
  std::cout
      << "¸.·´¯`·.¸¸.·´ BioFractalTree Version 0 Revision 1 `·.¸¸.·´¯`·.¸\n";

  // set up a bcurve for testing early curve / surface viz algs
  vector<double> coords0 = { 0.0, 0.0, 0.0 };
  vector<double> coords1 = { 0.0, 0.3, 0.3 };
  vector<double> coords2 = { 0.3, 0.0, 0.6 };
  vector<double> coords3 = { 0.0, 0.0, 1.0 };

  std::unique_ptr<point> point0(new point(coords0, 0));
  std::unique_ptr<point> point1(new point(coords1, 1));
  std::unique_ptr<point> point2(new point(coords2, 2));
  std::unique_ptr<point> point3(new point(coords3, 3));

  vector<point> curve0 = { *point0, *point1, *point2, *point3 };
  std::unique_ptr<bcurve> thisCurve(new bcurve(curve0, 20));

  // we set up a static Bernstein basis set for a given resolution
  std::unique_ptr<bBasis> bBasis_20(new bBasis(20));
  // this sets up a 4x21 vector of vector<double>
  // 19 internal points plus the two endpoints

  // we can return / output the basis set
  vector<vector<double> > returnBasis;
  bBasis_20->getBasis(returnBasis);
  //    std::cout << "Basis Set Output: \n";
  //    std::cout << "  size : " << returnBasis.at(0).size();
  for (int j = 0; j < 4; j++) {
    //        std::cout << "\n  b[" << j << "] : ";
    for (int i = 0; i < returnBasis.at(j).size(); i++) {
      //    std::cout << returnBasis.at(j).at(i) << " ";
    }
  }
  //    std::cout << "\n";

  // now we can try getting some points on the bcurve
  vector<point> returnPoints;
  thisCurve->getPointsOnCurve(returnPoints, returnBasis, 4);
  // only returnPoints gets modified by the above function
  // it returns 21 points along the curve, including endpoints
  std::cout << "points on curve : \n";
  for (int i = 0; i < returnPoints.size(); i++) {
    vector<double> tempCoord;
    returnPoints.at(i).getCoord(tempCoord);
    for (int j = 0; j < 3; j++) {
      std::cout << tempCoord.at(j) << " ";
    }
    std::cout << "\n";
  }

  return 0;
}
