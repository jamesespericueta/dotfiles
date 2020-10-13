file(REMOVE_RECURSE
  "../../../lib/xpp/include/xpp/proto/composite.hpp"
  "../../../lib/xpp/include/xpp/proto/randr.hpp"
  "../../../lib/xpp/include/xpp/proto/x.hpp"
  "../../../lib/xpp/include/xpp/proto/xkb.hpp"
  "libxpp.a"
  "libxpp.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/xpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
