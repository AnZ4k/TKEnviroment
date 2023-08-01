#ifndef TKJSONLIB
#define TKJSONLIB
#include "TKJsonNodeObject.hpp"
namespace tkv
{
    class TKJSON
    {
    private:

       
    public:
        TKJSON();
        TKJSON(tkv::tkString const json);

        tkv::TKJSONObjectNode evaluePath(tkv::tkString const path);
        
    };
}
#endif