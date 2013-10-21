/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#pragma once
#include "ShapeEnum.h"
#include "Shape.h"
#include <TopExp.hxx>
#include <TopExp_Explorer.hxx>

namespace topo
{

public ref class Explorer
{
protected:
    TopExp_Explorer* org;

public:

    Explorer()
    {
        org = new TopExp_Explorer();
    }

    Explorer(Shape^ target, topo::ShapeEnum type)
    {
        org = new TopExp_Explorer(*target->org, static_cast<TopAbs_ShapeEnum>(type));
    }

public:

    void Init(Shape^ target, topo::ShapeEnum type)
    {
        if (!org) return;
        org->Init(*target->org, static_cast<TopAbs_ShapeEnum>(type));
        return;
    }

    void ReInit()
    {
        if (!org) return;
        org->ReInit();
        return;
    }

    void Clear()
    {
        if (!org) return;
        org->Clear();
        return;
    }

    Shape^ Current()
    {
        if (!org) return nullptr;
        Shape^ result = gcnew Shape();
        *result->org = org->Current();
        return result;
    }

    System::Int32 Depth()
    {
        if (!org) return 0;
        return org->Depth(); 
    }

    System::Boolean More()
    {
        if (!org) return false;
        Standard_Boolean result = org->More();
        return result == Standard_True ? true : false;
    }

    void Next()
    {
        if (!org) return;
        org->Next();
        return;
    }

};

}