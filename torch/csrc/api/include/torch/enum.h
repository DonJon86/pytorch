#pragma once

#include <string>

#include <c10/util/variant.h>
#include <torch/csrc/WindowsTorchApiMacro.h>

#define TORCH_ENUM_DECLARE(name) \
namespace torch { \
namespace enumtype { \
  /*
    NOTE: We need to provide the default constructor for each struct,
    otherwise Clang 3.8 would complain:
    ```
    error: default initialization of an object of const type 'const enumtype::Enum1'
    without a user-provided default constructor
    ```
  */ \
  struct k##name { k##name() {} }; \
} \
TORCH_API extern const enumtype::k##name k##name; \
}

#define TORCH_ENUM_DEFINE(name) \
namespace torch { \
const enumtype::k##name k##name; \
}

#define TORCH_ENUM_PRETTY_PRINT(name) \
std::string operator()(const enumtype::k##name& v) const { \
  std::string k("k"); \
  return k + #name; \
}

TORCH_ENUM_DECLARE(Linear)
TORCH_ENUM_DECLARE(Conv1D)
TORCH_ENUM_DECLARE(Conv2D)
TORCH_ENUM_DECLARE(Conv3D)
TORCH_ENUM_DECLARE(ConvTranspose1D)
TORCH_ENUM_DECLARE(ConvTranspose2D)
TORCH_ENUM_DECLARE(ConvTranspose3D)
TORCH_ENUM_DECLARE(Sigmoid)
TORCH_ENUM_DECLARE(Tanh)
TORCH_ENUM_DECLARE(ReLU)
TORCH_ENUM_DECLARE(LeakyReLU)
TORCH_ENUM_DECLARE(FanIn)
TORCH_ENUM_DECLARE(FanOut)
TORCH_ENUM_DECLARE(Constant)
TORCH_ENUM_DECLARE(Reflect)
TORCH_ENUM_DECLARE(Replicate)
TORCH_ENUM_DECLARE(Circular)
TORCH_ENUM_DECLARE(Nearest)
TORCH_ENUM_DECLARE(Bilinear)
TORCH_ENUM_DECLARE(Bicubic)
TORCH_ENUM_DECLARE(Trilinear)
TORCH_ENUM_DECLARE(Area)
TORCH_ENUM_DECLARE(Sum)
TORCH_ENUM_DECLARE(Mean)
TORCH_ENUM_DECLARE(Max)

namespace torch {
namespace enumtype {
struct enum_name {
  TORCH_ENUM_PRETTY_PRINT(Linear)
  TORCH_ENUM_PRETTY_PRINT(Conv1D)
  TORCH_ENUM_PRETTY_PRINT(Conv2D)
  TORCH_ENUM_PRETTY_PRINT(Conv3D)
  TORCH_ENUM_PRETTY_PRINT(ConvTranspose1D)
  TORCH_ENUM_PRETTY_PRINT(ConvTranspose2D)
  TORCH_ENUM_PRETTY_PRINT(ConvTranspose3D)
  TORCH_ENUM_PRETTY_PRINT(Sigmoid)
  TORCH_ENUM_PRETTY_PRINT(Tanh)
  TORCH_ENUM_PRETTY_PRINT(ReLU)
  TORCH_ENUM_PRETTY_PRINT(LeakyReLU)
  TORCH_ENUM_PRETTY_PRINT(FanIn)
  TORCH_ENUM_PRETTY_PRINT(FanOut)
  TORCH_ENUM_PRETTY_PRINT(Constant)
  TORCH_ENUM_PRETTY_PRINT(Reflect)
  TORCH_ENUM_PRETTY_PRINT(Replicate)
  TORCH_ENUM_PRETTY_PRINT(Circular)
  TORCH_ENUM_PRETTY_PRINT(Nearest)
  TORCH_ENUM_PRETTY_PRINT(Bilinear)
  TORCH_ENUM_PRETTY_PRINT(Bicubic)
  TORCH_ENUM_PRETTY_PRINT(Trilinear)
  TORCH_ENUM_PRETTY_PRINT(Area)
  TORCH_ENUM_PRETTY_PRINT(Sum)
  TORCH_ENUM_PRETTY_PRINT(Mean)
  TORCH_ENUM_PRETTY_PRINT(Max)
};
} // namespace enumtype
} // namespace torch
