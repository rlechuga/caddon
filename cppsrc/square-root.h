#include <napi.h>

namespace mathlech
{
Napi::Number SquareRootWrapped(const Napi::CallbackInfo &info);
Napi::Object Init(Napi::Env env, Napi::Object exports);
double squareRoot(int num, int precision);
} // namespace mathlech