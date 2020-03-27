#include <napi.h>

namespace mathlech
{
float squareRoot(int num, int precision);
Napi::Number SquareRootWrapped(const Napi::CallbackInfo &info);
Napi::Object Init(Napi::Env env, Napi::Object exports);
} // namespace mathlech