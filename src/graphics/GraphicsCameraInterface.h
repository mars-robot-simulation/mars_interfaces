#pragma once

#include "../cameraStruct.h"

#include <vector>

//available cameras
#define ODE_CAM 1
#define OSG_CAM 2
#define MICHA_CAM 3
#define ISO_CAM 4
#define TRACKBALL 5

namespace mars
{
    namespace interfaces
    {

        struct local_settings
        {
            double left, right, bottom, top;
            double my_near, my_far;
            double rotation1[3];
            double rotation2[3];
            double pos[3];
            unsigned long id;
            int rotate_with;
        }; // end of struct local_settings


        class GraphicsCameraInterface
        {
        public:
            virtual ~GraphicsCameraInterface() {}
            virtual void getCameraInfo(cameraStruct *s) = 0;
            virtual void setCamera(int type) = 0;
            virtual int getCameraType(void) const = 0;
            virtual int getCamera(void) const = 0;
            virtual void updateViewport(double rx, double ry, double tx,
                                        double ty, double tz, double rz = 0,
                                        bool remember = 0) = 0;
            virtual void updateViewportQuat(double tx, double ty, double tz,
                                            double rx, double ry, double rz,
                                            double rw) = 0;
            /**switches the camera to iso mode and looks at the given position(x, y)
             * at the given height(z)*/
            virtual void lookAtIso(double x, double y, double z = 0)= 0;
            virtual void setViewport(int x, int y, int width, int height) = 0;
            virtual void getViewport(double *rx, double *ry, double *tx,
                                     double *ty, double *tz, double *rz) = 0;
            virtual void getViewportQuat(double *tx, double *ty, double *tz,
                                         double *rx, double *ry, double *rz,
                                         double *rw) = 0;
            virtual void changeCameraTypeToPerspective() = 0;
            virtual void changeCameraTypeToOrtho() = 0;
            virtual void setOrthoH(double v) = 0;

            //  <! -- OUTDATED, USE setFrustum INSTEAD -->
            //  virtual void setLocalSettings(local_settings *local) = 0;
            virtual void setFrustum(double left, double right,
                                    double bottom, double top,
                                    double near, double far) = 0;
            virtual void setFrustumFromRad(double horizontalOpeningAngle,
                                           double verticalOpeningAngle,
                                           double near, double far) = 0;
            virtual void getFrustum(std::vector<double>& frustum) = 0;

            virtual void setStereoMode(bool _stereo) = 0;
            virtual void toggleStereoMode(void) = 0;
            virtual void setEyeSep(double value) = 0;
            virtual double getEyeSep(void) const = 0;
            virtual void setFocalLength(double value) = 0;
            virtual double getFocalLength(void) const = 0;
            virtual void setSwitchEye(bool val) = 0;
            virtual void setLeftEye(void) = 0;
            virtual void setRightEye(void) = 0;

            virtual void context_setCamPredefLeft() = 0;
            virtual void context_setCamPredefRight() = 0;
            virtual void context_setCamPredefFront() = 0;
            virtual void context_setCamPredefRear() = 0;
            virtual void context_setCamPredefTop() = 0;
            virtual void context_setCamPredefBottom() = 0;
            virtual void deactivateCam() = 0;
            virtual void activateCam() = 0;
            virtual void toggleTrackball() = 0;
            virtual bool isTracking() = 0;
            virtual void setTrackingLogRotation(bool b) = 0;
            virtual void getOffsetQuat(double *tx, double *ty, double *tz,
                                       double *rx, double *ry, double *rz,
                                       double *rw) = 0;
            virtual void setOffsetQuat(double tx, double ty, double tz,
                                       double rx, double ry, double rz,
                                       double rw) = 0;
            virtual double getMoveSpeed() = 0;
            virtual void setMoveSpeed(double s) = 0;

        }; // end of class GraphicsCameraInterface

    } // end of namespace interfaces
} // end of namespace mars
