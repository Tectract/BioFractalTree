/*
-----BEGIN PGP SIGNED MESSAGE-----
Hash: SHA1


 * File:   bcurve.cpp
 *    constructor functions for bezier curve object
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
-----BEGIN PGP SIGNATURE-----

iQIcBAEBAgAGBQJUC8/BAAoJEIRVa2JtJuraFWMQAI9Pn0y4JH8EBbKM2+hFxTj0
CyLDZftPSl98VzF2eLFy7jxE83kDqLw8rvFekDb8zXuKCixpF9vDj53sgBoWRUJE
vN7NXaoNou42Ye9w1xUYPtI3TJYtmERu3xzT/cwKaHEQ2uHx3MEqVtTkD/BpefoP
6SK50q+yz4MBa6gvHH9IktLVHtt2lqVCxkcz4dEpSnaEOyT3cFkEmgwyHuS6Mpkm
UBjej1FRBnuIXmQjao7tCgdchN0Myc+6u5IjClHLFhlFbM2eevmbv7i25WSbl+al
Y3+ViXSuakvPVynWRbeG3cGz2EiB7XjdstdqzqPsh/H2e2Sq1YWouVZq471X0cRB
9V6uJzgxizhp0mNB7hz9+EgT+QUDv7HdjETbCPy2fk/JTiQGT98skJBRQS5YaTDf
D6xEug8rbDWR6AvgY6MNzl8ZAIzWn9RWmlRnjYya2mOZyRh7pNCoV1dwjO9jIbQe
2er/q1q9jgZIFKNMdfC4o23gW+n895G+lBkBBTrjHPeKD/DOWgkMIdrA+f3bmfmQ
ki0FbUa9gnBLHO8VMhl8kRfTuHJwhKCd/lm2HsrvUP45ln6PQJE/BTBqqW/cZaLI
Aeq2Tqvc4C6TsjSVWSM8gxgwno2mK/ip3eIVTXwGvU35W7wHSqf+dOvTuzZT2gru
Wcftvy9fjgc8ch+MJlAM
=5/zl
-----END PGP SIGNATURE-----
 */

#include "bcurve.hpp"
#include <memory>
#include <iostream>

bcurve::bcurve(vector<point>& pointSet, int Res) {
    controlPoints = new std::vector<point>;
    *controlPoints = pointSet;
    resolution = Res;
}

int bcurve::setPoints(vector<point>& pointSet) {
    *controlPoints = pointSet;
}

void bcurve::getPoints(vector<point>& returnPoints) {
    returnPoints = *controlPoints;
}

int bcurve::getPointsOnCurve(vector<point>& returnPoints, vector<vector<double>>&basis, int indStart) {
    // here we calculate the points according to the Berstein
    // polynomial basis functions for the Bezier curve equations
    returnPoints.clear();
    //returnPoints.resize(basis.at(0).size());
    vector<double> tempCoord;

    for (int64_t i = 0; i < basis.at(0).size(); i++) {
        vector<double> xyz;
        xyz = { 0.0, 0.0, 0.0 };
        for (int j = 0; j < 4; j++) {
            vector<double> controlxyz;
            controlPoints->at(j).getCoord(controlxyz);
            xyz.at(0) += basis.at(j).at(i) * controlxyz.at(0);
            xyz.at(1) += basis.at(j).at(i) * controlxyz.at(1);
            xyz.at(2) += basis.at(j).at(i) * controlxyz.at(2);
        }
        std::unique_ptr<point> tempPoint(new point(xyz, indStart++));
        returnPoints.push_back(*tempPoint);
    }
    return indStart; // return the next number available for global index

}
