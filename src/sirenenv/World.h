/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
* WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
* IN README OR LICENSE DOCUMENTATION OF THIS PROJECT.
* ---------------------------------------------------------
* AUTHOR: dyama <dyama@member.fsf.org>
*/

#pragma once

#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>

namespace sirenenv
{
    class World
    {
    protected:
        Handle(V3d_Viewer) myViewer;
        Handle(AIS_InteractiveContext) myContext;
        Handle(Graphic3d_GraphicDriver) myGraphicDriver;

    public:
        World(void);

    public:
        bool Init(void);
        void UpdateWorld(void);
        void EraseObjects(void);
        bool IsObjectSelected(void);
        Handle(AIS_InteractiveContext) GetContext(void);

    //     // Boolean Add(seabox::occ::VShape^ aVShape);
    };

    namespace RWorld {
        void cleenup(mrb_state* mrb, void *ptr);
        static struct mrb_data_type cppclassdeftype = { "World", RWorld::cleenup };
        mrb_value initialize(mrb_state* mrb, mrb_value self);
        // ---
        mrb_value to_s(mrb_state* mrb, mrb_value self);
        mrb_value init(mrb_state* mrb, mrb_value self);
        mrb_value updateworld(mrb_state* mrb, mrb_value self);
        mrb_value eraseobjects(mrb_state* mrb, mrb_value self);
        mrb_value isobjectselected(mrb_state* mrb, mrb_value self);
        // ---
        void install(mrb_state* mrb);
    }
}
