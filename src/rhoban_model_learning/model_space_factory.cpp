#include "rhoban_model_learning/model_space_factory.h"

#include "rhoban_model_learning/default_space.h"
#include "rhoban_model_learning/deviation_based_space.h"

namespace rhoban_model_learning
{
ModelSpaceFactory::ModelSpaceFactory()
{
  registerBuilder("DefaultSpace", []() { return std::unique_ptr<ModelSpace>(new DefaultSpace); });
  registerBuilder("DeviationBasedSpace", []() { return std::unique_ptr<ModelSpace>(new DeviationBasedSpace); });
}

}  // namespace rhoban_model_learning
