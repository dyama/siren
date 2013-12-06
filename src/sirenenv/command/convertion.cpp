/**
 * \brief Shape convertion commands
 * THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#include "Stdafx.h"

/**
 * \brief wire to points
 */
mrb_value wire2pts(mrb_state* mrb, mrb_value self)
{
	mrb_int src;
	mrb_float deflect;
	int argc = mrb_get_args(mrb, "i|f", &src, &deflect);

	Handle(AIS_Shape) hashape = ::get(src);
	if (hashape.IsNull()) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	if (argc != 2)
		deflect = 1.0e-1;

	mrb_value result = mrb_ary_new(mrb);
	double first_param, last_param;

	TopExp_Explorer	exp(hashape->Shape(), TopAbs_EDGE);
	for(; exp.More(); exp.Next()) {
		const TopoDS_Edge& edge = TopoDS::Edge(exp.Current());
		try {
			BRepAdaptor_Curve adaptor(edge);
			first_param = adaptor.FirstParameter();
			last_param = adaptor.LastParameter();

			GCPnts_UniformDeflection unidef(adaptor, (Standard_Real)deflect);
			if (!unidef.IsDone())
				continue;

			mrb_value line = mrb_ary_new(mrb);

			// first point
			mrb_ary_push(mrb, line, pnt2ar(mrb, adaptor.Value(first_param)));

			for (int i=0; i<unidef.NbPoints(); i++)
				mrb_ary_push(mrb, line, pnt2ar(mrb, unidef.Value(i)));

			// last point
			mrb_ary_push(mrb, line, pnt2ar(mrb, adaptor.Value(last_param)));
			
			mrb_ary_push(mrb, result, line);
		}
		catch (...) {
			; // nothing to do.
		}
	}

    return result;
}
