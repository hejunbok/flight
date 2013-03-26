#ifndef TRAJECTORY_TRAJLIB_HPP
#define TRAJECTORY_TRAJLIB_HPP

/*
 * Trajectory class representing a trajectory in state space
 *
 * Author: Andrew Barry, <abarry@csail.mit.edu> 2013
 *
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

#include <bot_core/rotations.h>
#include <bot_frames/bot_frames.h>
#include <GL/gl.h>
#include <bot_lcmgl_client/lcmgl.h>

using namespace std;

class Trajectory
{

    public:
        Trajectory();
        Trajectory(string filename); // loads a trajectory from a .csv file
        
        void LoadTrajectory(string filename);
        
        vector<float> GetPoint(float t);
        
        int GetDimension() { return dimension; }
        int GetUDimension() { return udimension; }
        
        void print();
        
        void GetTransformedPoint(int index, BotTrans *transform, double *xyz);
        void PlotTransformedTrajectory(bot_lcmgl_t *lcmgl, BotTrans *transform);
        
        // returns the distance to the closest point on the trajectory
        // could optimize this with cover trees?
        //float DistanceToPoint(float x, float y, float z);
        
        vector<vector<float>> xpoints;
        vector<vector<float>> upoints;
        
        
    private:
        
    
        int dimension; // state space dimension
        int udimension; // control input dimension
        

        void LoadXFromCSV( const std::string& filename);
        void LoadUFromCSV( const std::string& filename);

};

#endif