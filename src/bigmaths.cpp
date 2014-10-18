#include <node.h>
#include <v8.h>
#include <nan.h>

using namespace v8;

NAN_METHOD(countto) {
    NanScope();
    if (args.Length() < 1) {
      return NanThrowError("No upper bound passed to method");
    }
    if (!args[0]->IsNumber()) {
      return NanThrowError("No upper bound passed to method");
    }

    if (!args[1]->IsNumber()) {
      return NanThrowError("No skip value passed to method");
    }

    int uBound = args[0]->Uint32Value();
    int skip = args[1]->Uint32Value();

    int n = 0;
    int c = 0;
    while (n < uBound) {
        n += skip;
        c ++;
    }
    NanReturnValue(NanNew<Number>(c));
}

void Init(Handle<Object> exports) {
  exports->Set(NanNew<String>("countto"),
    NanNew<FunctionTemplate>(countto)->GetFunction());
}

NODE_MODULE(bigmaths, Init)