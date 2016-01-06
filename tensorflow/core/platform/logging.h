/* Copyright 2015 Google Inc. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_PLATFORM_LOGGING_H_
#define TENSORFLOW_PLATFORM_LOGGING_H_

// TODO(josh11b): switch this from port.h to platform.h
#include "tensorflow/core/platform/port.h"  // To pick up PLATFORM_define

#if defined(PLATFORM_GOOGLE) || defined(PLATFORM_GOOGLE_ANDROID)
#include "base/logging.h"
#else
#include "tensorflow/core/platform/default/logging.h"
#endif

namespace tensorflow {
namespace port {

// Some platforms require that filenames be of a certain form when
// used for logging.  This function is invoked to allow platforms to
// adjust the filename used for logging appropriately, if necessary
// (most ports can just do nothing).  If any changes are necessary, the
// implementation should mutate "*filename" appropriately.
void AdjustFilenameForLogging(string* filename);

}  // namespace port
}  // namespace tensorflow

#endif  // TENSORFLOW_PLATFORM_LOGGING_H_
