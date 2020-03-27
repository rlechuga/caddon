
/* cppsrc/main.cpp */
#include <napi.h>
#include "square-root.h"
#include "samples/classexample.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
  mathlech::Init(env, exports);
  return ClassExample::Init(env, exports);
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll);