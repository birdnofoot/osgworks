/*************** <auto-copyright.pl BEGIN do not edit this line> **************
 *
 * osgWorks is (C) Copyright 2009-2012 by Kenneth Mark Bryden
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 *************** <auto-copyright.pl END do not edit this line> ***************/

#ifndef __OSGWTOOLS_ORIENTATION_H__
#define __OSGWTOOLS_ORIENTATION_H__ 1


#include "osgwTools/Export.h"
#include <osg/Object>
#include <osg/Quat>
#include <osg/Matrix>
#include <osg/Vec3>


namespace osgwTools
{


/** \class Orientation Orientation.h osgwTools/Orientation.h
\brief Convert between yaw/pitch/roll and OSG Quat/Matrix classes.
\details
This classes replaces the deprecated makeHPRQuat() function from osgwTools/Quat.h.
*/
class OSGWTOOLS_EXPORT Orientation : public osg::Object
{
public:
    Orientation();
    Orientation( const Orientation& rhs, const osg::CopyOp copyop=osg::CopyOp::SHALLOW_COPY );

    META_Object(osgwTools,Orientation);


    /** \brief Set the base vectors.
    \details Determines the default basis corresponding
    to yaw = 0., pitch = 0., and roll = 0.
    \li Yaw is computed as rotation around \c baseUp.
    \li Pitch is computed as rotation around \c baseDir ^ \c baseUp.
    \li Roll is computed as rotation around \c baseDir.

    This function normalizes the vectors before storing them internally.
    getBasis() returns the normalized values, not the original values.

    By default, \c baseDir = (0.,1.,0.) and baseUp = (0.,0.,1.).
    */
    void setBasis( const osg::Vec3d& baseDir, const osg::Vec3d& baseUp );
    /** \brief Get the base vectors.
    \details Returns the normalized base vectors as set with
    setBasis() */
    void getBasis( osg::Vec3d& baseDir, osg::Vec3d& baseUp ) const;

    /** \brief Set right- or left-handed coordinate system.
    \details Determines the rotational direction of angles.
    If \c rightHanded is true, angles are measured counter-clockwise
    with respect to the axis of rotation (make a fist with your right
    hand and extend your thumb; your thumb represents the acis of
    rotation, and your other fingers indicate the direction of
    rotation). If false, angles indicate clockwise rotation.

    Axes of rotation are:
    \li baseUp, for yaw.
    \li baseDir^baseUp, for pitch.
    \li baseDir, for roll.

    See setBasis() to set the baseUp and baseDir vectors.

    Default is false (left-handed). */
    void setRightHanded( const bool rightHanded );
    bool getRightHanded() const;


    /** \brief Create an orientation quat.
    \details \c ypr contains angles in degrees.
    */
    osg::Quat getQuat( const osg::Vec3d& ypr );
    /** \overload */
    osg::Quat getQuat( const double yaw, const double pitch, const double roll );
    /** \brief Make an existing quat into an orientation quat.
    \details \c ypr contains angles in degrees.
    */
    void makeQuat( osg::Quat& result, const osg::Vec3d& ypr );
    /** \overload */
    void makeQuat( osg::Quat& result, const double yaw, const double pitch, const double roll );
    /** \brief Create an orientation matrix.
    \details \c ypr contains angles in degrees.
    */
    osg::Matrix getMatrix( const osg::Vec3d& ypr );
    /** \overload */
    osg::Matrix getMatrix( const double yaw, const double pitch, const double roll );
    /** \brief Make an existing matrix into an orientation matrix.
    \details \c ypr contains angles in degrees.
    */
    void makeMatrix( osg::Matrix& result, const osg::Vec3d& ypr );
    /** \overload */
    void makeMatrix( osg::Matrix& result, const double yaw, const double pitch, const double roll );


    osg::Vec3d getYPR( const osg::Quat& q ) const;
    void getYPR( const osg::Quat& q, double& yaw, double& pitch, double& roll ) const;
    osg::Vec3d getYPR( const osg::Matrix& m ) const;
    void getYPR( const osg::Matrix& m, double& yaw, double& pitch, double& roll ) const;

protected:
    virtual ~Orientation();

    /** \brief Normalize angle into range 0.0 <= angle < 360.0.
    \details This function accounts for the coordinate system.
    */
    double normalizeAngle( const double degreesIn );

    osg::Vec3d _baseDir, _baseUp, _baseCross;
    bool _rightHanded;
};


// namespace osgwTools
}

// __OSGWTOOLS_ORIENTATION_H__
#endif