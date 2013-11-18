/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#pragma once
#include "../StdAfx.h"

namespace gp
{

    public ref class Vec
    {
    protected:
        gp_Vec* org;

    public:

        Vec()
        {
            org = new gp_Vec();
            return;
        }

        Vec(System::Double x, System::Double y, System::Double z)
        {
            Standard_Real _x, _y, _z;
            _x = x; _y = y; _z = z;
            org = new gp_Vec(_x, _y, _z);
            return;
        }

    public:

        property System::Double X
        {
            void set(System::Double value) { if (!org) return; org->SetX(value); }
            System::Double get() { return (System::Double)org->X(); }
        }

        property System::Double Y
        {
            void set(System::Double value) { if (!org) return; org->SetY(value); }
            System::Double get() { return (System::Double)org->Y(); }
        }

        property System::Double Z
        {
            void set(System::Double value) { if (!org) return; org->SetZ(value); }
            System::Double get() { return (System::Double)org->Z(); }
        }

    };

}