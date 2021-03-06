#pragma once

#include "rhoban_model_learning/composite_model.h"
#include "rhoban_model_learning/basic_models/doubles_model.h"
#include "rhoban_model_learning/humanoid_models/pose_model.h"
#include "rhoban_model_learning/humanoid_models/calibration_model.h"

#include "robot_model/camera_model.h"

namespace rhoban_model_learning
{
class PosesOptimizationModel : public CompositeModel
{
public:
  PosesOptimizationModel();
  PosesOptimizationModel(const PosesOptimizationModel& other);

  double getPxStddev() const;

  const rhoban::CameraModel& getCameraModel() const;
  const CalibrationModel getCalibrationModel() const;
  const PoseModel getRobot3DPose() const;

  const Eigen::Vector3d& getTagPosition(int tag_idx) const;
  const Eigen::Vector3d getCornerPosition(int tag_idx, int corner_idx) const;

  virtual std::unique_ptr<Model> clone() const;

  void fromJson(const Json::Value& json_value, const std::string& dir_name) override;
  std::string getClassName() const;
};

}  // namespace rhoban_model_learning
