#pragma once

#ifndef _TESTCLASS_H_
#define _TESTCLASS_H_

#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>

namespace sirenenv {

    class TestClass
    {
    protected:
        int x_;
    public:
        TestClass(int x) : x_(x)
        {
            ;
        }
        virtual ~TestClass()
        {
            ;
        }
        int x() const
        {
            return x_;
        }
    };

    namespace RTestClass {
        void cleenup(mrb_state* mrb, void *ptr);
        static struct mrb_data_type cppclassdeftype = { "TestClass", cleenup };
        mrb_value initialize(mrb_state* mrb, mrb_value self);
        // ---
        mrb_value to_s(mrb_state* mrb, mrb_value self);
        mrb_value x(mrb_state* mrb, mrb_value self);
        // ---
        void install(mrb_state* mrb);
    }

}
#endif
