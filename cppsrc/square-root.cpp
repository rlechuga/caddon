#include "square-root.h"

using namespace std;

float mathlech::squareRoot(int num, int precision)
{
    int start = 0, end = num;
    int mid;

    float ans = 0.0;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (mid * mid == num)
        {
            ans = mid;
            break;
        }

        if (mid * mid < num)
        {
            start = mid + 1;
            ans = mid;
        }
        else
        {
            end = mid - 1;
        }
    }

    float increment = (float)0.1;
    for (int i = 0; i < precision; i++)
    {
        while (ans * ans <= num)
        {
            ans += increment;
        }

        ans = ans - increment;
        increment = increment / 10;
    }

    return ans;
}

Napi::Number mathlech::SquareRootWrapped(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber())
    {
        Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    }

    Napi::Number first = info[0].As<Napi::Number>();
    Napi::Number second = info[1].As<Napi::Number>();

    double returnValue = mathlech::squareRoot(first.Int32Value(), second.Int32Value());

    return Napi::Number::New(env, returnValue);
}

Napi::Object mathlech::Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(
        "squareRoot", Napi::Function::New(env, mathlech::SquareRootWrapped));

    return exports;
}