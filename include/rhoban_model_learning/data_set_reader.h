#pragma once

#include "rhoban_model_learning/sample.h"

#include <rhoban_utils/serialization/json_serializable.h>

#include <random>

namespace rhoban_model_learning
{

class DataSetReader : public rhoban_utils::JsonSerializable
{
public:
  /// Extract the training set and the validation set from the given file.
  /// Methods for separing training and validations sets might differ depending
  /// on DataSetReaders and might require a random engine
  virtual DataSet extractSamples(const std::string & file_path,
                                 std::default_random_engine * engine) const = 0;
};

}
