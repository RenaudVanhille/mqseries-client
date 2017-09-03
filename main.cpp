#include <iostream>

#include "Common/Utils.h"

#include "Common/Init.h"
#include "Common/Close.h"
#include "Common/On.h"

#include "Promise/CPromiseRunner.h"

using v8::Object;
using v8::Local;

namespace mqclient
{
    void InitAll(Local<Object> exports) {
        NODE_SET_METHOD(exports, "init", CPromiseRunner<SInit>::Do);
        NODE_SET_METHOD(exports, "close", CPromiseRunner<SClose>::Do);
        NODE_SET_METHOD(exports, "on", CPromiseRunner<SOn>::Do);
    }

    NODE_MODULE(NodePlanif, InitAll)
}