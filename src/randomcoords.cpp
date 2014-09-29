#include <node.h>
#include <v8.h>
#include <nan.h>

using namespace v8;

NAN_METHOD(getRandomCoords2D) {
    NanScope();
    if (args.Length() < 2) {
      return NanThrowError(node::ErrnoException(errno, "gettimeofday"));
    }
    if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
      return NanThrowError(node::ErrnoException(errno, "gettimeofday"));
    }

    Local<Number> xBound = args[0]->ToNumber();
    Local<Number> yBound = args[1]->ToNumber();

    Local<Object> obj = NanNew<Object>();
    obj->Set(NanNew<String>("x"), NanNew<Number>( 1 + (rand() % xBound->IntegerValue())) );
    obj->Set(NanNew<String>("y"), NanNew<Number>( 1 + (rand() % yBound->IntegerValue())) );
    NanReturnValue(obj);
}

NAN_METHOD(getRandomCoords3D) {
    NanScope();
    if (args.Length() < 3) {
      return NanThrowError(node::ErrnoException(errno, "gettimeofday"));
    }
    if (!args[0]->IsNumber() || !args[1]->IsNumber() || !args[2]->IsNumber()) {
      return NanThrowError(node::ErrnoException(errno, "gettimeofday"));
    }

    Local<Number> xBound = args[0]->ToNumber();
    Local<Number> yBound = args[1]->ToNumber();
    Local<Number> zBound = args[2]->ToNumber();

    Local<Object> obj = NanNew<Object>();
    obj->Set(NanNew<String>("x"), NanNew<Number>( 1 + (rand() % xBound->IntegerValue())) );
    obj->Set(NanNew<String>("y"), NanNew<Number>( 1 + (rand() % yBound->IntegerValue())) );
    obj->Set(NanNew<String>("z"), NanNew<Number>( 1 + (rand() % zBound->IntegerValue())) );
    NanReturnValue(obj);
}

void Init(Handle<Object> exports) {
  exports->Set(NanNew<String>("getRandomCoords2D"),
    NanNew<FunctionTemplate>(getRandomCoords2D)->GetFunction());

  exports->Set(NanNew<String>("getRandomCoords3D"),
    NanNew<FunctionTemplate>(getRandomCoords3D)->GetFunction());
}


NODE_MODULE(randomcoords, Init)