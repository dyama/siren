#include "stdafx.h"
#include "TestClass.h"

namespace sirenenv
{
    namespace RTestClass {
        mrb_value initialize(mrb_state* mrb, mrb_value self)
        {
            // Initialize data type first, otherwise segmentation fault occurs.
            DATA_TYPE(self) = &cppclassdeftype;
            DATA_PTR(self) = NULL;

            mrb_int x;
            mrb_get_args(mrb, "i", &x);
            TestClass* hoge = new TestClass(x);

            DATA_PTR(self) = hoge;
            return self;
        }

        void cleenup(mrb_state* mrb, void* ptr)
        {
            TestClass* hoge = static_cast<TestClass*>(ptr);
            delete hoge;
        }

        mrb_value to_s(mrb_state* mrb, mrb_value self)
        {
            TestClass* hoge = static_cast<TestClass*>(mrb_get_datatype(mrb, self, &cppclassdeftype));
            char buf[32];
            _snprintf_s(buf, sizeof(buf), "#TestClass<%d>", hoge->x());
            return mrb_str_new_cstr(mrb, buf);
        }

        mrb_value x(mrb_state* mrb, mrb_value self)
        {
            TestClass* hoge = static_cast<TestClass*>(mrb_get_datatype(mrb, self, &cppclassdeftype));
            return mrb_fixnum_value(hoge->x());
        }

        void RTestClass::install(mrb_state* mrb)
        {
            struct RClass *tc = mrb_define_class(mrb, "TestClass", mrb->object_class);
            MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);

            mrb_define_method(mrb, tc, "initialize", initialize, ARGS_REQ(1));
            mrb_define_method(mrb, tc, "inspect", to_s, ARGS_NONE());
            mrb_define_method(mrb, tc, "to_s", to_s, ARGS_NONE());
            mrb_define_method(mrb, tc, "x", x, ARGS_NONE());
        }
    }
}