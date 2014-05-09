#include "script/script.h"

void loadbc(mrb_state* mrb)
{
    mrb_load_irep(mrb, bcVec);
    mrb_load_irep(mrb, bcStype);
    mrb_load_irep(mrb, bcShape);

    return;    
}